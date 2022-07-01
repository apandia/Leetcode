class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge;
        stack<int> st;
        unordered_map<int, int> numNgeMap;

        for(int i = nums2.size()-1; i >=0; i--)
        {
            while(!st.empty() && (st.top() < nums2[i]))
            {
                st.pop();
            }

            if(!st.empty())
            {
                numNgeMap[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for(int num : nums1)
        {
            if(numNgeMap.count(num))
                nge.push_back(numNgeMap[num]);
            else
                nge.push_back(-1);
        }

        return nge;        
    }
};
