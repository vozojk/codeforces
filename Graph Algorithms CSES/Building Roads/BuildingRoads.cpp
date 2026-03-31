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
    int cities, roads;
    cin >> cities >> roads;
 
    deque<int> roads1;
    vector<bool> visited(cities+1);
 
    vector<vector<int>> connections(cities+1);
 
    int temp1, temp2;
 
    for (int i = 0; i < roads; i++){
        cin >> temp1 >> temp2;
        connections[temp1].push_back(temp2);
        connections[temp2].push_back(temp1);
    }
    vector<pair<int,int>> res;
    for (int i = 1; i <= cities; i++) {
        if (!visited[i]) {
            if (i!=1) res.push_back({i-1, i});
            roads1.push_back(i);
            visited[i]=true;
            while (!roads1.empty()) {
                int a = roads1.front();
                roads1.pop_front();
 
                for (int j : connections[a]) {
                    if (!visited[j])roads1.push_back(j);
                    visited[j] = true;
                }
            }
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << "\n";
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