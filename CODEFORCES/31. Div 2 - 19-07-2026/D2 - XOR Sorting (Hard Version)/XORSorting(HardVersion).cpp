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

#ifdef lOCAl
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
//#define dbg(x)
#endif

// --- Constants ---
constexpr int MOD = 1e9+7;
constexpr int INF = 2e9;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#include <iostream>

using namespace std;

int LOGN, N;

struct Node {
    int min_val;
    int max_val;
    int ans;
};

vector<Node> tr;
vector<int> nums;
int n;

// Helper function to merge children into the parent node
void update_node(int idx) {
    int left = idx << 1;
    int right = idx << 1 | 1;

    tr[idx].min_val = min(tr[left].min_val, tr[right].min_val);
    tr[idx].max_val = max(tr[left].max_val, tr[right].max_val);
    tr[idx].ans = max(tr[left].ans, tr[right].ans);

    // If there is an inversion between the left half and right half
    if (tr[left].max_val > tr[right].min_val) {
        // Calculate the power/level 'p' of this current node
        // __builtin_clz counts leading zeros. 31 - clz(idx) gets the floor(log2(idx))
        int p = LOGN - (31 - __builtin_clz(idx));
        tr[idx].ans = max(tr[idx].ans, 1 << (p - 1));
    }
}

void init() {
    // 1. Initialize the leaves (Level 0)
    for (int i = 0; i < N; i++) {
        if (i < n) {
            tr[i + N] = {nums[i], nums[i], 0};
        } else {
            // Pad the rest of the array with values that will NEVER trigger an inversion
            tr[i + N] = {INF, -INF, 0};
        }
    }
    // 2. Build the tree bottom-up
    for (int i = N - 1; i > 0; --i) {
        update_node(i);
    }
}

void update(int idx, int val) {
    idx += N; // Jump to the leaf node
    tr[idx] = {val, val, 0}; // Update the leaf

    // Propagate the changes all the way up to the root
    for (idx >>= 1; idx > 0; idx >>= 1) {
        update_node(idx);
    }
}

void solve() {


    int q;
    cin >> n >> q;
    N = 1;
    LOGN = 0;
    while (N < n) {
        N <<= 1;
        LOGN++;
    }
    nums.assign(n,0);
    tr.assign(2*N, Node({0,0,0}));
    cin >> nums[0];
    for (int i = 1; i < n; i++) {
        cin >> nums[i];
    }

    init();
    cout << tr[1].ans << " "; // Print initial state

    for (int i = 0; i < q; i++) {
        int idx, val;
        cin >> idx >> val;
        // Note: idx must be 0-indexed when passed into update()
        update(idx, val);
        cout << tr[1].ans << " "; // Print state after update
    }
    cout << "\n";
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