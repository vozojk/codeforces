#include <bits/stdc++.h>
 
using namespace std;
#include <climits>
#include <string>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
// 2. Define the Ordered Set (this is standard CP template boilerplate)
typedef tree<pair<int,int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
void swap(vector<int> &a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
ll getProducts(ll x, const vector<ll>& times) {
    ll total = 0;
    for (ll time : times) {
        if (LONG_LONG_MAX - total < x/time) return LONG_LONG_MAX;
        total+=x/time;
    }
    return total;
}
void solve() {
 
    int n, t ,a;
    cin >> n >> t;
    vector<ll> times(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        times[i]=a;
    }
    ll left = 1, right = pow(2,62);
    ll mid, ans = LONG_LONG_MAX, count;
    while (left <= right) {
        mid = (left+right)/2;
        count = getProducts(mid, times);
        if (count<t) {
            left = mid+1;
        }else {
            ans = min(ans,mid);
            right = mid-1;
        }
    }
 
    cout << ans << "\n";
 
 
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