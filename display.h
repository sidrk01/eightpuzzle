//
// Created by sidha on 5/4/2023.
//
#ifndef EIGHTPUZZLE_DISPLAY_H
#define EIGHTPUZZLE_DISPLAY_H

#include <iostream>
#include <cstdlib>
using namespace std;

//can be modified to add more tiles to puzzle
const int N = 3;
int user_puzzle[N][N];

const string welcome = "Welcome to my CS205  8-puzzle solver. Type '1' to use a default puzzle. or '2' to enter your own puzzle.\n";
const string puzzle_enter = "Enter your puzzle, use a zero to represent the blank. Please only use valid 8-puzzles. Enter the puzzle with spaces in between the tiles. Hit 'enter' only when finished.\n";
const string invalid = "An invalid response has been entered. Default is selected.\n";
const string algo = "Enter your choice of algorithm\n[1] Uniform Cost Search.\n[2] A* with the Misplaced Tile heuristic.\n[3] A* with the Manhattan distance heuristic.\n";
const string proceed = "Would you like to try another puzzle?\nHit 'y' to continue or 'n' to quit.\n";
const string default_choice = "Select the desired level of spice for your puzzle\n[1] No Spice\n[2] Lite Mild\n[3] Mild\n[4] Medium\n[5] HOT\n[6] Extra HOT\n[7] REAPER\n[8] EMERGENCY ROOM\n";
const string border = "========================================================================================================================";

//0 moves [1]
const int no_moves[N][N] = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 0,}};

//1 move [2]
const int one_move[N][N] = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 0, 8,}};

//2 moves [3]
const int two_moves[N][N] = {{1, 2, 0},
                        {4, 5, 3},
                        {7, 8, 6,}};

//3 moves [4]
const int three_moves[N][N] = {{1, 2, 3},
                          {0, 5, 6},
                          {4, 7, 8,}};

//16 moves [5]
const int sixteen_moves[N][N] = {{1, 5, 3},
                       {2, 4, 6},
                       {7, 8, 0,}};

//22 moves [6]
const int twenty_two_moves[N][N] = {{8, 7, 1},
                             {6, 0, 2},
                             {5, 4, 3,}};

//23 moves [7]
const int twenty_three_moves[N][N] = {{7, 2, 5},
                          {3, 1, 0},
                          {6, 4, 8,}};

//31 moves [8]
const int max_moves[N][N] = {{8, 6, 7},
                                  {2, 5, 4},
                                  {3, 0, 1,}};

//impossible to solve [9]
const int impossible[N][N] = {{1, 2, 3},
                                 {4, 5, 6},
                                 {8, 7, 0,}};

int goal_state[N][N] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 0}};

//Creates puzzle from default options
void puzzle_from_defaults(){
    cout << default_choice; // default select prompt

    int user_select;
    string puzzle_diff = "Lite Mild";
    cin >> user_select;

    switch (user_select) {
        case 1:
            copy(&no_moves[0][0], &no_moves[0][0] + N * N, &user_puzzle[0][0]); //2D array copy
            puzzle_diff = "no moves";
            break;
        case 2:
            copy(&one_move[0][0], &one_move[0][0] + N * N, &user_puzzle[0][0]);
            puzzle_diff = "one move";
            break;
        case 3:
            copy(&two_moves[0][0], &two_moves[0][0] + N * N, &user_puzzle[0][0]);
            puzzle_diff = "two moves";
            break;
        case 4:
            copy(&three_moves[0][0], &three_moves[0][0] + N * N, &user_puzzle[0][0]);
            puzzle_diff = "three moves";
            break;
        case 5:
            copy(&sixteen_moves[0][0], &sixteen_moves[0][0] + N * N, &user_puzzle[0][0]);
            puzzle_diff = "sixteen moves";
            break;
        case 6:
            copy(&twenty_two_moves[0][0], &twenty_two_moves[0][0] + N * N, &user_puzzle[0][0]);
            puzzle_diff = "twenty-two moves";
            break;
        case 7:
            copy(&twenty_three_moves[0][0], &twenty_three_moves[0][0] + N * N, &user_puzzle[0][0]);
            puzzle_diff = "twenty-three moves";
            break;
        case 8:
            copy(&max_moves[0][0], &max_moves[0][0] + N * N, &user_puzzle[0][0]);
            puzzle_diff = "thirty-one moves";
            break;
        case 9:
            copy(&impossible[0][0], &impossible[0][0] + N * N, &user_puzzle[0][0]);
            puzzle_diff = "FOUND THE HIDDEN PUZZLE!!!";
            break;

        default:
            cout << invalid;
            copy(&one_move[0][0], &one_move[0][0] + N * N, &user_puzzle[0][0]);
            puzzle_diff = "one move";
            break;
    }
    cout << "You have chosen: " + puzzle_diff + "." << endl; //User is notified of choice;
}

//Creates puzzle from user-inputs (option "2")
void puzzle_from_user(){
    string row_one, row_two, row_three;
    //12 cout << "Press Enter to begin:";
    cin.ignore();
    cout << puzzle_enter;
    cout << "Enter the first row, use space between numbers:";
    getline(cin, row_one);
    cout << "Enter the second row, use space  between numbers:";
    getline(cin, row_two);
    cout << "Enter the third  row, use space  numbers:";
    getline(cin, row_three);

//adds user inputs to puzzle but removes the spaces
    for (unsigned i = 0; i < N; i++) {
        for (unsigned j = 0; j < N; j++) {
            if (i == 0) {
                remove(row_one.begin(), row_one.end(), ' ');
                user_puzzle[i][j] =  static_cast<unsigned char>(row_one[j]) - 48; //char to int conversion with offset
            } else if (i == 1) {
                remove(row_two.begin(), row_two.end(), ' ');
                user_puzzle[i][j] = static_cast<unsigned char>(row_two[j]) - 48;
            } else if (i == 2) {
                remove(row_three.begin(), row_three.end(), ' ');
                user_puzzle[i][j] = static_cast<unsigned char>(row_three[j]) - 48;
            }
        }
    }
}

//prints contents of user puzzle
void puzzle_print(int puzzle[N][N]){
    for (unsigned i = 0; i < N; i++){
        for (unsigned j = 0; j < N; j++){
            if (puzzle[i][j] != 0)
                cout << puzzle[i][j];
            else
                cout << '*';

            if (j != 2)
                cout << " ";
        }
        cout << endl;
    }
}

#endif //EIGHTPUZZLE_DISPLAY_H
