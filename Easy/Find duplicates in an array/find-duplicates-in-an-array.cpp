//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
         sort(arr,arr+n);
        int flag=0;
        int max=arr[n-1];
        vector<int>freq(max+1);
        vector<int>dup;
        
        for(int i=0; i<n; i++){
            freq[arr[i]]++;
        }
        for(int i=0; i<freq.size(); i++){
            if(freq[i]>1){
                dup.push_back(i);
                flag=1;
            }
        }
        if(flag==0){
            dup.push_back(-1);
        }
        return dup;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends