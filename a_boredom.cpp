#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
#define fn(i,a,b) for(int i=a;i<b;i++)
#define fne(i,a,b) for(int i=a;i<=b;i++)
#define fr(i,a,b) for(int i=a;i>b;i--)
#define fre(i,a,b) for(int i=a;i>=b;i--)
#define print(x) for(auto ele:x)cout<<ele<<" ";cout<<endl;
#define printp(x)  for(auto ele:x)cout<<ele.first<<" "<<ele.second<<endl;
#define all(a) a.begin(),a.end()
// or add ll at the end for long long
#define cntleadz(x) __builtin_clz(x)
#define cnttrailz(x) __builtin_ctz(x)
#define cntpop(x) __builtin_popcount(x)
#define binparity(x) __builtin_parity(x)
#define pb push_back
#define pii pair<int,int>
#define int long long
#define fi first
#define se second
#define mod 1000000007
// #define mod 998244353
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define make_graph(k) int x,y; f0(i,0,k){cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define test int t;cin>>t;while(t--)
 
//ll binExp(ll x,ll n,ll m){ll res=1;while(n){if(n&1) res=(res*x)%m;x=(x*x)%m;n>>=1;}return res;}

//ll modInv(ll i, ll m) {return binExp(i,m-2,m);}
//ll add(ll a, ll b) {ll res = a+b; if(res >= mod) res -= mod; if(res < 0) res += mod; return res;}
//ll mul(ll a, ll b) {ll res = (a)*(b); res %= mod; if(res < 0) res += mod; return res;}
// ll fact[200005];
// ll rfact[200005];
// ll ncr(int n,int r) {return ((n>=r && r>=0)?(fact[n]*rfact[r])%mod*rfact[n-r]%mod:0);}
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int f(int idx, int n, vector<int>& a, vector<int>& dp) {
    if(idx >= n) return 0;

    if(dp[idx] != -1) return dp[idx];

    int ans = 0;
    // dont delete
    ans = max(ans, f(idx + 1, n, a, dp));
    // delete ak

    int i = idx + 1;

    int i1 = upper_bound(a.begin(), a.end(), a[idx]) - a.begin();
    int i2 = upper_bound(a.begin(), a.end(), a[idx] + 1) - a.begin();

    int temp = 0;
    temp = a[idx] * (i1 - idx);    
    
    ans = max(ans, f(i2, n, a, dp) + temp);
    
    return dp[idx] = ans;
}
void solve()
{
    int n;cin>>n;
    vector<int>a(n);
    fn(i, 0, n) cin>>a[i]; 
    sort(all(a)); 

    vector<int>dp(n, -1);
    cout<<f(0, n, a, dp)<<endl; 
}
 
signed main()
{
    fast
    clock_t start,end;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
    start = clock();
 
    int tc;
    tc = 1;
    // cin>>tc;
    fne(i,1,tc)solve();
 
    end = clock();
    double time_taken = double(end-start) / double(CLOCKS_PER_SEC);
    // cout<<time_taken<<" sec";
}
