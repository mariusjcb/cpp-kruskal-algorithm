#include <iostream>
#include <fstream>

#include "Bridging-Header.h"

using namespace std;

auto main() -> int {
    ifstream f("graph.in");

    int nodes, edges, source, weight, destination;
    f >> nodes >> edges;

    Graph graph = Graph(nodes, edges);

    while(f >> source >> weight >> destination) {
        struct Edge newEdge { };
        newEdge.source = source;
        newEdge.weight = weight;
        newEdge.destination = destination;

        graph.appendEdge(newEdge);
    }
    
    MinimumSpanningTree mstResult { };
    graph.toMinimumSpanningTree(&mstResult);

    cout << mstResult.totalWeight << '\n';
    for (int i = 0; i < mstResult.edgesCount; i++) {
        cout << mstResult.edges[i].source << ' ';
        cout << mstResult.edges[i].destination << '\n';
    }

    return 0;
}