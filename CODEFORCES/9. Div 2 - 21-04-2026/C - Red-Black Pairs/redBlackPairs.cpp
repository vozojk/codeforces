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

    int n;
    char color1, color2;
    string s1, s2;
    cin >> n >> s1 >> s2;
    vector<vector<int>> table(n, vector<int>(2));
    for (int i = 0; i<n; i++) {
        color1 = s1[i];
        color2 = s2[i];
        table[i][0]=color1;
        table[i][1]=color2;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (table[i][0]==table[i][1]) {
            table[i][0]=-1;
            table[i][1]=-1;
            count++;
        }
    }
    for (int i = 0; i < n-1; i++) {
        if (table[i][0]!=-1 && table[i+1][0]!=-1) {
            if (table[i][0] == table[i+1][0]) {
                table[i][0]=-1;
                table[i+1][0]=-1;
                count++;
            }
            if (table[i][1] == table[i+1][1]) {
                table[i][1]=-1;
                table[i+1][1]=-1;
                count++;
            }
        }
    }
    cout << (n-count) << "\n";



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