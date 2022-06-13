class Solution {
public:   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //1. Prepare adjList
        vector<vector<int>> adjList(numCourses);
        
        for(int i =0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        //2. Fill indegree count for each node
        vector<int> nodeIndegree(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++)
        {
            for(auto it : adjList[i])
            {
                nodeIndegree[it]++;
            }
        }
        
        //3. Add all node with indegree as 0 to queue
        queue<int> q;
        for(int i = 0; i < nodeIndegree.size(); i++)
        {
            if(nodeIndegree[i] == 0)
                q.push(i);            
        }
        
        //4. Apply Kahn Algorithm (BFS for topological sort)
        int count = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            count++;
            
            for(auto neighbour : adjList[curr])
            {
                nodeIndegree[neighbour]--;
                if(nodeIndegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        
        if(count == numCourses)
            return true;
        
        return false;        
    }
};
