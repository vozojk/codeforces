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
#define dbg(x)
#endif
 
 
 
// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
 
void solve() {
 
    int n,m,temp1,temp2,temp3,q;
    cin >> n >> m >> q;
 
    vector<vector<pair<ll,int>>> endWeight(n+1); //len, node
    vector<ll> dist((n+1)*(n+1),INF);
    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2 >> temp3;
        dist[temp1*(n+1)+temp2] = min(dist[temp1*(n+1)+temp2], (ll)temp3);
        dist[temp2*(n+1)+temp1] = min(dist[temp2*(n+1)+temp1], (ll)temp3);
    }
 
    for (int i = 0; i <=n; i++) {
        dist[i*(n+1)+i] = 0;
    }
    //mid
    for (int i = 1; i <= n; i++) {
        //start
        for (int j = 1; j <= n; j++) {
            //end
            for (int a = 1; a <=n; a++) {
 
                if (dist[j*(n+1)+i] != INF && dist[i*(n+1)+a] != INF) {
                    dist[j*(n+1)+a] = min(dist[j*(n+1)+a], dist[j*(n+1)+i]+dist[i*(n+1)+a]);
                }
            }
        }
    }
 
    for (int i = 0; i < q; i++) {
        cin >> temp1 >> temp2;
 
        cout << (dist[temp1*(n+1)+temp2]==INF ? -1 : dist[temp1*(n+1)+temp2]) << "\n";
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