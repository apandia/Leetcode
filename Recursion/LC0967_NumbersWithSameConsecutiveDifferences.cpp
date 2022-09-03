class Solution {
public:
    void  dfs(int n, int k, int curr, int prev, vector<int>& result)
    {
        if(n == 0)
        {
            result.push_back(curr);
            return;
        }

        int next = prev +k;
        if(next <= 9)
        {
            dfs(n-1, k, (curr * 10)+next, next, result);
        }

        next = prev - k;
        if(k != 0 && next >= 0)
        {
            dfs(n-1, k, (curr * 10)+next, next, result);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n == 1)
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        vector<int> result;

        for(int i = 1; i <= 9; i++)
        {
            dfs(n-1, k, i, i, result);
        }

        return result;   
    }
};
