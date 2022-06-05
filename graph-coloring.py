#-*- coding> utf-8 -*-

def addEdge(adj, v, w):
    adj[v].append(w)
    adj[w].append(v)
    return adj

#graph coloring algorithm
def graphColoring(adj, V):
    result = [-1] * V

    available = [False] * V

    # Assign the first color to first vertex
    result[0] = 0

    # Assign colors to remaining V-1 vertices
    for u in range(1, V):

        # Process all adjacent vertices and flag their colors as unavailable
        for i in adj[u]:
            if (result[i] != -1):

                available[result[i]] = True

        # Find the first available color
        color = 0
        while color < V:
            if (available[color] == False):

                result[u] = color
                break

            color += 1

        # Reset the values back to false
        for i in adj[u]:
            if (result[i] != -1):

                available[result[i]] = False

    # Print the result
    for u in range(V):
        
        print("Vertex", u, " ->  Color", result[u])


if __name__ == '__main__':
    graph = [[] for i in range(5)]
    graph = addEdge(graph, 0, 1)
    graph = addEdge(graph, 0, 2)
    graph = addEdge(graph, 1, 2)
    graph = addEdge(graph, 1, 3)
    graph = addEdge(graph, 2, 3)
    graph = addEdge(graph, 3, 4)
    graphColoring(graph, 5)
