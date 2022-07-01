class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end()); //if we sort and find median the operation will be O(N Log N) while with nth_element it is O(N)
        
        int median = nums[n/2];
        
        int numMoves = 0;
        
        for(auto num : nums)
        {
            numMoves += abs(median-num);
        }
        
        return numMoves;
    }
};
