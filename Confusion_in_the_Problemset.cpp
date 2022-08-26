/*---------------------------------------
   BISMILLAHIR RAHMANIR RAHIM
   AUTHOR : Md. Sajjat Hossen
   TIME : 24-March,2021 10:47:38 PM
----------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long               ll;
typedef  long double             ld;
typedef  unsigned long long      ull;
typedef  pair<int, int>          pii;
typedef  pair<ll, ll>            pll;
typedef  vector<int>             vi;
typedef  vector<ll>              vll;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int Mod     = (int) 1e9 + 7;

#define    debug(x)    cerr << #x << " = " << x << '\n';
#define    all(x)      x.begin(), x.end()
#define    szof(x)     (int) x.size()
#define    ff          first
#define    ss          second
#define    pb          push_back
#define    mp          make_pair
#define    PI          acos(-1.0)
#define    nl          '\n'
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
        int n = Int();
        int ar[n + 2];
        for (int i = 1; i <= n; ++i) ar[i] = Int();
        int res[n + 2];
    	memset(res, -1, sizeof res);
    	bool ok = 1;
    	for (int i = 1; i <= n; ++i) {
    		if (ar[i] + 1 > n or n - ar[i] < 1) break;
    		if (res[ar[i] + 1] == -1) {
    			res[ar[i] + 1] = 1;
    		} else if (res[n - ar[i]] == -1) {
    			res[n - ar[i]] = 1;
    		} else {
    			ok = 0;
    			break;
    		}
    	}
    	for (int i = 1; i <= n; ++i) if (res[i] == -1) ok = 0;
    	if (ok) printf("Case %d: yes\n", ++tc);
    	else printf("Case %d: no\n", ++tc);
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
