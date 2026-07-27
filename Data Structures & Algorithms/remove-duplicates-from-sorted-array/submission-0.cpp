class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i=0,j=0;
        while (j<arr.size()) {
            if (arr[i] == arr[j]) j++;
            else {
                arr[++i]=arr[j++];
            }
        }
        return i+1;
    }
};