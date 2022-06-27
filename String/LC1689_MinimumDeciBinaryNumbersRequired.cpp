class Solution {
public:
    int minPartitions(string n) {
        int numRequired = 0;
        
        for(int i = 0; i < n.size(); i++)
        {
            numRequired = max(numRequired, n[i]-'0');
        }
        return numRequired;
    }
};
