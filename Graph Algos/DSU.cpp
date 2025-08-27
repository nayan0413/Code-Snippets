class DisjointSet{
    vector<int> parent, rank, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    //find ultimate parent
    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    //union by rank
    void UnionByRank(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    //union by size
    void UnionBySize(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
