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

    int pupils, friendships, t1, t2;
    cin >> pupils >> friendships;

    vector<vector<int>> rel(pupils+1);

    for (int i = 0; i < friendships; i++) {
        cin >> t1 >> t2;
        rel[t1].push_back(t2);
        rel[t2].push_back(t1);
    }

    vector<int> pos(pupils+1, 0);
    deque<int> dq;
    for (int i = 1; i <= pupils; i++) {
        if (pos[i]==0) {
            dq.push_back(i);

            pos[i]=1;

            while (!dq.empty()) {
                int check = dq.front(); dq.pop_front();
                for (int a : rel[check]) {
                    if (pos[check] == pos[a]) {
                        cout << "IMPOSSIBLE\n";
                        return;
                    }

                    if (pos[a]>0)continue;
                    
                    if (pos[check]==1) {
                        pos[a]=2;
                    }else pos[a]=1;

                    dq.push_back(a);

                }
            }
        }
    }


    for (int i = 1; i <= pupils; i++) {
        cout << pos[i] << " ";
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