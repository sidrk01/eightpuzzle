//
// Created by sidha on 5/9/2023.
//

#include "../header/searchalgos.h"

SearchAlgos::SearchAlgos(Problem problem, int num) {
    p = &problem;
    algo_choice = num;
}

void SearchAlgos::graph_search() {
    Node head(*p);
    vector<Node> list; //list of expanded Nodes
    bool first = true;
    unsigned int frontier_size = frontier.size();
    unsigned int size_nodes = 0;

    frontier.push(head); //initialize the frontier using initial state of problem

    while(!frontier.empty()){ //loop do
        if(frontier.empty()){
            cout << "Unable to perform search." << endl;
            return;
        }

        if (frontier_size < frontier.size())
            frontier_size = frontier.size();

        Node temp = frontier.top();
        frontier.pop(); //choose a leaf node and remove it from the frontier


        if(temp.goal_test()){ //if a node contains a goal state then return the corresponding solution
            temp.print_result(); //prints output of search
            cout << "Goal state!" << endl << endl;
            cout << node_goal_depth << temp.depth << endl;
            cout << nodes_expand << size_nodes << endl;
            cout << node_queue_max << frontier_size << endl;
            return;
        }

        //prints "trace" of expanded nodes (comment out for faster execution time)
//        if (frontier_size > 1) {
//            cout << "The best state to expand with g(n) = " << temp.g_cost  << " and h(n) = " << temp.h_cost << " is..." << endl;
//        }
//        temp.print_result();
//        cout <<"expanding this node..." << endl << endl;

        list = expand(temp); //expand the chosen node
        explored_set.insert(head.state); //add to first node to explored set

        for (auto & i : list){ //adding resulting nodes to the frontier
            frontier.push(i);
        }
        size_nodes += 1;
    }
}

//helper function
vector<Node> SearchAlgos::expand(Node& curr) {
    int row = 0;
    int col = 0;
    curr.detect_space(row, col);
    vector<Node> list;

    for (unsigned i = 0; i < 4; i++){
        Node temp(curr);

        switch(i) {
            case 0: //slide up
                if (row > 0) {
                    temp.slide_up();
                    break;
                }
                else {
                    continue;
                }
            case 1: //slide down
                if (row < 2) {
                    temp.slide_down();
                    break;
                }
                else {
                    continue;
                }
            case 2: //slide left
                if (col > 0) {
                    temp.slide_left();
                    break;
                }
                else {
                    continue;
                }
            case 3: //slide right
                if (col < 2) {
                    temp.slide_right();
                    break;
                }
                else {
                    continue;
                }
            default:
                break;
        }

        if (explored_set.count(temp.state) == 0) {
            ++temp.g_cost;
            ++temp.depth;
            temp.set_heuristic(algo_choice);
            list.push_back(temp);
            explored_set.insert(temp.state);
        }
    }

    return list;
}




