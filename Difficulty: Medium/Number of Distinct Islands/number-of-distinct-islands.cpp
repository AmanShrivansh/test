//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    //string tmp="";
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        set<string>ans;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if(grid[i][j]){
           string tmp = "";
           dfs(grid,i,j,tmp);
           ans.insert(tmp);
          }
        
        return ans.size();
    }
    
    
    void dfs(vector<vector<int>>& grid,int r,int c,string &tmp){
      //  if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==1)return;
        grid[r][c]=0;
        
        if(r+1<grid.size() && grid[r+1][c]==1)
        {
            tmp+="d";
            dfs(grid,r+1,c,tmp);
        }
        
        if(r-1>=0 && grid[r-1][c]==1)
        {
            tmp+="u";
            dfs(grid,r-1,c,tmp);
        }
        
        if(c+1<grid[0].size() && grid[r][c+1]==1)
        {
            tmp+="l";
            dfs(grid,r,c+1,tmp);
        }
        
        if(c-1>=0 && grid[r][c-1]==1)
        {
            tmp+="r";
            dfs(grid,r,c-1,tmp);
        }
        
        tmp+="#";
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends