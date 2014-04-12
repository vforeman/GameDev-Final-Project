#include "src/AIManager.h"

AIManager& AIManager::getInstance()
{
    static AIManager instance;
    return instance;
}


