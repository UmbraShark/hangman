#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char *makeMan(int lives);

int main() {
    srand(time(NULL));
    char guessWord[][16] = {
                         "green",
                         "red",
                         "yellow",
                         "gray",
                         "black"
    };
    int randomIndex = rand() % 6;
    int numOfLives = 10;
    int numCorrect = 0;
    int oldCorrect = 0;
    int lenghtOfWord = strlen(guessWord[randomIndex]);

    int letterGuessed[6] = {0,0,0,0,0,0};
    int quit = 0;
    char guess[16];
    char letterEntred;
    int loopIndex = 0;
    //printf("guessWord -> %s\n",guessWord[randomIndex]);
   // printf("randomIndex -> %d\n",randomIndex);
    printf("Number of letters -> %d\n",lenghtOfWord);

    while (numCorrect < lenghtOfWord) {
        printf("Number of correct letter -> %d\n", numCorrect);
        for(int i = 0;i<lenghtOfWord;i++){
            if(letterGuessed[i] == 1){
                printf(" %c",guessWord[randomIndex][i]);}
            if(letterGuessed[i] == 0){
                printf(" _");
            }
        }
        printf("\nEnter you guess letter:");
        fgets(guess, 16, stdin);
        if (strncmp(guess, "quit", 4) == 0) {
            quit = 1;
            break;
        }

        letterEntred = guess[0];
        oldCorrect = numCorrect;
        for (loopIndex = 0; loopIndex < lenghtOfWord; loopIndex++) {

            if (letterEntred == guessWord[randomIndex][loopIndex] && letterGuessed[loopIndex] != 1) {
                letterGuessed[loopIndex] = 1;
                numCorrect++;


                if(numCorrect == lenghtOfWord){
                    printf("\nBravo,the Word guessed -> %s\n",guessWord[randomIndex]);
                    break;
                }
            }


        }

        if (oldCorrect == numCorrect){
            numOfLives--;
            if(numOfLives == 0) {
                printf("\nYou LOST...\n");
                printf("%s", makeMan(numOfLives));
                break;
            }else{
                printf("\nSorry wrong guess :( You still have %d lives\n", numOfLives);
                printf("%s", makeMan(numOfLives));
            }
        } else{
            printf("\nCorrect guest :)\n");
        }
    }
    if(quit == 1)
        printf("\nThe user quit early\n");

    return 0;
}

char *makeMan(int lives) {
    switch ( lives )
    {
        case 0:return "     ==========\n   //          |\n   ||          |\n   ||         (X)\n   ||        / | \\          *DEAD!!\n   ||          |\n   /\\         / \\\n  //\\\\\n ///\\\\\\\n";
        case 1:return "     ==========\n   //          |\n   ||          |\n   ||         ( )\n   ||        / | \\\n   ||          |\n   /\\         /\n  //\\\\\n ///\\\\\\\n";
        case 2:return "     ==========\n   //          |\n   ||          |\n   ||         ( )\n   ||        / | \\\n   ||          |\n   /\\          \n  //\\\\\n ///\\\\\\\n";
        case 3:return "     ==========\n   //          |\n   ||          |\n   ||         ( )\n   ||         /|\n   ||          |\n   /\\\n  //\\\\\n ///\\\\\\\n";
        case 4:return "     ==========\n   //          |\n   ||          |\n   ||         ( )\n   ||          |\n   ||          |\n   /\\\n  //\\\\\n ///\\\\\\\n";
        case 5:return "     ==========\n   //          |\n   ||          |\n   ||         ( )\n   ||          |\n   ||\n   /\\\n  //\\\\\n ///\\\\\\\n";
        case 6:return "     ==========\n   //          |\n   ||          |\n   ||         ( )\n   ||\n   ||\n   /\\\n  //\\\\\n ///\\\\\\\n";
        case 7:return "     ==========\n   //          |\n   ||          |\n   ||\n   ||\n   ||\n   /\\\n  //\\\\\n ///\\\\\\\n";
        case 8:return "     ==========\n   //\n   ||\n   ||\n   ||\n   ||\n   /\\\n  //\\\\\n ///\\\\\\\n";
        case 9:return "\n\n\n   //\n   ||\n   ||\n   ||\n   ||\n   /\\\n  //\\\\\n ///\\\\\\\n";


    }
}
