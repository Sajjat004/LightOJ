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

bool cmp(pii a, pii b) {
  if (a.ff == b.ff) return a.ss > b.ss;
  return a.ff > b.ff;
}

vi g[N];
vector<bool> used;

int total = 0;

pii dfs(int u, int par) {
  used[u] = 1;
  total++;
  pii res = {1, u};
  for (auto v : g[u]) {
    if (v == par) continue;
    pii x = dfs(v, u);
    x.ff++;
    if (x.ff > res.ff) res = x;
  }
  return res;
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
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    vector<pii> v;
    used.assign(n + 2, 0);
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
      if (used[i] == 0) {
        pii a = dfs(i, -1);
        total = 0;
        pii b = dfs(a.ss, -1);
        v.push_back({total, b.ff});
        mx = max(mx, b.ff);
      }
    }
    sort(all(v), cmp);
    int q; cin >> q;
    cout << "Case " << ++tc << ":" << nl;
    while (q--) {
      int k; cin >> k;
      if (k <= mx) cout << k - 1 << nl;
      else if (k > v[0].ff) cout << "impossible" << nl;
      else {
        int res = v[0].ss + (k - v[0].ss) * 2 - 1;
        for (auto x : v) {
          if (k > x.ff) break;
          res = min(res, x.ss + (k - x.ss) * 2 - 1);
        }
        cout << res << nl;
      }
    }
  }
  return 0;
}
