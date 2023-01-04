//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
         static bool comp(vector<int>a  , vector<int>b )
  {
      return a[1]<b[1] ;
  }
  
    int maximum_profit(int n, vector<vector<int>> &intervals) {
  
        sort(intervals.begin(), intervals.end(), comp ) ;
        
        vector<int>dp(n ,0 ) ; 
        dp[0] = intervals[0][2] ;
        int ans= dp[0] ;
        for(int i = 1 ; i<n ;i++)
        {
            int take = intervals[i][2]; 
            int last =-1 ;
            int l =0 , r = i-1; 
            while(l<=r)
            {
                int mid =(l+r)/2; 
                if(intervals[mid][1]<=intervals[i][0])
                {
                    l=mid+1 ;
                    last =mid ;
                }
                else
                r=mid-1 ;
            }
            if(last!=-1)
            take+=dp[last] ;
            
            dp[i] =max(dp[i-1] , take) ; 
            ans =max(ans ,dp[i] ); 
        }
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends