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

void print_node(ListNode* node, int reverse_mode);
void add_node(List* pList, int number);
void print_list(List* plist);
void print_list_reverse(List* plist);

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
    print_list_reverse(&input_list);
    return 0;
}

void print_node(ListNode* node, int reverse_mode){
    if(!reverse_mode){
        if(node != NULL){
            if(node->next == NULL)
                printf("%d\n", node->value);
            else
                printf("%d ", node->value);
        }
    }else{
        if(node != NULL){
            if(node->previous == NULL)
                printf("%d\n", node->value);
            else
                printf("%d ", node->value);
        }

    }
}
void add_node(List* pList, int number){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->value = number;
    node->previous = NULL;
    node->next = NULL;

    // Check for the head node
    if(pList->head == NULL){
        pList->head = node; 
    }

    // Append the node the tail of the list 
    if(pList->tail){
        node->previous = pList->tail;
        (pList->tail)->next = node;
    }
    pList->tail = node;
}

void print_list(List* plist){
    //node print not in reverse mode
    int reverse_mode = 0;
    if(plist && plist->head){
        ListNode* p;
        for(p = plist->head; p; p = p->next){
            print_node(p, reverse_mode);
        }
    }
}

void print_list_reverse(List* plist){
    //node print not in reverse mode
    int reverse_mode = 1;
    if(plist && plist->tail){
        ListNode* p;
        for(p = plist->tail; p; p = p->previous){
            print_node(p, reverse_mode);
        }
    }
}
