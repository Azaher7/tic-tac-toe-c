#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>



char create_game_board();
char play_game(char player_name[]);
int placeMove(int row, int col);
int computerMove();
int hasplayerXwon();
int hasplayerOwon();
int tieGame();



char *board[6][6];



int main(){

    char name[30];
 
    printf("\n\n");
    printf("What is your name?\n\n");
    

    scanf("%s", name);

    play_game(name);

    return 0;
}



char play_game(char player_name[]){

    bool game_on = true;

    create_game_board();

    printf("\n\n");
    printf("Hello %s ... Let's have fun !!! You = X | Computer = O\n",player_name);

    
    printf("\n\n");

    for (int i = 0;i<6;i++){
        for (int j = 0; j<6;j++){
            printf("%s",board[i][j]);
        }
    }

    printf("\n\n");

    int X,Y;


    while (game_on) {
        printf("\n\n");

        printf("Enter X,Y coordinates for your move: ");
        
        scanf("%d,%d", &X, &Y);

        if (X > 3 || X < 1 || Y > 3 || Y < 1) {
            printf("\n\n");
            printf("Invalid input- please input format 'X','Y' \n");
            printf("Please try again\n");
            continue;
        }


        else {

            printf("\n\n");

            if (placeMove(X, Y) == 0) {

                if (hasplayerXwon() == 1) {

                    for (int i = 0; i < 6; i++) {
                        for (int j = 0; j < 6; j++) {
                            printf("%s", board[i][j]);
                        }
                    }

                    printf("\n\n");
                    printf("Human wins! AI will not be taking over anytime soon!\n");
                    game_on = false;
                    break;
                }

                else {

                    if (tieGame() == 0) {

                        for (int i = 0; i < 6; i++) {
                            for (int j = 0; j < 6; j++) {
                                printf("%s", board[i][j]);
                            }
                        }

                        printf("\n\n");
                        printf("tie game\n");
                        game_on = false;
                        break;
                    }

                    else {

                        computerMove();

                        if (hasplayerOwon() == 1) {

                            for (int i = 0; i < 6; i++) {
                                for (int j = 0; j < 6; j++) {
                                    printf("%s", board[i][j]);
                                }
                            }

                            printf("\n\n");
                            printf("Computer wins! we are doomed!\n");
                            game_on = false;
                            break;
                        }

                        else if (tieGame() == 0) {

                            for (int i = 0; i < 6; i++) {
                                for (int j = 0; j < 6; j++) {
                                    printf("%s", board[i][j]);
                                }
                            }

                            printf("\n\n");
                            printf("tie game\n");
                            game_on = false;
                            break;
                        }

                        else {

                            for (int i = 0; i < 6; i++) {
                                for (int j = 0; j < 6; j++) {
                                    printf("%s", board[i][j]);
                                }
                            }

                            continue;
                        }
                    }
                }
            }

            else {
                continue;
            }
        }
    }

    return 0;
}




int placeMove(int X, int Y)
{


    if (X == 1) {
        X = 0;

        if (Y == 1) {
            Y = 0;
        }
        else if (Y == 3) {
            Y = 4;
        }
    }
    else if (X == 2) {
        if (Y == 1) {
            Y = 0;
        }
        else if (Y == 3) {
            Y = 4;
        }
    }
    else if (X == 3) {
        X = 4;

        if (Y == 1) {
            Y = 0;
        }
        if (Y == 3) {
            Y = 4;
        }
    }

    if (strcmp(board[X][Y], " X ") == 0 || strcmp(board[X][Y], " O ") == 0) {
        printf("\n\n");
        printf("Invalid input- position already taken\n");
        printf("Please try again\n");
        return 1;
    }

    else {
        board[X][Y] = " X ";
    }

    return 0;
}


