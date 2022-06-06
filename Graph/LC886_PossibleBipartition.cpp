class Solution {
public:
    bool isBipartite(int node, vector<vector<int>>& adjList, vector<int>& nodeColor)
    {
        queue<int> q;
        q.push(node);
        
        nodeColor[node] = 1;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(auto neighbour : adjList[curr])
            {
                if(nodeColor[neighbour] == -1)
                {
                    q.push(neighbour);
                    nodeColor[neighbour] = 1-nodeColor[curr];
                }
                else
                {
                    if(nodeColor[curr] == nodeColor[neighbour])
                        return false;
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {       
        vector<vector<int>> adjList(n+1);
        
        for(int i =0; i < dislikes.size(); i++)
        {
            adjList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjList[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> nodeColor(n+1, -1);
        
        for(int i = 1; i <= n ; i++)
        {
            if(nodeColor[i] == -1)
            {
                if(!isBipartite(i, adjList, nodeColor))
                    return false;
            }            
        }        
        return true;
    }
};
