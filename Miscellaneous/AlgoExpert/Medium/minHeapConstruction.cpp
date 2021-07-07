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

  void siftDown(int currentIdx, int endIdx) {
		/* Indices of children */
		int idx1 = 2 * currentIdx + 1;
		int idx2 = 2 * currentIdx + 2;
		
		while(idx1 <= endIdx) {
			if (idx2 > endIdx && heap[currentIdx] > heap[idx1]) {
				swap(heap[idx1], heap[currentIdx]);
				currentIdx = idx1;
			}
			else if (heap[idx1] < heap[idx2]
							 && heap[currentIdx] > heap[idx1]) {
				swap(heap[idx1], heap[currentIdx]);
				currentIdx = idx1;				
			}
			else if (heap[idx2] <= heap[idx1] 
							&& heap[currentIdx] > heap[idx2]){
				swap(heap[idx2], heap[currentIdx]);
				currentIdx = idx2;
			}
			else break;
			
			idx1 = currentIdx * 2 + 1;
			idx2 = currentIdx * 2 + 2;
		}
  }

  void siftUp(int currentIdx) {
		while(currentIdx > 0) {
			int pidx = currentIdx % 2 == 0 ?
				(currentIdx / 2) - 1 : currentIdx / 2;
			if (heap[pidx] > heap[currentIdx]) {
				swap(heap[pidx], heap[currentIdx]);
				currentIdx = pidx;
			}
			else break;			
		}
  }

  int peek() {
		if (heap.size() != 0) return heap[0];
    return -1;
  }

  int remove() {
		// Insert last element at the top
		int ret_val = heap[0];
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		
		siftDown(0, heap.size() - 1);
    return ret_val;
  }

  void insert(int value) {
		heap.push_back(value);
		siftUp(heap.size() - 1);
  }
};
