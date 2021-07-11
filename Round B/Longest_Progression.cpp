#include<bits/stdc++.h>
#define ll long long

using namespace std;


ll test_case() {
    int n; cin>>n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    ll forward[n];
    ll backward[n];
    backward[0] = 1;
    backward[1] = 2;
    for(int i = 2; i < n; i++) {
        if(arr[i] - arr[i - 1] == arr[i - 1] - arr[i - 2]) {
            backward[i] = backward[i - 1] + 1;
        } else {
            backward[i] = 2;
        }
    }
    forward[n - 1] = 1;
    forward[n - 2] = 2;
    for(int i = n - 3; i >= 0; i--) {
        if(arr[i + 1] - arr[i] == arr[i + 2] - arr[i + 1]) {
            forward[i] = forward[i + 1] + 1;
        } else {
            forward[i] = 2;
        }
    }
    ll ans = 2;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            ans = max(ans, forward[1] + 1);
        } else if(i == n - 1) {
            ans = max(ans, backward[n - 2] + 1);
        } else {
            ans = max(ans, forward[i + 1] + 1);
            ans = max(ans, backward[i - 1] + 1);
            if((arr[i + 1] - arr[i - 1])%2 == 0) {
                ll d = (arr[i + 1] - arr[i - 1])/2;
                ll combined = 1;
                if(i - 2 < 0) {
                    combined++;
                } else {
                    if(arr[i - 1] - arr[i - 2] == d) {
                        combined += backward[i - 1];
                    } else {
                        combined++;
                    }
                }
                if(i + 2 >= n) {
                    combined++;
                } else {
                    if(arr[i + 2] - arr[i + 1] == d) {
                        combined += forward[i + 1];
                    } else {
                        combined++;
                    }
                }
                ans = max(ans, combined);
            }
        }
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
