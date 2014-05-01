#include "src/AIManager.h"

AIManager& AIManager::getInstance()
{
    static AIManager instance;
    return instance;
}

bool isGoal(Node*, Node*);
float calculateHn(Vector3f, Vector3f);
void getSuccessors(Node* current , std::vector<Node*>& list, std::vector<Node*>& closed, Vector3f); 

bool checkObstacle(Vector3f);
Node* AIManager::astar(Vector3f end, Vector3f begin)
{
    bool firstGo = true;
    Node* start = new Node(begin);
    Node* goal = new Node(end);
    Node* current;
    std::vector<Node*> openlist;
    std::vector<Node*> closelist;
    Vector3f goalvf = end;

    openlist.push_back(start);
    std::make_heap(openlist.begin(), openlist.end());

    while(!openlist.empty())
    {
        current = openlist.front();
        std::pop_heap(openlist.begin(), openlist.end());
        openlist.pop_back();
        if(isGoal(current, goal))
        {
            return current;
        }
    //    getSuccessors(current, openlist, closelist, end);
    //If adjacent position is not obstacle and not on closed
    //add adjacent positions to list
    Node* temp = new Node;
    bool valid = true;
    //if(!Overlay::isObstacle(current->_x+STEP, current->_y, current->_z))
    if(!checkObstacle(Vector3f(current->_x+STEP, current->_y, current->_z)))
    {
        temp->_x = current->_x+STEP;
        temp->_z = current->_z; 
        for(unsigned int i = 0; i < closelist.size() && valid; ++i)
        {
            if(temp->isSamePosition(closelist[i]))
                valid = false;
        }
        
        if(valid)
        {
            temp->_g = current->_g+GSCORE;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goalvf);
            temp->calculateFn();
            temp->setParent(current);
            openlist.push_back(temp);
            std::push_heap(openlist.begin(), openlist.end());
        }
    }
    //if(!Overlay::isObstacle(current->_x-STEP, current->_y, current->_z))
    if(!checkObstacle(Vector3f(current->_x-STEP, current->_y, current->_z)))
    {
        temp->_x = current->_x-STEP;
        temp->_z = current->_z; 
        for(unsigned int i = 0; i < closelist.size() && valid; ++i)
        {
            if(temp->isSamePosition(closelist[i]))
                valid = false;
        }
        if(valid)
        {
            temp->_g = current->_g+GSCORE;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goalvf);
            temp->calculateFn();
            temp->setParent(current);
            openlist.push_back(temp);
            std::push_heap(openlist.begin(), openlist.end());
        }
        valid = true;
    }
    //if(!Overlay::isObstacle(current->_x, current->_y, current->_z+STEP))
    if(!checkObstacle(Vector3f(current->_x, current->_y, current->_z+STEP)))
    {
        temp->_x = current->_x;
        temp->_z = current->_z+STEP; 
        for(unsigned int i = 0; i < closelist.size() && valid; ++i)
        {
            if(temp->isSamePosition(closelist[i]))
                valid = false;
        }
        if(valid)
        {
            temp->_g = current->_g+GSCORE;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goalvf);
            temp->calculateFn();
            temp->setParent(current);
            openlist.push_back(temp);
            std::push_heap(openlist.begin(), openlist.end());
        }
        valid = true;
    }
    //if(!Overlay::isObstacle(current->_x, current->_y, current->_z-STEP))
    if(!checkObstacle(Vector3f(current->_x, current->_y, current->_z-STEP)))
    {
        temp->_x = current->_x;
        temp->_z = current->_z-STEP; 
        for(unsigned int i = 0; i < closelist.size() && valid; ++i)
        {
            if(temp->isSamePosition(closelist[i]))
                valid = false;
        }
        if(valid)
        {
            temp->_g = current->_g+GSCORE;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goalvf);
            temp->calculateFn();
            temp->setParent(current);
            openlist.push_back(temp);
            std::push_heap(openlist.begin(), openlist.end());
        }
        valid = true;
    }
        if(firstGo && !openlist.empty())
        {
            std::make_heap(openlist.begin(), openlist.end());
            firstGo = false;
        }
        closelist.push_back(current);
        return current;
    }
    return NULL;

}

