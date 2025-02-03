int removeElement(int* nums, int numsSize, int val) 
{ // O(n) Time Complexity, O(1) Space Complexity
    int placeIndex = 0; // Store a spot where we can shift the non-value numbers over to

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val) // If a number is not the target val
        {
            nums[placeIndex] = nums[i]; // Shift the number over to left/beginning
            placeIndex++; // Increment index to make space for another non-val num
        } 
    }

    return placeIndex;
}
