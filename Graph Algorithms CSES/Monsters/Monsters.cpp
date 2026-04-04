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
    cin >> n >> m;
    pair<int,int> found = {-1,-1};
    vector<vector<char>> pos(n, vector<char>(m));

    deque<pair<int,int>> monst;
    deque<pair<int,int>> me;
    vector<vector<char>> visited(n, vector<char>(m));
    pair<int,int> start = {-1,-1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pos[i][j];
            if (pos[i][j]=='M') monst.push_back({i,j});
            if (pos[i][j]=='A') {
                me.push_back({i,j});
                visited[i][j] = 'H';
                if (i==0 || i==n-1 || j==0 || j==m-1) {
                    found = {i,j};
                    goto end;
                }
            }
        }
    }

    while (!me.empty()) {
        int size = monst.size();
        for (int i = 0; i < size; i++) {
            pair<int,int> current = monst.front(); monst.pop_front();
            int a = current.first;
            int b = current.second;
            for (int j = 0; j < 4; j++) {

                if (a+dx[j]<0 || b+dy[j]<0 || a+dx[j]>=n || b+dy[j] >= m) continue;
                if (pos[a+dx[j]][b+dy[j]] != '#' && pos[a+dx[j]][b+dy[j]] != 'M') {
                    pos[a+dx[j]][b+dy[j]] = 'M';
                    monst.push_back({a+dx[j], b+dy[j]});
                }
            }

        }

        size = me.size();
        for (int i = 0; i < size; i++) {
            pair<int,int> current = me.front(); me.pop_front();
            int a = current.first;
            int b = current.second;
            for (int j = 0; j < 4; j++) {

                if (a+dx[j]<0 || b+dy[j]<0 || a+dx[j]>=n || b+dy[j] >= m) continue;

                char curr = pos[a+dx[j]][b+dy[j]];
                if (curr == '.') {
                    pos[a+dx[j]][b+dy[j]] = 'A';
                    me.push_back({a+dx[j], b+dy[j]});
                    visited[a+dx[j]][b+dy[j]] = dir_char[j];
                    if (a+dx[j]==0 || a+dx[j]==n-1 || b+dy[j]==0 || b+dy[j]==m-1) {
                        found = {a+dx[j], b+dy[j]};
                        goto end;
                    }
                }
            }
        }

    }
    if (found.first==-1) {
        cout << "NO\n";
        return;
    }
    end:
    int x = found.first, y = found.second;
    vector<char> moves;
    while (visited[x][y]!='H') {
        char move = visited[x][y];
        switch (move) {
            case 'U':
                moves.push_back('U');
                x+=1;
                break;
            case 'D':
                moves.push_back('D');
                x-=1;
                break;
            case 'L':
                moves.push_back('L');
                y+=1;
                break;
            case 'R':
                moves.push_back('R');
                y-=1;
                break;
        }
    }
    cout << "YES\n" << moves.size() << "\n";
    reverse(moves.begin(), moves.end());
    for (char m : moves) {
        cout << m;
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