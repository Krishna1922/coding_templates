#include <bits/stdc++.h> 
vector<int> k_stack(int l, int n, int q, vector<vector<int>> &que){
    // Write your code here.
    vector<int> top(n, -1), next(l, 0), v(l, 0);
    for(int i = 0;i<l;i++){
        next[i] = i+1;
    }
    vector<int> ans(q, 0);
    next[l-1] = -1;
    int freespot = 0;
    for(int i = 0;i < q;i++){
        int opr = que[i][0];
        if(opr == 1){
            int Stackno = que[i][1], ele = que[i][2];
            if(freespot == -1){
                ans[i] = -1;
                continue;
            }
            // find findspot
            int index = freespot;

            // update fre&espot
            freespot = next[index];

            // insert element
            v[index] = ele;

            // update next
            next[index] = top[Stackno - 1];

            //update top
            top[Stackno - 1] = index;
            ans[i] = 0;

        }else if(opr == 2){
            int Stackno = que[i][1];
            if(top[Stackno - 1] == -1){
                ans[i] = -1;
                continue;
            }
            int index = top[Stackno - 1];

            top[Stackno - 1] = next[index];

            next[index] = freespot;

            freespot = index;

            ans[i] = v[index];
        }
    }
    return ans;


}