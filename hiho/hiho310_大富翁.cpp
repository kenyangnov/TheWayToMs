#include <iostream>
#include <vector>
using namespace std;

void Solve(vector<int> &cell, int start){
    int ans = 0;
    for(int i=start; i<=cell.size()-1; i+=cell[i]){
        ans++;
    }
    cout<<ans<<endl;
}

int main(){
    int n, q, flag, y, u, v;
    cin>>n;
    vector<int> cell(n+1);
    for(int i=1; i<=n; i++){
        cin>>cell[i];
    }
    cin>>q;
    while(q--){
        cin>>flag;
        if(flag==1){
            cin>>y;
            Solve(cell, y);
        } else if(flag==2){
            cin>>u>>v;
            cell[u]=v;
        } else{
           break; 
        }
    }
    return 0;
}