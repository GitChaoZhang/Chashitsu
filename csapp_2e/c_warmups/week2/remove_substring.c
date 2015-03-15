#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LMT 80

void remove_str(const char *s1, const char *s2, char * res){
    
}

int main(int argc, const char *argv[]){
    char s1[STRING_LMT];
    char s2[STRING_LMT];
    char res[STRING_LMT] = "hello world";
    scanf("%s", s1);
    scanf("%s", s2);

    remove_str(s1, s2, res);
    printf("%s", res);
    return 0;
}
