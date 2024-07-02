// USER: "Ab.Mahin"
// Problem: Efficient Construction on Mars
// Contest: Toph
// URL: https://toph.co/p/efficient-construction-on-mars
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353
//0x3f

#define MAX LLONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//find_by_order() and order_of_key()
//k-th largest element and strictly smaller


/* To finding all possible submask for a mask(set bits);
 
for(ll mask = 0; mask < (1 << n); mask++){
    for(ll submask = mask ; submask > 0; submask = (submask - 1) & mask){
    	cout << mask << ' ' << submask << '\n';	
    }
}
*/

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cout.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 15;

ll pr[N];

ll find(ll i) {return pr[i] == i ? i : pr[i] = find(pr[i]);}

struct ed{
    ll u ,v ,w;
    bool operator < (const ed& p) const{
        return w < p.w;
    }
};

vector<ed> g;

ll dp[N][1 << N];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    //cin >> t;
	
    while(t--){
        ll n, c, e;
        cin >> n >> c >> e;
        for(ll i = 0; i < e; i++){
        	ll u, v, w;
        	cin >> u >> v >> w;
        	ed x;
        	x.u = u, x.v = v, x.w = w;
        	g.push_back(x);
        	
        }
        
        
        if(c >= n){
		    cout << 0 << '\n';
		    return 0;
		}
        
        sort(g.begin(), g.end());
        
        
                
        
        auto mst = [&](ll x){
        	
        	vector<ed> nv;
        	for(ll i = 0; i <= n; i++) pr[i] = i;
        	        	
        	auto Union = [&](ll i, ll j){
        		i = find(i);
        		j = find(j);
        		if(i == j) return 0;
        		
        		pr[j] = i;
        		return 1;
        	};
        	
        	for(auto i : g){
        		if((x & (1 << i.u)) && (x & (1 << i.v))){
        			nv.push_back(i);
        		}
        	}
        	ll cnt = 1, cost = 0;
        	for(ll i = 0; i < nv.size(); i++){
        		auto [x, y, w] = nv[i];
        		if(Union(x, y)){
        			cnt++;
        			cost += w;
        		}
        	}
        	return cnt == __builtin_popcount(x) ? cost : MAX;
        };
        
        
        for(ll i = 1; i < (1 << n); i++){
        	dp[1][i] = mst(i);
        }
        
        
        for(ll i = 2; i <= c; i++){
        	for(ll mask = 0; mask < (1 << n); mask++){
        		if(__builtin_popcount(mask) <= i){
		            dp[i][mask] = 0;
		            continue;
		        }
        		ll res = MAX;
        		for(ll sub = mask; sub > 0; sub = (sub - 1) & mask){
        			for(ll j = 1; j < i; j++){
        				dp[i][mask] = min(res, max(dp[j][sub], dp[i - j][sub ^ mask]));
        			}
        		}
        		dp[i][mask] = res;
        	}
        }
        ll ans = dp[c][(1 << n) - 1];
        if(ans >= MAX) ans = -1;
        cout << ans << '\n';           
    }
    
    
    return 0;
}