from tqdm import tqdm
import copy
num = open('SCC.txt', 'r')
lines = num.readlines()
counter = 0
numbers = []

graph = {}
for line in lines:
    nodes = [int(x) for x in line.split()]
    if nodes[0] in graph:
        graph[nodes[0]].append(nodes[1])
    else:
        graph.setdefault(nodes[0], [nodes[1]])

graph_copy = copy.deepcopy(graph)

class graph:
    def __init__(self):
        self.graph = {}
        self.graph_copy = {}
        self.graph_inv = {}
        self.ft = {}

    def initInputAssignment(self):
        num = open('SCC.txt', 'r')
        lines = num.readlines()
        for line in lines:
            nodes = [int(x) for x in line.split()]
            if nodes[0] in self.graph:
                self.graph[nodes[0]].append(nodes[1])
            else:
                self.graph.setdefault(nodes[0], [nodes[1]])

        self.graph_copy = copy.deepcopy(self.graph)

    def initInputTest(self):
        self.graph = {1:[2],2:[3],3:[4,6],4:[5],5:[1],6:[7,11],7:[8],8:[9],
                      9:[10],10:[7],11:[12],12:[13],13:[14],14:[15],15:[16],16:[6]}
        # test_graph = {7: [1], 5: [2], 9: [3, 7], 1: [4], 8: [5, 6], 3: [6], 4: [7], 2: [8], 6: [9]}
        self.graph_copy = copy.deepcopy(self.graph)

    def graph_inversion(self):
        for i in self.graph.keys():
            for j in self.graph[i]:
                if j not in self.graph_inv:
                    self.graph_inv.setdefault(j, [i])
                else:
                    self.graph_inv[j].append(i)

    def create_ft_graph(self, trans):
        for i in self.graph.keys():
            vertex = [trans[x] for x in self.graph[i]]
            if trans[i] not in self.ft:
                self.ft.setdefault(trans[i], vertex)
            else:
                self.ft[trans[i]] = self.ft[trans[i]] + vertex




def graph_inversion(graph):
    graph_inv = {}
    for i in graph.keys():
        for j in graph[i]:
            if j not in graph_inv:
                graph_inv.setdefault(j, [i])
            else:
                graph_inv[j].append(i)
    return graph_inv

# test_graph = {7: [1], 5: [2], 9: [3, 7], 1: [4], 8: [5, 6], 3: [6], 4: [7], 2: [8], 6: [9]}
# test_graph = {1:[2],2:[3],3:[4,6],4:[5],5:[1],6:[7,11],7:[8],8:[9],9:[10],10:[7],11:[12],12:[13],13:[14],14:[15],15:[16],16:[6]}
# graph_copy = copy.deepcopy(test_graph)




# Number of nodes processed so far
t = 0
# Current Source Vertex
s = None
explored = []
time = {}
leaders = {}



def create_ft_graph(graph, trans):
    ft_graph = {}
    for i in graph.keys():
        vertex = [trans[x] for x in graph[i]]
        if trans[i] not in ft_graph:
            ft_graph.setdefault(trans[i], vertex)
        else:
            ft_graph[trans[i]] = ft_graph[trans[i]] + vertex
    return ft_graph




def depthFirstSearch(graph, i):
    global t
    global s
    if i in graph and i not in explored:
        explored.append(i)
        if s in leaders:
            leaders[s].append(i)
        else:
            leaders.setdefault(s, [i])

        for j in graph[i]:
            if j not in explored:
                depthFirstSearch(graph, j)
        t = t + 1
        time[i] = t
            # if i not in explored:
    #     explored.append(i)
    #     if s in leaders:
    #         leaders[s].append(i)
    #     else:
    #         leaders.setdefault(s, [i])
    #
    #     if i in graph and i not in explored:
    #         for j in graph[i]:
    #             if j not in explored:
    #                 depthFirstSearch(graph, j)






def depthFirstSearchLoop(graph):
    n = 875714
    global s
    for i in tqdm(range(n, 0, -1)):
        if i not in explored:
            s = i
            depthFirstSearch(graph, i)

def sccSize(graph):
    global s
    graph_inv = graph_inversion(graph)
    depthFirstSearchLoop(graph_inv)
    print("Finishing Times : {}".format(time))
    ft_graph = create_ft_graph(graph_copy, time)
    print(ft_graph)
    s = 0
    explored.clear()
    leaders.clear()
    depthFirstSearchLoop(ft_graph)
    print("Leaders : {}".format(leaders))

    sizes = []
    for lead in leaders.keys():
        sizes.append(len(leaders[lead]))

    print(sizes)

    with open('sizes.txt', 'w') as filehandle:
        filehandle.writelines("%d," % size for size in sizes)


sccSize(graph)