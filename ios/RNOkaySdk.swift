//
//  RNOkaySdk.swift
//  RNOkaySdk
//
//  Created by Meer, Pavel on 4/18/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

import Foundation
//import PSA
//import PSACommon
//
@objc(RNOkaySdk)
class RNOkaySdk: NSObject {
//
//        @objc func updateDeviceToken(deviceToken: String!, resolve: RCTPromiseResolveBlock, reject: RCTPromiseRejectBlock) -> Void {
//            do {
//                PSA.updateDeviceToken(deviceToken)
//            } catch {
//                reject("Failed update device token", "Failed update device token", error);
//            }
//
//            resolve("Succes update device token")
//        }
//
//        @objc func enrollmentProcedure(withHost: String, installationId: String, pubPssBase64: String, resolve: @escaping RCTPromiseResolveBlock, reject: RCTPromiseRejectBlock) -> Void {
//            do {
//                if PSA.isReadyForEnrollment() {
//                    try PSA.startEnrollment(withHost: withHost, installationId: installationId, pubPssBase64: pubPssBase64) { status in
//                        resolve(status)
//                    }
//                }
//            } catch {
//                reject("setup_audio_session_failed", "Failed to setup audio session", error)
//            }
//        }
//
//        @objc func isEnrolled( _ resolve: RCTPromiseResolveBlock, reject: RCTPromiseRejectBlock) -> Void {
//            do {
//                let isEnrolled : Bool = PSA.isEnrolled();
//                resolve(isEnrolled);
//            } catch {
//                reject("setup_audio_session_failed", "Failed to setup audio session", error)
//            }
//        }
//
//    //    @objc func isEnrolled() -> Bool {
//    //       return PSA.isEnrolled();
//    //    }
//
//        @objc func isReadyForAuthorization(resolve: RCTPromiseResolveBlock, reject: RCTPromiseRejectBlock) -> Void {
//            do {
//                let isReadyForAuthorization : Bool = PSA.isReadyForAuthorization();
//                resolve(isReadyForAuthorization);
//            } catch {
//                reject("setup_audio_session_failed", "Failed to setup audio session", error)
//            }
//        }
//
////        @objc(authorization:sessionId:resolver:rejecter:)
////        func authorization(with: PSATheme?, sessionId:NSNumber?, resolve: RCTPromiseResolveBlock, reject: RCTPromiseRejectBlock) {
////            do {
////                PSA.startAuthorization(with: PSATheme, sessionId:NSNumber?) { isCancelled, status in
////                    resolve(status)
////                }
////            } catch {
////                reject("setup_audio_session_failed", "Failed to setup audio session", error)
////            }
//    //        }
}
