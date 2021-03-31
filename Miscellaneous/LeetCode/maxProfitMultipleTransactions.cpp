int maxProfitMultipleTransactions(vector<int>& prices) {
    int buy = 0, sell = 0, max_profit = 0;
    int bp = prices[0], sp = prices[0];

    for (int i = 1; i < prices.size(); i++) {
    	if (prices[i] >= sp) {
    		sp = prices[i];
    		if (i == prices.size() - 1) max_profit += (sp - bp);
    	}
    	else if (prices[i] < sp) {
    		max_profit += (sp - bp);
    		sp = bp = prices[i];
    	}
    }
    return max_profit;
}
