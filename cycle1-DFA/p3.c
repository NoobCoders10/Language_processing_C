#include <stdio.h>
#include <string.h>
#include <time.h>

int FINAL_STATE_1 = 0;
int FINAL_STATE_2 = 1;

int DFA[3][2] ={{1,0},{2,-1},{-1,0}};

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
    printf("applying %c to state : %d => ",input[0],0);
    int nextState = getNextState(firstInputCharacter,0);
    if(nextState==-1){return 0;}
    int currentState = nextState;
    printf("Reached state : %d,input symbol : %c\n",currentState,input[0]);
    int i = 1;
    while (input[i] != '\0'){
        int inputSymbol = convertInputSymbol(input[i]);
        if(firstInputCharacter == -1){return 0;}
        printf("applying %c to state : %d => ",input[i],currentState);
        nextState = getNextState(inputSymbol,currentState);
        if(nextState==-1){return 0;}
        currentState = nextState;
        printf("Reached state : %d,input symbol : %c\n",currentState,input[i]);
        i++;
    }
    if(currentState == FINAL_STATE_1 || currentState == FINAL_STATE_2){
        return 1;
    }
    return 0;
    
}


int main(){
    clock_t t;
    t = clock();
    char input[50];
    printf("Enter the input string : ");
    scanf("%s",input);
    int result = validateInput(input);
    if(result == 1){
        printf("String is valid\n");
    }else{
        printf("String is not valid\n");
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
    printf("The program took %f seconds to execute\n", time_taken);
    return 0;
}