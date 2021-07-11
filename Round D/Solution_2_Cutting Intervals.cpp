#include <algorithm>
#include <bitset>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename S>
using pbmap=tree<T, S, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define get_macro(_1,_2,_3,_4,_5,_6,mcr,...) mcr 

#define rd1(a) cin >> (a)
#define rd2(a, b) cin >> (a) >> (b)
#define rd3(a, b, c) cin >> (a) >> (b) >> (c)
#define rd4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define rd(...) get_macro(__VA_ARGS__, dummy, dummy, rd4, rd3, rd2, rd1)(__VA_ARGS__)

#define in1( a ) int a; rd( ( a ) )
#define in2( a, b ) int a, b; rd( ( a ), ( b ) )
#define in3( a, b, c ) int a, b, c; rd( ( a ), ( b ), ( c ) )
#define in4( a, b, c, d ) int a, b, c, d; rd( ( a ), ( b ), ( c ), ( d ) )
#define in( ... ) get_macro( __VA_ARGS__, dummy, dummy, in4, in3, in2, in1 )( __VA_ARGS__ )

#define repa(i, a, b) for (auto i = (a); i <= (b); ++i)
#define repd(i, a, b) for (auto i = (a); i >= (b); --i)
#define forz(i, n) for (auto i = 0; i < n; ++i)
#define fori(i, n) for (auto i = 1; i <= n; ++i)
#define fore(i, t) for (auto &&i : t)

#define all(x) (x).begin(), (x).end()
#define repmin(x, y) x = min(x, y)
#define repmax(x, y) x = max(x, y)
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ulll unsigned __int128
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define pss pair<string, string>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vd vector<ld>
#define vs vector<string>
#define umap unordered_map

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define sz(t) ((int)(t).size())

#define inf 1000000100
#define neginf -1000000100
#define DBG(args...) { cerr << "[" << __LINE__ << "] "; string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

template <typename T, typename S> ostream &operator<<(ostream &s, pair<T, S> &t) { return s << "(" << t.first << "," << t.second << ")"; }
template <typename T> ostream &operator<<(ostream &s, vector<T> &t) { s << "{ "; fore(x, t) s << x << " "; s << "}"; return s; }
template <typename T> ostream &operator<<(ostream &s, set<T> &t) { s << "{ "; fore(x, t) s << x << " "; s << "}"; return s; }
template <typename T> ostream &operator<<(ostream &s, unordered_set<T> &t) { s << "{ "; fore(x, t) s << x << " "; s << "}"; return s; }
template <typename T, typename S> ostream &operator<<(ostream &s, map<T, S> &m) { s << "{ "; for (auto i = m.begin(); i != m.end(); i++) s << "(" << i->first << " -> " << i->second << ") "; s << "}"; return s; }
template <typename T, typename S> ostream &operator<<(ostream &s, unordered_map<T, S> &m) { s << "{ "; for (auto i = m.begin(); i != m.end(); i++) s << "(" << i->first << " -> " << i->second << ") "; s << "}"; return s; }

void err(istream_iterator<string> it) {cerr << "\n";}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << "\t"; err(++it, args...); }

template <typename T> void read_vec(T& v, int n) { forz(i, n) { typename T::value_type t; cin >> t; v.pb(t); } }
template <typename T> void write_vec(T& v) { forz(i, sz(v)) { cout << v[i] << " \n"[i == sz(v) - 1]; } }

// globals
//

void preproc() {
  // add any preprocessing valid for all tests here
  //
}

using tlii = tuple<ll,int>;
void single(int testId) {
  int n; ll c;
  cin >> n >> c;
  vector<tlii> a;
  forz(i,n){
    ll left, right;
    cin >> left >> right;
    a.pb({left, 1});
    a.pb({right, -1});
  }
  sort(all(a));

  vector<pll> b;
  ll active = 0;
  ll last = get<0>(a[0]);
  int i = 0;
  while(i < sz(a)) {
    auto [p, t] = a[i];
    int j = i;
    if (t == 1) {
      if (p > last) b.pb({active, p-last});
      last = p;
      while(j < sz(a)) {
        auto [q, s] = a[j];
        if (q > p) break;
        if (s > t) break;
        active++;
        j++;
      }
    } else {
      if (p > last + 1) b.pb({active, p-last-1});
      last = p;
      while(j < sz(a)) {
        auto [q, s] = a[j];
        if (q > p) break;
        if (s > t) break;
        active--;
        j++;
      }
      b.pb({active, 1});
    }
    i = j;
  }

  sort(all(b), [](auto x, auto y){return x > y;});

  ll ans = n;
  fore(e, b) {
    ll k=min(e.se, c);
    ans += k*e.fi;
    c -= k;
  }

  cout << "Case #"<< testId << ": " << ans << "\n";
}

void multiple() {
  // multiple tests in single file
  int T;
  cin >> T;
  for (auto t = 1; t <= T; t++)
    single(t);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  preproc();

  //single(0);
  multiple();

  return 0;
}