int computerMove(){


    srand(time(0));
    bool occupied_position = true; 

    while(occupied_position){


        int X,Y;
        
        X = rand() %3 + 1;
        Y = rand() %3 + 1;


        if (X == 1) {
            X = 0;

            if (Y == 1) {
                Y = 0;
            }
            else if (Y == 3) {
                Y = 4;
            }
        }

        else if (X == 2) {
            if (Y == 1) {
                Y = 0;
            }
            else if (Y == 3) {
                Y = 4;
            }
        }

        else if (X == 3) {
            X = 4;
            
            if (Y == 1) {
                Y = 0;
            }
            
            if (Y == 3) {
                Y = 4;
            }
        }
    

        if (strcmp(board[X][Y], " X ") == 0 || strcmp(board[X][Y], " O ") == 0){
            continue;
        }

        else{
            board[X][Y] = " O ";
            occupied_position = false;
            break;
        }
    }

    return 0;

}

    

int tieGame(){

    for (int i = 0; i <= 4; i+=2){
        for (int j = 0; j<=4; j+=2){
            if  (!(strcmp(board[i][j], " X ") == 0 || strcmp(board[i][j], " O ") == 0)){
                return 1;
            }
        }
    }
    return 0;
}

int hasplayerXwon(){

    for (int i = 0;i<=4;i+=2){
        if (strcmp(board[i][0], " X ") == 0 && strcmp(board[i][2], " X ") == 0 && strcmp(board[i][4], " X ") == 0){
            return 1;
        }   
    }

    for (int j = 0;j<=4;j+=2){
        if (strcmp(board[0][j], " X ") == 0 && strcmp(board[2][j], " X ") == 0 && strcmp(board[4][j], " X ") == 0){
            return 1;
        }   
    }

     
    if (strcmp(board[0][0], " X ") == 0 && strcmp(board[2][2], " X ") == 0 && strcmp(board[4][4], " X ") == 0){
            return 1;
    }

    if (strcmp(board[0][4], " X ") == 0 && strcmp(board[2][2], " X ") == 0 && strcmp(board[4][0], " X ") == 0){
            return 1;
    }   

    return 0;
}

int hasplayerOwon(){

    for (int i = 0;i<=4;i+=2){
        if (strcmp(board[i][0], " O ") == 0 && strcmp(board[i][2], " O ") == 0 && strcmp(board[i][4], " O ") == 0){
            return 1;
        }   
    }

    for (int j = 0;j<=4;j+=2){
        if (strcmp(board[0][j], " O ") == 0 && strcmp(board[2][j], " O ") == 0 && strcmp(board[4][j], " O ") == 0){
            return 1;
        }   
    }


    if (strcmp(board[0][0], " O ") == 0 && strcmp(board[2][2], " O ") == 0 && strcmp(board[4][4], " O ") == 0){
            return 1;
    }

    if (strcmp(board[0][4], " O ") == 0 && strcmp(board[2][2], " O ") == 0 && strcmp(board[4][0], " O ") == 0){
            return 1;
    }   

    return 0;
}


char create_game_board(){

    for (int i = 0;i<6 ;i++){
        for (int j = 0; j<6;j++){
            if( i==1 || i==3){
                if (j == 0 || j == 2 ){
                    board[i][j] = "___";
                }

                else if (j == 1 || j == 3 ){
                    board[i][j] = "|";
                }

                else if (j == 4){
                    board[i][j] = "___";
                }

                else if (j==5){
                    board[i][j] =  "\n";
                }
            }

            else if ((i == 0|| i == 2 || i == 4))

            {
                if (j == 0 || j == 2){
                    board[i][j] = "   ";
                }

                else if ( j==1 || j==3 ){
                    board[i][j] = "|";
                }

                else if (j==4){
                    board[i][j] = "   ";
                }

                else if (j==5){
                     board[i][j] =  "\n";
                }
            }

            else if (i==5){
                if (j == 0 || j == 2){
                    board[i][j] = "   ";
                }

                else if ( j==1 || j==3 ){
                    board[i][j] = "|";
                }

                else if (j==4){
                    board[i][j] = "   ";
                }

                else if (j==5){
                     board[i][j] =  "\n";
                }
            }
        }
    }

    
    return 0;

}
