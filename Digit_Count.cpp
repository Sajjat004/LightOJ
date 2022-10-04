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

set<int> digits;
vector<vi> dp;

int call(int pos, int last) {
  if (pos < 1) return 1;
  if (dp[pos][last] != -1) return dp[pos][last];
  int ret = 0;
  for (auto x : digits) {
    int dif = abs(x - last);
    if (dif <= 2) ret += call(pos - 1, x);
  }
  return dp[pos][last] = ret;
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
    int n, m; cin >> n >> m;
    digits.clear();
    for (int i = 1; i <= n; ++i) {
      int x; cin >> x;
      digits.insert(x);
    }
    dp.assign(15, vi(15, -1));
    int ans = 0;
    for (auto x : digits) {
      ans += call(m - 1, x);
    }
    cout << "Case " << ++tc << ": " << ans << nl;
  }
  return 0;
}
