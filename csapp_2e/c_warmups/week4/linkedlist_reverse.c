#include <stdio.h>
#include <stdlib.h>
//Define the structure of list and node
typedef struct link_node {
    int value;
    struct link_node * next;
    struct link_node * previous;
} ListNode;

typedef struct List {
    int count;
    ListNode *head;
    ListNode *tail;
} List;

void print_node(ListNode* node);
void add_node(List* pList, int number);
void print_list(List* plist);

int main(int argc, char const argv[]){
    //read the input num until -1
    List input_list;
    input_list.head = input_list.tail = NULL;
    int number;
    do{
        scanf("%d", &number);
        if(number != -1){
            add_node(&input_list, number);
        }
    } while (number != -1);

    print_list(&input_list);
    return 0;
}

void print_node(ListNode* node){
    if(node != NULL){
        if(node->next== NULL)
            printf("%d", node->value);
        else
            printf("%d ", node->value);
    }
}
void add_node(List* pList, int number){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
}

void print_list(List* plist){
}
