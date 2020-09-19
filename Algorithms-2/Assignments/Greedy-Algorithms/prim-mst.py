class Edges:
    def __init__(self, start, end, cost):
        self.start = start
        self.end = end
        self.cost = cost

def process_file(fp):
    graph = []
    node = set()
    N, M = [int(x) for x in fp.readline().split(' ')]  # Number of nodes, edges
    for idx in range(M):
        edge_info = [int(x) for x in fp.readline().split(' ')]
        node.add(edge_info[0])
        node.add(edge_info[1])
        graph.append(Edges(edge_info[0], edge_info[1], edge_info[2]))

    return graph, node

def traverse_node(X, graph):
    min_cost = float("inf")
    min_edge = None
    for e in graph:
        if (e.start in X and e.end not in X)  \
                or (e.end in X and e.start not in X):
            if e.cost < min_cost:
                min_cost = e.cost
                min_edge = e

    return min_edge

def create_mst(graph, node):
    X = set()
    min_cost = float("inf")
    min_edge = None
    for edge in graph:
        if edge.cost < min_cost:
            min_cost = edge.cost
            min_edge = edge
    X.add(min_edge.start)
    X.add(min_edge.end)

    edge_list = [min_edge]
    print(min_edge.start, min_edge.end)

    while len(X) != len(node):
        min_edge = traverse_node(X, graph)
        X.add(min_edge.start)
        X.add(min_edge.end)
        edge_list.append(min_edge)
        print(min_edge.start, min_edge.end)

    return edge_list

def get_total_cost(edge_list):
    cost = 0
    for edge in edge_list:
        cost += edge.cost
    return cost

if __name__ == '__main__':
    fp = open('edges.txt')
    graph, node = process_file(fp)

    edge_list = create_mst(graph, list(node))
    print(len(edge_list))

    print(get_total_cost(edge_list))