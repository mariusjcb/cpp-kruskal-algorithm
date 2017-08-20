//
// Created by mariu on 8/20/2017.
//

#include "Graph.h"

#include "Subset.h"
#include "../Utils/Utils-Bridging-Header.h"

Graph::Graph(int nodes, int edges) {
    setNodesCount(nodes);
    setEdgesCount(edges);
}

//MARK: - Setters

void Graph::setNodesCount(int count) {
    this->nodesCount = count;
}

void Graph::setEdgesCount(int count) {
    this->edgesCount = count;
    this->edges = (struct Edge*) malloc(count * sizeof(struct Edge));
};

void Graph::appendEdge(struct Edge newEdge) {
    int newEdgeIndex = this->insertedEdges++;
    this->edges[newEdgeIndex] = newEdge;
}

//MARK: - Getters

int Graph::getNodesCount() {
    return this->nodesCount;
}

int Graph::getEdgesCount() {
    return this->edgesCount;
}

//MARK: - Kruskal Algorithm

void Graph::toMinimumSpanningTree(MinimumSpanningTree* result) {
    int nodesCount = getNodesCount();
    int edgesCount = getEdgesCount();

    result->totalWeight = 0;
    result->edgesCount = 0;
    result->edges = (struct Edge*) malloc( nodesCount * sizeof(struct Edge) );

    int takenEdgesCount = 0;

    // Sort O(n * log n)
    qsort(edges, (size_t)edgesCount, sizeof(this->edges[0]), EdgeUtil::compare);

    auto subsets = (struct Subset*) malloc(nodesCount * sizeof(struct Subset));

    for (int node = 0; node < nodesCount; node++) {
        subsets[node].parent = node;
        subsets[node].rank = 0;
    }

    while(takenEdgesCount < nodesCount) {
        struct Edge nextEdge = edges[takenEdgesCount++];

        int x = SubsetUtil::findSubset(subsets, nextEdge.source);
        int y = SubsetUtil::findSubset(subsets, nextEdge.destination);

        if (x != y) {
            result->edges[result->edgesCount++] = nextEdge;
            SubsetUtil::unionSubsets(subsets, x, y);

            result->totalWeight += nextEdge.weight;
        }
    }
}