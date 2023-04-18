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

bool nodetest(node* Parent)
{
    node* selectedChild = accessNext(Parent);
    

}


