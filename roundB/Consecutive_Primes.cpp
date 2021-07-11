#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll last_prime = 1000000007;

int check_prime(ll num) {
    ll ans = 1;
    if(num == 1) {
        return 0;
    }
    if(num == 2 || num == 3) {
        return 1;
    }
    for(ll i = 2; i <= (ll)sqrt(num); i++) {
        if(num%i == 0) {
            ans = 0;
            break;
        } 
    }
    return ans;
}

ll test_case(ll Z) {
    ll b = 2, e = last_prime;
    ll ans;
    while(b <= e) {
        ll mid = b + (e - b)/2;
        ll less_prime = mid - 1;
        for(ll i = mid - 1; i >= 2; i--) {
            if(check_prime(i)) {
                less_prime = i;
                break;
            }
        }
        ll great_prime = mid;
        for(ll i = mid; i <= last_prime; i++) {
            if(check_prime(i)) {
                great_prime = i;
                break;
            }
        }
        if(less_prime*great_prime <= Z) {
            ans = less_prime*great_prime;
            b = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll Z; cin>>Z;
        ll ans = test_case(Z);
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
