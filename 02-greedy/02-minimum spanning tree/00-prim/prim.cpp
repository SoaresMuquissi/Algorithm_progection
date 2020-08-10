#include <cstdio>
#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

typedef struct Node {

    pair<int, int> data;
    Node *left;
    Node *right;


}Node;

Node *newNode(pair<int, int> data) 
{
    /*Node *newNode = (Node*)malloc(sizeof(Node));*/

    Node *newNode = new Node;
    
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    
    return newNode;

}

Node  *insert(Node *root, pair<int , int> data)
{
    Node *data_insert = newNode(data);

    Node *_root_aux = root;
    Node *trailing = nullptr;

    while( _root_aux != nullptr) {

        trailing = _root_aux;

        if(_root_aux->data.first > data.first)
            _root_aux = _root_aux->left;

        else
            _root_aux = _root_aux->right;    
    }


    if(trailing == nullptr)
        trailing = data_insert;

    else if(trailing->data.first > data.first)
        trailing->left = data_insert;

     else {

         trailing->right = data_insert;

     }       
    
    return trailing;
}


class Prim {
    
    private:
        int V;
        vector<vector<pair<int, int> > > adj;

    public:
        Prim(int V) {

            this->V = V;
            vector<pair<int, int>> row;

            for(int i =1; i <= this->V; ++i) {
                adj.push_back(row);
            }
        }

        void addEdge(int source, int dest, int weight) {

            adj[source].push_back(make_pair(dest, weight));
            adj[dest].push_back(make_pair(source, weight));
        }

        void prinm(pair<int, int> source)
        {
            int custo =0;
            priority_queue<pair<int, int>, vector<pair<int, int>> , greater< pair<int, int> > > minHeap;

            vector<int> nods(V, INT_MAX); /*at the beginning all nodes have infinite distance*/
            vector<int> parents(V, -1); 
            vector<bool> MST(V, false);

            minHeap.push(source);

            nods[source.first] =0;

            while(!minHeap.empty()) {

                pair<int, int> nod = minHeap.top();
                minHeap.pop();

                MST[nod.first] = true;
                for(auto x : adj[nod.first]) {

                    int nod_adj  = x.first;
                    int weith = x.second;

                    if(MST[nod_adj] == false && nods[nod_adj] > weith) {

                        nods[nod_adj] = weith;
                        parents[nod_adj] = nod.first;
                        custo = custo + weith;
                        minHeap.push(x);

                    }
                }
            }
            
            for(int i=1; i<= V ; ++i) {

                cout << i << " --- " << parents[i] << endl;
            }

            cout << "total cost is : " << custo << endl;
            
        }


};


int main(int argc, char const *argv[])
{
    /* code */

    Prim *g = new Prim(12);

    g->addEdge(1, 2, 9);
    g->addEdge(1, 7, 2);
    g->addEdge(1, 9, 3);
    g->addEdge(2, 3, 5);
    g->addEdge(2, 7, 8);
    g->addEdge(4, 3, 8);
    g->addEdge(4, 6, 9);
    g->addEdge(5, 6, 2);
    g->addEdge(9, 10, 5);
    g->addEdge(9, 12, 8);
    g->addEdge(10, 11, 2);
    g->addEdge(11, 12, 7);

    g->prinm(make_pair(1, 0));

    return 0;
}
