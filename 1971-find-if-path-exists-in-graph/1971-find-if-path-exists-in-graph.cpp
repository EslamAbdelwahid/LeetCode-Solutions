struct DSU{
    vector<int> par, siz, edges;
    DSU(){}
    DSU(int n){
        init(n);
    }
    void init(int n){
        par = edges = vector<int>(n+1);
        siz = vector<int>(n+1,1);
        for(int i = 0;i <= n;++i){
            par[i] = i;
        }
    }
    int find(int u){
        return u == par[u] ? u : par[u] = find(par[u]);
    }
    bool same(int u, int v){
        return find(u) == find(v);
    }
    bool merge(int u, int v){
        int root1 = find(u), root2 = find(v);
        if(siz[root1] < siz[root2]) swap(root1, root2);
        if(!same(u, v)) {
            siz[root1] += siz[root2];
            edges[root1] += edges[root2] + 1;
        }else{
            edges[root1] += 1;
        }
        par[root2] = root1;
        return true;
    }
    int size(int u){
        return siz[find(u)];
    }
    int get_edges(int u){
        return edges[find(u)];
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);
        for(auto &edge : edges){
            dsu.merge(edge[0], edge[1]);
        }
        return dsu.same(source, destination); 
    }
};