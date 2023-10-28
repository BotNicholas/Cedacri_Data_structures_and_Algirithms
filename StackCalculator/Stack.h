#include <iostream>

using namespace std;

struct Numbers{
    int data;
    Numbers *next;
};

struct Operators{
    char data;
    Operators *next;
};

Numbers *topNumber=NULL;
Operators *topOperator=NULL;

bool areNumbersEmpty();
bool areOperatorsEmpty();

void pushNumber(int val){
    Numbers *newNumbers = new Numbers;
    newNumbers->data=val;
    newNumbers->next=NULL;

    if(areNumbersEmpty())
    {
        topNumber = newNumbers;
    }
    else{
        newNumbers->next = topNumber;
        topNumber = newNumbers;
    }
}

Numbers *popNumber();
Operators *popOperator();


void pushOperator(char val){
    if(val!=')'){
        Operators *newOperator = new Operators;
        newOperator->data=val;
        newOperator->next=NULL;

        if(areOperatorsEmpty())
        {
            topOperator = newOperator;
        }
        else{
            newOperator->next = topOperator;
            topOperator = newOperator;
        }
    } else {
        Operators *operators = new Operators();
        while(operators->data!='('){
            operators = popOperator();
            if(operators->data!='('){
                Numbers *number1 = popNumber();
                Numbers *number2 = popNumber();
                Numbers result;

                switch(operators->data){
                    case '+':
                        result.data = number2->data + number1->data;
                        break;
                    case '-':
                        result.data = number2->data - number1->data;
                        break;
                    case '*':
                        result.data = number2->data * number1->data;
                        break;
                    case '/':
                        result.data = number2->data / number1->data;
                        break;
                }
                pushNumber(result.data);
            }

        }
    }

}

Numbers *popNumber(){
    if(!areNumbersEmpty()){
        Numbers *Numbers = topNumber;
        topNumber = topNumber->next;

        return Numbers;
    }
}


Operators *popOperator(){
    if(!areOperatorsEmpty()){
        Operators *operators = topOperator;
        topOperator = topOperator->next;

        return operators;
    }
}

Numbers peekNumber(){
    if(!areNumbersEmpty()){
        return *topNumber;
    }
}

Operators peekOperator(){
    if(!areOperatorsEmpty()){
        return *topOperator;
    }
}

bool areNumbersEmpty(){
    return topNumber == NULL;
}


bool areOperatorsEmpty(){
    return topOperator == NULL;
}

int compute(){
    int result;
    if(!areOperatorsEmpty() && !areNumbersEmpty()) {
        while(!areOperatorsEmpty()){
            Numbers *number1 = popNumber();
            Numbers *number2 = popNumber();
            Operators *operators = popOperator();
            Numbers result;

            switch(operators->data){
                case '+':
                    result.data = number2->data + number1->data;
                    break;
                case '-':
                    result.data = number2->data - number1->data;
                    break;
                case '*':
                    result.data = number2->data * number1->data;
                    break;
                case '/':
                    result.data = number2->data / number1->data;
                    break;
            }
            pushNumber(result.data);
        }

        return popNumber()->data;

    } else if(areOperatorsEmpty() && !areNumbersEmpty()) {
        return popNumber()->data;
    }
}