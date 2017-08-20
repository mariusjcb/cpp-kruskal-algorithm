cmake_minimum_required(VERSION 3.8)
project(Kruskal)

set(CMAKE_CXX_STANDARD 17)

set(ENTRY main.cpp)

set(SOURCE_FILES main.cpp Model/Edge.h Model/Graph.h Model/Graph.cpp Model/Subset.h Utils/SubsetUtil.cpp Utils/SubsetUtil.h Utils/EdgeUtil.cpp Utils/EdgeUtil.h Utils/Utils-Bridging-Header.h Model/Model-Bridging-Header.h Bridging-Header.h Model/MinimumSpanningTree.h)
add_executable(Kruskal ${SOURCE_FILES})