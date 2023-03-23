#include <stdio.h>
#include <stdlib.h>

void display();
void insert(int);
void delete(int);


typedef struct node {
    int value;
    
    struct node *next;
    struct node *prev;
} node;

node* head = NULL;
node* tail = NULL;


/*
* DO NOT MODIFY THE MAIN FUNCTION
*/
int main() {
    
    int n, task;
    while (scanf("%d %d", &n, &task) == 2) {
        
        if (n == 0 && task == 0) {
            display();
            break;
        }
        else if (task == 1) {
            insert(n);
            display();
        }
        else if (task == -1) {
            delete(n);
            display();
        }
        else {
            continue;
        }
    }
    
    return 0;
}






/*
* This function inserts new value into the list.
*/
void insert(int value) {
    // TODO
    node *x = head;
    node *y = malloc(sizeof(node));
    y -> value = value;
    
    if(x == NULL || x -> value > value){
        y -> next = x;
        if(x != NULL){
            x -> prev = y;
        }
        else{
            tail = y;
        }
        head = y;
    }
    else{
        node *current = head -> next;
        node *prev = head;
        
        while(current && current -> value < value){
            prev = current;
            current = current -> next;
        }
        y -> next = prev -> next;
        y -> prev = prev;
        prev -> next = y;
        if(y -> next){
            y -> next -> prev = y;
        }
        if(prev == tail){
            tail = y;
        }
    }
}






/*
* This function deletes values from the list.
*/
void delete(int value) {
    // TODO
    node *x = head;
    int exist = 0;
    
    while(x){
        if(x -> value == value){
            exist = 1;
            node* y = x;

            if(y == head){
                head = y -> next;
                
                if(head != NULL){
                    head -> prev = NULL;
                } 
                else{
                    tail = NULL;
                }
            }
            else{
                y -> prev -> next = y -> next;

                if(y -> next != NULL){
                    y -> next -> prev = y -> prev;
                }
                else{
                    tail = y -> prev;
                }
            }
            x = y -> next;           
        } 
        else{
            x = x -> next;
        }
    }
    if(exist == 0){
        printf("Does not exist!\n");
    }  
}





/*
* This function displays all list elements.
*/
void display() {
    node* curr_node = head;
    printf("The list: ");
    while (curr_node) {
        printf("%d ", curr_node->value);
        curr_node = curr_node->next;
    }
    printf("\n");
}