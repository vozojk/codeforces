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
const int MOD = 676767677;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)cin >> arr[i];
    bool only = true;
    int maxE = 0, minE = 1e8, maxO = 0, minO = 1e8;
    for (int i = 0; i < n; i++) {
        if (arr[i]%2==0) {
            only=false;
            if (maxE < arr[i]) {
                maxE = arr[i];
            }
            if (minE > arr[i]) {
                minE = arr[i];
            }
        }
    }
    if (only) {
        for (int i = 0; i < n-1; i++) {
            if (arr[i]>arr[i+1]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;

    }
    only = true;
    for (int i = 0; i < n; i++) {
        if (arr[i]%2==1) {
            only=false;
            if (maxO < arr[i]) {
                maxO = arr[i];
            }
            if (minO > arr[i]) {
                minO = arr[i];
            }
        }
    }
    if (only) {
        for (int i = 0; i < n-1; i++) {
            if (arr[i]>arr[i+1]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    bool seen_large_even = false;
    bool seen_large_odd = false;
    for (int i = 0; i < n; i++) {

        if (arr[i]%2==0 && arr[i]>maxO) {
            seen_large_even = true;
        }
        if (arr[i]%2==1 && arr[i]>maxE) {
            seen_large_odd = true;
        }
        if (arr[i] < minO && seen_large_even && arr[i]%2==0) {
            cout << "NO\n";
            return;
        }
        if (arr[i] < minE && seen_large_odd && arr[i]%2==1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";








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