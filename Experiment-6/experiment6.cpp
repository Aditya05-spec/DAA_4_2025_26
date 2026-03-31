class Solution {
private:
    // Recursion Only
    // int longestSubsequenceWithIncreasingOrder(vector<int>& nums , int curr , int prev) {
    //     //Base case
    //     if(curr >= nums.size()) {
    //         return 0;
    //     }

    //     int include = 0;
    //     if(prev == -1 || nums[prev] < nums[curr]) {
    //         include = 1 + longestSubsequenceWithIncreasingOrder(nums , curr+1 , curr);
    //     } 

    //     int exclude = 0 + longestSubsequenceWithIncreasingOrder(nums , curr+1 , prev);

    //     return max(include , exclude);
    // }


    // Memoization and recursion
    int longestSubsequenceWithIncreasingOrder(vector<int>& nums , int curr , int prev , vector<vector<int> >&dp) {
        //Base case
        if(curr >= nums.size()) {
            return 0;
        }

        if(dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }
        
        int include = 0;
        if(prev == -1 || nums[prev] < nums[curr]) {
            include = 1 + longestSubsequenceWithIncreasingOrder(nums , curr+1 , curr , dp);
        }

        int exclude = 0 + longestSubsequenceWithIncreasingOrder(nums , curr+1 , prev , dp);

        dp[curr][prev+1] = max(include , exclude);
        return dp[curr][prev+1];
    }

    // int longestSubsequenceWithIncreasingOrder(vector<int>& nums) { // Using tabulation or Bottom up DP
    //     int n = nums.size();
    //     vector<vector<int> >dp (n+1 , vector<int>(n+1 , 0));

    //     for(int curr = n-1 ; curr>=0 ; curr--) {
    //         for(int prev = curr-1 ; prev>=-1 ; prev--) {
    //             int include = 0;
    //             if(prev == -1 || nums[prev] < nums[curr]) {
    //                 include = 1 + dp[curr+1][curr+1];
    //             }

    //             int exclude = 0 + dp[curr+1][prev+1];

    //             dp[curr][prev+1] = max(include , exclude);
    //         }
    //     }
    //     return dp[0][-1+1];
    // }

    int longestSubsequenceWithIncreasingOrder(vector<int>& nums) { // Space Optimization
        int n = nums.size();
        vector<int> currRow(n+1 , 0);
        vector<int> nextRow(n+1 , 0);

        for(int curr = n-1 ; curr>=0 ; curr--) {
            for(int prev = curr-1 ; prev>=-1 ; prev--) {
                int include = 0;
                if(prev == -1 || nums[prev] < nums[curr]) {
                    include = 1 + nextRow[curr+1];
                }

                int exclude = 0 + nextRow[prev+1];

                currRow[prev+1] = max(include , exclude);
            }
            nextRow = currRow;
        }
        return nextRow[-1+1];
    }

    int lengthOfLISOptimal(vector<int> &nums) {
        if(nums.size() == 0) {
            return 0;
        }

        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1 ; i<nums.size() ; i++) {
            if(nums[i] > ans.back()) {
                //Include
                ans.push_back(nums[i]);
            }
            else {
                //Overwrite 
                //Find index of just bada element
                int index = lower_bound(ans.begin() , ans.end() , nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
        

public:
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // int ans = longestSubsequenceWithIncreasingOrder(nums , curr , prev);

        // vector<vector<int> >dp (nums.size() , vector<int>(nums.size()+1 , -1));
        // int ans = longestSubsequenceWithIncreasingOrder(nums , curr , prev , dp);

        // int ans = longestSubsequenceWithIncreasingOrder(nums);
        // return ans;

        return lengthOfLISOptimal(nums);
    }
};