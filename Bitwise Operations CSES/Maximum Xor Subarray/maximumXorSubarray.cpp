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
 
struct Trie {
    vector<array<int, 2>> trie;
    int node_count;
 
    Trie(int max_el) {
        trie.assign(max_el * 31 + 2, {0,0});
        node_count = 1;
        insert(0);
    }
 
    void insert(int x) {
        int curr = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (trie[curr][bit]==0) {
                trie[curr][bit] = node_count++;
            }
            curr = trie[curr][bit];
        }
    }
 
    int get_max(int x) {
        int curr = 0;
        int max_xor = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int desired = bit^1;
 
            if (trie[curr][desired]!=0) {
                max_xor |= (1 << i);
                curr = trie[curr][desired];
            }else curr = trie[curr][bit];
        }
        return max_xor;
    }
};
 
 
void solve(){
    int n;
    cin >> n;
 
    Trie trie(n);
 
    int prefix = 0;
    int res = 0;
 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        prefix ^= a;
        res = max(res, trie.get_max(prefix));
        trie.insert(prefix);
    }
    cout << res << "\n";
 
 
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