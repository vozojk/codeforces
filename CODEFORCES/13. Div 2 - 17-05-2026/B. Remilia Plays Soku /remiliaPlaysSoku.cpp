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
constexpr ll INF = 2*1e9;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};




void solve() {

    int n,x1,x2,k;
    cin >> n >> x1 >> x2 >> k;
    ll total = 0;
    //move away if not exactly in the middle, if so let other move first, then moving k times which adds k seconds and then she waits for dist_diff seconds.
    if (n==2 || n==3) {
        cout << 1 << "\n";
        return;
    }
    total+=k;
    ll dleft = max(x1,x2)-min(x1, x2);
    ll dright = n-dleft;
    total+=min(dleft, dright);
    cout << total << "\n";



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