mmap使用例程
例程操作
1.利用mmap读取foo.txt中的内容并打印出来
2.TODO: 利用mmap回写一些内容到foo.txt中.
3.更多使用细节查看man mmap及其中例程

注意事项:
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
offset必须是pagesize的整倍数
从fd文件的offset偏移处,映射长度为length的空间到当前进程的空间中,若addr为Null则kernel自动生成映射后的地址.


