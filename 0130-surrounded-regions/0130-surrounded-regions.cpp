class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='O')
            return;

        grid[i][j]='$';

        dfs(grid,i,j-1);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i+1,j);
    }

    void solve(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int j=0;j<n;j++)
            if(grid[0][j]=='O')
                dfs(grid,0,j);

        for(int j=0;j<n;j++)
            if(grid[m-1][j]=='O')
                dfs(grid,m-1,j);

        for(int i=1;i<m-1;i++)
            if(grid[i][0]=='O')
                dfs(grid,i,0);

        for(int i=1;i<m-1;i++)
            if(grid[i][n-1]=='O')
                dfs(grid,i,n-1);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='O')
                    grid[i][j]='X';
                else if(grid[i][j]=='$')
                    grid[i][j]='O';
            }
        }
    }
};