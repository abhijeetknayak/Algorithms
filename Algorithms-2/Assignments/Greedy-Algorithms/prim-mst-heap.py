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
        self.size += 1
        self.values.append(x)

        index = self.size - 1
        while self.values[index].cost < self.values[index // 2].cost:
            self.swap_element(index, index // 2)
            index = index // 2

    def maintain_heap(self):
        pass

    def extract_min(self):
        min_val = self.values[0]
        self.values[0] = self.values[self.size - 1]
        self.size -= 1

        self.maintain_heap()


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

    heap = Heap()
    heap.insert(Edges(1, 2, 5))
    heap.insert(Edges(1, 2, 4))
    heap.insert(Edges(1, 2, 1))
    heap.insert(Edges(1, 2, -10))
    heap.insert(Edges(1, 2, 34))

    print(heap.values[0].cost)


