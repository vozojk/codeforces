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



void solve() {

    int n,c;
    cin >> n >> c;

    vector<int> have(n);
    vector<int> need(n);
    for (int i = 0; i < n; i++) {
        cin >> have[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> need[i];
    }
    int totalpre = 0;
    for (int i = 0; i < n; i++) {
        if (have[i]<need[i]) {
            break;
        }
        totalpre += have[i]-need[i];
        if (i==n-1) {
            cout << totalpre << "\n";
            return;
        }
    }
    sort(have.begin(), have.end());
    sort(need.begin(), need.end());
    int total = c;
    for (int i = 0; i < n; i++) {
        if (have[i]<need[i]) {
            cout << -1 << "\n";
            return;
        }
        total += have[i]-need[i];
    }
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