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
 
vector<ll> tr;
vector<int> nums;
int n;
 
void add(int idx, const int val) {
    for (; idx <= n; idx += idx & -idx) {
        tr[idx]+=val;
    }
}
 
ll query(int idx) { //point query
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += tr[idx];
    }
    return sum;
}
 
void solve() {
 
    int q,a,b;
    cin >> n >> q;
    nums.assign(n+1,0);
    tr.assign(n+2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        add(i, nums[i]);
        add(i+1, -nums[i]);
    }
 
 
 
    while (q--) {
        cin >> a >> b;
        if (a == 1) {
            int c, d;
            cin >> c >> d;
            add(b, d);
            add(c+1, -d);
        }else {
            cout << query(b) << "\n";
        }
    }
 
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