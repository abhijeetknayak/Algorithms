class heaps:
    def __init__(self):
        self.heap = []
    def insert(self, k):
        self.heap.append(k)
        pos = len(self.heap) - 1
        while pos > 0:
            parent_pos = (pos - 1) // 2
            if self.heap[parent_pos] > self.heap[pos]:
                # Swap parent and child
                self.heap[parent_pos], self.heap[pos] = self.heap[pos], self.heap[parent_pos]
                pos = parent_pos
            else:
                break
    def extract_min(self):
        return self.heap[0]

if __name__ == '__main__':
    heap = heaps()
    heap.insert(10)
    heap.insert(7)
    heap.insert(2)
    heap.insert(1)
    heap.insert(3)
    heap.insert(11)
    heap.insert(13)
    heap.insert(5)
    heap.insert(7)
    print(heap.heap)
    print(heap.extract_min())
    heap.insert(0)
    print(heap.extract_min())





