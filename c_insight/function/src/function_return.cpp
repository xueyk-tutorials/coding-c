#include <iostream>
using namespace std;

void hack() {
    cout << "**********hack*********" << endl;
}
void test()
{
    cout << "test" << endl;
    long a[2];
    a[0] = 1;
    a[1] = 2;

    long *p = a;
    *(p+3) = (long)&hack;
}
int main()
{
    test();
}