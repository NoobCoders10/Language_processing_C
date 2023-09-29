#include <stdio.h>
#include <string.h>

int FINAL_STATE = 3;

int DFA[4][3] ={{1,0,0},{1,2,0},{-1,1,3},{3,3,3}};

int getNextState(int inputSymbol, int currentState){
    return DFA[currentState][inputSymbol];
}

int convertInputSymbol(char inputSymbol){
    int character = -1;
    if(inputSymbol =='a'){
        character = 0;
    }else if(inputSymbol == 'b'){
        character = 1;
    }else if(inputSymbol == 'c'){
        character = 2;
    }
    return character;
}

int validateInput(char input[] ){
    int firstCharacter = convertInputSymbol(input[0]);
    if(firstCharacter == -1){
        return 0;
    }
    printf("applying %c to state : %d => ",input[0],0);
    int nextState = getNextState(firstCharacter,0);
    if(nextState==-1){return 0;}
    int currentState = nextState;
    printf("Reached state : %d,input symbol : %c\n",currentState,input[0]);
    int i = 1;
    while (input[i] != '\0'){
        int inputSymbol  = convertInputSymbol(input[i]);
        if(inputSymbol == -1){return 0;}
        printf("applying %c to state : %d => ",input[i],currentState);
        nextState = getNextState(inputSymbol,currentState);
        if(nextState==-1){return 0;}
        currentState = nextState;
        printf("Reached state : %d,input symbol : %c\n",currentState,input[i]);
        i++;
    }
    printf("\n");
    if(currentState == FINAL_STATE){
        return 1;
    }
    return 0;
    
}


int main(){
    char input[40];
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