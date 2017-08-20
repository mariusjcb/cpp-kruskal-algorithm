//
// Created by mariu on 8/20/2017.
//

#include "EdgeUtil.h"

int EdgeUtil::compareEdges(struct Edge *a, struct Edge *b) {
    return (int) (a->weight > b->weight);
}

int EdgeUtil::compare(const void *a, const void *b) {
    return compareEdges(
            (struct Edge*) a,
            (struct Edge*) b
    );
}