//Question link: https://leetcode.com/problems/clumsy-factorial/

/*Let's consider a number n. We will divide the numbers from n to 1 (decreasing order) in groups of 4.
  The first number will be stored in the variable prod. The second number (if exists) will be multiplied with prod.
  The third number (if exists) will be divided by prod. Then prod will be stored in the vector vec, followed by the fourth number.
  The same thing will be repeated untill we reach 1.
  
  Then we take the first number and store it in a variable sum. All other numbers are divided in groups of 2.
  The first number of a group (if exists) will be added to sum. The second number (if exists) will be subtracted from sum.
  Finally, we return sum. */

//Time complexity: O(n)
//Space complexity: O(1)
//Auxiliary space used: O(n)

class Solution {
public:
    int clumsy(int n) {
        int prod, sum;
        vector<int> vec;
        
        int num = n;
        while (num)
        {
            prod = num;
            num--;
            
            if (num)
            {
                prod *= num;
                num--;
            }
            
            if (num)
            {
                prod /= num;
                num--;
            }
            vec.push_back(prod);
            
            if (num)
            {
                vec.push_back(num);
                num--;
            }
        }
        
        int size = vec.size();
        sum = vec[0];
        int i = 1;
        while (i < size)
        {
            sum += vec[i];
            i++;
            
            if (i < size)
                sum -= vec[i];
            i++;
        }
        
        return sum;
    }
};
