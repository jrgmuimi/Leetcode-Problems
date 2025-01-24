class Solution {
public: // O(m+n) Time Complexity, O(m+n) Space Complexity (Because of using the additional "sorted" vector to store the sorts)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int total_len = m+n; // Combined sorted array length
        vector<int> sorted(m+n);
        int n1ind = 0; // "Pointer" or Index of the current element in the nums1 Vector
        int n2ind = 0; // "Pointer" or Index of the current element in the nums2 Vector

        if (!nums2.empty()) // If nums2 is empty then there are no elements to merge/combine, and so nums1 is already sorted
        {
            for (int i = 0; i < total_len; i++) 
            { // First check that we still have elements to sort in nums2 (index not out of bound), if so, then check the opposite and see if we've already
                // sorted all the elements in nums1 (nums2 will fill the rest of the "sorted" vector) OR the current nums2 element is < than the current nums1 element

                // If one of the two latter conditions hold, then the current nums2 element must be the next sorted element.
                if ((n2ind < n) && ((n1ind >= m) || (nums2[n2ind] < nums1[n1ind]))) // Can also use <= to Tiebreak
                {
                    sorted[i] = nums2[n2ind];
                    n2ind++;
                }
                else // If there are no more nums2 elements to sort, then sort nums1, 
                // OR if current nums1 element is < current nums2 AND there are elements to sort in nums1
                {
                    sorted[i] = nums1[n1ind];
                    n1ind++;
                }
            }

            for (int i = 0; i < total_len; i++) // Replace nums1 with sorted Vector
            {
                nums1[i] = sorted[i];
            }
        }
    }
};
