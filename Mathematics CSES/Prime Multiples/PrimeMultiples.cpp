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
 
inline int popcount(long long x) {
    return __builtin_popcountll(x);
}
ll k,n;
vector<ll> primes;
ll getIntx(int mask) {
    ll intx = 1;
    for (int i = 0; i < k; i++) {
 
        if ((mask >> i & 1) == 1) {
            if (n / intx < primes[i]) {
                return 0; // The denominator exceeded n, so n / intx is 0
            }
            intx*=primes[i];
        }
    }
 
    return n/intx;
}
void solve(){
    int a;
    cin >> n >> k;
    primes.assign(k,0);
    for (int i = 0; i < k; i++)cin >> primes[i];
    ll total = 0;
    for (int i = 1; i < (1 << k); i++) {
        ll intx = getIntx(i);
        if (popcount(i)%2==1) {
            total+=intx;
        }else {
            total -= intx;
        }
    }
    cout << total << "\n";
 
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
 
    //cin >> t;
    while(t--) {
        solve();
    }
 
    return 0;
}