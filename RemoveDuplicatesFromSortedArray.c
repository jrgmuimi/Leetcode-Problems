int removeDuplicates(int* nums, int numsSize) 
{ // O(n) Time Complexity, O(1) Space Complexity
    int lastFound = nums[0]; // Store the last UNIQUE found number
    int placeIndex = 1; // If array is only one element, start from 1

    for (int i = 1; i < numsSize; i++)
    {
        if(nums[i] != lastFound) // As we're iterating, if we find a new unique value
        {
            lastFound = nums[i]; // Change last unique found number to new one
            nums[placeIndex] = nums[i]; // Shift the new unique number left by using index pointer
            placeIndex++; // Increment index pointer to prepare for next unique number
        }
    }

    return placeIndex;
}
