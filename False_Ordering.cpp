/*....Bismillahir Rahmanir Rahim....*/
/**
      Author  :  Md. Sajjat Hosen
      Created :  Friday, 25 April, 2020
**/
/*....! TRY ONCE MORE !....*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long               ll;
typedef long double             ld;
typedef unsigned long long      ull;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<int>             vi;
typedef vector<ll>              vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }
inline float Float() { float x; scanf("%f", &x); return x; }
inline double Double() {double x; scanf("%lf", &x); return x; }

//    Moves : L, U, R, D, LU, RU, RD, LD.
int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N          = (int)2e5 + 5;
const int maxN       = (int)1e6 + 6;
const ll  Mod        = (ll)1e9 + 7;
const int inf        = (int)2e9;
const ll  Inf        = (ll)1e18;

#define     debug(x)    cerr << #x << " = " << x << '\n';
#define     Int         Int()
#define     Long        Long()
#define     Float       Float()
#define     Double      Double()
#define     all(x)      x.begin(), x.end()
#define     sz(x)       (int)x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     eb          emplace_back
#define     mp          make_pair
#define     TN          typename
#define     pie         acos(-1.0)
#define     nl          '\n'
#define     Fast_Read   ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

/*...... ! Code start from here ! ......*/
vector<pair<int, int>> vp;
int ck[1009];

bool cmp(pii a, pii b) {
    if (a.ss < b.ss) {
        return 1;
    } else if (a.ss == b.ss) {
        return a.ff > b.ff;
    } else {
        return 0;
    }
}

void precal() {
    for (int i = 1; i <= 1000; i++) {
        for (int j = i; j <= 1000; j += i) {
            ++ck[j];
        }
        vp.eb(mp(i, ck[i]));
    }
    sort(vp.begin(), vp.end(), cmp);
}

int main() {
    //Fast_Read
    //freopen("input.txt", "r", stdin);
    int test = 1, tc = 0;
    cin >> test;
    precal();
    int n;
    while (test--) {
        cin >> n;
        cout << "Case " << ++tc << ": " << vp[n - 1].ff << nl;
    }
    return 0;
}

/*................END.................*/
