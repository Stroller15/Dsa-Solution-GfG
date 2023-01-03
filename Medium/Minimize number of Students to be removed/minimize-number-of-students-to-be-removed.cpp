//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
  public:
    int removeStudents(int H[], int N) {
        vector<int> nums;
        for(int i=0;i<N;i++) nums.push_back(H[i]);
        return N-lengthOfLIS(nums);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends