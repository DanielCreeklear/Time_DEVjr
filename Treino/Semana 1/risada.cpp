#include <iostream>

using namespace std;

string risada, risadaVogais;
char answer = 'S';

int main()
{
    cin >> risada;

    for (auto caracter: risada)
    {
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') risadaVogais.push_back(caracter);
    }

    int i, j;
    i = 0;
    j = risadaVogais.length() - 1;

    while (i < j)
    {
        if (risadaVogais[i] != risadaVogais[j])
        {
            answer = 'N';
            break;
        }
        i++;
        j--;
    }

    cout << answer;
    return 0;
}