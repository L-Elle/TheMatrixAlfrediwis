#include <stdio.h>
#include <string.h>

void toLowerCase(char* myString){
    size_t n = strlen(myString);
    for(size_t i=0; i<n; i++){
        if(myString[i] >= 'A' && myString[i] <= 'Z'){
            myString[i] += 32;
        }
    }
}

void state_05(char* row){
    if(*row == 0){
        printf("\n\tIS CORRECT\n");
    }else if(*row == 'a' || *row == 'e' || *row == 'i' || *row == 'o'){
        printf("\n\tIS INVALID\n");
    }else{
        state_05(row + 1);
    }
}

void state_04(char* row){
    if(*row == 'u'){
        state_05(row + 1);
    }else if(*row == 0 || *row == 'a' || *row == 'e' || *row == 'i'){
        printf("\n\tIS INVALID\n");
    }else{
        state_04(row + 1);
    }
}

void state_03(char* row){
    if(*row == 'o'){
        state_04(row + 1);
    }else if(*row == 0 || *row == 'a' || *row == 'e' || *row == 'u'){
        printf("\n\tIS INVALID\n");
    }else{
        state_03(row + 1);
    }
}

void state_02(char* row){
    if(*row == 'i'){
        state_03(row + 1);
    }else if(*row == 0 || *row == 'a' || *row == 'o' || *row == 'u'){
        printf("\n\tIS INVALID\n");
    }else{
        state_02(row + 1);
    }
}

void state_01(char* row){
    if(*row == 'e'){
        state_02(row + 1);
    }else if(*row == 0 || *row == 'i' || *row == 'o' || *row == 'u'){
        printf("\n\tIS INVALID\n");
    }else{
        state_01(row + 1);
    }
}

void state_00(char* row){
    if(*row == 'a'){
        state_01(row + 1);
    }else if(*row == 0 || *row == 'e' || *row == 'i' || *row == 'o' || *row == 'u'){
        printf("\n\tIS INVALID\n");
    }else{
        state_00(row + 1);
    }
}

int main(){
    FILE* myText;
    char fileName[63] = "test.txt";
    myText = fopen(fileName, "r");

    char row[255];

    if(myText != NULL){
        while(fgets(row, sizeof(row), myText) != NULL){
            printf("\nThe string: %s",row);
            toLowerCase(row);
            state_00(row);
        }
    }else{
        printf("\n\tERROR: THE FILE DOES NOT EXIST\n");
    }
    
    fclose(myText);
    return 0;
}