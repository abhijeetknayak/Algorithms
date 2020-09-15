import random
import copy

num = open('karger.txt', 'r')
lines = num.readlines()
counter = 0
numbers = []

graph = {}
for line in lines:
    vertex = [int(x) for x in line.split()]
    graph[vertex[0]] = vertex[1:]

def merge_graph(graph, u, v):
    vertex = []
    if u != v: # Defensive Code
        # Extracting all nodes that are connected to u and v
        vertices = graph[u] + graph[v]
        for i in vertices:
            if i == u or i == v: # Removing Self Loops
                continue
            else:
                vertex.append(i)
                # Modifying other graph keys values(Removing 'v' node from them)
                edge_len = len(graph[i])
                for k in range(edge_len):
                    if graph[i][k] == v:
                        graph[i][k] = u
                        break
        # Finally removing v
        graph.pop(v)
        # Assigning values to key u
        graph[u] = vertex
    return graph

def random_contraction(graph, min_trials):
    min_count = 200
    # Over a number of trials
    for i in range(min_trials):
        # Deep copying the graph to create actual copies without modifying the actual graph
        graph_copy = copy.deepcopy(graph)
        while len(graph_copy) > 2:
            u = random.choice(list(graph_copy.keys()))
            v = random.choice(graph_copy[u])
            # Final contracted graph. Only Two Keys left
            graph_copy = merge_graph(graph_copy, u, v)
        # Finding Minimum Cut ---> Number of edges between the final nodes
        if len(graph_copy[random.choice(list(graph_copy.keys()))]) < min_count:
            min_count = len(graph_copy[random.choice(list(graph_copy.keys()))])
    print(min_count)

# 15 trials ?
random_contraction(graph, 15)