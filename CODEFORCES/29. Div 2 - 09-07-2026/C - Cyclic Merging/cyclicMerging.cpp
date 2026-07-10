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
// b>a/m -> b/a > 1/m m==a/b
void solve() {

    struct Node {
        int cost;
        int del;
        int stay;

        bool operator>(const Node& other) const {
            return cost > other.cost;
        }
    };
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> deleted(n, false);
    vector<pii> closest(n);

    for (int i = 1; i < n-1; i++) {
        closest[i]={i-1, i+1};
    }
    closest[0]={n-1, 1};
    closest[n-1]={n-2, 0};

    priority_queue<Node, vector<Node>, greater<>> pq;
    cin >> a[0];

    for (int i = 1; i < n; i++) {
        cin >> a[i];
        int stay;
        int del;
        if (a[i]>a[i-1]) {
            stay = i;
            del = i-1;
        }else {
            stay = i-1;
            del = i;
        }
        Node f = {max(a[i], a[i-1]), del, stay};
        pq.push(f);
    }
    int stay;
    int del;
    if (a[0]>a[n-1]) {
        stay = 0;
        del = n-1;
    }else {
        stay = n-1;
        del = 0;
    }
    Node f = {max(a[0], a[n-1]), del, stay};
    pq.push(f);

    ll total = 0;
    while (!pq.empty()) {
        Node rem = pq.top(); pq.pop();
        if (deleted[rem.del] || deleted[rem.stay] || rem.del==rem.stay)continue;
        deleted[rem.del]=true;
        total += rem.cost;

        int upd_idx1 = closest[rem.del].first;
        int upd_idx2 = closest[rem.del].second;

        closest[upd_idx1].second = upd_idx2;
        closest[upd_idx2].first = upd_idx1;

        int del;
        int stay;

        if (a[upd_idx1]>a[upd_idx2]) {
            del = upd_idx2;
            stay = upd_idx1;
        }else {
            del = upd_idx1;
            stay = upd_idx2;
        }
        pq.push({max(a[upd_idx1], a[upd_idx2]), del, stay});
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