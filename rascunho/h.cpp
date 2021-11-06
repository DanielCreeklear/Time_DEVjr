#include <bits/stdc++.h>

#define NUMERO first
#define COR second

using namespace std;

typedef pair<int,int> pii;
vector <pii> matriz;
vector <pii> matriz2;
vector <vector <int>> coresOrdenadas;

int N, K;
char resposta = 'Y';

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> K;

    for (int i = 0; i < N; i++) 
    {
        int n, c;
        cin >> n >> c;
        matriz.push_back({n, c});
    }

    for (int cor = 1; cor < K + 1; cor++)
    {
        vector <int> numerosDaCor;

        for (auto x: matriz)
        {
            if (x.COR == cor) numerosDaCor.push_back(x.NUMERO);
        }

        sort(numerosDaCor.begin(), numerosDaCor.end());

        coresOrdenadas.push_back(numerosDaCor);
    }


    for (auto item: matriz)
    {
        auto i = coresOrdenadas.begin();
        i += item.COR - 1;
        auto valorExcluir = (*i).begin();

        item.NUMERO = *valorExcluir;
        matriz2.push_back(item);
        (*i).erase(valorExcluir);
    }

    vector <int> numeros;
    vector <int> numerosOriginal;

    for (auto x: matriz2)
    {
        numeros.push_back(x.NUMERO);
        numerosOriginal.push_back(x.NUMERO);
    }

    sort(numeros.begin(), numeros.end());

    int i = 0;
    auto iOriginal = numerosOriginal.begin();
    for (int n: numeros)
    {
        if (n != *(iOriginal + i))
        {
            resposta = 'N';
            break;
        }
        i++;
    }

    cout << resposta;
    return 0;
}