//
//  main.c
//  Masters exercises
//
//  Created by Jamie Birch on 28/09/2015.
//  Copyright © 2015 Jamie Birch. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,b,c,i,buffer;
    buffer=0;
    for(i=0;i<1;i++){
//        a=0;
//        b=0;
//        c=0;
        printf("Input three numbers.\n");
        if (scanf("%d%d%d",&a,&b,&c)==3){ // will consume three integers from the input stream.
            printf("good job\n"); // non-integer inputs are left in the input stream in case another scanf() or getchar() wants to use it.
        } else {
            printf("a equals %d\n",a); // it sets them one-by-one, clearing each successful integer, plus any whitespace delimiting it, out of the input stream until it sees a non-digit.
            printf("b equals %d\n",b); // if this is a non-integer, b will remain zero and any further integers like c won't be read in at all (and thus shall remain zero too).
            printf("c equals %d\n",c);
            printf("try again. Please read the current buffer input and enter EOF.\n");
            while ((buffer = getchar()) != EOF ){ //keep reading characters one-at-a-time from the buffer and print them out on the same line.
                printf("%c",buffer);
            }

            fseek(stdin,0,SEEK_END); //seek to the end of the input buffer
            i--; // Return to start of for(). a,b,c will retain whatever values they got up to this point, but can be overwritten if alternative inputs are offered this time round.
        }
    }
    return 0;
}
