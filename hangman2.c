#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int wordCount(char *word);
void win(int try, int wrongGuess);
void lose();
int main(){
    srand(time(NULL));
    int r = rand() % 10;
    char *wordList[10] = {"apple", "banana", "grape", "orange", "water", "earth", "key", "bottle", "bag", "watch"};
    char *randWord = wordList[r];
    char userGuess;
    char *userWord = randWord;
    int try = 6;
    int wrongGuess = 0;
    int wordLen = wordCount(randWord);
    strset(userWord, '_');
    printf("Welcome to the Hangman Game!\n");
    printf("You will get 6 chances to guess the right word\n");

    while(try != 0){
        printf("Give me the alphabet in lower case: \n");       
        printf("%c\n",userWord);
        printf("you have %d more chances.\n", try);
        userGuess = getchar();
        if(strstr(*randWord, userGuess) != NULL){
            for(int i = 0; i < wordLen; i++){
                if(randWord[i] == userGuess){
                    userWord[i] = userGuess;
                }
            }
            printf("%c\n", userWord);
            try--;
            printf("You tried %d times. You have %d more chances.\n", 7 - try, try);
        }else{
            printf("Wrong input. Please try again!\n");
            printf("%c\n", userWord);
            try--;
            wrongGuess++;
            printf("You tried %d times. You have %d more chances.\n",7 - try, try);
        }
    }
    if(randWord == userWord){
        win(try, wrongGuess);
    }else{
        printf("You Lose\n");

        char playAgain = 'y';
        while (playAgain == 'y' || playAgain == 'Y') {
            printf("Do you want to play again? (Y/N): ");
            scanf_s("%c", &playAgain);
            if (playAgain == 'y' || playAgain == "Y") {
                main();
                return 0;
            } else if (playAgain == 'n' || playAgain == 'N') {
                printf("Thank you for playing.\n");
                return 0;
            } else {
                printf("ERROR: Invalid input. Please try again.\n");
            }
        }
    }
}

int wordCount(char *word){
    int len = 0;
    while(word[len]){
        len++;
    }
    return len;
}
void win(int try, int wrongGuess){
    printf("The hang man survived!!\n");
    printf("Try: %d\n", 7 - try);
    printf("Wrong Guess: %d\n", wrongGuess);
}
