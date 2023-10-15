#include <stdio.h>
#include <malloc.h>
#include <limits.h>

//Variant V
void task1(int *arr, int size){
    for(int i=0; i<size; i++){
        if(arr[i]%2==0){
            printf("\t%d\n", arr[i]);
        } else {
            printf("%d\n", arr[i]);
        }
    }
}

int task2(int *arr, int size){
    int sum=0;
    for(int i=0; i<size; i++){
        if(arr[i]>=-2 && arr[i]<=4){
            sum+=arr[i];
        }
    }
    return sum;
}

void task3(int **arr, int *size){
    int n;
    printf("\n\nEnter new number: ");
    scanf("%d", &n);

    int l;
    printf("Enter location: ");
    scanf("%d", &l);

    if(l<*size+1) {
        int *copy = malloc((*size + 1) * sizeof(int));
        for (int i = 0; i < *size; i++) {
            if (i < l) {
                copy[i] = (*arr)[i];
            }
            if (i == l) {
                copy[i] = n;
                copy[i + 1] = (*arr)[i];
            }
            if (i > l) {
                copy[i + 1] = (*arr)[i];
            }
        }
        *arr = copy;
        *size = *size + 1;
    }
}

void task4(int *arr, int size){
    int min=INT_MAX;
    int c=1;
    int sum=0;
    int *temp = malloc(100*sizeof(int));
    int *minArr;
    int n;
    for(int i=0; i<size; i++){

            if(arr[i]<arr[i+1] && (i+1)<size){
            sum+=arr[i];
            temp[c-1] = arr[i];
            c++;
        }
        if(arr[i]>arr[i+1] || (i+1)>=size){
            if(c>1){
                sum+=arr[i];
                temp[c-1] = arr[i];
                if(min>sum) {
                    min = sum;
                    minArr= malloc(c*sizeof(int));
                    for(int j=0; j<c; j++)
                        minArr[j]=temp[j];
                    n=c;
                }
                c=1;
                sum=0;
            }
        }

    }

    printf("subarray:\n");

    for(int i=0; i<n; i++){
        printf("%d ", minArr[i]);
    }

    printf("\navg = %.2f", (min*1.0)/n);
}



void task5v1(int **arr, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(j<m-i-1){
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}


void task5v2(int **arr, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i+j+1)<m){
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int size=9;
    int *arr = malloc(size*sizeof(int));
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    arr[3]=3;
    arr[4]=4;
    arr[5]=5;
    arr[6]=6;
    arr[7]=6;
    arr[8]=7;

    task1(arr, size);


    size = 10;
    free(arr);
    arr = malloc(size*sizeof(int));
    arr[0]=2;
    arr[1]=-1;
    arr[2]=6;
    arr[3]=4;
    arr[4]=-3;
    arr[5]=7;
    arr[6]=-2;
    arr[7]=0;
    arr[8]=9;
    arr[9]=2;

    printf("\n\nSum = %d", task2(arr, size));


    free(arr);

    size=8;
    arr = malloc(size*sizeof(int));
    arr[0]=54;
    arr[1]=2;
    arr[2]=6;
    arr[3]=7;
    arr[4]=8;
    arr[5]=65;
    arr[6]=21;
    arr[7]=91;

    task3(&arr, &size);

    printf("\n\n");
    for(int i=0; i<size; i++){
        printf("i[%d]=%d\n", i, arr[i]);
    }

    free(arr);

    size=9;
    arr= malloc(size*sizeof(int));
    arr[0]=3;
    arr[1]=1;
    arr[2]=4;
    arr[3]=5;
    arr[4]=6;
    arr[5]=7;
    arr[6]=1;
    arr[7]=2;
//    arr[8]=1;
    arr[8]=3;

    printf("\n\n");
    task4(arr, size);

    free(arr);


    printf("\n\n");

    int n=3;
    int m=3;

    int **matr = malloc(n*sizeof(int*));

    for(int i=0; i<n; i++)
        matr[i]= malloc(m*sizeof(int));

    matr[0][0] = 1;
    matr[0][1] = 2;
    matr[0][2] = 3;
    matr[1][0] = 4;
    matr[1][1] = 5;
    matr[1][2] = 6;
    matr[2][0] = 7;
    matr[2][1] = 8;
    matr[2][2] = 9;


    //    for(int i=0; i<n; i++) {
    //        for (int j = 0; j < m; j++)
    //            printf("%d ", matr[i][j]);
    //        printf("\n");
    //    }


    printf("\n1'st way:\n");
    task5v1(matr, n, m);
    printf("\n2'nd way:\n");
    task5v2(matr, n, m);


    for(int i=0; i<n; i++){
        free(matr[i]);
    }

    free(matr);

    return 0;
}
