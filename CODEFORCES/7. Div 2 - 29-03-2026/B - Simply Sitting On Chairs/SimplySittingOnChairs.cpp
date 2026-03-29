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
    //dfs with backtracking, mark visited, if i go back to visited save number and demark after recursive call
    int n;
    cin >> n;

    vi chairs(n+1);
    vi visited(n+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> chairs[i+1];
    }
    bool stop = false;
    int count = 0;
    while (true) {
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                stop = true;
                break;
            }
            if (chairs[i]<=i) {
                visited[i]=1;
                count++;
            }
        }
        if (stop) break;
    }
    cout << count << "\n";



}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;


}