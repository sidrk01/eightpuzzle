#ifndef EIGHTPUZZLE_PROBLEM_H
#define EIGHTPUZZLE_PROBLEM_H

#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
using namespace std;

//can be modified to add more tiles to puzzle
const int N = 3;

class Problem {

public:
    int initial_state[N][N];
    int goal_state[N][N];

    Problem(int puzzle[N][N], int goal[N][N]) { //constructor
        copy(&puzzle[0][0], &puzzle[0][0] + N * N, &initial_state[0][0]); //create initial state
        copy(&goal[0][0], &goal[0][0] + N * N, &goal_state[0][0]); //create goal state
    }
};

#endif //EIGHTPUZZLE_PROBLEM_H
