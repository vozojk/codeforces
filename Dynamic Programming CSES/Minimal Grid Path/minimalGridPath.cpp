#include <bits/stdc++.h>
 
using namespace std;
#include <climits>
#include <string>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
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
 
    int n;
    cin >> n;
 
    vector<vector<char>> grid(n, vector<char>(n, 100));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j];
        }
    }
    vector<int> visited(n*n, 0);
    queue<pair<int,int>> q;
    q.push({0, 0});
    string start = "";
    while (!q.empty()) {
        int size = q.size();
        char next = 'p';
        vector<pair<int,int>> toAdd;
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x>=n || y>=n)continue;
            if (grid[x][y]<next) {
                toAdd.clear();
                next = grid[x][y];
                toAdd.push_back({x,y});
            }else if (grid[x][y]==next)toAdd.push_back({x,y});
        }
        if (start.size()==2*n-1)break;
 
        for (auto p : toAdd) {
            int x = p.first, y = p.second;
            if (x+1 < n && visited[n*(x+1)+y]==0) {
                visited[n*(x+1)+y]=1;
                q.push({x+1, y});
            }
            if (y+1 < n && visited[n*x+y+1]==0) {
                visited[n*x+y+1]=1;
                q.push({x, y+1});
            }
        }
        start.push_back(grid[toAdd[0].first][toAdd[0].second]);
    }
    cout << start;
 
 
 
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