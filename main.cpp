#include <stdio.h>

#include "Graph.h"

// main function, reads the input and creates Graph objects
// calls the printProperties function for each graph
int main() {
    int graphCount, graphSize, listSize, vertex;

    scanf("%d", &graphCount);
    for(int i=0; i<graphCount; i++){
        scanf("%d", &graphSize);
        Graph currentGraph(graphSize);
        for(int j=0; j<graphSize; j++){
            scanf("%d", &listSize);
            currentGraph.setDegree(j, listSize);
            for(int k=0; k<listSize; k++){
                scanf("%d", &vertex);
                currentGraph.addEdge(j, vertex);
            }
        }
        currentGraph.printProperties();
    }

    return 0;
}

// Sources:
// Introduction to Algorithms, Fourth Edition, T. Cormen, Ch. Leiserson, R. Rivest, C. Stein (e.g. 2.3.1 Divide-and-Conquer)
// Lecture by dr eng. K. Manuszewski (e.g. DFS, BFS)