#include <stdio.h>
#include <string.h>
#include <time.h>
#include "List.h"

int main() {
    printList();

    OperationDetails operationDetails;
    strcpy(operationDetails.codBanca, "123456");
    strcpy(operationDetails.codClient, "12345678901");
    strcpy(operationDetails.dataOperatiune, "12-3-2023");
    operationDetails.sumaOperatiune = 2.5;
    push(operationDetails);

//    printList();

    strcpy(operationDetails.codBanca, "654321");
    strcpy(operationDetails.codClient, "10987654321");
    strcpy(operationDetails.dataOperatiune, "21-4-2023");
    operationDetails.sumaOperatiune = 15.122;
    push(operationDetails);
    push(operationDetails);

    strcpy(operationDetails.codBanca, "111111");
    strcpy(operationDetails.codClient, "11111111111");
    strcpy(operationDetails.dataOperatiune, "11-1-2011");
    operationDetails.sumaOperatiune = 5.4321;
    push(operationDetails);

    printList();
//
//
//    pop();
//
//    printList();
//
//    push(operationDetails);


    printOperationsFor("10987654321");


    sortList();

    printList();


    return 0;
}
