class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> nodeIndegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++)
        {
            for(auto it : adjList[i])
            {
                nodeIndegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < nodeIndegree.size(); i++)
        {
            if(nodeIndegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        int count = 0;
        stack<int> topo;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            count++;
            topo.push(curr);
            
            for(auto neighbour : adjList[curr])
            {
                nodeIndegree[neighbour]--;
                if(nodeIndegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        
        vector<int> result;
        
        if(count == numCourses)
        {
            while(!topo.empty())
            {
                result.push_back(topo.top());
                topo.pop();
            }            
        }
        
        return result;
    }
};
