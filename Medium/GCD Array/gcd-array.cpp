//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int k, vector<int> &arr) {
        // Calculate presum
        int preSum[n];
        preSum[0] = arr[0];
        for(int i=1;i<n;i++) preSum[i] = arr[i] + preSum[i-1];
        
        // Find all factors of entire arr sum
        vector<int> factors;
        int sum = preSum[n-1];
        
        for(int i=1;i<=sqrt(sum);i++) {
            if(sum%i == 0) {
                factors.push_back(i);
                // if divisors are not equal add them
                if(i != sum/i) factors.push_back(sum/i);
            }
        }
        
        // Iterate thorugh factors of preSum and check whether the factor divides the k subarrays
        int maxi = INT_MIN;
        for(auto i: factors) {
            int c = 0;
            
            for(int j=0;j<n;j++) {
                if(preSum[j] % i == 0) c++;
            }
            
            if(c >= k) {
                maxi = max(maxi, i);
                c = 0;
            }
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends