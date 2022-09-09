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

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

int n, m;
string s[505];
vector<vector<bool>> used1, used2;
vector<vector<int>> dp;

bool isValid(int x, int y) {
  return (x >= 0 and x < n and y >= 0 and y < m);
}

int cnt = 0;
void dfs(int x, int y) {
  if (!isValid(x, y)) return;
  if (used1[x][y]) return;
  if (s[x][y] == '#') return;
  if (s[x][y] == 'C') cnt++;
  used1[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    dfs(x + dx[i], y + dy[i]);
  }
}

void dfs1(int x, int y) {
  if (!isValid(x, y)) return;
  if (used2[x][y]) return;
  if (s[x][y] == '#') return;
  used2[x][y] = 1;
  dp[x][y] = cnt;
  for (int i = 0; i < 4; ++i) {
    dfs1(x + dx[i], y + dy[i]);
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
    cin >> n >> m;
    int q; cin >> q;
    for (int i = 0; i < n; ++i) cin >> s[i];
    used2.assign(n + 3, vector<bool>(m + 3, 0));
    used1.assign(n + 3, vector<bool>(m + 3, 0));
    dp.assign(n + 3, vector<int>(m + 3, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] != '#' and used1[i][j] == 0) {
          cnt = 0;
          dfs(i, j);
          dfs1(i, j);
        }
      }
    }
    cout << "Case " << ++tc << ":\n";
    while (q--) {
      int x, y; cin >> x >> y;
      x--;
      y--;
      cout << dp[x][y] << nl;
    }
  }
  return 0;
}
