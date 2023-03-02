// C++ Playground
// Written by: Preston Roesslet

#include <iostream>

using namespace std;

int main()
{

    int *y = new int[10];
    y[0] = 99;
    cout << y[0] << endl;
    delete[] y;

    return 0;
}