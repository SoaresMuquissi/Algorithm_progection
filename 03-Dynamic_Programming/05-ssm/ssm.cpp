#include <iostream>
#include <vector>

using namespace std;

int ssm(int *v, int size) {


    vector <int> memory(size, -1);
    int index;
    memory[1] = v[1];

    for(index = 2; index <= size; ++index) {

        if(memory[index -1] > 0) {

            memory[index] = memory[index -1] + v[index];

        } else {

            memory[index] = v[index];
        }
    }

    int max = memory[1];
    for(index = 2; index <= size ; ++index)
        if(max < memory[index])
            max = memory[index];

    return max;        
}


int main(int argc, char const *argv[])
{
    int n = 6;
    int v[n + 1];

    v[1] = -10;
    v[2] = 2;
    v[3] = 3;
    v[4] = -1;
    v[5] = 2;
    v[6] = -3;

    cout << "the ssm is : " << ssm(v, n) << endl;
    return 0;
}
