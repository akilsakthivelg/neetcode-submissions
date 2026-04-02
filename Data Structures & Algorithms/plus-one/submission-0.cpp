class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=1;
        for (int i=digits.size()-1;i>=0;i--) {
            if (digits[i]+n <= 9) {
                digits[i]+=1;
                return digits;
            } else {
                digits[i]=0;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
        
    }
};
