#include <iostream>
#include <vector>

using namespace std;

bool findPath(int row, int col, vector<vector<bool>> map, vector<pair<int, int>>& path)
{
    bool success = false;
    if (row < 0 || col < 0) return false;
    if (row == 0 && col == 0) 
    {
        // Path to source found, return
        // path.push_back(make_pair(0, 0));
        return true;
    }

    // Can only go left or up from the destination

    //Left
    if (col - 1 >= 0 && map[row][col - 1] != 0) success = findPath(row, col - 1, map, path);
    if (success) 
    {
        // Found path, add (row, col - 1) to path
        path.push_back(make_pair(row, col - 1));
        return success;
    }

    if (row - 1 >= 0 && map[row - 1][col] != 0) success = findPath(row - 1, col, map, path);
    if (success) 
    {
        // Found path, add (row, col - 1) to path
        path.push_back(make_pair(row - 1, col));
        return success;
    }    

    // If no path found yet, return false
    return false;
}

int main()
{
    int rows = 5, cols = 5;

    vector<vector<bool>> map = { {1, 1, 0, 0, 1},
                                 {0, 1, 1, 1, 0},
                                 {1, 0, 0, 1, 1},
                                 {1, 1, 1, 0, 1},
                                 {1, 1, 1, 1, 1}};

    vector<pair<int, int>> path;

    bool success = findPath(rows - 1, cols - 1, map, path);
    path.push_back(make_pair(rows - 1, cols - 1));
    cout << success << endl;
    for (auto ele : path)
    {
        cout << ele.first << " " << ele.second << endl;
    }
}