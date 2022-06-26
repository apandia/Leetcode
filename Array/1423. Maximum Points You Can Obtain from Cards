class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum = 0;
        int n = cardPoints.size();
        
        for(int val : cardPoints)
            totalSum += val;
        
        if(n == k)
            return totalSum;
        
        int notPickCount = n-k;
        
        int currWindowSum = 0;
        //Find min sum for the window of size not pick count
        for(int i = 0; i < notPickCount; i++)
            currWindowSum += cardPoints[i];
        
        //Now find the min sum among all window of size notPickCOunt using sliding window technique
        int minWindowSum = currWindowSum;
        for(int i = notPickCount; i < n ; i++)
        {
            currWindowSum += cardPoints[i] - cardPoints[i-notPickCount];
            minWindowSum = min(minWindowSum, currWindowSum);
        }
        
        return totalSum - minWindowSum;
    }
};
