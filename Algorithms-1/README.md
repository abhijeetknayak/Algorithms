# Algorithms
Stanford Course on Algorithms
https://lagunita.stanford.edu/courses/course-v1:Engineering+Algorithms1+SelfPaced/course/

* Divide and Conquer Approach to solve problems : Merge Sort, Strassen's Sub-cubic Matrix Multiplication, Closest points, Quick Sort
* Time Analysis of algorithms : Can we do better?
* Master Method to analyse running time of Algorithms
* Graphs - Minimum cuts using Random Contraction. Code included
  * Graph Search : <br>
    * Breadth-First Search : Add neighbors of explored node to the frontier. Every iteration, remove a node from the frontier and add its neighbors to the frontier. Start at the source node and continue till either all the nodes are traversed or if the destination node is reached(FIFO)
    * Depth-First Search : Add neighbors of explored node to the frontier. Every iteration, remove the last inserted node from the frontier and add its neighbors to the frontier. This uses a Stack, which follows the principle of Last-In-First-Out(LIFO)
* Strongly Connected components using Kosaraju's Algorithm : <br>
  * 
* Mother Vertex in a graph : A vertex that has a directed path to all the other vertices. <br>
  * 
* Tree Data Structure : Hierarchical Data Structure
  * Binary tree : A node has two child nodes, a left child and a right child.
  * Types of binary trees : 
    * Full Binary tree : A node has 0 or 2 children
    * Complete Binary tree : All levels are filled, except maybe the last one
    * Perfect Binary tree : All levels are filled
    * Balanced Binary tree : Maintain the O(log n) invariant after every operation on the tree
    * Degenerate Trees : Every node has a single child
* Dijkstra's Shortest path algorithm
* Two-Sum problem via hash table. Actually slow :(
* Heap class implementation with insert and extract-min functions

