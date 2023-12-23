#include<iostream>
using namespace std;
char space[3][3]={{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int row;
int col;
bool draw;
char token= 'X';
string player1_name;
string player2_name;

void inps() {
    cout << "Enter name of player 1: \n";
    getline(cin, player1_name);
    cout << "Enter name of player 2: \n";
    getline(cin, player2_name);
    cout << player1_name << " is Player 1 so they will start the game with X \n";
}

void gameStructure() {
    cout<< "      |        |   \n";
    cout<<"  "<< space[0][0]<<"  "<<" | " << "  "<< space[0][1]<<"   "<<" | " <<"  "<< space[0][2]<< "\n";
    cout<< "      |        |   \n";
    cout<< "______|________|______ \n";
    cout<< "      |        |   \n";
    cout<<"  "<< space[1][0]<<"  "<<" | " << "  "<< space[1][1]<<"   "<<" | " <<"  "<< space[1][2]<< "\n";
    cout<< "      |        |   \n";
    cout<< "______|________|______ \n";
    cout<< "      |        |   \n";
    cout<<"  "<< space[2][0]<<"  "<<" | " << "  "<< space[2][1]<<"   "<<" | " <<"  "<< space[2][2]<< "\n";
    cout<< "      |        |   \n";
    cout<< "      |        |   \n";
}

void checkInvalidValue() {
    char digit = '0';  
    do {
        if (token == 'X') {
            cout << player1_name << " Please enter: ";
        } else {
            cout << player2_name << " Please enter: ";
        }

        cin >> digit;

        if (digit >= '1' && digit <= '9') {
            row = (digit - '1') / 3;
            col = (digit - '1') % 3;
        } else {
            cout << "Invalid input!! ";
        }
    } while (digit < '1' || digit > '9' || space[row][col] == 'X' || space[row][col] == 'O');

    if (token == 'X') {
        space[row][col] = 'X';
        token = 'O';
    } else {
        space[row][col] = 'O';
        token = 'X';
    }
}

bool checkWin() {
    for(int i=0; i<3; i++){
        if((space[i][0]==space[i][1] && space[i][1]==space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i])){
            draw=false;
            return true;
        }
    }
    if((space[0][0] == space[1][1] && space[0][0] == space[2][2]) || (space[0][2]== space[1][1] && space[1][1]== space[2][0])){
        draw=false;
        return true;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(space[i][j]!='X' && space[i][j]!='O'){
                return false;
            }
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(space[i][j]=='X' || space[i][j]!='O'){
                draw=true;
                return true;
            }
        }
    }
    draw=true;
    return false;
}

int main() {
    inps();
    while(!checkWin()){
        gameStructure();
        checkInvalidValue();
    } 

    if(token=='X' && !draw){
        cout << player2_name << " Wins!! " << endl;
    }
    else if(token == 'O' && !draw){
        cout << player1_name << " Wins!! " << endl;
    }
    else {
        cout << "It's a draw! " << endl;
    }
}

