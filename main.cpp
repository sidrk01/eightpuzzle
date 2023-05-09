#include <iostream>
#include <string>
#include <algorithm>
#include "header/display.h"
#include "header/problem.h"
#include "header/node.h"

using namespace std;
int main() {
    char user_opt = 'y';
    int user_choice = 0;

    while (user_opt == 'y') {
        cout << welcome; //Welcome prompt
        cin >> user_choice;
        cout << border;

        if (user_choice == 1)
            puzzle_from_defaults();
        else
            puzzle_from_user();
        puzzle_print(user_puzzle); //prints contents of puzzle

        cout << border; //neatly separates user inputs
        cout << algo; //allows for choice of algorithm
        cin >> user_choice;

        //creates problem space
        Problem problem(user_puzzle, goal_state);
        //NODE TESTS:
        Node node(problem);
        node.print_result();
        cout << "\nSliding Node Right:\n";
        node.slide_right();
        node.print_result();
        cout << "\nSliding Node Left:\n";
        node.slide_left();
        node.print_result();
        cout << "\nSliding Node Up:\n";
        node.slide_up();
        node.print_result();
        cout << "\nSliding Node Down:\n";
        node.print_result();

        cout << "\nNode goal-matching:\n";
        cout << node.goal_test();

        cout << border;

        cout << proceed; //reset puzzle
        cin >> user_opt;
        cout << border;
    }

    return 0;
}
