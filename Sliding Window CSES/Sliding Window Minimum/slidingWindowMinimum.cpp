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
    ll n,k,x,a,b,c;
    cin >> n >> k >> x >> a >> b >> c;
    ll total = 0;
    int i = 1;
    deque<pair<ll, int>> s;
    s.push_back({x,i});
    while (i < k) {
        i++;
        x = (a*x+b)%c;
        while (!s.empty() && x<=s.back().first) {
            s.pop_back();
        }
        while (!s.empty() && s.front().second<=i-k) {
            s.pop_front();
        }
        s.push_back({x,i});
    }
 
    while (i < n) {
        total ^= s.front().first;
        i++;
        x = (a*x+b)%c;
        while (!s.empty() && x<=s.back().first) {
            s.pop_back();
        }
        while (!s.empty() && s.front().second<=i-k) {
            s.pop_front();
        }
        s.push_back({x,i});
    }
    total ^= s.front().first;
    cout << total << "\n";
 
 
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