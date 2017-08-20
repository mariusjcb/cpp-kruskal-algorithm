//
// Created by mariu on 8/20/2017.
//

#include "SubsetUtil.h"

int SubsetUtil::findSubset(Subset *subsets, int i) {
    if(subsets[i].parent != i)
        subsets[i].parent = findSubset(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void SubsetUtil::unionSubsets(Subset *subsets, int i, int j) {
    int iRoot = findSubset(subsets, i);
    int jRoot = findSubset(subsets, j);

    if(subsets[i].rank < subsets[j].rank)
        subsets[i].parent = jRoot;
    else if(subsets[i].rank > subsets[j].rank)
        subsets[j].parent = iRoot;
    else {
        subsets[jRoot].parent = iRoot;
        subsets[iRoot].rank++;
    }
}