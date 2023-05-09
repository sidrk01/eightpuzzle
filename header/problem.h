#ifndef EIGHTPUZZLE_PROBLEM_H
#define EIGHTPUZZLE_PROBLEM_H

#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
using namespace std;

//can be modified to add more tiles to puzzle
const int n = 3;

class Problem {

public:
    int initial_state[n][n];
    int goal_state[n][n];

    Problem(int puzzle[n][n], int goal[n][n]) { //constructor
        copy(&puzzle[0][0], &puzzle[0][0] + n * n, &initial_state[0][0]); //create initial state
        copy(&goal[0][0], &goal[0][0] + n * n, &goal_state[0][0]); //create goal state
    }
};

#endif //EIGHTPUZZLE_PROBLEM_H
