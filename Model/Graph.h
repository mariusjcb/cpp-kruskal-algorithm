//
// Created by mariu on 8/19/2017.
//

#ifndef KRUSKAL_GRAPH_H
#define KRUSKAL_GRAPH_H

#include <cstdio>
#include <cstdlib>

#include "Edge.h"
#include "MinimumSpanningTree.h"

class Graph {
    //MARK: Private Properties
private:
    int nodesCount;
    int edgesCount;
    int insertedEdges = 0;
    struct Edge* edges;

public:
    //MARK: - Public Methods

    Graph(int nodes, int edges);

    //MARK: Setters

    void setNodesCount(int count);
    void setEdgesCount(int count);

    void appendEdge(struct Edge);

    //MARK: Getters

    int getNodesCount();
    int getEdgesCount();

    //MARK: KruskalMST

    void toMinimumSpanningTree(MinimumSpanningTree* result);
};

#endif //KRUSKAL_GRAPH_H
