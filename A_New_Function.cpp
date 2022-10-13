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
    ll csum = 0;
    for (ll i = 2; (i * i) <= n; ++i) {
      ll j = n / i;
      csum += (j + i) * (j - i + 1) / 2;
      csum += (j - i) * i;
    }
    cout << "Case " << ++tc << ": " << csum << nl;
  }
  return 0;
}
