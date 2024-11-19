class Solution {
public:
   bool pas[201][201] = {false};
    bool att[201][201] = {false};
    void dfs1(vector<vector<int>>& heights, int i, int j, int par)
    {
        if(i<0||  j<0 || i>=heights.size() ||  j >= heights[0].size() || par>heights[i][j])
        {
            return;
        }
        if(pas[i][j]) return;
        pas[i][j] = true;

        dfs1(heights,i-1,j,heights[i][j]);
        dfs1(heights,i,j-1,heights[i][j]);
        dfs1(heights,i+1,j,heights[i][j]);
        dfs1(heights,i,j+1,heights[i][j]);
    }

    void dfs2(vector<vector<int>>& heights, int i, int j, int par)
    {
        if(i<0||  j<0 || i>=heights.size() ||  j >= heights[0].size() || par>heights[i][j])
        {
            return;
        }
        if(att[i][j]) return;
        att[i][j] = true;

        dfs2(heights,i-1,j,heights[i][j]);
        dfs2(heights,i,j-1,heights[i][j]);
        dfs2(heights,i+1,j,heights[i][j]);
        dfs2(heights,i,j+1,heights[i][j]);
    }
   
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<int>>v;
        for(int i=0;i<heights[0].size();i++)
        {
            dfs1(heights,0,i,-1);
        }
        for(int i=0;i<heights.size();i++)
        {
            dfs1(heights,i,0,-1);
        }
        for(int i=0;i<heights.size();i++)
        {
            dfs2(heights,i,heights[0].size()-1,-1);
        }
        for(int i=0;i<heights[0].size();i++)
        {
            dfs2(heights,heights.size()-1,i,-1);
        }

        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(pas[i][j]==true && att[i][j]==true)
                {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    v.push_back(temp);
                }
            }
        }
        return v;
    }
};