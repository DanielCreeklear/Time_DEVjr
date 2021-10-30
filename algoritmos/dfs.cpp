#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

vector <int> adj[MAXN];

int pai[MAXN];

void dfs(int v)
{
	for(auto x: adj[v])
    {
		if(pai[x] != -1) continue;
		pai[x] = v;
		dfs(x);
	}
}

int main()
{
	for(int i = 0; i < MAXN; i++) pai[i] = -1;
	int root = 0;
	pai[root] = root;
}
