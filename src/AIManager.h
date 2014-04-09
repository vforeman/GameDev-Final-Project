#ifndef AIMANAGER_H
#define AIMANAGER_H

#include "Vmath.h"

//Meyer's Singleton Implementation
/*
 *  DANGER! DANGER! DANGER, WILL ROBINSON!
 *  Compile as C++11. This is important to make this AIManager threadsafe.
 *  Meyer's singleton is not threadsafe before C++11.
 */
class AIManager
{
    public:
        static AIManager& getInstance();
        bool alertProximity(Vector3, Vector3);  //Determine if player is in firing range. AIManager should know level
    private:
        AIManager() {  }
        ~AIManager() { }
        AIManager(const AIManager&);
        AIManager& operator=(const AIManager&);
        static AIManager* _instance;
};

#endif
