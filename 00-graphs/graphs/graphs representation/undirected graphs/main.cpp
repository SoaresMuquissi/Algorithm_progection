#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;


class Graphs {

    private:
        int V;
        vector< vector<int>> adj;

    public:
        Graphs(int v) {

            this->V = v;
            vector<int> row;

            for(int i =0; i < v ; ++i) {

                adj.push_back(row);
            }
        }

        void addEdge(int source, int dest){

            adj[source].push_back(dest);
            adj[dest].push_back(source);
        }     

        void printGraphs(){

            for(int i =0; i < V; ++i) {

                cout << "\n Adjacency list of vertex " << i << " \n head  ";
                for(auto x : adj[i])
                    cout << " -> " << x;

                cout << endl;      
            }
        }
};


int main(int argc, char const *argv[])
{
    
    Graphs *g = new Graphs(5);
    g->addEdge(0, 1);
    g->addEdge(0, 4);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(2, 3);
    g->addEdge(3, 4);
    g->printGraphs();
    return 0;
}
