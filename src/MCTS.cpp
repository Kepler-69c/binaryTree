#include <queue>
#include <iostream>
#include "MCTS.h"
#include "xorshift.h"
using namespace std;
using namespace BinaryTree;

// TODO: comment the code

node* accessNext(node* Parent) {
    Xorshift128Plus rng;
    int min = 0;
    int max = 100;

    int probability = rng.random_integer(min, max);
    int ensure = rng.random_integer(min, max);
    if (probability >= ensure)
        return Parent->left;
    else
        return Parent->right;
}

void deletion(node* Nodeptr) {
    BT::Position Position;
    node* Parent =Nodeptr;
    while(Nodeptr != nullptr) {
        Position.v = Parent->right;
        if(Position.isExternal()){
            delete Parent->right;
            Parent->right = nullptr;
        }
        Position.v = Parent->left;
        if (Position.isExternal())
            delete Parent->left;
        if (Parent->right != nullptr)
            Parent = Parent->right;
        else if(Parent->left != nullptr)
            Parent = Parent->left;
        else
            Parent = Parent->parent;
    }
}

//int nodetest(node* Parent, int Value, int MaxDepth, int Depth) {
//    BT::Position PositionInhit;
//    node* selectedChild = nullptr;
//    if (Parent->left == nullptr) { selectedChild = Parent->right; }
//    else if (Parent->right == nullptr) { selectedChild = Parent->left; }
//    else { selectedChild = accessNext(Parent); }
//    PositionInhit.v = selectedChild;
//    bool Is_external = PositionInhit.isExternal();
//    if (selectedChild->data == Value)
//        return selectedChild->data;
//    else if (Is_external || Depth == MaxDepth)
//        return -1;
//    else {
//        Depth++;
//        return nodetest(selectedChild, Value, MaxDepth, Depth);
//    }
//}

int nodetest(node* Parent, int Value, int MaxDepth, int Depth) {
    // Position im Baum initialisieren, zufaelliges Kind initialisieren
    BT::Position PositionInhit;
    node* selectedChild = nullptr;
    // linkes/rechtes zufaellig Kind waehlen, falls es vorhanden ist.
    if (Parent->left == nullptr)        selectedChild = Parent->right;
    else if (Parent->right == nullptr)  selectedChild = Parent->left;
    else                                selectedChild = accessNext(Parent);
    // Position im Baum aktualisieren
    PositionInhit.v = selectedChild;
    // Pruefen, ob das ausgewaehlte Kind ein Blatt ist
    bool Is_external = PositionInhit.isExternal();
    // Ist der gesuchte Wert im Kind gefunden worden (success), ein externer Knoten oder in der maximalen Tiefe (-1)?
    if (selectedChild->data == Value)               return selectedChild->data;
    else if (Is_external || Depth == MaxDepth)      return -1;
    else                                            return nodetest(selectedChild, Value, MaxDepth, Depth++);
}

void MCTS(BT tree, node* root_node, int maxDepth, int searchValue) {
    int result;
    while (result < 0){
        result = nodetest(root_node,searchValue,maxDepth,0);
    }
}
