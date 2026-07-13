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
constexpr int MOD = 998244353;
constexpr ll INF = 1e9;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#include <iostream>
#include <string>

using namespace std;
int MAXN = 5005;
long long fact[5005];
long long invFact[5005];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;

    // 1. Compute all factorials
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);

    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    long long ans = fact[n];
    ans = (ans * invFact[r]) % MOD;
    ans = (ans * invFact[n - r]) % MOD;
    return ans;
}

void solve() {

    int n,b;
    cin >> n;
    unordered_map<int,int> a;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a[b]++;
    }
    int mf = 0;
    for (auto p: a) {
        mf = max(p.second, mf);
    }
    unordered_map<int,int> compr;
    int boss = 0;
    for (auto p : a) {
        if (p.second==mf) {
            boss++;
            continue;
        }
        compr[p.second]++;
    }
    vector<ll> dp(n+1, 0);
    dp[0]=1;
    for (auto p : compr) {
        vector<ll> next = dp;
        for (int i = 0; i <= n; i++){
            if (dp[i]==0)continue;
            int f = p.first;
            int c = p.second;

            for (int k = 1; k <= c; k++) {
                int new_sum = i + k * f;
                if (new_sum <= n) {
                    ll ways_to_pick = nCr(c, k);
                    ll freq_mult = power(f, k);
                    ll added = (ways_to_pick * freq_mult) % MOD;

                    next[new_sum] = (next[new_sum] + dp[i] * added) % MOD;
                }
            }
        }
        dp = move(next);
    }

    ll without = 0;
    for (int i = mf; i <= n; i++) {
        without = (without + dp[i]) % MOD;
    }

    ll ways_boss = (power(mf + 1, boss) - 1 + MOD) % MOD;

    ll others_mult = 1;
    for (auto p : compr) {
        ll f = p.first;
        ll c = p.second;
        others_mult = (others_mult * power(f + 1, c)) % MOD;
    }

    ways_boss = (ways_boss * others_mult) % MOD;

    ll total = (without + ways_boss) % MOD;
    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    precompute();
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}