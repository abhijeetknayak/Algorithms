using namespace std;

int minimumWaitingTime(vector<int> queries) {
	if (queries.size() == 1) return 0;
	sort(queries.begin(), queries.end());
	int min_time = queries[0];
	for (int i = 1; i < queries.size() - 1; i++) {
		queries[i] = queries[i] + queries[i - 1];
		min_time += queries[i];
	}
  return min_time;
}
