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
 
struct Trie {
    vector<array<int, 26>> trie;
    vector<bool> is_word;
    int node_count;
 
    Trie(int max_el) {
        trie.assign(max_el, {});
        is_word.assign(max_el, false);
        node_count = 1;
    }
 
    void insert(const string& s) {
        int curr = 0;
        for (char c : s) {
            int port = c - 'a';
            if (trie[curr][port]==0) {
                trie[curr][port] = node_count++;
            }
            curr = trie[curr][port];
        }
        is_word[curr]=true;
    }
};
 
 
void solve(){
    string goal;
    cin >> goal;
 
    int k;
    cin >> k;
 
 
    int total = 0;
    vector<string> strings(k);
    for (int i = 0; i < k; i++) {
        cin >> strings[i];
        total += strings[i].size();
    }
    Trie trie(total+10);
    for (string& s : strings) {
        trie.insert(s);
    }
 
    vector<ll> dp(goal.size()+1,0);
    dp[0]=1;
    for (int i = 0; i < goal.size(); i++) {
        if (dp[i]==0)continue;
 
        int curr = 0;
 
        for (int j = i; j < goal.size(); j++) {
 
            int port = goal[j]-'a';
            if (trie.trie[curr][port] == 0)break;
 
            curr = trie.trie[curr][port];
 
            if (trie.is_word[curr] == true) {
                dp[j+1] = (dp[j+1] + dp[i]) %MOD;
            }
        }
    }
    cout << dp[goal.size()] << "\n";
 
 
 
 
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