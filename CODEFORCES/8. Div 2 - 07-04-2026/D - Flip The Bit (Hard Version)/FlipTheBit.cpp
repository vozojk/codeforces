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

    int n, k, temp;
    cin >> n >> k;
    vector<int> elements;
    vector<int> bounds;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        elements.push_back(temp);
    }

    bounds.push_back(0);
    for (int i = 0; i < k; i++) {
        cin >> temp;
        bounds.push_back(temp);
    }
    bounds.push_back(n+1);

    int pad = elements[bounds[1]-1]; // Get correct target adjusted for 0-indexed

    elements.insert(elements.begin(), pad);
    elements.push_back(pad);

    vector<int> counts;
    int maxCount = 0, count, sum = 0;
    for (int i = 0; i <= k; i++) {
        count = 0;

        for (int j = bounds[i] + 1; j <= bounds[i+1]; j++) {
            if (elements[j]==elements[j-1])continue;
            count++;
        }
        sum += count;
        maxCount = max(maxCount, count);
    }

    cout << max(maxCount, sum/2) << "\n";






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