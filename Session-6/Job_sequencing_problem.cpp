#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    vector<pair<int , int> > deadlineToProfit;
    for(int i=0 ; i<deadline.size() ; i++) {
        deadlineToProfit.push_back({profit[i] , deadline[i]});
    }    
    sort(deadlineToProfit.begin() , deadlineToProfit.end() , greater<pair<int , int>>());

    int maxi = -1;
    for(auto i : deadline) {
        maxi = max(maxi , i);
    }

    vector<int> slots(maxi , -1);
    int countJobs = 0;
    int totalProfit = 0;
    for(int i=0 ; i<deadline.size() ; i++) {
        int d = deadlineToProfit[i].second;
        int p = deadlineToProfit[i].first;

        int j=d-1;
        while(j >=0) {
            if(slots[j] == -1) {
                slots[j] = p;
                countJobs++;
                totalProfit += p;
                break;
            }
            j--;
        }
    }

    return {countJobs , totalProfit};
}

int main() {
    int n;
    vector<int> deadline = {3,1,2,2}; 
    vector<int> profit = {50, 10, 20, 30};
    
    // for(int i=0 ; i<n ; i++) {
    //     cin >> deadline[i];
    // }

    // for(int i=0 ; i<n ; i++) {
    //     cin >> profit[i];
    // }

    vector<int> ans = jobSequencing(deadline , profit);
    for(auto i : ans) {
        cout << i << " ";
    }

    return 0;
}