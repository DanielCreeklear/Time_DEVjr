#include <iostream>

using namespace std;

int N;
int appearedNumber[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string number;
        cin >> number;
        for (auto digit: number)
        {
            int numberInt;
            numberInt = digit - '0';
            appearedNumber[numberInt]++;
        }
    }

    for (int i = 0; i < 10; i++) cout << i << " - " << appearedNumber[i] << endl;
    return 0;
}