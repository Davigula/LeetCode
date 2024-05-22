// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        std::unordered_map<int, int> num_to_index;

        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            
            int complement = target - num;

        
            if (num_to_index.find(complement) != num_to_index.end()) {
                
                return {num_to_index[complement], i};
            }

            
            num_to_index[num] = i;
        }

    
        return {};
    }
};

#include <iostream>

int main() {
    Solution solution;
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = solution.twoSum(nums1, target1);
    std::cout << "Output: [" << result1[0] << ", " << result1[1] << "]\n"; // Output: [0, 1]

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = solution.twoSum(nums2, target2);
    std::cout << "Output: [" << result2[0] << ", " << result2[1] << "]\n"; // Output: [1, 2]

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = solution.twoSum(nums3, target3);
    std::cout << "Output: [" << result3[0] << ", " << result3[1] << "]\n"; // Output: [0, 1]

    return 0;
}

