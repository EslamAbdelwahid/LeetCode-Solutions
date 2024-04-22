class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map < string, bool > exist, vis;
        for(auto &s : deadends) exist[s] = true;
        queue<string> q;
        q.push({"0000"});
        if(exist["0000"]) return -1;
        int depth = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                string u = q.front(); q.pop();
                if(u == target) return depth ;
                if(vis[u]) continue;
                for(int i = 0;i < 4;++i){
                    string v = u;
                    if(v[i] != '9'){
                        v[i]++;
                    }else v[i] = '0';
                    if(!vis[v] && !exist[v]) q.push(v);
                    v = u;
                    if(v[i] != '0') v[i]--;
                    else v[i] = '9';
                    if(!vis[v] && !exist[v]) q.push(v);
                }
                vis[u] = true ;
            }
            ++depth ;
        }
        return -1;
    }
};