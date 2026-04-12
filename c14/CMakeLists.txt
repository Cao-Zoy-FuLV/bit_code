cmake_minimum_required(VERSION 4.2)

project(c14)


set(CMAKE_CXX_STANDARD 20)

add_executable(c14 main.cpp
        #[[ 
        RBTree.h
         vector.h
         AVLTree.h
         Mysat.h
         Mymap.h
        HashTable.h
        
        ]]
        ../c12/Date.h
        ../c12/Date.cpp
        shared_ptr.h
)