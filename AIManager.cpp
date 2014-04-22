#include "src/AIManager.h"

AIManager& AIManager::getInstance()
{
    static AIManager instance;
    return instance;
}

bool isGoal(Node*, Node*);
float calculateHn(Vector3f, Vector3f);
void getSuccessors(Node* current , std::vector<Node*>& list, std::vector<Node*>& closed, Vector3f); 

/*TODO
 * FIX A-STAR SEARCH ALGORITHM
 * IT IS GIVING A BLACK SCREEN AND TAKING 204% OF THE CPU
 * NOTEWORTHY: THE PROBLEM IS IN THE LOOP OF THE A-STAR
 * ALTERING THE NODE TRAVERSAL HAS HAD LIMITED SUCCESS ONLY ON A SMALL LOOP
* SOMETHING COULD BE WRONG WITH YOUR HEURISTIC
*/
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
    if(!Overlay::isObstacle(current->_x+STEP, current->_y, current->_z))
    {
//        bool valid = true;
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
    if(!Overlay::isObstacle(current->_x-STEP, current->_y, current->_z))
    {
//        bool valid = true;
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
    if(!Overlay::isObstacle(current->_x, current->_y, current->_z+STEP))
    {
//        bool valid = true;
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
    if(!Overlay::isObstacle(current->_x, current->_y, current->_z-STEP))
    {
//        bool valid = true;
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
    return 100* dx * dx + dy * dy;
}

bool isGoal(Node* current, Node* goal)
{
    return current->isSamePosition(goal);
}


