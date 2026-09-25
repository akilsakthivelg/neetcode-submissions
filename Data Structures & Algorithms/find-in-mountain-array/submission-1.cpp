/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int i=1,j=m.length()-2;
        int peak=-1;
        while (i<=j) {
            int mid=i+(j-i)/2;
            int a=m.get(mid-1);
            int b=m.get(mid);
            int c=m.get(mid+1);
            if (a<b && b>c) {
                peak=mid;
                break;
            } else if (a<b && b<c) {
                i=mid+1;
            } else {
                j=mid-1;
            }
        }
        if (peak==-1) return -12345;
        i=0,j=peak;
        while (i<=j) {
            int mid = i+(j-i)/2;
            int e=m.get(mid);
            if (e==target) return mid;
            else if (e<target) i=mid+1;
            else j=mid-1;
        }
        i=peak+1,j=m.length()-1;
        while (i<=j) {
            int mid = i+(j-i)/2;
            int e=m.get(mid);
            if (e==target) return mid;
            else if (e<target) j=mid-1;
            else i=mid+1;
        }
        return -1;
    }
};