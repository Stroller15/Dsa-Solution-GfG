//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            int ans = new Solution().findKRotation(a, n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    int findKRotation(int arr[], int n) {
        // code here
        int low = 0, high = n - 1;
        
        while (low <= high) {
            if (arr[low] <= arr[high]) {
                // Case 1: Array is already sorted, and no rotations have been made
                return low;
            }
            
            int mid = (low + high) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            
            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
                // Case 2: Mid element is the minimum element (rotation point)
                return mid;
            }
            
            if (arr[low] <= arr[mid]) {
                // Case 3: The left part is sorted, and the rotation point is in the right part
                low = mid + 1;
            }
            else if (arr[mid] <= arr[high]) {
                // Case 4: The right part is sorted, and the rotation point is in the left part
                high = mid - 1;
            }
        }
        
        return -1; 
    }
    
}