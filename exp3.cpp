#include <iostream>
#include <list>
using namespace std;
class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};
// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}
// Add edges to the graph
void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::BFS(int startVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
    list<int> queue;
    visited[startVertex] = true;
    queue.push_back(startVertex);
    list<int>::iterator i;
    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop_front();
        for (i = adjLists[currVertex].begin(); i !=
                                               adjLists[currVertex].end();
             ++i)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
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
    myGraph.BFS(traverFrom);
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