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

    //all one side >vi
    int n;
    cin >> n;

    vector<int> match(n);
    for (int i = 0; i < n-1; i++) cin >> match[i];
    bool peak = false;
    int l=0,r=0;
    for (int i = 1; i < n-1; i++) {
        if (match[i-1]<match[i] && peak) {
            cout << "0\n";
            return;
        }
        if (match[i-1]>match[i]) {
            peak = true;
        }

    }

    vector<int> cnt(n+1,0);
    int last = match[0];
    cnt[match[0]]++;
    for (int i =1; i < n-1; i++) {
        if (last!=match[i] && cnt[match[i]]>0) {
            cout << "0\n";
            return;
        }
        last = match[i];
        cnt[match[i]]++;
    }
    if (cnt[n]>0 || cnt[n-1]==0) {
        cout << "0\n";
        return;
    }
    ll total = 2;
    int flat = 0;
    for (int i = n-1; i >= 1; i--) {
        if (cnt[i]>0) {
            flat+=cnt[i]-1;
        }else {
            total = (total*flat)%MOD;
            flat--;
        }
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