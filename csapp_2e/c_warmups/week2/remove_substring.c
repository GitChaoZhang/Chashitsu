#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LMT 80

void remove_str(char *s1, char *s2, char * res){
    int res_count = 0;
    int step_fwd;
    char * s1_head;
    char * const s2_head = s2;
    while(*s1){
        s1_head = s1;
        s2 = s2_head;
        //assume at least one step would be moved forward each time
        step_fwd = 1;
        while(*s1 == *s2){
            s1++;
            s2++;
            step_fwd++;
        }
        if(step_fwd == 1){
            s1++;
            s2++;
        }
        //if s2_iter is not at its ending position
        if( (strlen(s2_head) == 1 && step_fwd == 1) 
            || (strlen(s2_head) > 1 && *s2 != '\0') ){
            int i;
            for(i = 0; i < step_fwd; i++)
                *res++ = *s1_head++; 
        }
    }
    *res = '\0';
}

int main(int argc, const char *argv[]){
    char s1[STRING_LMT];
    char s2[STRING_LMT];
    char res[STRING_LMT];
    scanf("%s", s1);
    scanf("%s", s2);
    remove_str(s1, s2, res);
    printf("%s\n", res);
    return 0;
}
