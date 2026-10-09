class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();

        int carry=1;

        for(int i= n-1; i>=0; i--){
            int temp = (digits[i]+carry)%10;
            carry= (digits[i]+ carry)/10;
            digits[i]= temp;
        }

        if(carry){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};