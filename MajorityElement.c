/**
Used Boyer-Moore Majority Voting Algorithm: First, choose any candidate in the array to start 
and iterate through the rest of the array. We assign it an initial voting count of 1. For example 
the first element, nums[0]. We then evaluate the next element nums[1] and check if it is equal to 
our current candidate. If it is, we increase the votes, if not we decrease the vote and nums[1] 
becomes the new candidate. And so forth...

The rationale is that a majority element will not have the same amount of "votes" as another 
element: Consider the array [2, 2, 2, 2, 1, 1, 1, 1, 2]. We can see that the vote count of 2 will 
reach 4, but once we reach the fourth 1, or the second to last element, the count of 2 becomes 0. 
So, 1 now becomes the candidate and has a voting count of 1, but the final 2 subtracts 1 from 1's 
voting count and becomes the final candidate. If the final 2 was any other number other than 1 or 2, 
such as 4, we can see there would be no majority as 1 and 2 would be tied and don't cross the 
majority threshold. 4 would be returned in this case, but we can return any other element. Since we 
assume there is always a majority element in the problem, we don't have to handle the return 
of a non-majority array
https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/
 */
int majorityElement(int* nums, int numsSize) 
{ // O(n) Time Complexity, O(1) Space Complexity
    int candidate = nums[0];
    int candidate_ct = 1;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == candidate) { candidate_ct++; } 
        else { candidate_ct--; }

        if (candidate_ct == 0) { candidate = nums[i]; candidate_ct = 1; }
    }

    return candidate;
}