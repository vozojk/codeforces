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
    string full;
    cin >> full;
    string match;
    cin >> match;
    int n = full.size(), m = match.size();
    vector<ll> hashed(n);
 
    ll mult = 1;
    for (int i = 0; i < n; i++) {
        hashed[i] = (full[i] * mult)%MOD;
        mult = (mult*101)%MOD;
    }
    ll hash = 0;
 
    mult = 1;
    for (char c : match) {
        hash = (hash+c*mult)%MOD;
        mult = (mult * 101)%MOD;
    }
    vector<ll> windows(n);
    windows[0]=hashed[0];
    int left = 0;
    int right = 1;
    while (right < m) {
        windows[right] = (hashed[right]+windows[right-1])%MOD;
        right++;
    }
    while (right < n) {
        windows[right] = (windows[right-1]-hashed[left]+hashed[right]+MOD)%MOD;
        right++;
        left++;
    }
    int total = 0;
    mult = 1;
    for (int i = m-1; i < n; i++) {
        if (windows[i] == (hash*mult)%MOD)total++;
        mult = (mult*101)%MOD;
    }
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