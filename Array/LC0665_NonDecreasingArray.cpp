class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int index = -1;
        
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                if(index != -1)
                    return false;
                
                index = i;
            }
        }
        
        return (index == -1) || (index == 0) || (index == nums.size()-2) || (nums[index-1] <= nums[index+1]) || (nums[index] <= nums[index+2]);
    }
};