//Effectively increase the weight around obstacles
bool checkObstacle(Vector3f pos)
{
    
    if(Overlay::isObstacle(pos)) return true;

    bool obstaclePresent = false;
    float i = 0.0f;
    float x = pos.x;
    float z = pos.z;
    Vector3f check = pos; 
    while( i <= float(STEP)+7.5f && !obstaclePresent)
    {
        pos.x = pos.x + i;
        pos.z = pos.z + i;
        x = x - i;
        z = z - i;
    
        i = i + 0.125f;
        obstaclePresent = (
                            Overlay::isObstacle(Vector3f(pos.x, 0.0f, pos.z))      || 
                            Overlay::isObstacle(Vector3f(check.x, 0.0f, pos.z))    ||
                            Overlay::isObstacle(Vector3f(pos.x, 0.0f, check.z))    ||
                            Overlay::isObstacle(Vector3f(check.x, 0.0f, z))        ||
                            Overlay::isObstacle(Vector3f(x, 0.0f, check.z))        ||
                            Overlay::isObstacle(Vector3f(x, 0.0f, z)) );
    }

    return obstaclePresent;
}

void getSuccessors(Node* current , std::vector<Node*>& list, std::vector<Node*>& closed, Vector3f goal) 
{
    //If adjacent position is not obstacle and not on closed
    //add adjacent positions to list
    Node* temp = new Node;
    bool valid = true;
    std::vector<int> closelist;
    if(!Overlay::isObstacle(current->_x+STEP, current->_y, current->_z))
    {
        temp->_x = current->_x+STEP;
        temp->_z = current->_z; 

        
        if(valid)
        {
            temp->_g = current->_g+GSCORE;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
        valid = true;
    }
    if(!Overlay::isObstacle(current->_x-STEP, current->_y, current->_z))
    {
        temp->_x = current->_x-STEP;
        temp->_z = current->_z; 
        for(unsigned int i = 0; i < closelist.size() && valid; ++i)
        {
            if(temp->isSamePosition(closed[i]))
                valid = false;
        }
        
        if(valid)
        {
            temp->_g = current->_g+GSCORE;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
        valid = true;
    }
    if(!Overlay::isObstacle(current->_x, current->_y, current->_z+STEP))
    {
        temp->_x = current->_x;
        temp->_z = current->_z+STEP; 
        for(unsigned int i = 0; i < closelist.size() && valid; ++i)
        {
            if(temp->isSamePosition(closed[i]))
                valid = false;
        }
        
        if(valid)
        {
            temp->_g = current->_g+GSCORE;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
        valid = true;
    }
    if(!Overlay::isObstacle(current->_x, current->_y, current->_z-STEP))
    {
        temp->_x = current->_x;
        temp->_z = current->_z-STEP; 
        for(unsigned int i = 0; i < closelist.size() && valid; ++i)
        {
            if(temp->isSamePosition(closed[i]))
                valid = false;
        }

        if(valid)
        {
            temp->_g = current->_g+GSCORE;
            temp->_h = calculateHn(Vector3f(float(temp->_x), float(temp->_y), float(temp->_z)), goal);
            temp->calculateFn();
            temp->setParent(current);
            list.push_back(temp);
            std::push_heap(list.begin(), list.end());
        }
        valid = true;
    }
}

float calculateHn(Vector3f curr, Vector3f goal)
{
    float dx = std::fabs(curr.x - goal.x);
    float dy = std::fabs(curr.y - goal.y);


    //return D * (dx * dx + dy * dy);
    return 200* dx * dx + dy * dy;
}

bool isGoal(Node* current, Node* goal)
{
    return current->isSamePosition(goal);
}

Vector3f AIManager::getPlayer()
{
    return _player;
}

Vector3f AIManager::randVec3f()
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::uniform_real_distribution<double> placement(0.0, (double)Overlay::OVERLAY_WIDTH/2);
    float quadrant = placement(generator);
    float x = placement(generator);
    float z = placement(generator);
    if(quadrant >= 0 && quadrant < 0.25f)
    {
        return Vector3f(x, 0.5f, z);    //Quadrant I Cartesian (Pos X and pos Z)
    }
    if(quadrant >= 0.25f && quadrant < 0.5f)
    {
        return Vector3f(-x, 0.5f, z);   //Quadrant II
    }
    if(quadrant >= 0.5f && quadrant < 0.75f)
    {
        return Vector3f(-x, 0.5f, -z);  //Quadrant III
    }
    else
    {
        return Vector3f(x, 0.5f, z);    //Quadrnat IV
    }
}   

void AIManager::setPlayer(Vector3f player)
{
    _player = player;
}
