
def read_file():
    graph = {}
    num = open('dijkstra.txt', 'r')
    lines = num.readlines()
    for line in lines:
        nodes = [x for x in line.split()]
        if nodes[0] in graph:
            graph[nodes[0]] = graph[nodes[0]] + nodes[1:]
        else:
            graph.setdefault(int(nodes[0]), nodes[1:])

    for key in graph.keys():
        values = [tuple(map(int, val.split(','))) for val in graph[key]]
        graph[key] = values

    return graph

graph = read_file()
print(graph)

x = [1]
dist = {1:0}
# Naive
while len(x) < 200:
    minVal = 100000
    minNode = 201
    for node in x:
        for subnode in graph[node]:
            if subnode[0] not in x:
                if dist[node] + subnode[1] < minVal:
                    minNode = subnode [0]
                    minVal = dist[node] + subnode[1]

    x.append(minNode)
    dist[minNode] = minVal

print(dist[7])
print(dist[37])
print(dist[59])
print(dist[82])
print(dist[99])
print(dist[115])
print(dist[133])
print(dist[165])
print(dist[188])
print(dist[197])

# Implement Heap Based Version of this? How?




