#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    printf("SUBSCRIBER\n");

    int fd = open("/tmp/ex1", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    char mes[1024];
    while(1) {
        read(fd, mes, 1024);
        printf("%s", mes);
        sleep(1);
    }
}
