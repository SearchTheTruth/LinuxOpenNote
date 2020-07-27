#include "ITest.h"

IMPLEMENT_META_INTERFACE(Test, "android.jianghao.TestService");

status_t BnTest::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
	status_t err;
	int size;
	switch (code) {
		case SET:
			CHECK_INTERFACE(ITest, data, reply);
		err = setListContent(data.readInt32(), data.readString16());
			reply->writeInt32(err);
		break;
		case GET:
			CHECK_INTERFACE(ITest, data, reply);
			err = getListSize(&size);
			reply->writeInt32(err);
			reply->writeInt32(size);
		break;
		case REMOVE:
			CHECK_INTERFACE(ITest, data, reply);
			err = removeList(data.readInt32());
			reply->writeInt32(err);
		break;
		default:
			BBinder::onTransact(code, data, reply, flags);
		break;
	}
	return NO_ERROR;
}

status_t TestService::getListSize(int *size)
{
	*size = textList.size();
	print();
	return OK;
}

status_t TestService::setListContent(const int pos, const String16 &txt)
{
	auto beg = textList.begin();
	for (int i = 0; beg != textList.end(); ++i, ++beg) {
		if (i == pos) {
			textList.insert(beg, txt);
		}
	}
	print();
	return OK;
}

status_t TestService::removeList(const int pos)
{
	auto beg = textList.begin();
	for (int i = 0; beg != textList.end(); ++i, ++beg) {
		if (i == pos) {
			textList.erase(beg);
		}
	}
	print();
	return OK;
}

void TestService::print()
{
	ALOGE("+++++++++++++++++");
	ALOGE("size = %lu", textList.size());
	for(auto &txt : textList) {
		ALOGE("%s", String8(txt).string());
	}
	ALOGE("+++++++++++++++++");
}
