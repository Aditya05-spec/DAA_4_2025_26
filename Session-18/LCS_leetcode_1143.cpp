class Solution {
private:
    // Using memoization 
    // int LongestSubsequence(string &text1 , string &text2 , int index1 , int index2 , vector<vector<int> > &dp) {
    //     //Base case
    //     if(index1 >= text1.length()) {
    //         return 0;
    //     }

    //     if(index2 >= text2.length()) {
    //         return 0;
    //     }

    //     if(dp[index1][index2] != -1) {
    //         return dp[index1][index2];
    //     }

    //     int ans = 0;
    //     if(text1[index1] == text2[index2]) {
    //         ans = 1 + LongestSubsequence(text1 , text2 , index1+1 , index2+1 , dp);
    //     }
    //     else {
    //         ans = 0 + max(LongestSubsequence(text1 , text2 , index1+1 , index2 , dp) , LongestSubsequence(text1 , text2 , index1 , index2+1 , dp));
    //     }

    //     dp[index1][index2] = ans;
    //     return dp[index1][index2];
    // }

    // Using tabulation
    int LongestSubsequence(string &text1 , string &text2) {
        vector<vector<int> > dp(text1.size()+1 , vector<int>(text2.size()+1 , 0));
        
        for(int index1=text1.length()-1 ; index1>=0 ; index1--) {
            for(int index2=text2.length()-1 ; index2>=0 ; index2--) {
                int ans = 0;
                if(text1[index1] == text2[index2]) {
                    ans = 1 + dp[index1+1][index2+1];
                }
                else {
                    ans = 0 + max(dp[index1+1][index2] , dp[index1][index2+1]);
                }
                dp[index1][index2] = ans;
            }
        }
        return dp[0][0];
    } 

    int solve(string &text1, string &text2 , int i , int j) {
        //Base case
        if(i >= text1.length()) {
            return 0;
        }

        if(j >= text2.length()) {
            return 0;
        } 

        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = 1 + solve(text1 , text2 , i+1 , j+1);
        }
        else {
            ans = 0 + max(solve(text1 , text2 , i+1 , j) , solve(text1 , text2 , i , j+1));
        }

        return ans;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;

        // Using memoization
        // return LongestSubsequence(text1 , text2 , i , j , dp);

        // Using tabulation method
        return LongestSubsequence(text1 , text2);

        
        // return solve(text1 , text2 , i , j);
    }
};