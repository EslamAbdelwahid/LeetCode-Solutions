struct DSU{
    vector<int> par, siz, edges, Min_edge;
    DSU(){}
    DSU(int n){
        init(n);
    }
    void init(int n){
        par = edges = vector<int>(n+1);
        siz = vector<int>(n+1,1);
        Min_edge = vector<int>(n+1,2e9);
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
    bool merge(int u, int v, int cost){
        int root1 = find(u), root2 = find(v);
        if(siz[root1] < siz[root2]) swap(root1, root2);
        if(!same(u, v)) {
            siz[root1] += siz[root2];
            edges[root1] += edges[root2] + 1;
            Min_edge[root1] = min({Min_edge[root1], Min_edge[root2], cost});
        }else{
            edges[root1] += 1;
            Min_edge[root1] = min(cost, Min_edge[root1]);
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
    int get_Min(int u){
        return Min_edge[find(u)];
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n);
        for(auto &i : roads){
            dsu.merge(i[0], i[1], i[2]);
        }
        return dsu.get_Min(n);
    }
};

