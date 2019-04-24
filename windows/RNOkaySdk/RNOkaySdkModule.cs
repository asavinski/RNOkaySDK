using ReactNative.Bridge;
using System;
using System.Collections.Generic;
using Windows.ApplicationModel.Core;
using Windows.UI.Core;

namespace Okay.Sdk.RNOkaySdk
{
    /// <summary>
    /// A module that allows JS to share data.
    /// </summary>
    class RNOkaySdkModule : NativeModuleBase
    {
        /// <summary>
        /// Instantiates the <see cref="RNOkaySdkModule"/>.
        /// </summary>
        internal RNOkaySdkModule()
        {

        }

        /// <summary>
        /// The name of the native module.
        /// </summary>
        public override string Name
        {
            get
            {
                return "RNOkaySdk";
            }
        }
    }
}
