//
// Created by mariu on 8/20/2017.
//

#ifndef KRUSKAL_EDGEUTIL_H
#define KRUSKAL_EDGEUTIL_H

#include "../Model/Edge.h"

class EdgeUtil {
public:
    static int compareEdges(struct Edge* a, struct Edge* b);
    static int compare(const void* a, const void* b);
};


#endif //KRUSKAL_EDGEUTIL_H
