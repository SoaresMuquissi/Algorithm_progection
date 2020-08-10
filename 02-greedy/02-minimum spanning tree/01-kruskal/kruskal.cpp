#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


class Edge {

    public:
        int source;
        int dest;
        int weight;

};



class Graphs {

    private:

    public:
        int V;
        int E;
        Edge *edges;
        Graphs(int V, int E) {

            this->V = V;
            this->E = E;
            this->edges = new Edge[E];
        }
};

class set {

    public:
        int parent;
        int rank;
};


int find(set *subsets, int i) {

    if(subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }

    return subsets[i].parent;
}

void _union(int x, int y, set subsets[]){

    int x_root = find(subsets, x);
    int y_root = find(subsets, y);

    if(subsets[x_root].rank < subsets[y_root].rank) {
        subsets[x_root].parent = y_root;

    } else if(subsets[y_root].rank > subsets[y_root].rank) {
        subsets[y_root].parent = x_root;

    }else {
        subsets[y_root].parent = x_root;
        subsets[x_root].rank++;
    }
 }

 int cmp(const void *x, const void *y) {

     Edge *a1 = (Edge*)x;
     Edge *a2 = (Edge*)y;

     return a1->weight > a2->weight;

 }

 void Kruskal(Graphs *g) {

     Edge MST[g->V];
     int edge_index;
     int i;

     qsort(g->edges, g->E, sizeof(g->edges[0]), cmp);

     set *subsets = new set[(g->V*sizeof(subsets))];


     for(int nod = 1; nod <= g->V; ++nod) {

         subsets[nod].parent = nod;
         subsets[nod].rank = 0;
     }


     while(edge_index < g->V -1 &&  i < g->E) {

         Edge ed  = g->edges[i++];

         int x = find(subsets, ed.source);
         int y = find(subsets, ed.dest);

         if(x != y) {

             MST[edge_index++] = ed;
             _union(x, y, subsets);

         }
     }

     cout << "Edge  in constructed MST" << endl;
     for(int i = 1; i <= edge_index; ++i) {
         cout <<  MST[i].source << " ---- " << "==== " << MST[i].weight  << endl; 
     }
 }


 int main(int argc, char const *argv[])
 {
     int V = 12;
     int E = 15;
     Graphs *g = new Graphs(V, E);

     g->edges[1].source =1;
     g->edges[1].dest = 9;
     g->edges[1].weight = 3;

     g->edges[1].source = 1;
     g->edges[1].dest = 2;
     g->edges[1].weight = 9;

     g->edges[1].source = 1;
     g->edges[1].dest = 7;
     g->edges[1].weight = 2;

     g->edges[1].source = 1;
     g->edges[1].dest = 8;
     g->edges[1].weight  = 6;

     
     return 0;
 }
 