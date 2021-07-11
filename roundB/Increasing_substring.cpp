#include<bits/stdc++.h>
#define ll long long

using namespace std;


vector<ll> test_case() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> ans(n);
    ans[0] = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] > s[i-1]) {
            ans[i] = ans[i - 1] + 1;
        } else {
            ans[i] = 1;
        }
    }
    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        vector<ll> ans = test_case();
        cout<<"Case #"<<case_no+1<<": ";   //<<ans<<"\n";
        for(int i = 0; i < ans.size(); i++) {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}
