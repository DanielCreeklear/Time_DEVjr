#include <iostream>
#include <stdlib.h>

using namespace std;

int N;
int *sumColumns, *sumLines, sumMainDiagonal = 0, sumSecondaryDiagonal = 0;
int answer = -1;

int main()
{
    cin >> N;

    sumColumns = (int*)malloc(sizeof(int) * N);
    sumLines = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        sumColumns[i] = 0;
        sumLines[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int number;
            cin >> number;

            sumColumns[j] += number;
            sumLines[i] += number;

            if (i == j) sumMainDiagonal += number;
            if (j == N - 1 - i) sumSecondaryDiagonal += number;
        }
    }

    if (sumMainDiagonal == sumSecondaryDiagonal && sumMainDiagonal == sumColumns[0] && sumMainDiagonal == sumLines[0])
    {
        for (int i = 1; i < N; i++) 
        {
            if (sumColumns[i] != sumMainDiagonal || sumLines[i] != sumMainDiagonal) break;
            if (i + 1 == N) answer = sumMainDiagonal;
        }
    }
    cout << answer;
    return 0;
}