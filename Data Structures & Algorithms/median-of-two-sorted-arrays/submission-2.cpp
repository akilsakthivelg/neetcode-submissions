class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> a;
        int i,j;
        i=j=0;
        while (i<n || j<m) {
            if (i<n && j<m) {
                if (nums1[i]<nums2[j]) a.push_back(nums1[i++]);
                else a.push_back(nums2[j++]);
            }
            else if (i<n) a.push_back(nums1[i++]);
            else a.push_back(nums2[j++]);
        }
    
        int pos=(n+m)/2;
        if ((n+m)%2==0) return (1.0*a[pos]+a[pos-1])/2;
        return a[pos];
    }
};
