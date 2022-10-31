#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool findPathEfficient(int row, int col, vector<vector<bool>> grids, vector<pair<int, int>>& path, 
                       map<pair<int, int>, bool>& dp)
{
    bool success = false;
    if (row < 0 || col < 0) return false;
    pair<int, int> point = make_pair(row, col);
    
    if (dp.find(point) != dp.end())
    {
        return dp.at(point);
    }

    if (row == 0 && col == 0) 
    {
        // Path to source found, return
        // path.push_back(make_pair(0, 0));
        return true;
    }

    // Can only go left or up from the destination

    //Left
    if (col - 1 >= 0 && grids[row][col - 1] != 0) success = findPathEfficient(row, col - 1, grids, path, dp);
    if (success) 
    {
        // Found path, add (row, col - 1) to path
        path.push_back(make_pair(row, col - 1));
        dp[make_pair(row, col - 1)] = true;
        return success;
    }

    if (row - 1 >= 0 && grids[row - 1][col] != 0) success = findPathEfficient(row - 1, col, grids, path, dp);
    if (success) 
    {
        // Found path, add (row, col - 1) to path
        path.push_back(make_pair(row - 1, col));
        dp[make_pair(row - 1, col)] = true;
        return success;
    }    

    // If no path found yet, return false
    dp[make_pair(row, col)] = false;
    return false;    
}

bool findPathNaive(int row, int col, vector<vector<bool>> grids, vector<pair<int, int>>& path)
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
    if (col - 1 >= 0 && grids[row][col - 1] != 0) success = findPathNaive(row, col - 1, grids, path);
    if (success) 
    {
        // Found path, add (row, col - 1) to path
        path.push_back(make_pair(row, col - 1));
        return success;
    }

    if (row - 1 >= 0 && grids[row - 1][col] != 0) success = findPathNaive(row - 1, col, grids, path);
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

    vector<vector<bool>> grids = { {1, 1, 0, 0, 1},
                                 {0, 1, 1, 1, 0},
                                 {1, 0, 0, 1, 1},
                                 {1, 1, 1, 0, 1},
                                 {1, 1, 1, 1, 1}};

    vector<pair<int, int>> path;

    bool success = findPathNaive(rows - 1, cols - 1, grids, path);
    path.push_back(make_pair(rows - 1, cols - 1));
    cout << success << endl;
    for (auto ele : path)
    {
        cout << ele.first << " " << ele.second << endl;
    }

    map<pair<int, int>, bool> dp;
    success = findPathEfficient(rows, cols, grids, path, dp);
    cout << success << endl;
    for (auto ele : path)
    {
        cout << ele.first << " " << ele.second << endl;
    }
}