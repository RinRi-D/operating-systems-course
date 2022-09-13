#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count(char s[], char c) {
    int cnt = 0, sz = strlen(s);
    for (int i = 0; i < sz; ++i) {
        if (tolower(s[i]) == tolower(c))
            cnt++;
    }

    return cnt;
}

void countAll(char s[]) {
    int sz = strlen(s);
    for (int i = 0; i < sz; ++i) {
        int cnt = count(s, s[i]);
        if (cnt > 0)
            printf("%c:%d%s", tolower(s[i]), cnt, (i == sz - 1 ? "\n" : ", "));
    }
}

int main() {
    char s[257];
    scanf("%s", s);
    countAll(s);
}