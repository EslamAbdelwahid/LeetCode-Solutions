class Solution {
public:

struct DSU{
    vector<int>par,siz;
    int comp;
    DSU(int n){
        par = vector<int>(n+1);
        siz = vector<int>(n+1,1);
        comp = n;
        for(int i = 0;i <= n;++i){
            par[i] = i;
        }
    }
    int find(int u){
        if(par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    bool merge(int u , int v){
        int l1 = find(u) , l2 = find(v);
        if(l1 != l2){
            --comp;
            if(siz[l1] < siz[l2]) swap(l1,l2);
            siz[l1] += siz[l2];
            par[l2] = l1;
            return 1;
        }
        return 0;
    }
};
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int extra = 0;
        for(auto &i : connections){
            int u = i[0] , v = i[1];
            if(!dsu.merge(u , v)) ++extra;
        }
        int need = dsu.comp - 1;
        if(extra >= need) return need;
        return -1;
    }
};