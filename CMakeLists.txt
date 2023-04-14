cmake_minimum_required(VERSION 3.5)
project(binaryTree)

        

project(binaryTree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
        binaryTree
            main.cpp
            src/treeSearch.cpp src/treeSearch.h
            src/BinarySearchTree.cpp src/BinarySearchTree.h
            src/MCTS.h src/MCTS.cpp)
