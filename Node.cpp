#include "src/Node.h"

Node::Node() : _x(0),    _y(0),    _z(0),
               _f(0.0f), _g(0.0f), _h(0.0f), _parent(NULL)
{
}

Node::Node(int x, int y, int z) : _x(x),        _y(y),      _z(z),
                                  _f(0.0f),     _g(0.0f),   _h(0.0f),   _parent(NULL)
{
}

Node::Node(Vector3f v3f) : _x(int(v3f.x)),      _y(int(v3f.y)),        _z(int(v3f.z)),
                           _f(0.0f),             _g(0.0f),              _h(0.0f),
                           _parent(NULL)
{
}

bool Node::operator< (const Node& that)
{
    return this->_f > that._f;
}

bool Node::operator> (const Node& that)
{
    return this->_f < that._f;
}

bool Node::operator== (const Node& that)
{
    return this->_f == that._f;
}

bool Node::operator>= (const Node& that)
{
    if( this->_f < that._f )
        return true;
    else if (this->_f == that._f)
        return true;
    else
        return false;
}

bool Node::operator<= (const Node& that)
{
    if(this->_f > that._f)
        return true;
    else if(this->_f == that._f)
        return true;
    else
        return false;
}

bool Node::operator!= (const Node& that)
{
    return !(this->_f == that._f);
}

Node& Node::operator= (const Node& that)
{
    _f = that._f;
    _g = that._g;
    _h = that._h;
    _x = that._x;
    _y = that._y;
    _z = that._z;

    _parent = new Node;
    _parent = that._parent;
}

bool Node::isSamePosition(const Node& that)
{
    if(std::abs(that._x - this->_x) <= 15 && std::abs(that._z - this->_z) <= 15)
        return true;
    else 
        return false;
}

bool Node::isSamePosition(const Node* that)
{
    if(std::abs(that->_x - this->_x) <= 15 && std::abs(that->_z - this->_z) <= 15)
        return true;
    else
        return false;
}

void Node::calculateFn()
{
    _f  = _g + _h;
}

void Node::traverse(std::vector < Vector3f >& path)
{
    Node *temp = new Node();
    *temp = *this;
    
    while(temp != NULL)
    {
        path.push_back(Vector3f(float(temp->_x),
                                float(temp->_y),
                                float(temp->_z)));
        temp = temp->_parent;
    }
}


