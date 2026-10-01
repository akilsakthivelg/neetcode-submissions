class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans=1;
        int i=0,j=1;
        char prev=' ';
        while (j<arr.size()) {
            if (arr[j-1]<arr[j] && prev!='<') {
                ans=max(ans,j-i+1);
                j++;
                prev='<';
            } else if (arr[j-1]>arr[j] && prev!='>') {
                ans=max(ans,j-i+1);
                j++;
                prev='>';
            } else {
                if (arr[j-1]==arr[j]) j++;
                i=j-1;
                prev=' ';
            }
        }
        return ans;
    }
};