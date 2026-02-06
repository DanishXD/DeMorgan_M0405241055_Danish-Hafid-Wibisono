#include <stdio.h>
#include <ctype.h>
int main() {
    int text, prev = ' ';
    while ((text = getchar()) != EOF) {
        if (isspace(prev) && !isspace(text)) {
            text = toupper(text);
        }
        putchar(text);
        prev = text;
    }
    return 0;
}