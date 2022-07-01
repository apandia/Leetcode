class Solution {
public:
    void findCombination(int index, int target, vector<int>& input, vector<vector<int>>& ans, vector<int>& ds) {
        //Base case
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        //recursion case
        for(int i = index; i< input.size(); i++)
        {
            if((i > index) && (input[i] == input[i-1])) continue;
            if(input[index] > target) break;

            ds.push_back(input[i]);
            findCombination(i+1, target-input[i], input, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0, target, candidates, ans, ds);

        return ans;        
    }
};
