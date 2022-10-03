//Question link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);  
            
        int first_min = arr[0] + k;
        int last_max = arr[n-1] - k;
        int max_ht, min_ht, min_diff = arr[n-1] - arr[0];
        
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - k < 0)
                continue;
                
            min_ht = min(first_min, arr[i] - k);
            max_ht = max(last_max, arr[i-1] + k);
            
            min_diff = min(min_diff, max_ht - min_ht);
        }
        
        return min_diff;
    }
};
