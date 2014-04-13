#include "src/AIManager.h"

AIManager& AIManager::getInstance()
{
    static AIManager instance;
    return instance;
}

bool isGoal(Node*, Node*);
float calculateHn(Vector3f, Vector3f);
void getSuccessors(Node* current , std::vector<Node*>& list, std::vector<Node*>& closed, Vector3f); 

Node* AIManager::astar(Vector3f begin, Vector3f end)
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
        
        std::pop_heap(openlist.begin(), openlist.end());
        openlist.pop_back();
        if(isGoal(current, goal))
        {
            return current;
        }
        getSuccessors(openlist.front(), openlist, closelist, end);
    }
    return NULL;
}

void getSuccessors(Node* current , std::vector<Node*>& list, std::vector<Node*>& closed, Vector3f goal) 
{
    //If adjacent position is not obstacle and not on closed
    //add adjacent positions to list
    Node* temp = new Node;
    if(!Overlay::isObstacle(current->_x+10, current->_y, current->_z))
    {
        bool valid = true;
        temp->_x = current->_x+10;
        temp->_z = current->_z; 
        for(unsigned int i = 0; i < closed.size() && valid; ++i)
        {
            if(temp->isSamePosition(closed[i]))
                valid = false;               
        }

        if(valid)
        {
            temp->_g = current->_g+10;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
        
    }
    if(!Overlay::isObstacle(current->_x-10, current->_y, current->_z))
    {
        bool valid = true;
        temp->_x = current->_x-10;
        temp->_z = current->_z; 
        for(unsigned int i = 0; i < closed.size() && valid; ++i)
        {
                
            if(temp->isSamePosition(closed[i]))
                valid = false;               
        }
        if(valid)
        {
            temp->_g = current->_g+10;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
    }
    if(!Overlay::isObstacle(current->_x, current->_y, current->_z+10))
    {
        bool valid = true;
        temp->_x = current->_x;
        temp->_z = current->_z+10; 
        for(unsigned int i = 0; i < closed.size() && valid; ++i)
        {
            if(temp->isSamePosition(closed[i]))
                valid = false;               
        }

        if(valid)
        {
            temp->_g = current->_g+10;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
    }
    if(!Overlay::isObstacle(current->_x, current->_y, current->_z-10))
    {
        bool valid = true;
        temp->_x = current->_x;
        temp->_z = current->_z-10; 
        for(unsigned int i = 0; i < closed.size() && valid; ++i)
        {
            if(temp->isSamePosition(closed[i]))
                valid = false;               
        }

        if(valid)
        {
            temp->_g = current->_g+10;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
    }
    if(!Overlay::isObstacle(current->_x+10, current->_y, current->_z+10))
    {
        bool valid = true;
        temp->_x = current->_x+10;
        temp->_z = current->_z+10; 
        for(unsigned int i = 0; i < closed.size() && valid; ++i)
        {
            if(temp->isSamePosition(closed[i]))
                valid = false;               
        }

        if(valid)
        {
            temp->_g = current->_g+10;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
    }
    if(!Overlay::isObstacle(current->_x+10, current->_y, current->_z-10))
    {
        bool valid = true;
        temp->_x = current->_x+10;
        temp->_z = current->_z-10; 
        for(unsigned int i = 0; i < closed.size() && valid; ++i)
        {
            if(temp->isSamePosition(closed[i]))
                valid = false;               
        }

        if(valid)
        {
            temp->_g = current->_g+10;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
    }
    if(!Overlay::isObstacle(current->_x-10, current->_y, current->_z-10))
    {
        bool valid = true;
        temp->_x = current->_x-10;
        temp->_z = current->_z-10; 
        for(unsigned int i = 0; i < closed.size() && valid; ++i)
        {
            if(temp->isSamePosition(closed[i]))
                valid = false;               
        }

        if(valid)
        {
            temp->_g = current->_g+10;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
    }
    if(!Overlay::isObstacle(current->_x-10, current->_y, current->_z+10))
    {
        bool valid = true;
        temp->_x = current->_x-10;
        temp->_z = current->_z+10; 
        for(unsigned int i = 0; i < closed.size() && valid; ++i)
        {
            if(temp->isSamePosition(closed[i]))
                valid = false;               
        }
        if(valid)
        {
            temp->_g = current->_g+10;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
    }
}

float calculateHn(Vector3f curr, Vector3f goal)
{
    float dx = std::abs(curr.x - goal.x);
    float dy = std::abs(curr.y - goal.y);


    //return D * (dx * dx + dy * dy);
    return dx * dx + dy * dy;
}

bool isGoal(Node* current, Node* goal)
{
    return current->isSamePosition(goal);
}


