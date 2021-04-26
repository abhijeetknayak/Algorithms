#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
	int cur_reward = 0, total_reward = 0, skipped = 0;
	for(int i = 0; i < scores.size(); i++) {
		if (i == scores.size() - 1) {
			/* Last element */
			if (scores[i] > scores[i - 1]) {
				cur_reward++; total_reward += cur_reward;
			}
			else total_reward += 1; 
		}
		else if (scores[i] < scores[i + 1]) {
			if (skipped) {
				cur_reward++;
				if (cur_reward > skipped + 1) {
					int temp1 = cur_reward - skipped;
					int temp = (cur_reward * (cur_reward + 1)) - (temp1 * (temp1 + 1));
					total_reward += (temp / 2);
					cur_reward -= skipped;
				}
				else {
					total_reward += (skipped + 1) * (skipped + 2) / 2;
					cur_reward = 1;	skipped = 0;					
				}
			}
			else {
				cur_reward++;
				total_reward += cur_reward;
			}
		}
		else if (scores[i] > scores[i + 1]) skipped++;
	}
	
	if (skipped) {
		/* Still some elements we have skipped */
		

	}
  return total_reward;
}
