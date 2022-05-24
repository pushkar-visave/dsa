#include <iostream>
using namespace std;

class graph1
{
    int n;
    int G[10][10];
    int SPG[10][10];
    int visited[10];

public:
    void creategraph();
    void dfs(int);
    void prims();
};

void graph1::creategraph()
{
    int edg, i, j, u, v, wt;
    cout << "\n Enter total number of vertices for graph";
    cin >> n;
    cout << "\n Enter total number of edges";
    cin >> edg;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            G[i][j] = 9999;
            SPG[i][j] = 0;
        }

    for (i = 1; i <= edg; i++)
    {
        cout << "\n Enter vertices for edge[" << i << "]"
             << "and its weight";
        cin >> u >> v >> wt;
        if (u <= n && v <= n)
        {
            G[u][v] = wt;
            G[v][u] = wt;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << G[i][j] << "  ";
        }
        cout << "\n";
    }

    for (i = 1; i <= n; i++)
        visited[i] = 0;
}
void graph1::dfs(int v)
{
    visited[v] = 1;
    cout << v << "==";
    for (int i = 1; i <= n; i++)
    {
        if (G[v][i] == 1)
            if (visited[i] == 0)
                dfs(i);
    }
}
void graph1::prims()
{
    int distance[10], from[10];
    int cost = 0;
    visited[1] = 1;
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        distance[i] = G[1][i];
        from[i] = 1;
    }
    int edg = 0, min = 9999;
    int u, v;
    while (edg < n)
    {
        min = 9999;
        for (int i = 1; i <= n; i++)
        {
            if (distance[i] < min && visited[i] == 0)
            {
                min = distance[i];

                v = i;
            }
        }
        u = from[v];
        SPG[u][v] = distance[v];
        SPG[v][u] = 1;
        edg++;
        cost = cost + distance[v];
        visited[v] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (G[v][i] < distance[i] && visited[i] == 0)
            {
                distance[i] = G[v][i];
                from[i] = v;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << SPG[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "minimum cost is" << cost;
}

int main()
{
    int ch, v;
    graph1 g1;
    do
    {
        cout << "\n 1. CreateGraph";
        cout << "\n 2. print graph";
        cout << "\n 3. Prims";
        cout << "\n Enter your choice";
        cin >> ch;
        switch (ch)
        {
        case 1:
            g1.creategraph();
            break;
        case 2:
            cout << "\n Enter vertex number from which DFS to start";
            cin >> v;
            g1.dfs(v);
            break;
        case 3:
            g1.prims();
            break;
        }
    } while (ch < 4);
}