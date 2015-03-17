#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mainly check with string array, which actually is double char array
int main(int argc, const char *argv[]){
    int input;
    int read_num;
    int strength_num; 
    const char * readability[5] = {
        "unreadable",
        "barely readable, occasional words distinguishable",
        "readable with considerable difficulty",
        "readable with practically no difficulty",
        "perfectly readable"
    };
    const char * strength[9] = {
        "Faint signals, barely perceptible",
        "Very weak signals",
        "Weak signals",
        "Fair signals",
        "Fairly good signals",
        "Good signals",
        "Moderately strong signals",
        "Strong signals",
        "Extremely strong signals"
    };
    scanf("%d", &input);
    read_num = input / 10;
    strength_num = input - 10 * read_num;
    printf("%s, %s.\n", strength[strength_num -1], readability[read_num - 1]) ;
    return 0;
}
