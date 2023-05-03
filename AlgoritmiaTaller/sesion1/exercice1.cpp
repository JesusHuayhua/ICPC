class Solution{
    public:
        int maxProfit(vector<int>&prices){
            int n_prices = (int)prices.size();
            int max_profit = 0;
            // construimos el arreglo mx[i] = max_[j = i]^{n-1} (a[i])
            vector<int> mx(n_prices);
            mx[n_prices - 1] = prices[n_prices - 1];
            for(int i = n_prices - 2; i >= 0; i--){
                // mx[i] = max(prices)
            }
        }
}
