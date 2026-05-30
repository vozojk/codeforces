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




void solve(){

    int n,a;
    cin >> n;

    unordered_map<int,int> cnts;
    vector<int> ids(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ids[i]=a;
        cnts[a]++;
        if (cnts[a]>m)m = cnts[a];
    }
    sort(ids.begin(), ids.end());
    int c = 0;
    vector<int> left(n);
    vector<int> right(n);
    right[n-1]=0;
    left[0]=0;
    for (int i = 1; i < n; i++) {
        if (ids[i]==ids[i-1])left[i]=left[i-1];
        else left[i]=left[i-1]+cnts[ids[i-1]];
    }
    for (int i = n-2; i >= 0; i--) {
        if (ids[i]==ids[i+1])right[i]=right[i+1];
        else right[i]=right[i+1]+cnts[ids[i+1]];
    }
    int b = 200;
    for (int i = 0; i < n; i++) {
        b = min(b, max(left[i],right[i]));
    }
    cout << b << "\n";

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