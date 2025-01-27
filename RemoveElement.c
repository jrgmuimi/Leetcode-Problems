void swap(int* nums, int index1, int index2) // Swap two elements in the nums array given two indices
{ // Will be useful to bring the "non-val" occurences to the front as desired
    int cp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = cp;
}

// O(n^2) Time Complexity [Worst Case - If all elements in the array are the target value n(n+1) / 2 Operations], O(1) Space Complexity
int removeElement(int* nums, int numsSize, int val) 
{
    int not_val_ct = 0; // Count number of non-val elements

    for (int i = 0; i < numsSize; i++) // Check each element to see if it is the targeted value
    {
        if (nums[i] == val) // If so,
        {
            for (int j = i+1; j < numsSize; j++) // In order to shift the non-target values to the front, we search
            { // For the first non-target value in the rest of the array at the current index (if it exists)
                if (nums[j] != val)
                {
                    swap(nums, i, j); // We then swap or shift their locations 
                    not_val_ct++; // Since we found a non-target value, we increment the count
                    break; // Only looking for first occurence, so break once found
                }
            }
        } 
        else { not_val_ct++; } // If not, increment non-target value count
    }

    return not_val_ct;
}
