#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

map<ll, ll> dp;

ll get(ll n) {
  if (dp[n]) return dp[n];
  ll sum = 0;
  ll m = n;
  while (n) {
    sum += n / 5;
    n /= 5;
  }
  return dp[m] = sum;
}

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0; cin >> test;
  while (test--) {
    ll m; cin >> m;
    ll l = 1, r = (ll) 1e18 + 8;
    ll ans = -1;
    while (l <= r) {
      ll mid = (l + r) >> 1;
      ll cnt = get(mid);
      if (cnt == m) {
        ans = mid;
        r = mid - 1;
      } else if (cnt > m) r = mid - 1;
      else l = mid + 1;
    }
    if (ans == -1) cout << "Case " << ++tc << ": impossible" << nl;
    else cout << "Case " << ++tc << ": " << ans << nl;
  }
  return 0;
}
