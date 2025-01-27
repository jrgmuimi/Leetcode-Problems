import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) 
    { // O(n) Time Complexity, O(n) Space Complexity [Worst case - If the "two pair" numbers are at the beginning and end of the nums array]
        HashMap<Integer, Integer> alreadyExists = new HashMap<Integer, Integer>(); // Hashmap for quicker retrievals since no duplicates
        int[] indices = new int[2]; // Store indices of found two sum elements

        int size = nums.length;
        for (int i = 0; i < size; i++)
        { // For each element, check if the subtraction of it from the target already exists in the hash map. 
        // If not, append to the hash map and keep searching for two pairs
            
            int otherNumToFind = target - nums[i]; 
            Integer otherNum = alreadyExists.get(otherNumToFind); // Primitive can't be null
            
            if (otherNum != null) // If hit on retrieval, store the two pair in indices array
            {
                indices[0] = otherNum;
                indices[1] = i;
                break; // There is only one unique pair
            }
            alreadyExists.put(nums[i], i); // If not, store the current integer at nums[i] as a key, and its index as a value
        }
        return indices;
    }
}