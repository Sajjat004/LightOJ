#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pll;
typedef vector<int>        vi;
typedef vector<ll>         vll;

const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;

#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define nl       '\n'
#define PI       acos(-1.0)
#define debug(x) cerr << #x << " = " << x << '\n';

/*................. let's try one more time .................*/

#ifdef LOCAL
#include "headerFile/debug.h"
#endif

string getMin(string y, string z) {
  int n = szof(y), m = szof(z);
  if (n > m) {
    return y;
  }
  if (n < m) {
    return z;
  }
  for (int i = 0; i < n; ++i) {
    if (y[i] < z[i]) {
      return y;
    } else if (y[i] > z[i]) {
      return z;
    }
  }
  return y;
}
int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  cin >> test;
  while (test--) {
    string s, t; cin >> s >> t;
    int n = szof(s), m = szof(t);
    string dp[n + 2][m + 2];
    for (int i = n; i >= 0; --i) {
      for (int j = m; j >= 0; --j) {
        if (i == n or j == m) {
          dp[i][j] = "";
          continue;
        }
        if (s[i] == t[j]) {
          string temp = "";
          temp += s[i];
          dp[i][j] = temp + dp[i + 1][j + 1];
        } else {
          dp[i][j] = getMin(dp[i + 1][j], dp[i][j + 1]);
        }
      }
    }
    if (szof(dp[0][0])) cout << "Case " << ++tc << ": " << dp[0][0] << nl;
    else cout << "Case " << ++tc << ": :(" << nl;;
  }
  return 0;
}
