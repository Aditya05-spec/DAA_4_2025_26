#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
int operation = 0;
int maxDepth = 0;
void complexRec(int n , int depth) {
    operation++;
    maxDepth = max(maxDepth , depth);

   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2 , depth+1);
   complexRec(n / 2 , depth+1);
   complexRec(n / 2 , depth+1);
}

int main() {
    auto start = high_resolution_clock::now();
    complexRec(16 , 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Number of operations performed : " << operation << endl;
    cout <<"Max depth of the recc calls are : " <<  maxDepth << endl;
    cout << "Duration of the code from end to start is : " << duration.count() << endl;
    return 0;
}


// complexity = 3T(n/2) + O(nlogn) 
// depth  = O(logn)
// master theoram case 1 is applied h(n) = logn/sqrt(n)  O(n^log(base 2)3)