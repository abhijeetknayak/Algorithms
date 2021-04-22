#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) { 
	int cur_mov = -1, temp = 0;
	for(int i = 0; i < array.size(); i++) {
		if (cur_mov != -1) {
			if (array[i] != toMove) {
				/* Swap elements at i and cur_mov */
				temp = array[i];
				array[i] = array[cur_mov];
				array[cur_mov] = temp;
				cur_mov++;
			}
		}
		else if (array[i] == toMove) {
			/* Found an integer to move */
			cur_mov = i;
		}
	}
  return array;
}
