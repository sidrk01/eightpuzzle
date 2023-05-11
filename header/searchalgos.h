//
// Created by sidha on 5/9/2023.
//

#ifndef EIGHTPUZZLE_SEARCHALGOS_H
#define EIGHTPUZZLE_SEARCHALGOS_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
#include "Problem.h"
#include "Node.h"

const string nodes_expand = "Number of nodes expanded: ";
const string node_queue_max = "Maximum queue size:  ";
const string node_goal_depth = "The depth of the solution: ";

using namespace std;

struct comp{ //comparison operator for priority queue
    bool operator()(Node lhs, Node rhs) const {
        return (lhs.total_cost() > rhs.total_cost()); //determines node ordering by cost
    }
};

class SearchAlgos{
private:
    int algo_choice; //choice of search algorithm
    Problem* p;
    priority_queue<Node, vector<Node>, comp> frontier; //frontier for graph
    unordered_set<string> explored_set; //set of explored nodes

public:
    SearchAlgos(Problem, int); //constructor
    void graph_search(); //implementation of generic graph search
    vector<Node> expand(Node&); //expansion of nodes

};

#endif //EIGHTPUZZLE_SEARCHALGOS_H
