// A C++ program to implement greedy algorithm for graph coloring
#include <iostream>
#include <list>
using namespace std;

//class Graph
class Graph 
{
    int V;
    list<int> *adj;
public:
    
    // Constructor and destructor
    Graph(int V) 
    {

        this->V = V;

        adj = new list<int>[V];
    }

    ~Graph() 
    { 
        delete[] adj; 
    }

    //add edge method
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);

        adj[w].push_back(v); 
    }

    //graph coloring method
    void graphColoring()
    {
        int result[V];

        bool available[V];

        // Initialize all vertices as unassigned
        for (int u = 1; u < V; u++)
        {
            result[u] = -1; 

            available[u] = false;
        }

        // assign the first color
        result[0] = 0;

        // Assign colors to remaining V-1 vertices
        for (int u = 1; u < V; u++)
        {
            // Process all adjacent vertices and flag their colors as unavailable
            list<int>::iterator i;

            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {

                if (result[*i] != -1) 
                    {
                        available[result[*i]] = true;
                    }
            }

            // Find the first available color
            for (int color = 0; color < V; color++) 
            {
                if (available[color] == false) 
                {
                    result[u] = color; 
                    break;
                }
            }

            // Reset the values back to false for the next iteration
            for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            {
                if (result[*i] != -1) 
                {
                    available[result[*i]] = false;
                }
            }
        }

        // print the result
        for (int u = 0; u < V; u++) 
        {
            cout << "Vertex " << u << " ->  Color " << result[u] << endl;
        }
    }
};

int main()
{
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.graphColoring();

    return 0;
}