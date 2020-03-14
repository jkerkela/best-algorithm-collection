class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m - 1;
        int j = n - 1;
        auto currrentIndexToFill = nums1.size() - 1;
        while ((currrentIndexToFill >= 0) && (i >= 0 || j >= 0)) {
            if(i < 0) {
                nums1[currrentIndexToFill] = nums2[j];
                j--;
            } else if (j < 0) {
                nums1[currrentIndexToFill] = nums1[i];
                i--;
            } else if (nums1[i] <= nums2[j]) {
                nums1[currrentIndexToFill] = nums2[j];
                j--;
            } else if (nums2[j] <= nums1[i]) {
                nums1[currrentIndexToFill] = nums1[i];
                i--;
            }
            currrentIndexToFill--;
        }
   }
};
