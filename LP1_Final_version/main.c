#include <stdio.h>
#include <math.h>

void Task1(){
    printf("\nTask 1.1 (Even numbers from 1 to 100):\n");
    for(int i=1; i<=100; i++){
        if(i%2==0)
            printf("\t%d\n", i);
    }

    printf("\nTask 1.2 (Odd numbers from 1 to 100):\n");
    int i=1;
    while(i<=100){
        if(i%2!=0)
            printf("\t%d\n", i);
        i++;
    }
}


//Using Recursion
int factorial(int n){
    if(n==0 || n==1)
        return 1;

    return n * factorial(n-1);
}


int perimeter(int a, int b, int c){
    return a+b+c;
}



void Task3(){
    printf("\nTask 3.1:\n");
    int arr_size=5;
    int arr[arr_size];

    for(int i=0; i<arr_size; i++){
        printf("i[%d]=", i);
        scanf("%d", &arr[i]);
    }

// arr - указатель на первый элемент массива
// *arr - значение этого указателя - (адрес первого значения)
// &arr - адрес самого arr (то есть указателя)

    int max=0;
    for(int i=1; i<arr_size; i++){
        if(arr[i]>arr[max])
            max=i;
    }

    printf("Max value index=%d and value=%d", max, arr[max]);
}

int Task4(char *str){
    char vowels[] ={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int counter=0;

    for(int i=0; i<sizeof(str); i++){
        for(int j=0; j<sizeof(vowels); j++){
            if(str[i]==vowels[j]){
                counter++;
            }
        }
    }
    return counter;
}




//ADVANCED TASKS

void sort(int *arr, int arrSize){
    //bubble sort
    for(int i=0; i<arrSize-1; i++){
        for(int j=0; j<arrSize-i-1; j++){
            if(arr[j]>arr[j+1]){
                int a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=a;
            }
        }
    }
}

void AdvancedTask1(){
    int arrSize=5;
    int arr[arrSize];
    printf("Enter array's numbers:\n");
    for(int i=0; i<arrSize; i++){
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]); //arr[i] - returns i's value, but we need its address => we use & operator
    }

    printf("\nArray before sorting: \n");
    for(int i=0; i<arrSize; i++){
        printf("arr[%d]=%d\n", i, arr[i]);
    }

    sort(arr, arrSize);

    printf("\nArray after sorting: \n");
    for(int i=0; i<arrSize; i++){
        printf("arr[%d]=%d\n", i, arr[i]);
    }
}

void AdvancedTask2(char *str, int length){
    for(int i=0; i<length/2; i++){
        char a = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = a;
    }
}

void addToEnd(int *arr, int *size){

    int n;
    printf("Enter new number: ");
    scanf("%d", &n);

    arr[*size]=n;
    *size=*size+1;
}

void addToTop(int *arr, int *size){
    int n;
    printf("Enter new number: ");
    scanf("%d", &n);

    for(int i=*size; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0]=n;
    *size=*size+1;
}

void AdvancedTask3(){
    int arrSize=5;
    int arr[100];

    printf("Enter 5 numbers: \n");
    for (int i = 0; i < arrSize; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }

    printf("\n\nEntered array: \n");
    for (int i = 0; i < arrSize; i++) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }


    addToEnd(arr, &arrSize);


    printf("\n\nEdited array: \n");
    for (int i = 0; i < arrSize; i++) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }

    addToTop(arr, &arrSize);

    printf("\n\nEdited array: \n");
    for (int i = 0; i < arrSize; i++) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }



}


int main() {

    Task1();

    int n;

    printf("\n\nTask 2:\n");
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial for %d = %d", n, factorial(n));


    int a, b, c;

    printf("\n\nEnter A side: ");
    scanf("%d", &a);
    printf("Enter B side: ");
    scanf("%d", &b);
    printf("Enter C side: ");
    scanf("%d", &c);

    printf("Perimeter = %d", perimeter(a, b, c));


    printf("\n\n");
    Task3();
    printf("\n\n");

    char str[] = {'H', 'e', 'l', 'l', 'o', '!'};
    printf("\nString \"%s\" has %d vowels!\n", str, Task4(str));

    printf("\n\nADVANCED TASKS:\n\n");



    //Array sort
    AdvancedTask1();

    //Reverse string
    printf("\n\nStr before inversion: %s\n", str);
    AdvancedTask2(str, (sizeof(str)/sizeof(str[0])));
    printf("Str after inversion: %s\n\n", str);

    //Array operations
    AdvancedTask3();
    return 0;
}
