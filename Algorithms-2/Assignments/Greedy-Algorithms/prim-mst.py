class Edges:
    def __init__(self, start, end, cost):
        self.start = start
        self.end = end
        self.cost = cost

def process_file(fp):
    graph = []
    N, M = [int(x) for x in fp.readline().split(' ')]  # Number of nodes, edges
    for idx in range(M):
        edge_info = [int(x) for x in fp.readline().split(' ')]
        graph.append(Edges(edge_info[0], edge_info[1], edge_info[2]))

    return graph





if __name__ == '__main__':
    fp = open('edges.txt')
    graph = process_file(fp)

    print(len(graph))