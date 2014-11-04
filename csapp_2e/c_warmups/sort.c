#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define RAND_LIST_NUMBER_LIMIT 50
#define RAND_LIST_LENGTH_LIMIT 100

int generate_rands(){
    FILE *rand_nums ;
    rand_nums=fopen("rand_num_inputs", "w+");
    int rand_list_counter;
    for(rand_list_counter = 0; rand_list_counter < RAND_LIST_NUMBER_LIMIT; rand_list_counter++){
        fprintf(rand_nums, "line %d:", rand_list_counter);

        int rand_list_length =  rand() % RAND_LIST_LENGTH_LIMIT;
        int rand_num;
        for(rand_num = 0; rand_num < rand_list_length; rand_num ++){
           fprintf(rand_nums, " %d", rand()); 
        }
        fprintf(rand_nums, "\n\n");
    }
    fclose(rand_nums);
    return 0; 
}


int main(){
    generate_rands();
    quick_sort();
    return 0;
}
