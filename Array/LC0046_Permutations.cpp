class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermutations(0, nums, ans);
        return ans;        
    }
    
    void findPermutations(int index, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            findPermutations(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
};
