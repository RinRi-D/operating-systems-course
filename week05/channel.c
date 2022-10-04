#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("create pipe");
        exit(1);
    }

    char mes[1024];
    switch (fork()) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            close(fd[1]);
            read(fd[0], mes, 1024);
            printf("%s\n", mes);
            close(fd[0]);
            break;
        default:
            close(fd[0]);
            fgets(mes, 1024, stdin);
            write(fd[1], mes, 1024);
            close(fd[1]);
            int status;
            wait(&status);
    }
}
