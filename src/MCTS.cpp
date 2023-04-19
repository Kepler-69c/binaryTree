#include "MCTS.h"
#include <queue>
#include <future>
#include "xorshift.h"
using namespace std;
using namespace BinarySearchTree;


int gen_random_float(int min, int max) {
    Xorshift128Plus rng;
    return rng.random_integer(min, max);
}

node* accessNext(node* Parent)
{
    int probability = gen_random_float(0, 100);
    int ensure = gen_random_float(0, 100);
    if (probability >= ensure)
    {return Parent->left;}
    else
    {return Parent->right;}
}

void deletion(node* Nodeptr)
{
    BST::Position Position;
    node* Parent =Nodeptr;
    while(Nodeptr != nullptr)
    {
        Position.v = Parent->right;
        if(Position.isExternal()){
            delete Parent->right;
            Parent->right = nullptr;
        }
        Position.v = Parent->left;
        if (Position.isExternal()){
            delete Parent->left;
        }
        if (Parent->right != nullptr){
            Parent = Parent->right;
        }
        else if(Parent->left != nullptr){
            Parent = Parent->left;
        }
        else{
            Parent = Parent->parent;
        }
    }
}

int nodetest(node* Parent, int Value, int MaxDepth, int Depth)
{
    BST::Position PositionInhit;
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
        //async(std::launch::async,deletion,selectedChild);
        return -1;
    }
    else {
        Depth++;
        return nodetest(selectedChild, Value, MaxDepth, Depth);
    }
}

double MCTS(BST tree, node* root_node, int searchDepth) {
//    BST tree(size);
//    node* root_node = tree.root().v;
//    tree.random(size, 1, size*2);
    int searchValue = tree.getFromDepth(searchDepth);
    int result;
    clock_t time0 = clock();
    while (result < 0){
    result = nodetest(root_node,searchValue,searchDepth,0);}
    clock_t time1 = clock();
    return double(time1-time0) / CLOCKS_PER_SEC;
}

