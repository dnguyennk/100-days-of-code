//3 pointers start from end
//Time: O (m+n)
//Space: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Set p1 and p2 point to the end of their repsective arrays
        int p1 = m - 1;
        int p2 = n - 1;
        // Move p (p = m+n-1) backward through array
        //Each time writting the smalles value pointed at by p1 or p2
        for (int p = m + n - 1; p >= 0; p--){
            if (p2 < 0){    //p2 exhausted
                break;
            }
            if (p1 >=0 && nums1[p1] > nums2[p2]){
                nums1[p] = nums1[p1--];
            } else {
                nums1[p] = nums2[p2--];
            }
        }
    }
};