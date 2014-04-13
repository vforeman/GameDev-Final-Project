#ifndef NODE_H
#define NODE_H

#include "Vmath.h"
#include <vector>
#include <cmath>

class Node
{
    public:
        Node();
        Node(int, int, int);
        Node(Vector3f);
        int _x, _y, _z;         //position operators
        float _g, _h;
        bool isSamePosition(int, int, int);
        bool isSamePosition(const Node&);
        bool isSamePosition(const Node*);
        void calculateFn();      //calculate F = step + heuristic
        void setParent(Node*);
        void traverse(std::vector< Vector3f >& );
        void traverseFl(std::vector< float* >&);

        //Overloaded operators- compare _f scores
        bool operator< (const Node&);
        bool operator> (const Node&);
        bool operator== (const Node&);
        bool operator>= (const Node&);
        bool operator<= (const Node&);
        bool operator!= (const Node&);
        Node& operator= (const Node&);
    private:
        Node* _parent;
        float _f;       
};

#endif
