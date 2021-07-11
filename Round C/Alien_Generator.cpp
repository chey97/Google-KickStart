#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll g; cin>>g;

        ll ans = 0;
        for(int i  = 1; i <= (int)pow(2*g, 0.5); i++) {
            if((2*g)%i == 0) {
                if((((2*g)/i) - i + 1)%2 == 0) {
                    ans++;
                }
            }
        }
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
