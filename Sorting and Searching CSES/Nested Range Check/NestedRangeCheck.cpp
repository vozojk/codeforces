#include <bits/stdc++.h>
 
using namespace std;
#include <climits>
#include <string>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
// 2. Define the Ordered Set (this is standard CP template boilerplate)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
 
void swap(vector<ll> &a, ll i, ll j) {
    ll temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
 
void solve() {
 
    ll n, a, b;
    cin >> n;
    vector<ll> contains(n);
    vector<ll> isContained(n);
    vector<tuple<ll,ll,ll>> ranges(n);
    for (ll i = 0; i < n; i++) {
        cin >> a >> b;
        ranges[i] ={a,b,i};
    }
    sort(ranges.begin(), ranges.end(), [](tuple<int,int,int> c, tuple<int,int,int> d) {
        if (get<0>(c) == get<0>(d)) {
            return get<1>(c) > get<1>(d);
        }
        return get<0>(c) < get<0>(d);
    });
    ll mini = std::get<0>(ranges[0]);
    ll maxi = get<1>(ranges[0]);
    ll current = 0;
    for (ll i = 1; i < n; i++) {
        if (get<1>(ranges[i])<=maxi) {
            isContained[get<2>(ranges[i])] = 1;
        }else {
            current = i;
            mini = get<0>(ranges[i]);
            maxi = get<1>(ranges[i]);
        }
 
    }
    mini = std::get<0>(ranges[n-1]);
    maxi = get<1>(ranges[n-1]);
    current = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (get<1>(ranges[i])>=maxi) {
            contains[get<2>(ranges[i])] = 1;
 
        }
        current = i;
        mini = max(mini, get<0>(ranges[i]));
        maxi = min(maxi, get<1>(ranges[i]));
    }
    for (ll i : contains) {
        cout << i << " ";
    }
    cout << "\n";
    for (ll i : isContained) {
        cout << i << " ";
    }
 
 
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    ll t = 1;
    //cin >> t;
 
    while(t--) {
        solve();
    }
 
    return 0;
 
 
}