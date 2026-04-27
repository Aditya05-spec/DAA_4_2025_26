class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        
        int n = cost.size();
        
        if(n == 1) return 0;
        
        int VISITED_ALL = (1 << n);
        const int INF = 1e9;
        
        vector<vector<int>> dp(VISITED_ALL, vector<int>(n, INF));
        
        dp[1][0] = 0;
        
        for(int mask = 1; mask < VISITED_ALL; mask++) {
            for(int u = 0; u < n; u++) {
                
                if(!(mask & (1 << u))) continue;
                
                for(int v = 0; v < n; v++) {
                    
                    if(!(mask & (1 << v))) {
                        dp[mask | (1 << v)][v] = min(
                            dp[mask | (1 << v)][v],
                            dp[mask][u] + cost[u][v]
                        );
                    }
                }
            }
        }
        
        int ans = INF;
        
        for(int i = 1; i < n; i++) {
            ans = min(ans, dp[VISITED_ALL - 1][i] + cost[i][0]);
        }
        
        return ans;
    }
};