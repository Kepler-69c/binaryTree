#pragma once

#include "BinarySearchTree.h"
#include <iostream>
#include <random>
#include <functional>

using namespace BinarySearchTree;
float gen_random_float(float min, float max);
node* accessNext(node* Parent);
int nodetest(node* Parent, int Value, int MaxDepth);
double MCTS(BST tree, node* root_node, int SearchDepth);
