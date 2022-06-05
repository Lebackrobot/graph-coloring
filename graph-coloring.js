//Class Graph
class Graph 
{
    // Constructor
    constructor(v) 
    {
        this.V = v;

        this.adj = new Array(v);

        for(let i = 0; i < v; ++i) 

        {

            this.adj[i] = [];
            
        }
    }

    //add Edge method
    addEdge(v,w) 
    {
        this.adj[v].push(w);

         this.adj[w].push(v);
    }

    //Graph coloring method
    graphColoring() 
    {

        let result = new Array(this.V);
        
        let available = new Array(this.V);

        // Initialize all vertices as unassigned
        for(let i = 0; i < this.V; i++) 

        {

            result[i] = -1;

            available[i] = true;

        }

        //assign the first color
        result[0]  = 0;

        // Assign colors to remaining V-1 vertices
        for(let u = 1; u < this.V; u++) 

        {

            // Process all adjacent vertices and flag their colors as unavailable
            for(let it in this.adj[u]) 
        
            {
        
                let i = it;
        
                if (result[i] != -1) {
        
                    available[result[i]] = false;
        
                }
        
            }

            // Find the first available color
            for(let color = 0; color < this.V; color++) 

            {
                if (available[color]) 
                
                {

                    result[u] = color;

                    break;

                }
            }

            // Reset the values back to true
            for(let i = 0; i < this.V; i++) 
            {

                available[i] = true;

            }

        }

        // print the result
        for(let u = 0; u < this.V; u++) 

        {

            console.log(`Vertex ${u} ->  Color ${result[u]}`)

        }
    }
}

let graph = new Graph(5);
graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 2);
graph.addEdge(1, 3);
graph.addEdge(2, 3);
graph.addEdge(3, 4);
graph.graphColoring();