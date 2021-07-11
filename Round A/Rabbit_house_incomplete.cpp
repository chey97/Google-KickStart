#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll test_case() {
    ll r,c; cin>>r>>c;
    int grid[r][c];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin>>grid[i][j];
        }
    }
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll ans = test_case();
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
