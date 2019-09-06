from tqdm import tqdm
num = open('algo1-programming_prob-2sum.txt', 'r')
lines = num.readlines()
counter = 0
numbers = []

graph = {}
for line in lines:
    if int(line) not in graph:
        graph.setdefault(int(line), 0)

targets = []

for i in tqdm(range(-10000, 10000)):
    for key in graph.keys():
        if i - key in graph and (i - key != i):
            targets.append(i)
            break

print(len(targets))