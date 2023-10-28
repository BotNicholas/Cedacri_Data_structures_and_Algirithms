#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct OperationDetails{
    char codBanca[6];
    char codClient[11];
    char dataOperatiune[11];
    double sumaOperatiune;
} OperationDetails;

#define TYPE OperationDetails

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


void insertOn(int pos, TYPE val){
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

Node *peek(){
    if(!isEmpty()){
        Node *node = list;
        while(node->next!=NULL){
            node = node->next;
        }
        return node;
    }
}

Node *getFrom(int pos){
    if(!isEmpty() && count()>pos && pos >= 0){
        Node *temp = list;
        for(int i=0; i<pos; i++){
            temp = temp->next;
        }
        return temp;
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
        printf("\nlist{operation{%.*s, %.*s, %.*s, %.2f}", (int)sizeof(node->data.codBanca),
                                                                  node->data.codBanca,
                                                                  (int)sizeof(node->data.codClient),
                                                                  node->data.codClient,
                                                                  (int)sizeof(node->data.dataOperatiune),
                                                                  node->data.dataOperatiune,
                                                                  node->data.sumaOperatiune);
        node = list->next;
        while(node!=NULL){
            printf(", operation{%.*s, %.*s, %.*s, %.2f}", (int)sizeof(node->data.codBanca),
                   node->data.codBanca,
                   (int)sizeof(node->data.codClient),
                   node->data.codClient,
                   (int)sizeof(node->data.dataOperatiune),
                   node->data.dataOperatiune,
                   node->data.sumaOperatiune);
            node = node->next;
        }
        printf("}\n");
    } else {
        printf("List is empty!");
    }
}


bool verifyClientCodes(char clientCode1[11], char clientCode2[11], int size){
    bool equals=1;

    for (int i = 0; i < size; ++i) {
        if(clientCode1[i]!=clientCode2[i])
            equals = false;
    }

    return equals;
}

void printOperationsFor(char codClient[11]){
    if(!isEmpty()){
        Node *node = list;
        printf("\nlist for %.*s{", (int) sizeof(codClient),
                                          codClient);
        while(node!=NULL){
            if(verifyClientCodes(codClient, node->data.codClient, 11)) {
                printf("operation{%.*s, %.*s, %.*s, %.2f}  ", (int) sizeof(node->data.codBanca),
                       node->data.codBanca,
                       (int) sizeof(node->data.codClient),
                       node->data.codClient,
                       (int) sizeof(node->data.dataOperatiune),
                       node->data.dataOperatiune,
                       node->data.sumaOperatiune);
            }
            node = node->next;
        }
        printf("}\n");
    } else {
        printf("List is empty!");
    }
}


void sortList(){
    int listSize = count();
    for(int i=0; i<listSize-1; i++){
        for(int j=0; j<listSize-i-1; j++){
            Node *node = getFrom(j);
            Node *next = getFrom(j+1);
            if(node->data.sumaOperatiune < next->data.sumaOperatiune){
                TYPE temp = node->data;
                node->data = next->data;
                next->data = temp;
            }
        }
    }
}