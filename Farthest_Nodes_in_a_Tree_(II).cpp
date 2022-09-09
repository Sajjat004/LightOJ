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

vector<pii> g[N];
vi dp1, dp2;
int mx = -1;

void dfs(int u, int par, int d, int& p, vi& dp) {
  dp[u] = d;
  if (dp[u] > mx) {
    p = u;
    mx = dp[u];
  }
  for (auto x : g[u]) {
    int v = x.ff, w = x.ss;
    if (v == par) continue;
    dfs(v, u, d + w, p, dp);
  }
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
    int n; cin >> n;
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v, w; cin >> u >> v >> w;
      g[u].pb({v, w});
      g[v].pb({u, w});
    }
    dp1.assign(n + 2, 0);
    dp2.assign(n + 2, 0);
    int p, q;
    mx = 0;
    dfs(0, -1, 0, p, dp1);
    mx = 0;
    dfs(p, -1, 0, q, dp1);
    mx = 0;
    dfs(q, -1, 0, p, dp2);
    cout << "Case " << ++tc << ":\n";
    for (int i = 0; i < n; ++i) cout << max(dp1[i], dp2[i]) << nl;
  }
  return 0;
}
