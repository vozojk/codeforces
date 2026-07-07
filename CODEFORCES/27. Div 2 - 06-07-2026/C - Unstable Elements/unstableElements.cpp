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
#include <string>

using namespace std;
// dont have a pair marked, can delete or make a pair
void solve() {
    //possibilities from n numbers which can repeat
    //nums with same count go together
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    unordered_map<int,int> cnts;
    int marked = 1;
    cnts[a[0]]++;
    for (int i = 1; i < n; i++) {
        if (a[i]!=a[i-1]) {
            marked++;
        }
        cnts[a[i]]++;
    }
    unordered_map<int,int> cmpr;
    for (auto p : cnts) {
        cmpr[p.second]++;
    }
    vector<pii> sorted(cmpr.size());
    int idx = 0;
    for (auto p : cmpr) {
        sorted[idx] = p;
        idx++;
    }
    sort(sorted.begin(), sorted.end());
    int sz = cmpr.size();

    ll ans = 0;
    ll dist = 0;
    ll sum = 0;

    for (int i = sz-1; i >= 0; i--) {
        ll curr = sorted[i].first;
        ll cnt = sorted[i].second;

        dist+=cnt;
        sum+=curr*cnt;
        ll diff = k-sum;

        if (diff%dist == 0) {
            ll d = diff/dist;
            if (curr+d >= 1) {
                ans++;
            }
        }
    }

    cout << ans << "\n";



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