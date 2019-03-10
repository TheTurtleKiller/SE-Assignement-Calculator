#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findOp(int n);     //function to determine operations when printing on screen
int findTotal(int n, int* operators, int* operations);  //function that computes the total

int main(int argc, char* argv[])
{
    srand(time(NULL));      //initializing rand function
    FILE* fp=fopen("result.txt","w");
    //opening file
    if(fp==NULL){
        fprintf(stderr, "Error: file failed to open.");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "1756136\n\n");     //printing student id
    if(argc!=2){
        printf("Invalid input");        //making sure the input is in the correct form
        return 0;
    }
    int n= atoi(argv[1]);       //n is the input from the user
    int operators[5], operations[4];
    for(int i=0; i<n; i++){
        operators[i]=rand()%101;        //generating random numbers n times
    }
    for(int i=0; i<n-1; i++){
        operations[i]=rand()%4;         //generating n-1 operations
    }
    for(int i=0; i<n; i++){
        printf("%d ",operators[i]);     //printing on screen and on file the operations
        fprintf(fp, "%d ",operators[i]);
        if(i!=n){
            if(operations[i]==0){
                fprintf(fp, "+ ");
                }
            if(operations[i]==1){
                fprintf(fp, "- ");
                }
            if(operations[i]==2){
                fprintf(fp, "* ");
                }
            if(operations[i]==3){
                fprintf(fp, "/ ");
            }
        }
            fprintf(fp, " ",operations[i-1]);
        findOp(operations[i]);
    }
    int tot = findTotal(n, operators, operations);      //computing total
    printf("tot is %d\n", tot);
    fprintf(fp, "%d\n", tot);
    fclose(fp);
    return 0;
}

//to determine operations we generate a number between 0 and 3 and assign an operation to each value
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

