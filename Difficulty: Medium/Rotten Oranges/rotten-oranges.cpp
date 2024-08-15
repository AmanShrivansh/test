//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    
    typedef pair<int,int> pairs;
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pairs>q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        if(cnt==0)return 0;
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        
        int time=-1;
        
        while(q.size()){
            time++;
            int sz=q.size();
            while(sz--){
                pairs p = q.front(); 
                q.pop();
                int x=p.first;
                int y=p.second;
                for(int i=0;i<4;i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends