#include <iostream>

using namespace std;

int main()
{
    bool p, r;

    cin >> p >> r;

    if (!p)
    {
        cout << "C";
    }
    else
    {
        if (!r)
        {
            cout << "B";
        }
        else
        {
            cout << "A";
        }
    }
}