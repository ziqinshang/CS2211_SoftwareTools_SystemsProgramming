// CS2211a 2020
// Assignment number 2
// Ziqin Shang
// 250890594
// zshang3
// Oct6,2020
#include <stdio.h>
float K2M(char x){//km to mi
    float input;
    float result=0;
    if (x=='K'){
        printf("conversion from Kilometer to Mile\n");
        scanf("%f",&input);
        result=input*0.621371;
        printf("result = %f\n", result);
    }
    if (x=='M'){
        printf("conversion from Mile to Kilometer\n");
        scanf("%f",&input);
        result=input*1.60934;
        printf("result = %f\n", result);
    }
    return result;
}
float L2G(char x){//liter to gallon
    float input;
    float result=0;
    if (x=='L'){
        printf("conversion from Litre to Gallon\n");
        scanf("%f",&input);
        result=input*0.264172;
        printf("result = %f\n", result);
    }
    if (x=='G'){
        printf("conversion from Gallon to Litre\n");
        scanf("%f",&input);
        result=input*3.78541;
        printf("result = %f\n", result);
    }
    return result;
}
float C2I(char x){//centimeter to inch
    float input;
    float result=0;
    if (x=='C'){
        printf("conversion from Centimetre to Inch\n");
        scanf("%f",&input);
        result=input*0.393701;
        printf("result = %f\n", result);
    }
    if (x=='I'){
        printf("conversion from Inch to Centimetre\n");
        scanf("%f",&input);
        result=input*2.54;
        printf("result = %f\n", result);
    }
    return result;
}
float C2F(char x){//Celsius to Fahrenheit
    float input;
    float result=0;
    if (x=='C'){
        printf("conversion from Celsius to Fahrenheit\n");
        scanf("%f",&input);
        result=(input*1.8)+32;
        printf("result = %f\n", result);
    }
    if (x=='F'){
        printf("conversion from Fahrenheit to Celsius\n");
        scanf("%f",&input);
        result=(input-32)/1.8;
        printf("result = %f\n", result);
    }
    return result;
}
int main() {
    char inputvalue;
    char option;
    //char newlinebuffer;
    while(1){
    printf("Please enter the character\n1 for conversion between Kilometer and Mile\n");
    printf("2 for conversion between Litre and Gallon\n3 for conversion between Centimetre and Inch\n");
    printf("4 for conversion between Celsius and Fahrenheit\n5 for quit\n");
    //if(inputvalue=='\n') inputvalue='\0';
    scanf(" %c",&inputvalue);
    //scanf(" %c",&newlinebuffer);
    printf("You entered %c.", inputvalue);
        if(inputvalue=='1'){
         printf("Please enter the character\n K for K2M\n M for M2K\n");
            scanf(" %c",&option);
            K2M(option);
        }
        else if (inputvalue=='2'){
            printf("Please enter the character\n L for L2G\n G for G2L\n");
            scanf(" %c",&option);
            L2G(option);
        }
        else if (inputvalue=='3'){
            printf("Please enter the character\n C for C2I\n I for I2C\n");
            scanf(" %c",&option);
            C2I(option);
        }
        else if (inputvalue=='4'){
            printf("Please enter the character\n C for C2F\n F for F2C\n");
            scanf(" %c",&option);
            C2F(option);
        }
        else if (inputvalue=='5')return 0;
    }
            return 0;
    }

