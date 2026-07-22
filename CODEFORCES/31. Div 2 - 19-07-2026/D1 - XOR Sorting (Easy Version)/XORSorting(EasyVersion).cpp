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
constexpr int MOD = 1e9+7;
constexpr ll INF = 1e9;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#include <iostream>

using namespace std;



void solve() {


    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    bool sorted = true;
    cin >> a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i]<a[i-1])sorted=false;
    }
    vector<int> tosort =a;
    sort(tosort.begin(), tosort.end());
    
    if (sorted) {
        cout << 0 << "\n";
        return;
    }
    for (int two = 1; two <= 2*n; two = two*2) {
        bool ok = true;
        for (int i = 0; i < n; i+=two) {
            int end = min(n, i+two);
            int sz = end-i;

            vector<int> piece(a.begin()+i, a.begin()+end);

            sort(piece.begin(), piece.end());

            for (int j = 0; j < sz; j++) {
                if (piece[j]!=tosort[j+i]) {
                    ok=false;
                    break;
                }
            }
            if (!ok)break;
        }
        if (ok) {
            cout << two/2 << "\n";
            return;
        }
    }
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