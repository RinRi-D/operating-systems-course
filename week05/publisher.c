#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [subs]", argv[0]);
        exit(1);
    }

    printf("PUBLISHER\n");

    int subs = atoi(argv[1]);

    if (mkfifo("/tmp/ex1", 0777) == -1) {
        if (errno != EEXIST) {
            perror("mkfifo");
            exit(1);
        }
    }

    int fd = open("/tmp/ex1", O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    while(1) {
        char mes[1024];
        fgets(mes, 1024, stdin);

        for (int i = 0; i < subs; ++i)
            write(fd, mes, 1024);
        sleep(1);
    }
}

// mkfifo reference 
// https://man7.org/linux/man-pages/man3/mkfifo.3.html
