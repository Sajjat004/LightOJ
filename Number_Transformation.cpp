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

int start, target;
vi dp;
set<int> prime[1005];

void preCal() {
  for (int n = 1; n <= 1000; ++n) {
    int m = n;
    for (int i = 2; (i * i) <= m; ++i) {
      if (m % i == 0) {
        while (m % i == 0) m /= i;
        prime[n].insert(i);
      }
    }
    if (m > 1 and n != m) prime[n].insert(m);
  }
}
bool flag = 0;
int dfs(int n) {
  if (n > target) return INF;
  if (n == target) {
    flag = 1;
    return 0;
  }
  if (dp[n] != -1) return dp[n];
  int res = INF;
  for (auto x : prime[n]) {
    res = min(res, dfs(n + x) + 1);
  }
  return dp[n] = res;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  preCal();
  cin >> test;
  while (test--) {
    cin >> start >> target;
    flag = 0;
    dp.assign(1005, -1);
    int res = dfs(start);
    if (!flag) res = -1;
    cout << "Case " << ++tc << ": " << res << nl;
  }
  return 0;
}
