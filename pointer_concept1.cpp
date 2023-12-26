#include <iostream>
using namespace std;
int **check()
{
    int t, *p, **s;
    t = 100;
    p = &t;
    s = &p;
    return s;
}
int main()
{
    int **y = check();
    cout << **y;
}