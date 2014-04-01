#ifndef SINGLETONPATTERN_H
#define SINGLETONPATTERN_H
#include <stdlib.h>

namespace Patterns
{
 template <typename T>
 class Singleton
 {
  private:
   static T m_Instance;
  public:
   static T Get()
   {
    if (m_Instance == NULL)
    {
     m_Instance = new T();
     return m_Instance;
    }
    else
    {
     return m_Instance;
    }
   }

 };
}


#endif
