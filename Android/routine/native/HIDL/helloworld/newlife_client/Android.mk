LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := newlife_client
LOCAL_SRC_FILES := \
	client.cpp

LOCAL_SHARED_LIBRARIES := \
	liblog \
	libhidlbase \
	libutils \
	android.hardware.newlife@1.0 \

LOCAL_VENDOR_MODULE := true
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/bin

include $(BUILD_EXECUTABLE)
