#include <cstddef>
#include <iostream>
#include <vector>


using namespace std;


void fibo(int n) {

    vector<int> memorization(n, -1);

    if(n <= 1)
        return;

    memorization[0] = 0;
    memorization[1] = 1;

    for(int index = 2 ;index <= n ; ++index) {

        memorization[index] = memorization[index - 2] + memorization[index - 1];
    }    

    int value =1;

    cout << "sequence is  : ";
    for(int i = 0; i <= n ; ++i) {

        cout << " " << memorization[i];
    }
}


int main(int argc, char const *argv[])
{
    fibo(11);
    cout << endl;
    return 0;
}
