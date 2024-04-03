class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n, m;
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        int ans = 0;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(board[i][j] == word[0]){
                     vector<vector<int>> vis(n, vector<int>(m, 0));
                    ans |= dfs(board, word, vis,i, j, 1);
                }
            }
        }
        return ans;
    }

    bool dfs(vector<vector<char>>& board, string word, vector<vector<int>> &vis,int i = 0,int j = 0, int idx = 0) {
        vis[i][j] = 1;
        if(idx == word.size()) return true;
        int ret = 0;
        for(int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && board[ni][nj] == word[idx]) {
                ret |= dfs(board, word, vis,ni,nj,idx+1);
            }
        }
        vis[i][j] = 0;
        return ret;
    }
};