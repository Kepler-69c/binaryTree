#include "MCTS.h"

using namespace std;
using namespace BinarySearchTree;

float gen_random_float(float min, float max)
{
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator
    uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

node* accessNext(node* Parent)
{
    float probability = gen_random_float(0, 1);
    float ensure = gen_random_float(0, 1);
    if (probability >= ensure)
    {return Parent->left;}
    else
    {return Parent->right;}
}

void reset(node* child)
{
    if (child->parent->left == child) { child->parent->left = nullptr; }
    else { child->parent->right = nullptr; }
}

int nodetest(node* Parent, int Value)
{
    BST::Position PositionInhit;
    if (Parent->left == nullptr) { node* selectedChild = Parent->right; }
    else if (Parent->right == nullptr) { node* selectedChild = Parent->left; }
    else { node* selectedChild = accessNext(Parent); }
    PositionInhit.v = selectedChild;
    bool Is_external = PositionInhit.isExternal();
    if (selectedChild->data == Value) {
        return selectedChild->data;
    }
    else if (Is_external) {
        reset(selectedChild);
        delete (selectedChild);
        return -1;
    }
    else {
        return nodetest(selectedChild, Value);
    }
}

