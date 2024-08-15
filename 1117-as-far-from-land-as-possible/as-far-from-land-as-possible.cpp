class Solution {
public:
    typedef pair<int,int>pairs;
    
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        queue<pairs>q;
        int dis=-1;
        
        
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        int cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(grid[i][j])q.push({i,j});
            else{
                cnt++;
            }  
            }  
        if(cnt==0)return -1;
        while(q.size()){
            dis++;
            int sz=q.size();
            while(sz--){
                pairs p = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=p.first+dir[i][0];
                    int ny=p.second+dir[i][1];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0){
                        grid[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        return dis;
    }
};