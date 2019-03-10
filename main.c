#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findOp(int n);
int findTotal(int n, int* operators, int* operations);

int main(int argc, char* argv[])
{
    FILE* fp=fopen("result.txt","w");
    if(fp==NULL){
        fprintf(stderr, "Error: file failed to open.");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "1756136\n\n");
    if(argc!=2){
        printf("Invalid input");
        return 0;
    }
    int n= atoi(argv[1]);
    int operators[5], operations[4];
    for(int i=0; i<n; i++){
        operators[i]=rand()%101;
    }
    for(int i=0; i<n-1; i++){
        operations[i]=rand()%4;
    }
    for(int i=0; i<n; i++){
        printf("%d ",operators[i]);
        findOp(operations[i]);
    }
    int tot = findTotal(n, operators, operations);
    printf("tot is %d\n", tot);
    fprintf(fp, "%d\n", tot);
    fclose(fp);
    return 0;
}

int findTotal(int n, int* operators, int* operations){
    int tot=operators[0];
    for(int i=0; i<n; i++){
        if (operations[i]==0){
            tot= tot+ operators[i+1];
        }
        if (operations[i]==1){
            tot= tot- operators[i+1];
        }
        if (operations[i]==2){
            tot= tot* operators[i+1];
        }
        if (operations[i]==3){
            tot= tot/ operators[i+1];
        }

    }
    return tot;
}

void findOp(int n){
    if(n==0){
        printf("+ ");
    }
    if(n==1){
        printf("- ");
    }
    if(n==2){
        printf("* ");
    }
    if(n==3){
        printf("/ ");
    }
}

