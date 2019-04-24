
package com.reactlibrary;

import android.app.Activity;
import android.content.Intent;

import com.facebook.react.bridge.ActivityEventListener;
import com.facebook.react.bridge.BaseActivityEventListener;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableArray;
import com.facebook.react.bridge.WritableNativeArray;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.protectoria.psa.PsaManager;
import com.protectoria.psa.api.PsaConstants;
import com.protectoria.psa.api.entities.SpaAuthorizationData;
import com.protectoria.psa.api.entities.SpaEnrollData;
import com.protectoria.psa.dex.common.data.enums.PsaType;
import com.protectoria.psa.dex.common.ui.PageTheme;
import com.protectoria.psa.ui.activities.authorization.AuthorizationActivity;


public class RNOkaySdkModule extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;

    private Promise mPickerPromise;

    private final ActivityEventListener mActivityEventListener = new BaseActivityEventListener() {

        @Override
        public void onActivityResult(Activity activity, int requestCode, int resultCode, Intent data) {
            if (requestCode == PsaConstants.ACTIVITY_REQUEST_CODE_PSA_ENROLL) {
                if (resultCode == Activity.RESULT_OK) {
                    mPickerPromise.resolve(resultCode);
                } else {
                    mPickerPromise.reject("" + resultCode);
                }
            }

            if (requestCode == PsaConstants.ACTIVITY_REQUEST_CODE_PSA_AUTHORIZATION) {
                if (resultCode == Activity.RESULT_OK
                        || resultCode == AuthorizationActivity.RESULT_OK_CONSUMED_PUSH) {
                    mPickerPromise.resolve(resultCode);
                } else {
                    mPickerPromise.reject("" + resultCode);
                }
            }
        }
    };


    public RNOkaySdkModule(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;
        reactContext.addActivityEventListener(mActivityEventListener);
    }


    @ReactMethod
    public void init(String endpoint, final Promise promise) {
        PsaManager psaManager = PsaManager.init(reactContext, new CrashlyticsExceptionLogger());
        psaManager.setPssAddress(endpoint);
        promise.resolve("Success endpoint");
    }


    @ReactMethod
    public void enrollProcedure(final ReadableMap data, final Promise promise) {
        Activity activity = reactContext.getCurrentActivity();
        mPickerPromise = promise;

        ReadableMap spaEnrollDataMap = data.getMap("SpaEnrollData");
        String appPns = spaEnrollDataMap.getString("appPns");
        String pubPss = spaEnrollDataMap.getString("pubPss");
        String installationId = spaEnrollDataMap.getString("installationId");
        ReadableMap pageThemeMap = spaEnrollDataMap.getMap("pageTheme");
        PageTheme pageTheme = initPageTheme(pageThemeMap, promise);
        PsaType psaType = PsaType.OKAY;

        SpaEnrollData enrollData = new SpaEnrollData(appPns, pubPss, installationId, pageTheme, psaType);
        PsaManager.startEnrollmentActivity(activity, enrollData);
    }


    @ReactMethod
    public void authorization(final ReadableMap data, final Promise promise) {
        Activity activity = reactContext.getCurrentActivity();
        mPickerPromise = promise;

        ReadableMap spaEnrollDataMap = data.getMap("SpaAuthorizationData");
        int sessionId = spaEnrollDataMap.getInt("sessionId");
        String appPNS = spaEnrollDataMap.getString("appPNS");
        ReadableMap pageThemeMap = spaEnrollDataMap.getMap("pageTheme");
        PageTheme pageTheme = initPageTheme(pageThemeMap, promise);
        PsaType psaType = PsaType.OKAY;

        SpaAuthorizationData authorizationData = new SpaAuthorizationData(sessionId, appPNS, pageTheme, psaType);
        PsaManager.startAuthorizationActivity(activity, authorizationData);
    }


    @ReactMethod
    public void isEnrolled(final Promise promise) {
        promise.resolve(PsaManager.getInstance().isEnrolled());
    }


    @ReactMethod
    public void isReadyForAuthorization(final Promise promise) {
        promise.resolve(PsaManager.getInstance().isReadyForAuthorization());
    }


    @ReactMethod
    public void permissionRequest(final Promise promise) {
        String[] permissions = PsaManager.getRequiredPermissions();
        WritableArray writableArray = new WritableNativeArray();
        for (String permission : permissions) {
            writableArray.pushString(permission);
        }
        if (writableArray.size() == 0) {
            promise.reject("No permissions found.");
        }
        promise.resolve(writableArray);
    }


    public PageTheme initPageTheme(ReadableMap pageThemeMap, Promise promise) {
        ObjectMapper mapper = new ObjectMapper();
        PageTheme pageTheme = new PageTheme();
        try {
            pageTheme = mapper.convertValue(pageThemeMap.toHashMap(), PageTheme.class);
        } catch (Exception e) {
            promise.reject("Invalid object property");
        }
        return pageTheme;
    }


    @Override
    public String getName() {
        return "RNOkaySdk";
    }
}