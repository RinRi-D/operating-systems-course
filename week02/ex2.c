#include <stdio.h>
#include <string.h>

int main() {
    char s[257], c;
    int i = 0;
    while ((c = getc(stdin)) != '.') {
        if (c == '\n')
            break;
        s[i++] = c;
    }
    s[i] = '\0';
    // i is already the size of s. I've used strlen to follow the 'hints'
    // section.
    putc('\"', stdout);
    for (i = strlen(s) - 1; i >= 0; --i) {
        putc(s[i], stdout);
    }
    putc('\"', stdout);
}