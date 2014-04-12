#include "AIManager.h"

AIManager& AIManager::getInstance()
{
    static AIManager instance;
    return instance;
}

bool isGoal(Node*, Node*);
float calculateHn(Vector3f, Vector3f);

Node* AIManager::astar(Vector3f end, Vector3f begin) //Needs map parameter
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
            return current;
        }
    }
}

void getSuccessors(Node* current , std::vector<Node*> list, std::vector<Node*> closed) //Needs map parameter
{
    //If adjacent position is not obstacle and not on closed
    //add adjacent positions to list
}

float calculateHn(Vector3f curr, Vector3f goal)
{
    float dx = std::abs(curr._x - goal._x);
    float dy = std::abs(curr._y - goal._y);
    

    //return D * (dx * dx + dy * dy);
    return dx * dx + dy * dy;
}

bool isGoal(Node* current, Node* goal)
{
    return current->isSamePosition(goal);
}


