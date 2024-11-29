#include "p6c.h"

int min1(int num1, int num2){
    if(num1<num2){
        return num1;
    }
    else{return num2;}
}

int min2(int num1,int num2,int *min){
    if(num1<num2){
        *min=num1;
    }else{
        *min=num2;
    }
}