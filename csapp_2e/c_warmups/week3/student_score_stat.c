#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STU_NUM 10
#define COURSE_NUM 3

/***************************the required section**********************************/
typedef struct {
    char name[20];
    int score[3];
} Student;
 
//输入一个学生的数据
Student* student_input(Student *pStudent);
//输出一个学生的数据，包括平均成绩
void student_print(const Student *pStudent);
//计算一个学生的平均成绩
double student_average(const Student *pStudent);    
//获得学生的一个成绩
int student_get_score(const Student *pStudent, int index);
/***************************util function******************************************/
int isScoreValid(int score){
    return score >= 1 && score <= 5;
}

/***************************functions implementation*******************************/
Student* student_input(Student *pStudent){
    int input_score;
    int course_iter;
    printf("Input the student name: ");
    scanf("%s", pStudent->name);
    for(course_iter = 0; course_iter < COURSE_NUM; course_iter++){
        printf("Input the score for course %d: ", course_iter + 1);
        scanf("%d", &input_score);
        if (isScoreValid(input_score)) {
            pStudent->score[course_iter] = input_score;
        }else{
            printf("invalid score range, should be between 1 to 5\n");
            exit(1);
        }
    }
    return pStudent;
}

void student_print(const Student *pStudent){
    double student_avg = student_average(pStudent);
    int score_iter;
    printf("%s\t", pStudent->name);
    for(score_iter = 0; score_iter < 3; score_iter++){
        printf("%d\t", student_get_score(pStudent, score_iter));
    }
    // print format tuning
    printf("%7.5f\n", student_avg);

    return; 
}

double student_average(const Student *pStudent){
    double sum;
    double avg;
    sum = 0.0;
    int score_iter;
    for(score_iter = 0; score_iter < 3; score_iter++){
        sum += student_get_score(pStudent, score_iter);
    }
    avg = sum / 3.0;
    return avg;
}

int student_get_score(const Student *pStudent, int index){
    return pStudent->score[index];
}

int main(int argc, const char argv[]){

    Student students[STU_NUM];
    int student_iter;

    int course1_min = 100;
    int course1_max = 0;
    int course1_sum = 0;

    int course2_min = 100;
    int course2_max = 0;
    int course2_sum = 0;

    int course3_min = 100;
    int course3_max = 0;
    int course3_sum = 0;

    int curr_student_course1;
    int curr_student_course2;
    int curr_student_course3;
    //read the input  of the students
    for(student_iter = 0; student_iter <  STU_NUM; student_iter++){
        student_input(&(students[student_iter])) ; 
    }

    //print out the result
    printf("no\tname\tscore1\tscore2\tscore3\taverage\n");
    for(student_iter = 0; student_iter <  STU_NUM; student_iter++){
        printf("%d\t", student_iter);
        curr_student_course1 = student_get_score(&students[student_iter], 0); 
        curr_student_course2 = student_get_score(&students[student_iter], 1); 
        curr_student_course3 = student_get_score(&students[student_iter], 2); 

        course1_sum += curr_student_course1;
        course1_max = curr_student_course1 > course1_max? curr_student_course1 : course1_max;
        course1_min = curr_student_course1 < course1_min? curr_student_course1 : course1_min;
 
        course2_sum += curr_student_course2;
        course2_max = curr_student_course2 > course2_max? curr_student_course2 : course2_max;
        course2_min = curr_student_course2 < course2_min? curr_student_course2 : course2_min;
 
        course3_sum += curr_student_course3;
        course3_max = curr_student_course3 > course3_max? curr_student_course3 : course3_max;
        course3_min = curr_student_course3 < course3_min? curr_student_course3 : course3_min;
        student_print(&students[student_iter]);
    }
    printf("average\t%3.1f\t%3.1f\t%3.1f\n", course1_sum / (STU_NUM * 1.0), course2_sum / (STU_NUM * 1.0), course3_sum / (STU_NUM * 1.0));
    printf("min\t%d\t%d\t%d\n", course1_min, course2_min, course3_min);
    printf("max\t%d\t%d\t%d\n", course1_max, course2_max, course3_max);
    return 0;
}
