//
// Created by mariu on 8/20/2017.
//

#ifndef KRUSKAL_SUBSETUTIL_H
#define KRUSKAL_SUBSETUTIL_H

#include "../Model/Subset.h"

class SubsetUtil {
public:
    static int findSubset(struct Subset subsets[], int i);
    static void unionSubsets(struct Subset subsets[], int i, int j);
};


#endif //KRUSKAL_SUBSETUTIL_H
