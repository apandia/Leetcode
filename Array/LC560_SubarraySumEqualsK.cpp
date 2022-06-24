class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(nums.size() == 0)
            return 0;
        
        unordered_map<int, int> um;
        
        int prefixSum = 0;
        int count = 0;
        
        for(auto value : nums)
        {
            prefixSum += value;
            
            if(prefixSum == k)
                count++;
            
            if(um.find(prefixSum-k) != um.end())
                count += um[prefixSum-k];
            
            um[prefixSum] += 1;
        }
        
        return count;
    }
};
