//Question link: https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        sort(a, a+n);
        sort(b, b+m);
        
        vector<int> union_vec;
        int prev_a = -1, prev_b = -1;
        int i = 0, j = 0;
        
        while (i < n && j < m)
        {
            if (a[i] == b[j])
            {
                if (prev_a != a[i] && prev_b != b[j])
                {
                    union_vec.push_back(a[i]);
                    prev_a = a[i];
                    prev_b = b[j];
                }
                
                i++;    j++;
            }
            else if (a[i] < b[j])
            {
                if (prev_a != a[i])
                {
                    union_vec.push_back(a[i]);
                    prev_a = a[i];
                }
                
                i++;
            }
            else
            {
                if (prev_b != b[j])
                {
                    union_vec.push_back(b[j]);
                    prev_b = b[j];
                }
                
                j++;
            }
        }
        
        while (i < n)
        {
            if (prev_a != a[i])
            {
                union_vec.push_back(a[i]);
                prev_a = a[i];
            }
            
            i++;
        }
        
        while (j < m)
        {
            if (prev_b != b[j])
            {
                union_vec.push_back(b[j]);
                prev_b = b[j];
            }
            
            j++;
        }
        
        return union_vec.size();
    }
};
