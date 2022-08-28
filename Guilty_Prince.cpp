
/**
*     => Md. Sajjat Hosen
*     => Department of Computer Science and Engineering
*     => Bangabandhu Sheikh Mujibur Rahman Science and Technology University
**/

/*..................! TRY ONCE MORE !..................*/

/*...Part - 01...*/

#include <bits/stdc++.h>
using namespace std ;

/*...Part - 02...*/

typedef long long               ll ;
typedef long double             ld ;
typedef unsigned long long      ull ;
typedef pair<int,int>           pii ;
typedef pair<ll,ll>             pll ;
typedef vector<int>             vi ;
typedef vector<ll>              vll ;
typedef vector<vector<int>>     vvi ;

int Int(){int x ; scanf("%d",&x) ; return x ;}
ll Long(){ll x ; scanf("%lld",&x) ; return x ;}
float Float(){float x ; scanf("%f",&x) ; return x ;}
double Double(){double x ; scanf("%lf",&x); return x;}

/*...Part - 03...*/
/*....Debugger....*/

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}

/*...Part - 04...*/
/*...Needed to change according to problem requirements...*/

const int N          = (int)2e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;

/*..........................................................*/
/*...Part - 05...*/

#define     debug(x)    cerr << #x << " = " << x << '\n' ;
#define     rep(i,b,e)  for(__typeof(e) i = (b) ; i != (e + 1) - 2 * ((b) > (e))  ; i += 1 - 2 * ((b) > (e)))
#define     Int         Int()
#define     Long        Long()
#define     Float       Float()
#define     Double      Double()
#define     all(x)      x.begin() , x.end()
#define     sz(x)       (int)x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     eb          emplace_back
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

/*...Part - 06...*/
/*...... ! Code start from here ! ......*/

bool vis[25][25];
int ans = 0, n, m;
string g[50];

int x[] = {0, 0, -1, 1};
int y[] = {1, -1, 0, 0};

void dfs(int u, int v){
    vis[u][v] = true;
    ans++;
    for(int i = 0; i < 4; i++){
        int uu = u + x[i];
        int vv = v + y[i];
        if(uu >= 0 and uu < n and vv >= 0 and vv < m and g[uu][vv] == '.' and !vis[uu][vv]) dfs(uu, vv);
    }

}

int main(){
    //freopen("input.txt","r",stdin);
    int test = Int , tc = 0 ;
    int  i, j, u, v;
    while(test--){
        ans = 0;
        memset(vis, false, sizeof vis);
        m = Int;
        n = Int;
        for(i = 0; i < n; i++){
            cin >> g[i];
            for(j = 0; j < g[i].size(); j++){
                if(g[i][j] == '@'){
                    u = i;
                    v = j;
                }
            }
        }
        dfs(u, v);
        printf("Case %d: %d\n", ++tc, ans);
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/
