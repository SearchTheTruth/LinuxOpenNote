LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := thread_routine
LOCAL_SRC_FILES := \
  howToUseThread.cpp

LOCAL_SHARED_LIBRARIES := \
	liblog \
	libutils \

LOCAL_VENDOR_MODULE := true
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/bin

include $(BUILD_EXECUTABLE)
