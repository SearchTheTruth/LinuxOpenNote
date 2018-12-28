auto类型的变量
const int cstint = 100;
auto &refer = cstint;
cstint是顶层变量，一般auto会忽略掉顶层const。n
那么此时refer的类型是什么，是否可以通过更改refer修改cstint?


不能通过refer改变cstint的值
此时refer应该是const int &refer
