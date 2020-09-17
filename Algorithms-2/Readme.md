Algorithms-2 : Design and Analysis of Algorithms

## **Part 1 : Greedy Algorithms** <br>
* **Shortest path Routing** :
  * Example Application - **Internet** is a graph with routers and endpoints, **Web graphs** - Webpages are vertices, links are edges
  * Internet routing almost always has multiple hops. Dijkstra's algorithm is a shortest path algorithm that works with non-negative edge lengths.
  But each node needs to have information about all the nodes in the graph. For an application such as the internet, where the graph size is huge, this would be highly inefficient.
  **There is a need to restrict computations to be performed locally, and yet make it possible to converge on the desired result**
  * **Bellman-Ford algorithm** solves this problem(also for negative edge lengths)
  * Sequence Matching is another application : Finding out how similar two strings are. Apply penalties for added balnk spaces and mismatches in characters. The objective is to minimize the sum of all penalties(termed as the **Needleman-Wunsch score**). two strings would be similar when they have a small NW score
  * **Greedy Algorithms** : Makes myopic decisions, easy to propose, but hard to prove correctness. **Most Greedy Algorithms are not correct**
    * **Optimal Caching Algorithm(Furthest-in-future)** helps us understand the basis of greedy algorithms. Future events are unknown, hence an implementable solution would be to look at the past and decide on data eviction using that information. **Least Recently Used** Cache works this way
    * **Scheduling Algorithms** : Defining optimal schedules for processes, so as to minimize the cost or penalty
    
    * **Minimum Spanning Trees** : Connecting a set of points as cheaply as possible. The MST should not have any cycles. Additionally, it has to span all vertices of the graph. 
 
