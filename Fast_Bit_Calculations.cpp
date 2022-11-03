#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nl '\n'

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  cin >> test;
  while (test--) {
    ll n; cin >> n;
    n++;
    ll ans = 0;
    for (int i = 0; i <= 30; ++i) {
      ll x = (1 << i);
      ll y = x * 4;
      ll z = n / y;
      ans += (1LL * x * z);
      ll extra = n - z * y;
      ans += max(0LL, extra - (y - x));
    }
    cout << "Case " << ++tc << ": " << ans << nl;
  }
  return 0;
}
