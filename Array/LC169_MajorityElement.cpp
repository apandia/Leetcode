class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int number = -1;
        
        int totalElement = nums.size();
        
        unordered_map<int, int> um;
        
        for(auto num : nums){
            um[num]++;
            if(um[num] > (totalElement/2)) {
                number = num;
            }
        }
        
        return number;        
    }
};
