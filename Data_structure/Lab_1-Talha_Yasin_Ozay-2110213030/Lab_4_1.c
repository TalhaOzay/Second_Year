#include <stdio.h>
#include <stdlib.h>

struct numbers{
    int number;
    struct numbers *next;
};
typedef struct numbers node;
node *head,*current;

node* adding (node *head,int value);
void write (node *head);

int main(){
    int num;
    printf("Enter numbers to add the list ( Enter -1 for exit )\n");
    while (1){
        scanf("%d",&num);
        if (num == -1){
            break;    // Stop mechanism
        }
        head = adding(head,num);
        current = head;
    }
    write (head);
    return 0;
}

node* adding (node *head , int value){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->number = value;
    if (head == NULL){     // if it is first number we are being it first sturct
        head = newNode;
        newNode->next = NULL;
    }else if (value % 2 != 0){ // if the number is odd
        newNode->next = current;
        head = newNode;
    }else{   //For even number
        while (current->next != NULL){  
            current = current->next;  // Finding last node
        }
        current->next = newNode; // Adding ent of the list
        newNode->next = NULL;
    }
    return head;
}

void write (node *head){     // Classic printing function for linked list.
    int counter = 1;
    while (current != NULL){  // Printing all node
        printf("%d.- %d\n",counter,current->number);
        current = current->next;
        counter++;
    }
    current = head;
}