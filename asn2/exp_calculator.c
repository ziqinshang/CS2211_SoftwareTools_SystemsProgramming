// CS2211a 2020
// Assignment number 2
// Ziqin Shang
// 250890594
// zshang3
// Oct6,2020
#include <stdio.h>
#include <math.h>
float calculation(float base,int exponent){
    float result;
    if (exponent == 0) return 1;
    if (exponent%2 == 0){
        result = calculation(base, exponent/2);
        return result*result;
    }
    else return base*calculation(base, exponent-1);
//    if (exponent > 0){
//        if (exponent%2 == 0){
//            result = pow(pow(base, exponent/2),2);
//        }
//        else{
//            result = (pow(pow(base, (exponent-1)/2),2))*base;
//        }
//    }
//    else if (exponent < 0){
//        result = 1 / (pow(base, (exponent*-1)));
//    }
//    printf("result = %f\n", result);
//    return result;
}
int main(){
    float result;
    float base;
    int exponent;
        while(1){
    printf("enter the base");
    scanf(" %f",&base);
    printf("enter the exponent");
    scanf(" %d",&exponent);
    if(base==0) return 0;
    result = calculation(base, exponent);
    printf("result = %f\n", result);
    }
    
}
