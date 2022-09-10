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
vi g[105];
vector<bool> used;
vi nodes;

void dfs(int u) {
  if (used[u]) return;
  used[u] = 1;
  nodes.pb(u);
  for (auto v : g[u]) dfs(v);
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
    for (int i = 1; i <= n; ++i) g[i].clear();
    used.assign(n + 2, 0);
    nodes.clear();
    map<pii, int> cost;
    for (int i = 1; i <= n; ++i) {
      int u, v, w; cin >> u >> v >> w;
      g[u].pb(v);
      g[v].pb(u);
      cost[{u, v}] = w;
    }
    dfs(1);
    nodes.pb(nodes[0]);
    int res1 = 0, res2 = 0;
    int sz = szof(nodes);
    for (int i = 1; i <= n; ++i) {
      if (cost[{nodes[i], nodes[i - 1]}] != 0) res1 += cost[{nodes[i], nodes[i - 1]}];
      else res2 += cost[{nodes[i - 1], nodes[i]}];
    }
    cout << "Case " << ++tc << ": " << min(res1, res2) << nl;
  }
  return 0;
}
