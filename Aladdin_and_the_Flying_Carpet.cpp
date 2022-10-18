#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nl '\n'

const int N = (int) 1e6 + 5;

vector<ll> prime;
vector<bool> used(N + 2, 0);
// primefactorization
void seive() {
  for (int i = 4; i <= N; i += 2) used[i] = 1;
  for (int i = 3; i * i <= N; i += 2) {
    if (!used[i]) {
      for (int j = i * i; j <= N; j += (2 * i)) used[j] = 1;
    }
  }
  for (int i = 2; i <= N; ++i) if (!used[i]) prime.push_back(i);
}

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0; cin >> test;
  seive();
  while (test--) {
    ll a, aa, b; cin >> a >> b;
    aa = a;
    if ((b * b) >= a) {
      cout << "Case " << ++tc << ": 0" << nl;
      continue;
    }
    ll ans = 1;
    // NOD
    for (auto x : prime) {
      if ((x * x) > a) break;
      ll cnt = 0;
      while (a % x == 0) {
        cnt++;
        a /= x;
      }
      ans *= (cnt + 1);
    }
    if (a > 1) ans *= 2;
    ans /= 2;
    // remove extra
    for (int i = 1; i < b; ++i) if (aa % i == 0) ans--;
    cout << "Case " << ++tc << ": " << ans << nl; 
  }
  return 0;
}
