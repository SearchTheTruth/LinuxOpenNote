#include <memory>
#include <iostream>

using namespace std;

struct connection {
    struct destnation *dst;
    int srcnu;
};

struct destnation {
    int dstnu = 0;
};

struct connection *connect(struct destnation *dst)
{
    struct connection *con = new connection();
    con->dst = dst;
    con->srcnu = 10;
    return con;
}

void disconnect(struct connection *con)
{
    delete con;
}

void print(struct connection *con)
{
    cout << "Dst:" << con->dst->dstnu << " Src:" << con->srcnu << endl;
}

void link()
{
    struct destnation dst = {1};
    struct connection *con = connect(&dst);
    print(con);
    disconnect(con);
}

void link_leak()
{
    struct destnation dst = {2};
    struct connection *con = connect(&dst);
    print(con);
    //此处不进行disconnect会导致一个connection大小的内存泄漏
}

void link_shared_ptr()
{
    struct destnation dst = {3};
    struct connection *con = connect(&dst);
    shared_ptr<connection> mng(con, disconnect);
    print(con);
    //此处不主动释放,mng指向con所指的对象.
    //函数结束时,mng计数为0,调用删除器disconnect来释放指向的对象.
}

void link_lambda()
{
    struct destnation dst = {4};
    struct connection *con = connect(&dst);
    shared_ptr<connection> mng(con, [](struct connection *con) {disconnect(con);});
    print(con);
}

int main()
{
    link();
    link_leak();
    link_shared_ptr();
    link_lambda();
    return 0;
}
