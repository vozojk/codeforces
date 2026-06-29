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
    int n, edge;
    cin >> n;
    vector<int> parent(n);
    vector<vector<int>> child(n);
    vector<pair<ll,ll>> counts(n, {1,0});
    vector<int> indeg(n,0);
    for (int i = 1; i < n; i++) {
        cin >> edge;
        edge--;
        parent[i]=edge;
        child[edge].push_back(i);
        indeg[edge]++;
    }
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        if (child[i].empty())dq.push_back(i);
    }

    while (!dq.empty()) {
        auto idx = dq.front(); dq.pop_front();
        int m1 = -1, m2=-1;
        for (int chil : child[idx]) {
            counts[idx].first += counts[chil].first;

            int depth = counts[chil].second;
            if (depth > m1) {
                m2 = m1;
                m1 = depth;
            }else if (depth > m2) {
                m2 = depth;
            }
        }

        if (m1 != -1) {
            counts[idx].second = m1+1;
        }
        if (child[idx].size() >= 2) {
            counts[idx].first += m2+1;
        }

        indeg[parent[idx]]--;
        if (indeg[parent[idx]]==0 && idx!=0) {
            dq.push_back(parent[idx]);
        }
A
    }
    cout << counts[0].first << "\n";
    //save depth, add that+1+sum of children
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