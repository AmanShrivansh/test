class Solution {
public:
    typedef pair<int,int>pairs;
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pairs>q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }else{
                    grid[i][j]=-1;
                }
                
            }
        
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while(q.size()){
            pairs rem = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=rem.first+dir[i][0];
                int nc=rem.second+dir[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==-1){
                    grid[nr][nc] = grid[rem.first][rem.second]+1;
                    q.push({nr,nc});
                }
            }
        }
        return grid;
    }
};