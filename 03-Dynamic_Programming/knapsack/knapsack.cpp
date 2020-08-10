#include <iostream>
#include <vector>

using namespace std;
int knapsack(vector<int> profit , vector<int> weight, int m,  int n)
{
    int n_rows = n + 1;
    int n_cols = m + 1;

    //vector<vector<int> > memory(n_rows,   vector<int>(n_cols, 0));
    int memory[n_rows][n_cols];
    for(int i =0; i <= n_rows; ++i) {
        for(int w =0; w < n_cols; ++w) {

            if( w == 0 || i ==0)
                memory[i][w] = 0;

            else if(weight[i] <= w) 
                memory[i][w] = max(profit[i] + memory[i -1][w - weight[i]], memory[i-1][w]);

            else
                memory[i][w] = memory[i-1][w];        

        }
    } 

    return memory[n_rows-1][n_cols -1];
}



int main(int argc, char const *argv[])
{
    int m = 8;
    int n = 4;
    vector<int> p;

    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    p.push_back(5);
    p.push_back(6);

    vector<int> w;

    w.push_back(0);
    w.push_back(2);
    w.push_back(3);
    w.push_back(4);
    w.push_back(5);

     cout << "ptofit is: " << knapsack(p, w, m, n ) << endl;
    return 0;
}
