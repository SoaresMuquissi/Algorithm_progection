#include <c++/7/bits/c++config.h>
#include <cstdint>
#include <iostream>
#include <vector>
#include<queue>
#include <climits>


using namespace std;


class dikjstra
{
private:
    /* data */
    int V;
    vector< vector< pair<int, int>>> adj;

public:

    dikjstra(int V) {

        this->V = V;
        vector<pair<int, int>> row;

        for(int i = 1; i <= this->V; ++i){

            adj.push_back(row);


        }
    }

    void addEdge(int source, int dest, int weight) {

        adj[source].push_back(make_pair(dest, weight));
    }


    void _dikjstra(int source) {

        vector<int> distance(V, INT_MAX);
        priority_queue<int, vector<int> , greater<int> > queue_p;

        distance[source] = 0;
        queue_p.push(source);

        for(auto x : adj[source]){

            queue_p.push(x.first);
            distance[x.first] = x.second;
        }

        while(!queue_p.empty()) {

            int get_data = queue_p.top();
            queue_p.pop();
            for(auto nod : adj[get_data]) {


                if(distance[nod.first] > distance[get_data] + nod.second) {

                    distance[nod.first] = distance[get_data] + nod.second;
                    queue_p.push(nod.first);
                }
               
            }

            
        }

        for(int i =1 ; i <= 6; ++i){

            cout << " " << distance[i];
        }

        cout << endl;
    
    }

};

int main(int argc, char const *argv[])
{
    dikjstra *g = new dikjstra(6);
   
    g->addEdge(1, 2, 1);
    g->addEdge(1, 3, 2);
    g->addEdge(1, 6, 3);
    g->addEdge(3, 4, 5);
    g->addEdge(3, 5, 8);
    g->addEdge(4, 6, 6);
    g->addEdge(5, 1, 7);
    g->addEdge(5, 4, 4);
    g->addEdge(6, 1, 4);
    g->addEdge(6, 5, 4);

    g->_dikjstra(1);
 
    return 0;
}
