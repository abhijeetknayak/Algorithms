#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int> &vector) {
		for (int i = 0; i < vector.size(); i++) {
			insert(vector[i]);
		}
    return heap;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
		swap(heap[currentIdx], heap[endIdx]);
  }

  void siftUp(int currentIdx, vector<int> &heap) {
    // Write your code here.
  }

  int peek() {
		if (heap.size() != 0) return heap[0];
    return -1;
  }

  int remove() {
		// Insert last element at the top
		heap[0] = heap[heap.size() - 1];
		
		int idx = 0;
		while(idx) {
			int idx1 = 2 * idx + 1;
			int idx2 = 2 * idx + 2;
			if (heap[idx1] < heap[idx2]) {
				siftDown(idx, idx1, heap);
			}
			else {
				siftDown(idx, idx2, heap);
			}
		}
    return -1;
  }

  void insert(int value) {
		int idx = heap.size();
		heap.push_back(value);
		while(true) {
			int pidx = idx % 2 == 0 ? (idx / 2) - 1 : idx / 2;
			if (heap[pidx] > heap[idx]) {
				swap(heap[pidx], heap[idx]);
				idx = pidx;
			}
			else break;			
		}
  }
};
