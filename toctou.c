/* vulnerable-program.c */

#include <stdio.h>
#include <unistd.h>
#include <string.h> 

/* for fixing vunerability */
#include <sys/types.h>

#define DELAY 50000

void delay() {
    for(int i = 0; i < DELAY;i++) i ^ 2;
}

int main(int argc, char * argv[])

{ 
    char * fileName = argv[1];

    char buffer[60];

    /* get user input */
    scanf("%50s", buffer );

    if(!access(fileName, W_OK)) {
        /*Simulating the Delay*/         
        delay();

        /* THIS IS THE FIX */
        /* Set the effective user id to the real user id value.*/
        // seteuid(getuid());

        FILE * fileHandler = fopen(fileName, "a+"); 
        
        fwrite("n", sizeof(char), 1, fileHandler);

        fwrite(buffer, sizeof(char), strlen(buffer), fileHandler); 
        
        fwrite("n", sizeof(char), 1, fileHandler); 
        
        fclose(fileHandler);

    } else {
        printf("No permission n");
    }
}
