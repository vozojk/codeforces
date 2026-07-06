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

#ifdef lOCAl
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
//#define dbg(x)
#endif

// --- Constants ---
constexpr int MOD = 998244353;
constexpr ll INF = 1e9;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#include <iostream>
#include <string>

using namespace std;

void solve() {

    ll n,x;

    cin >> n >> x;
    ll edit = x;
    vector<ll> jump(n);
    vector<ll> freq(n);
    vector<ll> cost(n);
    vector<ll> perBack1Before(n);
    vector<ll> perbackincl(n);
    pair<ll,ll> maxJumpIncl;
    bool zer = false;
    bool forward = false;
    for (int i = 0; i < n; i++) {
        cin >> jump[i] >> freq[i] >> cost[i];
        perBack1Before[i] = jump[i]*(freq[i]-1);
        edit-=perBack1Before[i];

        perbackincl[i] = jump[i]*freq[i]-cost[i];
        if (perbackincl[i]>0)forward = true;
        if (maxJumpIncl.first<perbackincl[i]) {
            maxJumpIncl = {perbackincl[i], i};
        }

    }
    if (edit<=0) {
        cout << 0 << "\n";
        return;
    }
    if (!forward) {
        cout << -1 << "\n";
        return;
    }
    int idx = maxJumpIncl.second;
    if (edit%maxJumpIncl.first==0)cout << edit/maxJumpIncl.first << "\n";
    else cout << edit/maxJumpIncl.first+1 << "\n";







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