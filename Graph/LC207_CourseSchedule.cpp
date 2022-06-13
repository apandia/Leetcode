class Solution {
public:
    bool checkCycle(int node, vector<int>& visited, vector<vector<int>>& adjList)
    {
        if(visited[node] == 2)
            return true;
        
        visited[node] = 2;
        
        for(auto neighbour : adjList[node])
        {
            if(visited[neighbour] != 1)
            {
                if(checkCycle(neighbour, visited, adjList))
                    return true;
            }
        }
        
        visited[node] = 1;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses+1);
        
        for(int i =0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> visited(numCourses+1, 0);
        
        for(int i = 0; i <= numCourses; i++)
        {
            if(visited[i] == 0)
            {
                if(checkCycle(i, visited, adjList))
                    return false;
            }
        }
        return true;
    }
};
