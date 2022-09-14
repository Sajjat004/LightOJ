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

vi g[102];
vector<vector<bool>> used(103, vector<bool>(2, 0));

int res = 0;

void dfs(int u, bool take) {
  if (used[u][take]) return;
  used[u][take] = 1;
  for (auto v : g[u]) {
    dfs(v, (take ^ 1));
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  cin >> test;
  while (test--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
      used[i][0] = used[i][1] = 0;
    }
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    res = 0;
    if (szof(g[1]))
      dfs(g[1][0], 0);
    for (int i = 1; i <= n; ++i) res += used[i][1];
    cout << "Case " << ++tc << ": " << res << nl;
  }
  return 0;
}
