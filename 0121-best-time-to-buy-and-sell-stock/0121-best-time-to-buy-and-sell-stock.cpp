class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<pair<int, int>> cache(prices.size());
        cache[0] = {prices[0], 0};  // 최소값, 차이
        for(int i=1;i<prices.size();i++)
        {
            if (prices[i] < cache[i - 1].first)
                cache[i] = {prices[i], cache[i - 1].second};
            else
                cache[i] = {cache[i - 1].first, max(cache[i - 1].second, prices[i] - cache[i - 1].first)};
        }

        int maxi = -1;
        for(int i=0;i<cache.size();i++)
            maxi = max(maxi, cache[i].second);
        return maxi;
    }
};