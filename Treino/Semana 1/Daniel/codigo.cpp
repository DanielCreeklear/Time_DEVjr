#include <iostream>

using namespace std;

int N, inputCode, codesFound = 0, digit = 0;
int digits[] = {1, 0, 0};

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> inputCode;
        if (inputCode == digits[digit])
        {
            if (digit == 2)
            {
                codesFound++;
                digit = 0;
            }
            else
            {
                digit++;
            }
        }
        else
        {
            if (inputCode == digits[0])
            {
                digit = 1;
            }
            else
            {
                digit = 0;
            }
        }
    }
    cout << codesFound;
    return 0;
}