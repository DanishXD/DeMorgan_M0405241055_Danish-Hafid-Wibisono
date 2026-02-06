#include <stdio.h>
#include <ctype.h>
int main() {
    char c1, c2;
    int text;
    scanf("%c %c", &c1, &c2);
    getchar();
    while((text = getchar()) != EOF){
        if(tolower(text) == tolower(c1)){
          if(isupper(text)){
            text = toupper(c2);}
          else text = tolower(c2);{
          }
        }
        putchar(text);
    }
    return 0;
}