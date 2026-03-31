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
    int computers, cables;
    cin >> computers >> cables;
 
    deque<int> roads1;
    vector<int> visited(computers+1, -1);
 
    vector<vector<int>> connections(computers+1);
 
    int temp1, temp2;
 
    for (int i = 0; i < cables; i++){
        cin >> temp1 >> temp2;
        connections[temp1].push_back(temp2);
        connections[temp2].push_back(temp1);
    }
    vector<pair<int,int>> res;
    roads1.push_back(1);
    visited[1]=1;
    while (!roads1.empty()){
        int a = roads1.front();
        roads1.pop_front();
        for (int j : connections[a]) {
            if (visited[j] < 0) {
                roads1.push_back(j);
                visited[j] = a;
            }
        }
    }
    vector<int> path;
    string print;
    if (visited[computers]==-1) {
        cout << "IMPOSSIBLE" << "\n";
    }else {
        int a = computers;
        while (a > 1) {
            path.push_back(a);
            a = visited[a];
        }
        for (int i = path.size()-1; i >= 0; i--) {
            print.append(to_string(path[i]));
            print.push_back(' ');
        }
        cout << (path.size()+1) << "\n1 " << print << "\n";
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