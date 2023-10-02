/**
 * DFA accepting binay string ending with 00
*/

#include <stdio.h>
#include <string.h>

int FINAL_STATE = 2;

int DFA[3][2] ={{1,0},{2,0},{2,0}};

int getNextState(int inputSymbol, int currentState){
    return DFA[currentState][inputSymbol];
}

int convertInputSymbol(char inputSymbol){
    int symbol = -1;
    if(inputSymbol == '0'){
        symbol = 0;
    }else if(inputSymbol == '1'){
        symbol = 1;
    }
    return symbol;
}

int validateInput(char input[] ){
    int firstInputCharacter = convertInputSymbol(input[0]);
    if(firstInputCharacter == -1){return 0;}
    int nextState = getNextState(firstInputCharacter,0);
    if(nextState==-1){return 0;}
    int currentState = nextState;
    int i = 1;
    while (input[i] != '\0'){
        int inputSymbol = convertInputSymbol(input[i]);
        if(firstInputCharacter == -1){return 0;}
        nextState = getNextState(inputSymbol,currentState);
        if(nextState==-1){return 0;}
        currentState = nextState;
        i++;
    }
    if(currentState == FINAL_STATE){
        return 1;
    }
    return 0;
    
}


int main(){
    char input[20];
    printf("Enter the input string : ");
    scanf("%s",input);
    int result = validateInput(input);
    if(result == 1){
        printf("String is valid\n");
    }else{
        printf("String is not valid\n");
    }
    return 0;
}