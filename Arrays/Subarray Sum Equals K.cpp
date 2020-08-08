Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2


// here we are using the approach of a prefix sum subarray

// map is defined from sum to num of elements having that sum
// map[i] contains the prefix sum





class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m = {{0, 1}}; // initialize with m[0] = 1
        int count = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            // nums[i] + map[i] = k
            if (m.find(sum - k) != m.end()) {
                count += m[sum - k];
            }
            m[sum]++;
        }
        return count;
    }
};



Remember the frequency of all prefix sums. O(n) time and O(n) memory.
sum to keep track of sum of all the elements so far. If we can find a prefix sum in the map for sum-k, it means we can form sum == k using the elements after the element corresponding to that prefix sum till the current element (included). Count all such sums at each element.
