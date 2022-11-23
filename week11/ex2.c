#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR *d = opendir("/");
    if (d == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(d))!= NULL) {
        if (entry->d_name[0] == '.')
            continue;

        printf("%s ", entry->d_name);
    }
}
