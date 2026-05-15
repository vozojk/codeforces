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
constexpr ll INF = 2*1e9;
 
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
vector<int> tr;
int n, padded_n;
 
void add(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) {
        tr[idx]+=val;
    }
}
int query(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) {
        res += tr[idx];
    }
    return res;
}
 
void solve() {
    int a,b,q;
    cin >> n >> q;
 
    tr.assign(n+1, 0);
    unordered_map<int,int> last_seen;
    last_seen.reserve(n+1);
    vector<tuple<int,int,int>> queries(q);
    vector<int> res(q);
    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++)cin >> nums[i];
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        queries[i] = {a,b,i};
    }
    sort(queries.begin(), queries.end(), [](tuple<int,int,int>& c, tuple<int,int,int>& d) {
        if (get<1>(c) != get<1>(d)) {
            return get<1>(c) < get<1>(d);
        }
        return get<0>(c) < get<0>(d);
    });
    int ptr = 0;
    for (int i = 1; i <= n; i++) {
        int seen = last_seen[nums[i]];
        if (seen > 0) {
            add(seen, -1);
        }
        add(i, 1);
        last_seen[nums[i]]=i;
        while (ptr < q && get<1>(queries[ptr])==i) {
            res[get<2>(queries[ptr])] = query(i)-query(get<0>(queries[ptr])-1);
            ptr++;
        }
    }
    for (const int f : res)cout << f << "\n";
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
 
    return 0;
}