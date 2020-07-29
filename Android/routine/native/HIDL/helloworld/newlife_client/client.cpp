#include <android/hardware/newlife/1.0/INewlife.h>
#include <hidl/Status.h>
#include <hidl/LegacySupport.h>
#include <utils/misc.h>
#include <hidl/HidlSupport.h>
#include <stdio.h>



using android::hardware::newlife::V1_0::INewlife;
using android::sp;
using android::hardware::hidl_string;

int main()
{
	sp service = INewlife::getService();
	if (service == nullptr) {
		printf("Failed to get service\n");
		return -1;
	}

	service->helloWorld("JJ HIDL", [&](hidl_string result) {
		printf("%s\n", result.c_str());
	});

	return 0;
}
