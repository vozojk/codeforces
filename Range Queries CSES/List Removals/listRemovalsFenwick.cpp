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
int n;
 
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
    int a;
    cin >> n;
 
    tr.assign(n+1, 0);
    vector<int> vals(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        vals[i]=a;
        add(i, 1);
    }
 
 
    for (int i = 0; i < n; i++) {
        cin >> a;
        int ans = -1;
        int left = 1, right = n;
        while (left <= right) {
            int mid = (left+right)/2;
            int num = query(mid);
            if (num >= a) {
                ans = mid;
                right = mid-1;
            }else {
                left = mid+1;
            }
        }
        add(ans, -1);
        cout << vals[ans] << " ";
 
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
