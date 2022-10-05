//Question link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

/* The idea is to use a vector to store the individual numbers of the factorial as we go on multiplying the numbers from 1 to n (since factorial of n grows 
   very fast, it might quickly get out of bounds of int datatype). 
   
   The digits are stored in the reverse order for ease of multiplying. 
   Vector size is increased when there is a carry from the most significant digit.
*/

//Time complexity: O(n^2)
//Space complexity: O(1)
//Auxiliary space used: O(1)

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> vec;
        vec.push_back(1);     //By default we store 1, which is the factorial of 1.
        int carry = 0, size = 1, dig;   
        //Carry stores the carry from each digit multiplication.
        //Size denotes the current size of the resultant vector.
        
        for (int num = 2; num <= N; num++)    //Since the factorial of 1 is already stored, we calculate from 2 onwards.
        {
            for (int i = 0; i < size; i++)
            {
                dig = num * vec[i] + carry;   //Multiplying num by every digit of the vector and storing in dig.
                vec[i] = dig % 10;            //vec[i] will contain the least significant digit.
                carry = dig / 10;             //rest will be considered as carry.
            }
            
            while (carry)
            {
                vec.push_back(carry % 10);    //Carry from the most significant digit is added to the vector.
                size++;                       //size of the vector increases after every addition of carry.
                carry /= 10;
            }
        }
        
        reverse(vec.begin(), vec.end());      //Since the vector was stored in reverse order, we reverse the digits and then return.
        
        return vec;
    }
};
