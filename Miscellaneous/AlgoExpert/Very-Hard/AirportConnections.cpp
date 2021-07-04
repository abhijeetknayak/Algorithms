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

void recursively_add_connections(string last_airport,
				 vector<string>& already_connected,
				 map<string, vector<string>> max_connections) {
	for(int i = 0; i < max_connections[last_airport].size(); i++) {
		string new_airport = max_connections[last_airport][i];
		if (find(already_connected.begin(), already_connected.end(), new_airport) == already_connected.end()) {
			already_connected.push_back(new_airport);
			recursively_add_connections(new_airport, already_connected, max_connections);
		}
	}
}

int airportConnections(vector<string> airports, vector<vector<string>> routes,
                       string startingAirport) {
	map<string, vector<string>> connections;
	
	/* Create the graph */
	generate_graph(routes, connections);
	
	map<string, vector<string>> max_connections;
	priority_queue<pair<int, string>> p;
	
	/* Find all possible airports that you can get to from amn airport */
	find_max_possible_connections(connections, max_connections, p, airports);
	
	vector<string> already_connected = max_connections[startingAirport];
	int count = 0;
	vector<string> result;
	
	/* Now check if you can add connections to the airports, if not already connected
	If a new connection is created, make sure all the other possible connections are added recursively */
	while(!p.empty()) {
		pair<int, string> top = p.top();		p.pop();
		if (top.second == startingAirport) continue;
		if (find(already_connected.begin(), already_connected.end(), top.second) == already_connected.end()) {
			/* This airport is not connected yet */
			count += 1;
			result.push_back(top.second);
			already_connected.push_back(top.second);
			
			/* Find all the other connections that are added because of this new one */
			recursively_add_connections(top.second, already_connected, max_connections);
		}
	}	

  return count;
}
