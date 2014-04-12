#ifndef AIMANAGER_H
#define AIMANAGER_H

#include "Node.h"
#include <vector>
#include <algorithm>

class AIManager
{
    public:
        static AIManager& getInstance();
        void astar( Vector3f, Vector3f );       //A-Star search
    private:
        static AIManager* _instance;
        AIManager(const AIManager&);
        AIManager& operator=(const AIManager&);
        AIManager() {};
};

#endif
