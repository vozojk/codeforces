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
 
 
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> boss(n, -1);
    vector<vector<int>> edge(n);
    vector<int> depth(n);
    vector<int> visited(n,0);
    int start, end;
    for (int i = 1; i < n; i++) {
        cin >> start >> end;
        start--;
        end--;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }
    queue<int> qu;
    vector<int> topo;
    qu.push(0);
    visited[0]=1;
    int d = 0;
    while (!qu.empty()) {
        int size = qu.size();
        for (int i = 0; i < size; i++) {
            int node = qu.front(); qu.pop();
            topo.push_back(node);
            depth[node]=d;
            for (int nei : edge[node]) {
                if (visited[nei]==0) {
                    qu.push(nei);
                    visited[nei]=1;
                    boss[nei]=node;
                }
            }
        }
        d++;
    }
    vector<vector<int>> dp(n, vector<int>(20, -1));
    for (int i = 1; i < n; i++) {
        dp[i][0]=boss[i];
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            if (dp[i][j-1]!=-1){
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
    vector<int> mark(n, 0);
    while (m--) {
        int a,b,oga,ogb;
        cin >> a >> b;
        a--;
        b--;
        oga = a;
        ogb = b;
        if (depth[a] > depth[b]) {
            for (int j = 19; j >= 0; j--) {
                if (dp[a][j] == -1 || depth[dp[a][j]]<depth[b])continue;
                a = dp[a][j];
            }
        }else if (depth[b] > depth[a]) {
            for (int j = 19; j >= 0; j--) {
                if (dp[b][j] == -1 || depth[dp[b][j]]<depth[a])continue;
                b = dp[b][j];
            }
        }
        int lca;
        if (a!=b) {
            for (int j = 19; j >= 0; j--) {
                if (dp[a][j]==dp[b][j] || dp[a][j]==-1 || dp[b][j] == -1)continue;
                a = dp[a][j];
                b = dp[b][j];
            }
            lca = dp[a][0];
        }else lca = a;
 
        mark[oga]++;
        mark[ogb]++;
        mark[lca]--;
        if (lca!=0) {
            mark[boss[lca]]--;
        }
    }
    for (int i = topo.size()-1; i >= 0; i--) {
        if (boss[topo[i]]!=-1)mark[boss[topo[i]]]+=mark[topo[i]];
    }
    for (int f : mark)cout << f << " ";
 
 
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