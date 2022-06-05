#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 

/* 
Problem Description:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/


/*
My Brute Force Solution:
    - Iterate through the vector, for each iteration, start iterating through the vector again, 
        but starting from the current index + 1 to save time
    - If the sum of the element at the current index and the element at the second index is equal to the target, 
        return the indices of the two elements
*/
class Solution {
    public: 
        vector<int> twoSum(vector<int>& nums, int target) {
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    if ((nums[i] + nums[j]) == target && i != j) {
                        nums.clear();
                        nums.push_back(i);
                        nums.push_back(j);
                        return nums;
                    }
                }
            }
            return nums;
        }
};

/* 
My Optimized Solution: 
    - Iterate through the vector, for each value at the current index,
        check to see if target - value is in the unordered map.
    - If it is, return the indices of the two elements.
    - Place the element at the current index as a key in the 
        unordered map, and the index as the value.
    - 
*/
class OptimizedSolution {
    public: 
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> myMap;

            for (int i = 0; i < nums.size(); ++i) {
                auto itr = myMap.find(target - nums[i]);
                if (itr == myMap.end())
                    myMap[nums[i]] = i;

                else if (itr != myMap.end() && i != itr->second) {
                    nums.clear();
                    nums.push_back(i);
                    nums.push_back(itr->second);
                    return nums;
                }
            }
            return nums;
        }
};