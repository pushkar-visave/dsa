#include <iostream>
using namespace std;

class Graph
{
    int n;
    char name[10][20];
    int g[10][20];

public:
    void creatgraph();
    void display();
    void prims();
};

void Graph::creatgraph()
{
    int edg, i, j, u, v, wt;
    cout << "\nEnter total number of Cities : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cout << "Enter City Name : ";
        cin >> name[i];
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            g[i][j] = 0;
        }

    cout << "\nEnter total number of Edges : ";
    cin >> edg;

    for (i = 1; i <= edg; i++)
    {
        cout << "\nEnter vertices for edge [" << i << "]"
             << "and its widht ";
        cin >> u >> v >> wt;
        if (u <= n && v <= n)
        {
            g[u][v] = wt;
            g[v][u] = wt;
        }
    }
}
void Graph::display()
{
    int i, j;
    cout << "\n\t";
    for (i = 1; i <= n; i++)
    {
        cout << name[i] << "\t";
    }
    cout << "\n";
    for (i = 1; i <= n; i++)
    {
        cout << name[i] << "\t";
        for (j = 1; j <= n; j++)
        {
            cout << g[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Graph::prims()
{
    int dist[10], from[10];
}

int main()
{
    int ch;
    Graph g1;
    do
    {
        cout << "\n0.Exit\n1.Create Graph\n2.Display Graph\n3.DIsplay With Prims------------------";
        cout << "\nEnter your choice : ";
        cin >> ch;
        cout << "------------------";
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            g1.creatgraph();
            break;
        case 2:
            g1.display();
            break;
        case 3:
            g1.prims();
            break;
        default:
            cout << "Invalid Input";
        }
    } while (ch < 3);
    return 0;
}
