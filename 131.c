#include <stdio.h>
#include <ctype.h>
int main(){
    char ch;
    int jml[26] = {0};
    while ((ch=getchar())!=EOF){
        if(isalpha(ch)){
            ch = tolower(ch);
            jml[ch - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (jml[i] > 0) {
            printf("%c %d\n", 'a' + i, jml[i]);
        }
    }
    return 0;
}