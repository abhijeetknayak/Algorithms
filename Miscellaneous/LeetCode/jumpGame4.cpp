class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        map<int, vector<int>> locations;
        for (int i = 0; i < arr.size(); i++) {
            if (locations.find(arr[i]) != locations.end()) {
                /* Already available in the map */
                locations[arr[i]].push_back(i);
            }
            else locations[arr[i]] = {i};
        }
                
        /* Now you've got all locations of numbers in the array */
        /* BFS */
        vector<int> frontier {0};
        vector<int> visited {0, n - 1};
        vector<int> other {n - 1};
        
        int count = 0;
        
        while(!frontier.empty()) {
            vector<int> new_frontier;
            /* Expand the smaller vector */
            if (frontier.size() > other.size()) {
                vector<int> temp = other;
                other = frontier;
                frontier = temp;
            }
            
            for (int i = 0; i < frontier.size(); i++) {
                int top = frontier[i];
                
                /* Add all nodes that you can get to from index i */
                for (int idx = 0; idx < locations[arr[top]].size(); idx++) {
                    if (find(other.begin(), other.end(), locations[arr[top]][idx]) != other.end()) return count + 1;
                    if (find(visited.begin(), visited.end(), locations[arr[top]][idx]) == visited.end()) {
                        /* Not yet explored */
                        new_frontier.push_back(locations[arr[top]][idx]);
                        visited.push_back(locations[arr[top]][idx]);
                    }
                }
                
                if (find(other.begin(), other.end(), top + 1) != other.end()
                   || find(other.begin(), other.end(), top - 1) != other.end()) {
                    return count + 1;
                }
                
                if (top - 1 >= 0
                    && find(visited.begin(), visited.end(), top - 1) == visited.end()) {
                    new_frontier.push_back(top - 1);
                    visited.push_back(top - 1);
                }
                if (top + 1 < n && find(visited.begin(), visited.end(), top + 1) == visited.end()) {
                    // cout << top + 1 << endl;
                    new_frontier.push_back(top + 1);
                    visited.push_back(top + 1);
                }
            }
            
            frontier = new_frontier;            
            count++;            
        }
        
        return -1;
    }
};
