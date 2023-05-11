//
// Created by sidha on 5/9/2023.
//

#include "../header/node.h"

Node::Node() { //initialize with empty values
    state = "";
    g_cost = 0;
    h_cost = 0;
    depth = 0;
}

Node::Node(Node *prev){ //initialize with previous Node
    this->state = prev->state;
    this->g_cost = prev->g_cost;
    this->h_cost = prev->h_cost;
    this->depth = prev->depth;
    copy(&prev->puzzle[0][0],&prev->puzzle[0][0] + n*n,&this->puzzle[0][0]); //copies over puzzle
    copy(&prev->goal[0][0],&prev->goal[0][0] + n*n,&this->goal[0][0]); //copies over goal state
}

Node::Node(Problem p){ //creates initial and goal state
    state = puzzle_string(p.initial_state);
    g_cost = 0;
    h_cost = 0;
    depth = 0;
    copy(&p.initial_state[0][0],&p.initial_state[0][0] + n*n,&this->puzzle[0][0]);
    copy(&p.goal_state[0][0],&p.goal_state[0][0] + n*n,&this->goal[0][0]);
}

void Node::slide_up() {
    int row = 0;
    int col = 0;
    detect_space(row, col);
    swap(puzzle[row][col], puzzle[row - 1][col]); //shift space with number above
    state = puzzle_string(puzzle);
}

void Node::slide_down() {
    int row = 0;
    int col = 0;
    detect_space(row, col);
    swap(puzzle[row][col], puzzle[row + 1][col]); //shift space with number below
    state = puzzle_string(puzzle);
}

void Node::slide_left() {
    int row = 0;
    int col = 0;
    detect_space(row, col);
    swap(puzzle[row][col], puzzle[row][col - 1]); //shift space with left-side number
    state = puzzle_string(puzzle);
}

void Node::slide_right() {
    int row = 0;
    int col = 0;
    detect_space(row, col);
    swap(puzzle[row][col], puzzle[row][col + 1]); //shift space with right-side number
    state = puzzle_string(puzzle);
}

string Node::puzzle_string(int puzzle_node[n][n]) {
    string puzzle_out;
    for (unsigned i = 0; i < n; i++){
        for (unsigned j = 0; j < n; j++){
            puzzle_out.push_back(puzzle_node[i][j] + 48); //appends character-by-character to string
        }
    }
    return puzzle_out;
}

bool Node::goal_test() {
    for (unsigned i = 0; i < n; i++){
        for (unsigned j = 0; j < n; j++){
            if (puzzle[i][j] != goal[i][j])
                return false; //tile doesn't match goal
        }
    }
    return true;
}

bool Node::detect_space(int& row, int& col){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (puzzle[i][j] == 0){
                row = i;
                col=j;
                return true; //space has been found
            }
        }
    }
    return false;
}

double Node::total_cost(){
    return h_cost + g_cost;
}

void Node::set_heuristic(int choice) {
    switch(choice){
        case 1: //Uniform Cost Search
            h_cost = 0;
            break;
        case 2: //A* with misplaced tile
            h_cost = misplaced_tile();
            break;
        case 3: //A* with manhattan distance
            h_cost = manhattan_distance();
            break;
        default:
            break;
    }
}

int Node::misplaced_tile() {
    int misplaced_tiles = 0;
    string goal_string = puzzle_string(goal);
    //checks tiles of current puzzle against goal using strings
    for (unsigned i = 0; i < goal_string.size(); i++){
        if ((state.at(i) != 0) && (state.at(i) != goal_string.at(i)))
            misplaced_tiles += 1;
    }
    return misplaced_tiles;
}

int Node::manhattan_distance() {
        int total_count = 0;
        for (int num = 1; num < puzzle_string(this->puzzle).size(); num++) {
            int node_r, node_c, goal_r, goal_c;
            bool node_set = false;
            bool goal_set = false;

            //coordinates of the current number in the node and goal states
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (this->puzzle[i][j] == num) {
                        node_r = i;
                        node_c = j;
                        node_set = true;
                    }
                    if (this->goal[i][j] == num) {
                        goal_r = i;
                        goal_c = j;
                        goal_set = true;
                    }
                    if (goal_set && node_set) {
                        break;
                    }
                }
                if (goal_set && node_set) {
                    break;
                }
            }
            //distance obtained from goal vs current positions
            total_count += (abs(goal_r - node_r) + abs(goal_c - node_c));
        }
        return total_count;
}

void Node::print_result() {
    for (auto &i: puzzle) {
        for (unsigned j = 0; j < n; j++) {
            if (i[j] != 0)
                cout << i[j];
            else
                cout << '*';

            if (j != 2)
                cout << " ";
        }
        cout << endl;
    }
}

