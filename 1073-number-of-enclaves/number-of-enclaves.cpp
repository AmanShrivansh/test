class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
      int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==1)
                dfs(grid,i,j);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cnt++;
            }
        }
        
        return cnt;
    }
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    
    void dfs(vector<vector<int>>& grid,int r,int c){
        
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size() || grid[nr][nc]==0)continue;        
            dfs(grid,nr,nc);
        }
    }
    
};