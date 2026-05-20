#include <bits/stdc++.h>
 
using namespace std;
#include <climits>
#include <string>
#include <cmath>
 
// --- Type Aliases ---
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using pii = pair<int, int>;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
//#define dbg(x)
#endif
 
// --- Constants ---
constexpr int MOD = 1e9+7;
constexpr ll INF = 1e18;
 
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
vector<ll> fact(1e6+1);
vector<ll> ifact(1e6+1);
 
ll binary(ll a, ll b) {
    if (b == 0)return 1;
    if (b%2==1) {
        return (a*binary(a,b-1))%MOD;
    }else {
        ll num = binary(a,b/2);
        return (num*num)%MOD;
    }
}
void getFact() {
    fact[0]=1;
    for (int i = 1; i <= 1e6; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    ifact[1e6] = binary(fact[1e6], MOD-2)%MOD;
    for (int i = 1e6-1; i>=0; i--) {
        ifact[i]=(ifact[i+1]*(i+1))%MOD;
    }
}
void solve(){
    int a,b;
    cin >> a >> b;
    //a!/b!(a!-b!)
    ll total = ((fact[a] * ifact[b])%MOD * ifact[a-b])%MOD;
    cout << total << "\n";
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    getFact();
    cin >> t;
    while(t--) {
        solve();
    }
 
    return 0;
}