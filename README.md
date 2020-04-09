# Oculus Mobile SDK (mirror)

This is a Git mirror of Oculus' Android SDK, provided so that it can be
git submodule'd into other projects.

You must still agree to Oculus' licensing terms to use it.

# Oculus Mobile SDK 15.0

The Oculus Mobile SDK includes libraries, tools, and resources for native C/C++ development of Android apps for the Oculus Quest and Oculus Go standalone devices. If you primarily use Unity or Unreal Engine for Android development, it is not necessary to download the Mobile SDK in most cases . For more information on Oculus Mobile development using Unity or Unreal Engine, see Mobile Development with Unity and Unreal.

For documentation on developing for Oculus devices that use Android, see our Mobile SDK Developer Guide.

## Version history

### Oculus Mobile SDK 15.0 (API 1.32.0) (2020-04-06)

For details on migrating to Mobile SDK 15.0 (API 1.32) from previous versions, see the Mobile SDK Migration Guide.
API Changes

* A new ovrSystemStatus, VRAPI_SYS_STATUS_SCREEN_CAPTURE_RUNNING, has been added, which returns true when recording is enabled
* ovrControllerType_Headset and associated structures have been removed.
* The permission flag in the Android manifest to use hand tracking functionality has changed to: `<uses-permission android:name="com.oculus.permission.HAND_TRACKING" />`
