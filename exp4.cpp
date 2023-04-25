#include <iostream>
#include <list>
using namespace std;
class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};
// Initialize graph
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}
// Add edges
void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_front(dest);
}
// DFS algorithm
void Graph::DFS(int vertex)
{
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];
    cout << vertex << " ";
    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
int main()
{
    int totalEdge, traverFrom;
    cout << "enter total no. of edges " << endl;
    cin >> totalEdge;
    Graph myGraph(totalEdge);
    for (int i = 0; i < totalEdge; i++)
    {
        int source, destination;
        cout << "Enter source for " << i << " egde" << endl;
        cin >> source;
        cout << "Enter Destination for " << i << " egde" << endl;
        cin >> destination;
        myGraph.addEdge(source, destination);
    }
    cout << "Traverse from ??" << endl;
    cin >> traverFrom;
    myGraph.DFS(traverFrom);
    return 0;
}


/*
4
0
1
0
2
1
2
2
3
0
*/