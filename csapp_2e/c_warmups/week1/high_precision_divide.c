#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FLOAT_PRECISE 200
#define INPUT_LENGTH 10
#define NUM_LENGTH 5
#define DENOM_LENGTH 5
int checkRange(int num2Check){
    return  (num2Check >= 10) && (num2Check < 100);
}

int main (int argc, char *argv[]) {

    int numerator;
    char numer_str[NUM_LENGTH];
    int denomitor;
    char denom_str[DENOM_LENGTH];
    char input[INPUT_LENGTH];
    const char tok_mark[2] = "/";
    char *token;
    int res[FLOAT_PRECISE] = {0};
    int div_res;
    int resbit_counter = 0;
    int resbit_number;
    if (argc != 2) {
        printf("there should be only one argument with the formant a/b\n");
        return 1;
    }
    // The input format would be a/b, truncate the input now
    memset(input, '\0', sizeof(input));
    strcpy(input, argv[1]);
    token = strtok(input, tok_mark);
    strcpy(numer_str, token);
    numerator = atoi(numer_str);
    token = strtok(NULL, tok_mark);
    strcpy(denom_str, token);
    denomitor = atoi(denom_str);
    
    if (numerator < denomitor && checkRange(numerator) && checkRange(denomitor)) {
         //The array to store the result
         while (resbit_counter < FLOAT_PRECISE) {
             div_res = (numerator * 10) / denomitor;
             res[resbit_counter] = div_res;
             numerator = numerator * 10 - div_res * denomitor;
             if (div_res == 0 && numerator == 0) {
                 break;
             }else{
                 resbit_counter++;
             }
         }
         resbit_number = resbit_counter++;
         // print out the result based on array
         printf("0.");
         int i;
         for (i = 0 ;i < resbit_number ;i++) {
             printf("%d", res[i]);
         }
         printf("\n");
         return 0;
    }else{
        printf("invalid argumts\n");
        return 1;
    }
}
