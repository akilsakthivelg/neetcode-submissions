class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        char prev = ' ';
        int l=0,r=1;
        int ans=1;

        while (r<arr.size()) {
            if (arr[r-1]<arr[r] && prev!='<') {
                ans=max(ans,r-l+1);
                r++;
                prev='<';
            } else if (arr[r-1]>arr[r] && prev!='>') {
                ans=max(ans,r-l+1);
                r++;
                prev='>';
            } else {
                if (arr[r-1]==arr[r]) r++;
                l=r-1;
                prev=' ';
            }
        }
        return ans;
    }
};