#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct file {
    ino_t inode;
    char names[64][256];
    int sz;
};

int putToFiles(char name[256], ino_t inode, struct file *files, int sz) {
    // if found the same inode
    for (int i = 0; i < sz; ++i) {
        if (files[i].inode == inode) {
            memcpy(files[i].names[files[i].sz++], name, 256);
            return sz;
        }
    }

    // if not found
    files[sz].inode = inode;
    memcpy(files[sz].names[0], name, 256);
    files[sz].sz = 1;
    sz++;

    return sz;
}

int main() {
    DIR *d = opendir("./tmp");
    if (d == NULL) {
        perror("opendir");
        exit(1);
    }

    struct file files[64];
    int sz = 0;

    struct dirent *entry;
    while ((entry = readdir(d))!= NULL) {
        if (entry->d_name[0] == '.')
            continue;

        //printf("%s ", entry->d_name);
        struct stat s;
        char buf[256] = "./tmp/";
        strncpy(buf + strlen(buf), entry->d_name, 200);

        if (stat(buf, &s) == -1) {
            perror("stat");
            exit(1);
        }

        sz = putToFiles(entry->d_name, s.st_ino, files, sz);
    }

    printf("File --- Hard links\n");
    for (int i = 0; i < sz; ++i) {
        if (files[i].sz > 1) {
            for (int j = 0; j < files[i].sz; ++j) {
                printf("%s --- ", files[i].names[j]);
                for (int k = 0; k < files[i].sz; ++k) {
                    printf("%s ", files[i].names[k]);
                }
                printf("\n");
            }
        }
    }
}
