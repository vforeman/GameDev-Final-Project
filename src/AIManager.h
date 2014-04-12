#ifndef AIMANAGER_H
#define AIMANAGER_H

#include "Node.h"

class AIManager
{
    public:
        static AIManager& getInstance();
        void astar( );
    private:
        static AIManager* _instance;
        AIManager(const AIManager&);
        AIManager& operator=(const AIManager&);
        AIManager() {};
};

#endif
