#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

vector <int> adj[MAXN];
int Q, t, x, pai[MAXN], ultimoNascido = 0, reiAtual = 0;
bool morreu[MAXN];

void dfs(int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> Q;

    for(int i = 0; i < Q; i++) pai[i] = -1;
	int root = 0;
	pai[root] = root;

    for (int i = 0; i < Q; i++)
    {
        cin >> t >> x;
        x--;
        if (t == 1)
        {
            // vertice x teve um filho
            ultimoNascido++;
            cout << "A pessoa " << x + 1 << " teve um filho " << ultimoNascido + 1 << endl;
            adj[x].push_back(ultimoNascido);
            pai[ultimoNascido] = x;
        }
        else if (t == 2)
        {
            // vertice x morreu
            morreu[x] = true;

            if (x == reiAtual)
            {
                cout << "O rei " << x + 1 << " morreu. Seus filhos sao: ";
                if (adj[reiAtual].empty())
                {
                    cout << "Rei atual " << reiAtual + 1 << " nao possui filho!" << endl;

                    bool achouNovoRei = false;
                    int paiRei;
                    while (!achouNovoRei)
                    {
                        paiRei = pai[reiAtual];
                        bool todosMorreram = true;
                        int maisVelho = INT_MAX, maisVelhoMorto = INT_MAX;

                        cout << "Verificando seus irmaos, filhos do pai " << paiRei << endl;
                        for (auto irmao: adj[paiRei])
                        {
                            if (!morreu[irmao])
                            {
                                cout << "Achamos alguem q nao morreu, irmao " << irmao + 1 << endl; 
                                todosMorreram = false;
                                if (irmao < maisVelho) maisVelho = irmao;
                            }
                            else
                            {
                                if (irmao < maisVelhoMorto) maisVelhoMorto = irmao;
                            }
                        }
                        if (!todosMorreram)
                        {
                            reiAtual = maisVelho;
                            achouNovoRei = true;
                            cout << "Achamos o novo rei: " << reiAtual << endl;
                        }
                        else
                        {
                            cout << "Todos seus irmaos morreram!" << endl;
                            if (paiRei == 0)
                            {
                                paiRei = maisVelhoMorto;
                            }
                            else
                            {
                                paiRei = pai[paiRei];
                            }
                        }
                    }
                }
                else
                {
                    for (auto filho: adj[reiAtual])
                    {
                        cout << "Filho " << filho + 1 << ",";
                    }
                    cout << endl;

                    int maisVelho = INT_MAX, maisVelhoMorto = INT_MAX;
                    bool todosMorreram = true;

                    for (auto filho: adj[reiAtual])
                    {
                        if (!morreu[filho]) 
                        {
                            cout << "Filho " << filho + 1 << " nao morreu!" << endl;
                            todosMorreram = false;
                            if (filho < maisVelho) maisVelho = filho;
                            cout << "Por enqaunto o filho mais velho e " << maisVelho + 1 << endl;
                        }
                    }

                    if (todosMorreram)
                    {
                        cout << "todo morreram!" << endl;
                    }
                    else
                    {
                        cout << "temos um prox rei" << endl;
                        reiAtual = maisVelho;
                    }

                }
            }
            cout << "Rei atual = " << reiAtual + 1 << endl;
        }
    }

    dfs(reiAtual);

    //for (int i = 1; i < ultimoNascido + 1; i++) cout << "Pai do filho " << i + 1 << " = " << pai[i] + 1 << endl;
    return 0;
}

void dfs(int v)
{
	for(auto x: adj[v])
    {
		if(pai[x] != -1) continue;
		pai[x] = v;
		dfs(x);
	}
}