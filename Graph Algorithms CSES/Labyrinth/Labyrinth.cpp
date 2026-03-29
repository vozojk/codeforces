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
 
    int n, m;
    char temp;
 
    cin >> n >> m;
    vector<pii> endpoints;
    vector<vector<pair<char,char>>> states(n, vector<pair<char,char>>(m));
    pii start, end;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            states[i][j].first = temp;
            if (temp=='A'){
                start = {i,j};
                states[i][j].second = -1;
            }else if (temp=='B'){
                end = {i,j};
            }
        }
    }
 
    deque<pii> bfs;
    bool found = false;
 
    bfs.push_back(start);
    while (!bfs.empty()) {
        int x = bfs.front().first, y = bfs.front().second;
        bfs.pop_front();
        if (x == end.first && y == end.second) {
            cout << "YES\n";
            found = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x+dx[i];
            int yy = y+dy[i];
 
            if (xx < 0 || xx > n-1 || yy < 0 || yy > m-1 || states[xx][yy].first=='#' || states[xx][yy].second != 0) continue;
 
            bfs.push_back({xx, yy});
            states[xx][yy].second = dir_char[i];
        }
    }
    if (found) {
        int r = end.first, c = end.second;
        string path;
        while (r != start.first || c != start.second) {
            char move = states[r][c].second;
            path+=move;
 
            if (move == 'U') r++;
            else if (move == 'D')r--;
            else if (move == 'L')c++;
            else c--;
        }
        cout << path.size() << "\n";
        reverse(path.begin(), path.end());
        cout << path << "\n";
        return;
    }
    cout << "NO";
 
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