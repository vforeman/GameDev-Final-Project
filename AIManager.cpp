#include "AIManager.h"

AIManager& AIManager::getInstance()
{
    static AIManager instance;
    return instance;
}

bool isGoal(Node*, Node*);

void AIManager::astar(Vector3f end, Vector3f begin) //Needs map parameter
{
    Node* start = new Node(begin);
    Node* goal = new Node(end);
    Node* current = new Node();
    std::vector<Node*> openlist;
    std::vector<Node*> closelist;

    openlist.push_back(start);

    std::make_heap(openlist.begin(), openlist.end());

    while(!openlist.empty())
    {
        if(isGoal(current, goal))
        {
            return;
        }
    }
}

void getSuccessors(Node* current , std::vector<Node*> list, std::vector<Node*> closed) //Needs map parameter
{
    //If adjacent position is not obstacle and not on closed
    //add adjacent positions to list
}


bool isGoal(Node* current, Node* goal)
{
    return current->isSamePosition(goal);
}


