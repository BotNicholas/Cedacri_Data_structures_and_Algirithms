#include <iostream>
#include <cstring>
#include "Stack.h"

using namespace std;

int main() {
    char str[100];
    cin >> str;
    char prev;

    for(int i=0; i<strlen(str); i++){
        if(isdigit(str[i])){
            if(prev!='n') {
                prev = 'n';
                pushNumber(str[i] - '0');
            } else {
                prev = 'n';
                pushNumber(popNumber()->data*10+(str[i] - '0'));
            }
        } else{
            prev='o';
            pushOperator(str[i]);
        }
    }

    printf("%d", compute());

    return 0;
}
