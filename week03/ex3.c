#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

struct Directory;
struct File;

struct File {
    int id;
    unsigned long size;
    char data[2048];
    char name[64];

    struct Directory *directory; // The parent directory
};

struct Directory {
    int nf;
    int nd;
    char path[4096];

    struct File *files[256];
    struct Directory *directories[8];
};

typedef struct Directory Directory;
typedef struct File File;

// Operations on files
void add_to_file(File *file, const char *content);
void append_to_file(File *file, const char *content);
void pwd_file(File *file);

// Operations on directories
void add_file(File *file, Directory *dir);
void add_dir(Directory *dir1, Directory *dir2); // given to you

// Helper functions
void show_dir(Directory *dir);
void show_file(File *file);
void show_file_detailed(File *file);

void init_dir(Directory *dir, char *name);
void init_file(File *file, char *name);

int cur_id = 0;

int main() {

    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";

    Directory home, bin, root;
    init_dir(&root, "/");
    init_dir(&home, "home");
    init_dir(&bin, "bin");

    // Example: the path of the folder home is /home

    // Add subdirectories
    add_dir(&home, &root);
    add_dir(&bin, &root);

    File bash, ex31, ex32;
    init_file(&bash, "bash");
    init_file(&ex31, "ex3_1.c");
    init_file(&ex32, "ex3_2.c");

    //<WRITE YOUR CODE HERE>

    add_file(&bash, &bin);
    add_file(&ex31, &home);
    add_file(&ex32, &home);

    add_to_file(&bash, content4);
    add_to_file(&ex31, content1);
    add_to_file(&ex32, content3);

    append_to_file(&ex31, content2);

    show_dir(&root);
    show_file_detailed(&bash);
    show_file_detailed(&ex31);
    show_file_detailed(&ex32);

    pwd_file(&bash);
    pwd_file(&ex31);
    pwd_file(&ex32);

    return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir
void show_dir(Directory *dir) {
    printf("\nDIRECTORY\n");
    printf(" path: %s\n", dir->path);
    printf(" files:\n");
    printf("    [ ");
    for (int i = 0; i < dir->nf; i++) {
        show_file(dir->files[i]);
    }
    printf("]\n");
    printf(" directories:\n");
    printf("    { ");

    for (int i = 0; i < dir->nd; i++) {
        show_dir(dir->directories[i]);
    }
    printf("}\n");
}

// Prints the name of the File file
void show_file(File *file) { printf("%s ", file->name); }

// Shows details of the File file
void show_file_detailed(File *file) {
    printf("\nFILE\n");
    printf(" id: %d\n", file->id);
    printf(" name: %s\n", file->name);
    printf(" size: %lu\n", file->size);
    printf(" data:\n");
    printf("    [ %s ]\n", file->data);
}

// Implementation: Operations on files

// Adds the content to the File file
void add_to_file(File *file, const char *content) {
    if (file && content) {
        strcpy(file->data, content);
        file->size = strlen(file->data) + 1;
    }
}

// Appends the content to the File file
void append_to_file(File *file, const char *content) {
    if (file && content) {
        int sz = strlen(file->data);
        strcpy(file->data + sz, content);
        file->size = strlen(file->data) + 1;
    }
}

// Prints the path of the File file
void pwd_file(File *file) {
    if (file) {
        printf("%s/%s\n", file->directory->path, file->name);
    }
}

// Implementation: Operations on directories

// Adds the File file to the Directory dir
void add_file(File *file, Directory *dir) {
    if (file && dir) {
        dir->files[dir->nf] = file;
        dir->nf++;

        file->directory = dir;
    }
}

// Given to you
// Adds the subdirectory dir1 to the directory dir2
void add_dir(Directory *dir1, Directory *dir2) {
    if (dir1 && dir2) {
        dir2->directories[dir2->nd] = dir1;
        dir2->nd++;

        int sz1 = strlen(dir1->path), sz2 = strlen(dir2->path);
        if (dir2->path[sz2 - 1] == '/') {
            memmove(dir1->path + sz2, dir1->path, sz1 + 1);
        } else {
            memmove(dir1->path + sz2 + 1, dir1->path, sz1 + 1);
            *(dir1->path + sz2) = '/';
        }
        memcpy(dir1->path, dir2->path, sz2);
    }
}

void init_dir(Directory *dir, char *name) {
    dir->nd = dir->nf = 0;
    strcpy(dir->path, name);
}

void init_file(File *file, char *name) {
    file->data[0] = '\0';
    file->id = cur_id++;
    strcpy(file->name, name);
    file->size = 0;
}
