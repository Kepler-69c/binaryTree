cmake_minimum_required(VERSION 3.25)
project(binaryTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        binaryTree
            main.cpp
            src/treeSearch.cpp src/treeSearch.h
            src/BinaryTree.cpp src/BinaryTree.h
            src/xorshift.h
            src/MCTS.h src/MCTS.cpp
)
