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

    int n,m;
    cin >> n >> m;

    unordered_map<int,int> cnts;
    vector<unordered_map<int,int>> setcnt(n);
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        int a;
        for (int j = 0; j < sz; j++) {
            cin >> a;
            cnts[a]++;
            setcnt[i][a]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (cnts[i]<1) {
            cout << "no\n";
            return;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool good = true;
        for (auto p : setcnt[i]) {
            if (cnts[p.first]-p.second<=0) {
                good = false;
                break;
            }
        }
        if (good)cnt++;
    }
    cout << (cnt>=2 ? "YES" : "NO") << "\n";
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