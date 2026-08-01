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
constexpr ll INF = 1e9+1;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#include <iostream>

using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> a(n);
    int big = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]==n)big=i;
    }

    for (int i = big; i > 0; i--) {
        if (a[i]<a[i-1]) {
            cout << "no\n";
            return;
        }
    }
    for (int i = big; i < n-1; i++) {
        if (a[i]<a[i+1]) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";


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