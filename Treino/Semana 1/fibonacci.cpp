#include <iostream>
#include <stdlib.h>

using namespace std;

int *fibonacciCalculated;

int fibonacci(int n);

int main()
{
    int n;
    cin >> n;

    fibonacciCalculated = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) fibonacciCalculated[i] = -1;
    fibonacciCalculated[0] = fibonacciCalculated[1] = 1;

    cout << fibonacci(n);

    free(fibonacciCalculated);
    return 0;
}

int fibonacci(int n)
{
    if (fibonacciCalculated[n] != -1)
    {
        return fibonacciCalculated[n];
    }
    else
    {
        fibonacciCalculated[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return fibonacciCalculated[n];
    }
}