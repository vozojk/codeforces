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
    int n,k,x;
    cin >> n >> k;
    multiset<int> low;
    multiset<int> high;
    queue<int> q;
 
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
        int low_high = low.empty() ? 0 : *low.rbegin();
        x > low_high ? high.insert(x) : low.insert(x);
        if (i >= k) {
            int a = q.front(); q.pop();
            high.find(a)!=high.end() ? high.erase(high.find(a)) : low.erase(low.find(a));
        }
        int ls = low.size();
        int hs = high.size();
        if (ls>hs+1) {
            int a = *low.rbegin();
            low.erase(low.find(a));
            high.insert(a);
        }else if (hs>ls+1) {
            int a = *high.begin();
            high.erase(high.find(a));
            low.insert(a);
        }
        if (i >= k-1) {
            if (high.size()>low.size())cout << *high.begin() << " ";
            else cout << *low.rbegin() << " ";
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