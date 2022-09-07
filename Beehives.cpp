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

vi g[505];
int res = -1;
void shortageCycle(int n) {
  res = INF;
  for (int i = 0; i < n; ++i) {
    vi dist(n + 2, INF);
    vi par(n + 2, -1);
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (dist[v] == INF) {
          dist[v] = dist[u] + 1;
          par[v] = u;
          q.push(v);
        } else if (par[u] != v) {
          res = min(res, dist[u] + dist[v] + 1);
        }
      }
    }
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
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    shortageCycle(n);
    if (res == INF) cout << "Case " << ++tc << ": impossible" << nl;
    else cout << "Case " << ++tc << ": " << res << nl;
  }
  return 0;
}
