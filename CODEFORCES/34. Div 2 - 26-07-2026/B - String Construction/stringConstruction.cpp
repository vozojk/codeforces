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

    int n,k;
    cin >> n >> k;

    if (k==0) {
        for (int i = 0; i < n; i++) {
            if ((i)%2==0)cout << '1';
            else cout << '0';
        }
        cout << "\n";
        return;
    }

    if (n-2<k) {
        cout << "-1\n";
        return;
    }
    if (k%2==1 && n!=k+2) {
        cout << '0';
        n--;
    }
    if (k%2==1) {
        cout << '1';
        n--;
    }
    for (int i = 0; i <= k/2; i++) {
        cout << '1';
    }
    for (int i = 0; i <= k/2; i++) {
        cout << '0';
    }
    int s = k+2-k%2;
    for (int i = s; i < n; i++) {
        if ((i-s)%2==0)cout << '1';
        else cout << '0';
    }
    cout << "\n";

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