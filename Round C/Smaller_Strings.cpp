#include<bits/stdc++.h>
#define ll long long
#define p 1000000007

using namespace std;


ll power(ll x, ll y, ll m)
{
    ll res = 1;     // Initialize result
 
    x = x % m; // Umdate x if it is more than or
                // equal to m
  
    if (x == 0) return 0; // In case x is divisible by m;
 
    while (y > 0)
    {
        // If y is odd, multimly x with result
        if (y & 1)
            res = (res*x) % m;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % m;
    }
    return res;
}

ll test_case() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    string last = s;
    int consider = 1; 
    ll ans = 0;
    for(int i = 1; i < ((n+1)/2) + 1; i++) {
        char limit = min(k + 97 - 1, (int)s[i - 1]);
        if(limit < (int)s[i-1]) {
            ans = (ans + power(k, (n + 1)/2  - i + 1, p))%p;
            consider = 0;
            break;
        } else {
            ans = (ans + ((limit - 97)*power(k, (n + 1)/2  - i, p))%p)%p;
            last[i - 1] = limit;
            last[n - i] = limit;
        }
    }
    if(consider && last < s) {
        ans = (ans + 1)%p;
    }
    return ans;

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
