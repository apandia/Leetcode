class Solution {
public:
    void findCombination(int index, vector<int>& input, int target, vector<vector<int>>& ans, vector<int>& ds){
        //Base case
        if(index == input.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        //recursion case
        //pick same index
        if(input[index] <= target){
            ds.push_back(input[index]);
            findCombination(index, input, target-input[index], ans, ds);
            ds.pop_back();
        }
        
        //Pick next index
        findCombination(index+1, input, target, ans, ds);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        findCombination(0, candidates, target, ans, ds);
        
        return ans;
        
    }
};
