class Solution {
public:
    int minDeletions(string s) {
        vector<int> frequency(26);
        
        for(auto c : s)
        {
            frequency[c-'a']++;
        }
        sort(frequency.begin(), frequency.end(), greater<int>());
        
        int result = 0;
        int currFrequency = frequency[0];
        
        for(int freq : frequency)
        {
            if(freq > currFrequency)
            {
                if(currFrequency > 0)
                    result += freq-currFrequency;
                else
                    result += freq;
            }
            currFrequency = min(currFrequency-1, freq-1);
        }
        return result;
    }
};
