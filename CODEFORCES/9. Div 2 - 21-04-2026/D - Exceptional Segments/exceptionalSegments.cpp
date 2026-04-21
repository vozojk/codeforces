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
#define dbg(x)
#endif



// --- Constants ---
const int MOD = 998244353;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

ll count_mod(ll max, ll remainder, ll mod) {
    if (max < 0)return 0;
    return (max-remainder+mod)/mod;
}

void solve() {

    ll n,x;
    cin >> n >> x;

    ll l_zero = count_mod(x-1, 3, 4)+1;
    ll r_zero = count_mod(n, 3, 4) - count_mod(x-1, 3, 4);

    ll l_one = count_mod(x-1, 1, 4);
    ll r_one = count_mod(n, 1, 4) - count_mod(x-1, 1, 4);

    ll ans_zero = ((l_zero%MOD)*(r_zero%MOD))%MOD;
    ll ans_one = ((l_one%MOD)*(r_one%MOD))%MOD;
    cout << (ans_zero+ans_one)%MOD << "\n";


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;


}