int maxProfitSingleTransaction(vector<int>& prices) {
    int max_profit = 0;
    int buy_price = prices[0], sell_price = prices[0];

    for (int i = 1; i < prices.size(); i++) {

    	if (prices[i] < buy_price) {
    		buy_price = prices[i];
    		sell_price = prices[i];
    	}
    	else if (prices[i] > sell_price) {
    		sell_price = prices[i];
    	}

        max_profit = max(max_profit, (sell_price - buy_price));
    }

    return max(max_profit, (sell_price - buy_price));

}
