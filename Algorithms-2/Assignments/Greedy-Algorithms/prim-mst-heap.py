class Edges:
    def __init__(self, start, end, cost):
        self.start = start
        self.end = end
        self.cost = cost

class Heap:
    def __init__(self):
        self.values = []
        self.size = 0

    def insert(self, x):
        pass

    def extract_min(self):
        min_val = self.values[0]

        # Maintain Heap
        return min_val

    def swap_element(self, pos1, pos2):
        self.values[pos1], self.values[pos2] = self.values[pos2], self.values[pos1]


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

def get_total_cost(edge_list):
    cost = 0
    for edge in edge_list:
        cost += edge.cost
    return cost

if __name__ == '__main__':
    fp = open('edges.txt')
    graph, node = process_file(fp)
