LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    $(common_includes) \
    $(kernel_includes)

LOCAL_SRC_FILES := android_native_thread.cpp

LOCAL_MODULE := android_native_thread

LOCAL_SHARED_LIBRARIES := \
    libutils libhardware liblog libcutils

LOCAL_CPPFLAGS += -g

LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/bin
include  $(BUILD_EXECUTABLE)
###################################
include $(CLEAR_VARS)

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    $(common_includes) \
    $(kernel_includes)

LOCAL_SRC_FILES := android_native_looper.cpp

LOCAL_MODULE := android_native_looper

LOCAL_SHARED_LIBRARIES := \
    libutils libhardware liblog libcutils libgui

LOCAL_CPPFLAGS += -g

LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/bin
include  $(BUILD_EXECUTABLE)