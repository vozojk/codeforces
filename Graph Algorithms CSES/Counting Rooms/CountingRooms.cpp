#include <bits/stdc++.h>
 
using namespace std;
#include <climits>
#include <string>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
// 2. Define the Ordered Set (this is standard CP template boilerplate)
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
#define dbg(x)
#endif
 
// Counts the number of 1s in the binary representation of x
#define popcount(x) __builtin_popcountll(x)
 
// Returns the index of the lowest set bit (trailing zeros)
#define lsb(x) __builtin_ctzll(x)
 
// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// For 8-directional movement (Kings/Queens):
// const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
// Fast modulo
void add(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }
void sub(int &a, int b) { a -= b; if (a < 0) a += MOD; }
 
// --- Custom hash ---
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
void solve() {
 
    int n, m, count = 0;
    char temp;
 
 
 
    cin >> n >> m;
    vvi states(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            if (temp == '#') states[i][j]=0;
            else states[i][j] = 1;
        }
    }
 
    deque<pair<int,int>> bfs;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (states[i][j]==1) {
                bfs.push_back({i,j});
                count++;
            }
 
            while (!bfs.empty()) {
                int x = bfs.front().first, y = bfs.front().second;
                bfs.pop_front();
                if (x < 0 || x > n-1 || y < 0 || y > m-1 || states[x][y]==0) continue;
                states[x][y] = 0;
                bfs.push_back({x+dx[0], y+dy[0]});
                bfs.push_back({x+dx[1], y+dy[1]});
                bfs.push_back({x+dx[2], y+dy[2]});
                bfs.push_back({x+dx[3], y+dy[3]});
            }
        }
 
    }
    cout << count;
 
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