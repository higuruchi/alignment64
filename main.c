#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
    int member32bit;
    long member64bit;
} Test;

int main(void) {
    Test t = {
        .member32bit = 1,
        .member64bit = 2,
    };

    int fd = open("./test", O_CREAT | O_RDWR);
    write(fd, &t, sizeof(Test));

    return 0;
}