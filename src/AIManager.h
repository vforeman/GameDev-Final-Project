#ifndef AIMANAGER_H
#define AIMANAGER_H

#include "Node.h"
#include "Overlay.h"
#include <vector>
#include <algorithm>

const unsigned int STEP = 5;
const unsigned int GSCORE = 20;

class AIManager
{
    public:
        Vector3f _player;                       //Position of player updated, used to determine alert of enemies
        static AIManager& getInstance();
        Node* astar( Vector3f, Vector3f );       //A-Star search
        Vector3f randVec3f();
    private:
        static AIManager* _instance;
        AIManager(const AIManager&);
        AIManager& operator=(const AIManager&);
        AIManager() {};
};

#endif
