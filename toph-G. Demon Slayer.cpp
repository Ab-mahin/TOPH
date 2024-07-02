#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll int
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
const ll N = 3e5 + 5;

ll fun(ll x, ll y, ll dy, ll dx){
	if(dy == 0) return 0;
	ll g = __gcd(dy, dx);
	dy /= g;
	dx /= g;
	
	ll p = (dy * x) - (dx * y);
	return (p % dy) ? 0 : (p / dy);
}

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
        ll n, m;
        cin >> n >> m;
        
        vector<pair<ll, ll>> v;
        ll ans[n + 1]{0}, cnt[n + 1]{0};
        for(ll i = 0; i < m; i++){
        	ll x, y;
        	cin >> x >> y;
        	vector<ll> b;        	
        	for(auto [p, q] : v){
        		ll dy = (q - y);
        		ll dx = (p - x);
        		ll dn = fun(p, q, dy, dx);
        		if(dx == 0) dn = p;
        		if(dn > 0 && dn <= n){
    				if(!cnt[dn]) b.push_back(dn);
    				cnt[dn]++;
    			}
        	}
        	for(auto j : b) {
        		ans[j] = max(ans[j], cnt[j]);
        		cnt[j] = 0;
        	} 
        	v.push_back({x, y});      	
        }
        for(ll i = 1; i <= n; i++){
        	cout << ans[i] + 1 << " \n"[i == n];
        }   
    }
    
    
    return 0;
}