Algorithms-2 : Design and Analysis of Algorithms

## **Part 1 : Greedy Algorithms** <br>
* **Shortest path Routing** :
  * Example Application - **Internet** is a graph with routers and endpoints, **Web graphs** - Webpages are vertices, links are edges
  * Internet routing almost always has multiple hops. Dijkstra's algorithm is a shortest path algorithm that works with non-negative edge lengths.
  But each node needs to have information about all the nodes in the graph. For an application such as the internet, where the graph size is huge, this would be highly inefficient.
  **There is a need to restrict computations to be performed locally, and yet make it possible to converge on the desired result**
  
