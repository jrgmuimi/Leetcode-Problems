/** Used niits' Explanation: To start, we can divide up the array into sequential groups of 2.
We have to perform checking on the first element of the second group, aka element 3 in the array.
Since the array is sorted, either the 3rd element is a duplicate of the first element or is a
brand new element. If it's a duplicate, then we know the 2nd element is also a duplicate, and
we can simply skip over 3 without adjusting the pointer to left-shift the items to the front.
If 3 is not a duplicate, then we can place it in its same spot and adjust the pointer.
Consider the sequence 111223: The third element is a duplicate and the pointer won't be adjusted, however
the fourth element, when looking two places behind the current pointer, is not a duplicate, so the array
becomes 112223, and the pointer shifts to index 3. Similar to the beginning, we don't care about the 2nd element
following a "unique" or "newly discovered" element; it can be either a duplicate or a different number.
The one we need to be aware for is the third one after the unique element. Since the 2 at element 4 compares
against 1, the pointer gets incremented and the array stays the same: 112223. The 2 at element 5 is a duplicate
when comparing, and so the pointer index doesn't shift and its spot is open for the next unique value, which is 3.
Everytime we shift the placeIndex we know a new "unique" value exists, so we use it also as a counter.
Everytime there is a spot open, a "non-duplicate" will shift to fill the space.
 */

int removeDuplicates(int* nums, int numsSize) 
{ // O(n) Time Complexity, O(1) Space Complexity

    if (numsSize == 1) { return 1; }

    int placeIndex = 2;

    for (int i = 2; i < numsSize; i++)
    {
        if(nums[i] != nums[placeIndex-2])
        {
            nums[placeIndex] = nums[i];
            placeIndex++;
        }
    }
    
    return placeIndex;
}