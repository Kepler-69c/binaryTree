#include "MCTS.h"
#include <queue>
#include <future>

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



int nodetest(node* Parent, int Value, int MaxDepth, int Depth)
{
    BST::Position PositionInhit;
    queue<node*> Storage;
    node* selectedChild = nullptr;
    if (Parent->left == nullptr) { selectedChild = Parent->right; }
    else if (Parent->right == nullptr) { selectedChild = Parent->left; }
    else { selectedChild = accessNext(Parent); }
    PositionInhit.v = selectedChild;
    bool Is_external = PositionInhit.isExternal();
    if (selectedChild->data == Value) {
        return selectedChild->data;
    }
    else if (Is_external || Depth == MaxDepth) {
        Storage.push(selectedChild);

        return -1;
    }
    else {
        Depth++;
        return nodetest(selectedChild, Value, MaxDepth, Depth);
    }
}

int MCTS(int Value, int MaxDepth, int Size)
{
    BST tree(Size);
    node* root_node = tree.root().v;

    int result = nodetest();
}

