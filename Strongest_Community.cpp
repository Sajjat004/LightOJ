// In the name of Allah, Most Gracious, Most Merciful.
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using vll = vector<ll>;
using vi  = vector<int>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const int N   = (int) 2e5 + 5;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 9;

#define nl      '\n'
#define ff      first
#define ss      second
#define szof(x) (int) x.size()
#define all(x)  x.begin(), x.end()

int arr[N];
template<typename type> class SegTreeMax {
  struct Type {
    type left, right, leftVal, rightVal, mx;
    Type() : left(0), right(0), leftVal(0), rightVal(0), mx(0) {};
  };
  vector<Type> tree;
  int n;
  void build(int at, int b, int e) {
    if (b == e) {
      tree[at].left = tree[at].right = 1;
      tree[at].leftVal = tree[at].rightVal = arr[b];
      tree[at].mx = 1;
      return;
    }
    int mid = (b + e) >> 1;
    build(2 * at, b, mid);
    build(2 * at + 1, mid + 1, e);
    tree[at].mx = max(tree[2 * at].mx, tree[2 * at + 1].mx);
    tree[at].left = tree[2 * at].left;
    tree[at].leftVal = tree[2 * at].leftVal;
    tree[at].right = tree[2 * at + 1].right;
    tree[at].rightVal = tree[2 * at + 1].rightVal;
    if (tree[2 * at].rightVal == tree[2 * at + 1].leftVal) {
      tree[at].mx = max(tree[at].mx, tree[2 * at].right + tree[2 * at + 1].left);
      if (tree[2 * at].leftVal == tree[2 * at].rightVal) tree[at].left += tree[2 * at + 1].left;
      if (tree[2 * at + 1].leftVal == tree[2 * at + 1].rightVal) tree[at].right += tree[2 * at].right;
    }
  }
  Type query(int at, int b, int e, int l, int r) {
    if (r < b or e < l) return Type();
    if (l <= b and e <= r) return tree[at];
    int mid = (b + e) >> 1;
    Type x = query(2 * at, b, mid, l, r);
    Type y = query(2 * at + 1, mid + 1, e, l, r);
    Type ret;
    ret.mx = max(x.mx, y.mx);
    ret.left = x.left;
    ret.leftVal = x.leftVal;
    ret.right = y.right;
    ret.rightVal = y.rightVal;
    if (x.rightVal == y.leftVal) {
      ret.mx = max(ret.mx, x.right + y.left);
      if (x.leftVal == x.rightVal) ret.left += y.left;
      if (y.leftVal == y.rightVal) ret.right += x.right;
    }
    return ret;
  }
public:
  SegTreeMax(int n) {
    this->n = n;
    tree.resize(4 * n);
    build(1, 1, n);
  }
  type query(int l, int r) {
    Type ans = query(1, 1, n, l, r);
    return ans.mx;
  }
};

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0; cin >> test;
  while (test--) {
    int n, c, q; cin >> n >> c >> q;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    SegTreeMax<ll> segTree(n);
    cout << "Case " << ++tc << ":\n";
    while (q--) {
      int l, r; cin >> l >> r;
      cout << segTree.query(l, r) << nl;
    }
  }
  return 0;
}
