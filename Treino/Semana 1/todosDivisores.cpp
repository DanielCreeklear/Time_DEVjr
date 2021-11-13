#include <iostream>

using namespace std;

int X;

int main()
{
    cin >> X;
    for (int i = 0; i <= X; i++)
    {
        if (i > 0)
        {
            int remainingDivision = X % i;
            if (!remainingDivision)
            {
                cout << i << " ";
            }
        }
    }
    return 0;
}