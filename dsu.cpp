class DSU{
    public:
    vector<int> par;
    int n;
    DSU(int size){
        n = size;
        par.assign(size+1, -1);
    }
    int findset(int node){
        if(par[node] < 0) return node;
        return par[node] = findset(par[node]);
    }
    void Union(int a, int b){
        a = findset(a);
        b = findset(b);
        if(a!=b){
            if(par[a] > par[b]){
                swap(a, b);
            }
            par[a] += par[b];
            par[b] = a;
        }
    } 
    int compSize(){
        int ans = 0;
        for(int i =0; i < n; i++){
            ans += par[i]<0;
        }
        return ans;
    }

};