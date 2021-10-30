#include <bits/stdc++.h>
using namespace std;

#define MAXV 1001000  
typedef pair<int,int> pii;

int n,distancia[MAXV];
vector<pii> adj[MAXV];

void dijkstra(int fonte)
{
	for(int i=0;i<=n;i++) distancia[i]=-1;
	set <pii> fila;
	fila.insert({0,fonte});

	pii aux;
	while(!fila.empty())
    {
		aux=*fila.begin();
		fila.erase(fila.begin());

		int vertice=aux.second;
		int distV=aux.first;

		if(distancia[vertice]!=-1) continue;

		distancia[vertice]=distV;

		for(auto vizinho: adj[vertice])
        {
			if(distancia[vizinho.first]!=-1) continue;
			fila.insert({vizinho.second+distV,vizinho.first});
		}
	}
}