using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
	int x_u = array.size() - 1, x_l = 1, y_u = array[0].size() - 1, y_l = 0;
	int count = (x_u + 1) * (y_u + 1) - 1;
	int dir = 0; // Can take values 0, 1, 2, 3
	vector<int> result;
	int x = 0, y = -1;
	
	while(count >= 0) {
		if (dir == 0) {
			y++; result.push_back(array[x][y]);
			if(y == y_u) { y_u--; dir = 1; }
		}
		else if (dir == 1) {
			x++; result.push_back(array[x][y]);
			if (x == x_u) { x_u--; dir = 2;}
		}
		else if (dir == 2) {
			y--; result.push_back(array[x][y]);
			if (y == y_l) { y_l++; dir = 3; }
		}
		else {
			x--; result.push_back(array[x][y]);
			if (x == x_l) { x_l++; dir = 0;}
		}		
		count--;
	}
  return result;
}
