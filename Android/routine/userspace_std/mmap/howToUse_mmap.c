#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>



int main()
{
	char *addr;
	struct stat sb;
	int fd = open("foo.txt", O_RDWR);
	if (fd < 0)
		printf("open failed\n");

	if (fstat(fd, &sb) == -1)
		printf("fstat error\n");

	//将fd从offset 0开始, length = sb.st_size的内容映射到当前程序的进程空间中, 存放在addr的位置.
	addr = mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);

	write(STDOUT_FILENO, addr, sb.st_size);

	return 0;

}

