class Solution {
public:
    void markIslands(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != '1')
            return;
        
        grid[i][j] = '2';
        
        markIslands(grid, i-1, j);
        markIslands(grid, i+1, j);
        markIslands(grid, i, j-1);
        markIslands(grid, i, j+1);        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int numIslands = 0;
        
        for(int i = 0; i< grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    markIslands(grid, i, j);
                    numIslands++;
                }                
            }            
        }
        return numIslands;
    }
};
