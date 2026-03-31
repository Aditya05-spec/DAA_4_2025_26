class Solution {
private:
    int solveUsingRecursion(vector<int>& coins, int amount) {
        //Base case
        if(amount == 0) {
            return 0;
        }

        if(amount < 0) {
            return INT_MAX;
        }

        int mini = INT_MAX;
        for(int i=0 ; i<coins.size() ; i++) {
            int ans = solveUsingRecursion(coins , amount-coins[i]);
            if(ans != INT_MAX) {
                mini = min(ans+1 , mini);
            }
        }
        return mini;
    }

    int solveMemo(vector<int> &coins , int amount , vector<int> &dp) {
        //Base case
        if(amount == 0) {
            return 0;
        }

        if(amount < 0) {
            return INT_MAX;
        }

        if(dp[amount] != -1) {
            return dp[amount];
        }

        int mini = INT_MAX;
        for(int i=0 ; i<coins.size() ; i++) {
            int ans = solveMemo(coins , amount-coins[i] , dp);
            if(ans != INT_MAX) {
                mini = min(ans+1 , mini);
            }
        }
        dp[amount] = mini;
        return mini;
    }

    int solveTabulation(vector<int>& coins, int amount) {
        // Step 1 : create dp array
        vector<int> dp(amount+1 , INT_MAX);

        // step 2 : checl the base case of topdown
        dp[0] = 0;

        // step 3 :
        for(int target = 1 ; target <= amount ; target++) {
            int mini = INT_MAX;
            for(int i=0 ; i<coins.size() ; i++) {
                if(target - coins[i] >= 0) {
                    int ans = dp[target - coins[i]];
                    if(ans != INT_MAX) {
                        mini = min(mini , ans+1);
                    }
                }
            }
            dp[target] = mini;
        }
        return dp[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveUsingRecursion(coins , amount);

        // if(ans == INT_MAX) {
        //     return -1;
        // }
        // return ans;

        // vector<int> dp(amount+1 , -1);
        // int ans = solveMemo(coins , amount , dp);

        // if(ans == INT_MAX) {
        //     return -1;
        // }
        // return ans;

        int ans = solveTabulation(coins , amount);
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};