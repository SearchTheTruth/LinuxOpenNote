LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := TestService
LOCAL_SRC_FILES := \
  main_testserver.cpp ITest.cpp

LOCAL_SHARED_LIBRARIES := \
	liblog \
	libutils \
	libbinder \

LOCAL_STATIC_LIBRARIES := \
	libserviceutils \

LOCAL_VENDOR_MODULE := true
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/bin

include $(BUILD_EXECUTABLE)
