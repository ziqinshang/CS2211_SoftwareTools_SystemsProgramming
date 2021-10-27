/* CS2211a 2020 */
/* Assignment 03 */
/* ziqin shang */
/* 250890594 */
/* zshang3 */
/* OCT 19 2020*/
#include <stdio.h>
//this program adds all prime numbers that is before the input numbers
int main()
{
int totalvalue,primechecker,input,verifier;
while(1)
    {
        totalvalue=0;
        printf("Input? ");
        scanf("%d",&input);
        //program exit, no positive integers are before zero
            if (input==0) break;
            //for all integers before the input number
            for (int index=1;index<=input;index++)
            {
                verifier = 0;
                //continuously iterate the prime checker to check it that is a prime number
                for (primechecker=2; primechecker <= index; primechecker++)//
                {
                        //if that number can be divided by itself, it is a prime number
                     if (index%primechecker==0) verifier++;
                }
                //add this prime number to the total value
                if (verifier==1) totalvalue=totalvalue+index;
            }
        printf("The final total is: %d\n",totalvalue);
    }
return 0;
}

