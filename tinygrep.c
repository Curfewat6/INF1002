#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

int compare(char *string, char *pattern, int sense);
// const char* result(int index);

int compare(char *string, char *pattern, int sense){
    int string_length, pattern_length;
    char working_string[256];
    strcpy(working_string, string);
    pattern_length = strlen(pattern);
    string_length = strlen(string);
   // printf("PATTERN LENGTH:     %d\n",pattern_length);

    if(sense){
    // Lower case everything
    for(int i = 0; working_string[i]; i++){
        
        working_string[i] = tolower(working_string[i]);
    }
    for(int k = 0; pattern[k]; k++){
        
        pattern[k] = tolower(pattern[k]);
    }

    }
    for(int pointer_one = 0; pointer_one <= string_length - pattern_length; pointer_one++){
        int pointer_two = 0;
        int pointer_three = 0;
       //printf("POINTER2 VALUE BEFORE INNER LOOP:     %d\n\n", pointer_two);
        //printf("Now running through character:  %c\n", working_string[pointer_one]);
        if (working_string[pointer_one] == pattern[pointer_two] || pattern[pointer_two] == '.' || pattern[pointer_two] == '_'){
            
            pointer_three = pointer_one + 1;
            pointer_two++;
          //  printf("\n%c matched the first character with the pattern:    %c\n",working_string[pointer_one],pattern[pointer_one] );
            while(pointer_two < pattern_length && (working_string[pointer_three] == pattern[pointer_two] || pattern[pointer_two] == '.' || pattern[pointer_two] == '_')){
                if (pattern[pointer_two] == '.'){
                   // printf("im lost boss");
                    pointer_two++;
                    continue;
                } else if (pattern[pointer_two] == '_' && working_string[pointer_three] == ' ' ){
                    printf("indeed!\n");
                    pointer_two++;
                    continue;
                }
              //  printf("This is pointer2:   %d", pointer_two);
                pointer_three++;
                pointer_two++;
            }
          //  printf("POINTER2 VALUE AFTER INNER LOOP:     %d\n\n", pointer_two);
            if(pointer_two == pattern_length){
                //printf("match from position:    %d\n", pointer_one);
                return pointer_one;
            }
        }
    }   return -1;
}

int main(){
    char input[256];
    char pattern[256];
    short c_sens;
    printf("Enter a line of text:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Enter a pattern:\n");
    fgets(pattern, sizeof(pattern), stdin); 

    pattern[strcspn(pattern, "\n")] = '\0';
    printf("Is this pattern case sensitive (Y/N):\n");
    scanf(" %c",&c_sens); 
    if(c_sens == 'Y'|| c_sens=='y'){
        c_sens = 0;
    }
    else if (c_sens == 'N' || c_sens == 'N')
    {
        c_sens = 1;
    }
    
    int index = compare(input, pattern, c_sens);
    // char match[] = result(index);
    // printf("%s", match);
    if(index < 0){
        printf("No match");
    } else{
        printf("Matches at position %d", index);
    }
    return 0;
}