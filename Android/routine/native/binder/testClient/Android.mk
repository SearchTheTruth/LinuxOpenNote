LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := TestClient
LOCAL_SRC_FILES := \
	main_testclient.cpp \
	../testService/ITest.cpp \

LOCAL_SHARED_LIBRARIES := \
	liblog \
	libutils \
	libbinder \
	libbase \

LOCAL_VENDOR_MODULE := true
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/bin

include $(BUILD_EXECUTABLE)
