# **Algorithms-2 : Design and Analysis of Algorithms**

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
    
    * **Minimum Spanning Trees** : Connecting a set of points as cheaply as possible. The MST should not have any cycles. Additionally, it has to span all vertices of the graph.<br>
    **Prim's algorithm** is an efficient way to create a minimum spanning tree from a graph. **The naive implementation(like Djikstra's) has running time O(m * n)**, where m is the number of edges and n is the number of vertices. Fast implementation of Prim's algorithm makes use of heaps, where minimum edge costs to the vertices that are already visited is stored in the heap. This has a running time of O(m + log(n)). <br>
    **Kruskal's Algorithm** is another MST algorithm. First, sort all edges according to their edge costs. Iterate over all edges and add them to the MST if there are no cycle creations because of the edge being added. **Naive implementation has a running time of O(m * n)**. using the **Union Find data structure**, the cycle checks can be completed in constant time, thereby reducing the running time of Kruskal's algorithm to O(m * log(n))
    * **Clustering** : Classification into coherent groups, by looking for patterns in data. This is similar to Kruskal's algorithm, except for the fact that clustering is stopped once 'k' clusters are formed. The objective here is to maximize the minimum spacing. Spacing here refers to the distance between individual clusters.<br>
    Union-Find Data structure : <br>
     * [**Lazy Unions**]() -> The leader of a cluster is made to point to the leader of the other cluster while merging, without changing pointer on any of the other nodes. Merging operation can be done in constant time, with two find operations.
     * **Union by Rank** -> If the root node while performing a union operation is arbitrarily chosen, the tree structure that is formed can be one-sided, which results in linear-time find operations(bad!). Instead, each node keeps track of its rank(Maximum number of hops needed to get to the node from a leaf node). The two leader nodes of two clusters are obtained using the find method. The new leader node is the one which has a bigger rank.
    
    
 
