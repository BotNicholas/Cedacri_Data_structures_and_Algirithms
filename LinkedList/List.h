#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define TYPE int

typedef struct Node{
    TYPE data;
    struct Node *next;
}Node;

Node *list=NULL;

int count();
bool isEmpty();


void push(TYPE val){
    Node *newNode = malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;

    if(isEmpty())
    {
        list = newNode;
    }
    else{
        Node *node = list;
        while(node->next!=NULL){
            node = node->next;
        }
        node->next = newNode;
    }
}


Node pop(){
    if(!isEmpty()){
        Node *node = list;
        Node *last;

        if(node->next==NULL) { //if only one element's left
            last = list;
            list = NULL;
        } else {
            while (node->next->next != NULL) {
                node = node->next;
            }
            last = node->next;
            node->next = NULL;
        }
        return *last;
    }
}


void insertOn(int pos, int val){
    Node *newNode = malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;


    if(isEmpty() && pos==0){
        push(val);
    } else if(!isEmpty() && pos==0){
        newNode->next = list;
        list = newNode;
    } else if(!isEmpty() && count()>=pos && pos > 0){
        Node *temp = list;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}



Node removeOn(int pos){
    if(!isEmpty() && count()>pos && pos >= 0){
        Node *temp = list;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        Node *removed;
        if(pos==0){
            removed=list;
            list=list->next;
        } else {
            removed = temp->next;
            temp->next = temp->next->next;
        }
        return *removed;
    }
}

Node peek(){
    if(!isEmpty()){
        Node *node = list;
        while(node->next!=NULL){
            node = node->next;
        }
        return *node;
    }
}

Node getFrom(int pos){
    if(!isEmpty() && count()>pos && pos >= 0){
        Node *temp = list;
        for(int i=0; i<pos; i++){
            temp = temp->next;
        }
        return *temp;
    }
}


int count(){
    int c=0;
    if(!isEmpty()) {
        Node *node = list;
        while(node!=NULL){
            c++;
            node = node->next;
        }
    }
    return c;
}

bool isEmpty(){
    return list == NULL;
}

void updateOn(int pos, TYPE data){
    if(!isEmpty() && count()>pos && pos >= 0){
        Node *temp = list;
        for(int i=0; i<pos; i++){
            temp = temp->next;
        }
        temp->data = data;
    }
}

void printList(){
    if(!isEmpty()){
        Node *node = list;
        printf("\nlist{%d", node->data);
        node = list->next;
        while(node!=NULL){
            printf(", %d", node->data);
            node = node->next;
        }
        printf("}\n");
    } else {
        printf("List is empty!");
    }
}
