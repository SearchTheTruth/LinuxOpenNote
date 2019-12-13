#include <algorithm>
#include <functional>
#include <string>

using namespace std;
using namespace std::placeholders;

count_if(ivec.begin(), ivec.end(), bind(greater<int>(), _1, 1024));
find_if(svec.begin(), svec.end(), bind(not_equal_to<string>(), _1, "pooh"));
transform(ivec.begin(), ivec.end(), ivec.begin(), bind(multiplies<int>(), _1, 2));
