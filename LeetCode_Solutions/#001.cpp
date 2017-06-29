//#001
//
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){

            int search = target - nums[i];
            if(umap.find(search)!=umap.end() && umap[search]!=i){
                ans.push_back(umap[search]);
                ans.push_back(i);
                return ans;
            }
            umap[nums[i]]=i;
        }
    }
};
