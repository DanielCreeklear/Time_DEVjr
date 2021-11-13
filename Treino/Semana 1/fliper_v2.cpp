#include <iostream>
#include <vector>

#define MAX_NODES 1000
#define nodeP 0
#define nodeR 1
#define nodeA 2
#define nodeB 3
#define nodeC 4

using namespace std;

vector <int> adj[MAX_NODES];
int parent[MAX_NODES];
bool isRightP, isRightR;
int answer;

void dfs(int node)
{
    if (adj[node].empty())
    {
        answer = node;
    }
    else
    {
        for (auto nextNode: adj[node])
        {
            if (parent[nextNode] != -1) continue;
            parent[nextNode] = node;
            dfs(nextNode);
        }
    }
}

int main()
{
    for (int i = 0; i < MAX_NODES; i++) parent[i] = -1;
    cin >> isRightP >> isRightR;

    if (isRightP)
    {
        adj[nodeP].push_back(nodeR);
    }
    else
    {
        adj[nodeP].push_back(nodeC);
    }

    if (isRightR)
    {
        adj[nodeR].push_back(nodeA);
    }
    else
    {
        adj[nodeR].push_back(nodeB);
    }

    dfs(nodeP);

    switch (answer)
    {
        case nodeA:
            cout << "A";
            break;
        
        case nodeB:
            cout << "B";
            break;

        case nodeC:
            cout << "C";
            break;

        default:
            cout << "Error";
            break;
    }
    return 0;
}