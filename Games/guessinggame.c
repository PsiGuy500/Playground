#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int SecretNumber = 5;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    int OutOfGuesses = 0;

    while(guess != SecretNumber)
    {
        if(guessCount < guessLimit)
        {
            printf("Enter a number: ");
            scanf("%d", &guess);
            guessCount++;
        }
        
        else
        {
            OutOfGuesses == 1;
        }
    }

    if(OutOfGuesses == 1)
    {
        printf("Out of guesses");
    }
    
    else
    {
        printf("Yow win!");
    }

}
