#include <jni.h>
#include <iostream>

#include <android/log.h>
#include <android/native_activity.h>

#define LOG_D(...) ((void) __android_log_print(ANDROID_LOG_DEBUG, "NATIVE_APP", "%s", __VA_ARGS__));

static void onCreate(ANativeActivity* activity) {
    LOG_D("onCreate")
}

static void onStart(ANativeActivity* activity) {
    LOG_D("onStart")
}

static void onPause(ANativeActivity* activity) {
    LOG_D("onPause")
}

JNIEXPORT
void ANativeActivity_onCreate(ANativeActivity* activity, void* savedState, size_t savedStateSize) {
    activity->callbacks->onStart = onStart;
    activity->callbacks->onPause = onPause;
    onCreate(activity);
}