class Solution {
private:
    int topDown(int n , vector<int> &dp) {
        //Base case
        if(n <= 1) {
            return 1;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        dp[n] = topDown(n-1 , dp) + topDown(n-2 , dp);
        return dp[n];
    }

    int bottomUp(int n) {
        // Step 1 : Create dp array
        vector<int> dp(n+1 , -1);

        dp[0] = 1;
        dp[1] = 1;

        //Step 2 : Observe base case in above solution
        if(n <= 1) {
            return 1;
        }

        // step 3
        for(int i=2 ; i<=n ; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    int spaceOptSolve(int n) {
        int prev2 = 1;
        int prev1 = 1;

        if(n <= 1) {
            return 1;
        }

        int curr;
        for(int i=2 ; i<=n ; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

public:
    int climbStairs(int n) {
        // vector<int> dp(n+1 , -1);
        // int ans =  topDown(n , dp);
        // return ans;

        // return bottomUp(n);

        return spaceOptSolve(n);
    }
};