#include "p6b.h"

int min2(int num1,int num2,int *min){
    if(num1<num2){
        *min=num1;
    }else{
        *min=num2;
    }
}