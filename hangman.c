#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LETTERS 12

int guessCount = 7;
char word[13];

char hangman[12] = "_";

void createHangman(){
    for(int i = 1; i < strlen(word); i++){
        strcat(hangman," _");
    }
}

int notWord(){
    for(int j = 0; word[j] != '\0'; j++){
        if (isalpha(word[j]) == 0)
            return 1;
    }
    return 0;
}

void player_1(){
    int error;
    do{
        error = 0;
        if(error){
            printf("Sorry, the word must be no more than 12 letters.\n");
        }
        if(notWord(word)){
            printf("Sorry, the word must contain only English letters.\n");
        }
        printf("Player 1, enter a word of no more than 12 letters:");
        scanf("%s", word);
        if(strlen(word) > MAX_LETTERS){
        error = 1;
        }
    } while(error || notWord(word));
    printf("%s\n", word);
}

int checkAnswer(char guessInput){

    for(int i = 0; word[i] != '\0'; i++){
                if(word[i] == guessInput){
            return i;
        }
    }
    return -1;
}

void updateHangman(int slot){
    hangman[slot] = word[slot/2];
}

int hangmanSolved(){
    for(int i = 0; i <= strlen(hangman); i++){
        if(hangman[i] == '_'){
            return 0;
        }
        if(i != strlen(hangman)){
            continue;
        }
    }
    return 1;
}

void player_2(){
    do{
        
    char guessInput;
        printf("Player 2 has so far guessed: %s\n", hangman);
        if (hangmanSolved()){
            printf("Player 2 wins.");
            break;
        }
        printf("Player 2, you have %d guesses remaining. Enter your next guess:\n", guessCount);
        scanf(" %c", &guessInput);
        int position =  checkAnswer(guessInput);
        if(position != -1){
            updateHangman(position*2);
        } else{
        guessCount--;
        }
        
        
    } while(guessCount != 0);
}

void lowerit(){
    for(int i = 0; word[i]; i++){
        word[i] = tolower(word[i]);
    }
}
int main(){
    player_1();
    lowerit();
    createHangman();
    player_2();
    return 0;
}