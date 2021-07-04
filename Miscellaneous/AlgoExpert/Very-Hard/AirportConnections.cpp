#include <vector>
using namespace std;

class Node {
	public:
		string name;
	  vector<int> connections;
};

void generate_graph(vector<vector<string>> routes, 
									 map<string, vector<string>>& connections) {
	for (int i = 0; i < routes.size(); i++) {
		string start = routes[i][0];
		if (connections.find(start) != connections.end()) {
			connections[start].push_back(routes[i][1]);
		}
		else {
			connections[start] = vector<string> {routes[i][1]};
		}
	}
}

void DFS_from_start_airport(string airport, string cur_airport, map<string, vector<string>> connections,
													 vector<string>& visited) {
	if (connections.find(cur_airport) != connections.end()) {
		/* Add new connections */
		for (int i = 0; i < connections[cur_airport].size(); i++) {
			string new_airport = connections[cur_airport][i];
			if (new_airport != airport
					&& (find(visited.begin(), visited.end(), new_airport) == visited.end())) {
				visited.push_back(new_airport);
				/* New airport not the same as the one we started from */
				DFS_from_start_airport(airport, new_airport, connections, visited);
			}				
		}
	}
}

void find_max_possible_connections(map<string, vector<string>> connections,
																	map<string, vector<string>>& max_con,
																	priority_queue<pair<int, string>>& p,
																	vector<string> airports) {
	for (int i = 0; i < airports.size(); i++) {
		vector<string> visited{};
		DFS_from_start_airport(airports[i], airports[i], connections, visited);
		max_con[airports[i]] = visited;
		p.push(make_pair(visited.size(), airports[i]));
	}
}

int airportConnections(vector<string> airports, vector<vector<string>> routes,
                       string startingAirport) {
	map<string, vector<string>> connections;
	generate_graph(routes, connections);
	
	map<string, vector<string>> max_connections;
	priority_queue<pair<int, string>> p;
	find_max_possible_connections(connections, max_connections, p, airports);
	
	// while (!p.empty()) {
	// 	pair<int, string> top = p.top();
	// 	cout << top.first << " " << top.second << endl;
	// 	p.pop();
	// }
	
	for (auto ele : max_connections) {
		cout << ele.first << " ";
		for (int i  = 0; i < ele.second.size(); i++) {
			cout << ele.second[i] << " ";
		}
		cout << endl;
	}
	

  return -1;
}
