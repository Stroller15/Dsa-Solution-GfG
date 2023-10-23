//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	private:
    int firstOcc(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;
        
        while(low <= high) {
             int mid = low + (high - low) / 2; 
            
            if(arr[mid] == x) {
                ans = mid;
                high = mid - 1;
            }else if(arr[mid] < x) {
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    int lastOcc(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;
        
        while(low <= high) {
             int mid = low + (high - low) / 2; 
            
            if(arr[mid] == x) {
                ans = mid;
                low = mid + 1;
            }else if(arr[mid] < x) {
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    public:	
	int count(int arr[], int n, int x) {
	    // code here
	    
        int ans1 = firstOcc(arr, n, x);
        int ans2 = lastOcc(arr, n, x);
        
        int ans = ans2 - ans1+1;
        
        return (ans1 == -1 && ans2 == -1) ? 0 : ans;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends