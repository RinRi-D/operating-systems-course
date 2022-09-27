#include <stdio.h>
#include <stdlib.h>

int main() {
    while(1) {
        printf("$ ");
        char command[256];
        fgets(command, 256, stdin);
        system(command);
    }
}
