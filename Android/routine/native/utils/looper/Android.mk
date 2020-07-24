LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := looper_routine
LOCAL_SRC_FILES := \
  howToUseLooper.cpp

LOCAL_SHARED_LIBRARIES := \
	liblog \
	libutils \
	libbase \

LOCAL_CFLAGS += -Wno-unused-variable -Wno-unused-parameter

LOCAL_VENDOR_MODULE := true
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/bin

include $(BUILD_EXECUTABLE)
