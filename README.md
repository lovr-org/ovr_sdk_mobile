# Oculus Mobile SDK (mirror)

This is a Git mirror of Oculus' 
[Android SDK](https://developer.oculus.com/downloads/package/oculus-mobile-sdk/), 
provided so that it can be git submodule'd into other projects.

You must still agree to Oculus' licensing terms to use it.

# About

The Oculus Mobile SDK includes libraries, tools, and resources for native C/C++ development of Android apps for the Oculus Quest and Oculus Go standalone devices. If you primarily use Unity or Unreal Engine for Android development, it is not necessary to download the Mobile SDK in most cases . For more information on Oculus Mobile development using Unity or Unreal Engine, see Mobile Development with Unity and Unreal.

For documentation on developing for Oculus devices that use Android, see our Mobile SDK Developer Guide.

# Version history

## Oculus Mobile SDK 20.0 (API 1.37.0) (2020-09-02)

### API Changes

* The ovrDeviceType values, VRAPI_DEVICE_TYPE_OCULUSGO and VRAPI_DEVICE_TYPE_MIVR_STANDALONE, have been removed from the API.
* The ovrModeFlags flag, VRAPI_MODE_FLAG_FRONT_BUFFER_565, has been removed from the API.
* The ovrSystemStatus value, VRAPI_SYS_STATUS_FRONT_BUFFER_565, has been removed from the API.
* The ovrProperty, VRAPI_BLOCK_REMOTE_BUTTONS_WHEN_NOT_EMULATING_HMT, has been removed from the API.
* The ovrSystemUIType types, VRAPI_SYS_UI_KEYBOARD_MENU and VRAPI_SYS_UI_FILE_DIALOG_MENU, have been removed from the API.
* vrapi_ShowFatalError is now marked deprecated and should no longer be used.
* The deprecated vrapi_ShowSystemUIWithExtra entry point has been removed from the API.

### Bug Fixes

* There are no major bug fixes with this release.

### Known SDK Issues

* There are no known issues with this release.

## Oculus Mobile SDK 19.0 (API 1.36) (2020-08-03)

For details on migrating to Mobile SDK 19.0 (API 1.36) from previous versions, see the [Mobile SDK Migration Guide](https://developer.oculus.com/documentation/native/android/mobile-native-migration/).

### API Changes

* A new ovrTextureSwapChain creation method, vrapi_CreateTextureSwapchain4, and corresponding structure, ovrSwapChainCreateInfo, have been added to the API.
* A new ovrControllerType, ovrControllerType_StandardPointer, and corresponding structure, ovrInputStandardPointerCapabilities, have been added to the API.
* The vrapi_SetRemoteEmulation function has been removed from the API and should no longer be used.


## Oculus Mobile SDK 15.0 (API 1.32.0) (2020-04-06)

For details on migrating to Mobile SDK 15.0 (API 1.32) from previous versions, see the Mobile SDK Migration Guide.

### API Changes

* A new ovrSystemStatus, VRAPI_SYS_STATUS_SCREEN_CAPTURE_RUNNING, has been added, which returns true when recording is enabled
* ovrControllerType_Headset and associated structures have been removed.
* The permission flag in the Android manifest to use hand tracking functionality has changed to: `<uses-permission android:name="com.oculus.permission.HAND_TRACKING" />`
