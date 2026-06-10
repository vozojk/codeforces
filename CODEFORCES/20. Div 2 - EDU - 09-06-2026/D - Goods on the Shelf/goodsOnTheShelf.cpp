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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    auto b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    vector<vector<int>> block_indices(n);
    vector<int> block_count(n, 0);

    for (int i = 0; i < n; ) {
        int j = i;
        while (i < n && a[i] == a[j]) {
            i++;
        }

        block_indices[a[j]].push_back(j);
        block_indices[a[j]].push_back(j - 1);
        block_indices[a[j]].push_back(i - 1);
        block_indices[a[j]].push_back(i);

        block_count[a[j]]++;
    }

    auto check_swap = [&](int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= n) return false;

        swap(a[x], a[y]);
        vector<int> current_counts(n, 0);
        for (int i = 0; i < n; ) {
            int j = i;
            while (i < n && a[i] == a[j]) i++;
            current_counts[a[j]]++;
        }
        swap(a[x], a[y]);

        for (int i = 0; i < n; i++) {
            if (current_counts[i] > 1) return false;
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        if (block_count[i] < 2) continue;
        if (block_count[i] > 3) {
            cout << "NO\n";
            return;
        }
        
        sort(block_indices[i].begin(), block_indices[i].end());
        block_indices[i].erase(unique(block_indices[i].begin(), block_indices[i].end()), block_indices[i].end());
        
        for (int x : block_indices[i]) {
            for (int y : block_indices[i]) {
                if (x < y && check_swap(x, y)) {
                    cout << "YES\n";
                    return;
                }
            }
        }
        cout << "NO\n";
        return;
    }

    cout << "YES\n";


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