#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353
//0x3f
#define lc (n << 1)
#define rc ((n << 1) | 1)

#define MAX LONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//find_by_order() and order_of_key()
//k-th largest element and strictly smaller

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cerr.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 1e5 + 5;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    cin >> t;
	
    while(t--){
        ll n;
        cin >> n;
        ll a[n + 2]{0};
        for(ll  i = 1; i <= n; i++) cin >> a[i];
                
        ll res = 0;
        
        ll prf[n + 1], suf[n + 1], csum[n + 1];
        csum[0] = a[0] = a[n + 1] = 0;
        ll sum = 0, mxsum = 0;
        for(ll i = 1; i <= n; i++){
        	sum += a[i];
        	if(mxsum < a[i]) mxsum = a[i];
        	if(sum < 0) sum = 0, mxsum = 0;
        	prf[i] = mxsum;
        	csum[i] = csum[i - 1] + a[i];
        	res = max(res, sum * mxsum);
        }
        sum = 0,mxsum = 0;
        for(ll i = n; i >= 1; i--){
        	sum += a[i];
        	if(mxsum < a[i]) mxsum = a[i];
        	if(sum < 0) sum = 0, mxsum = 0;
        	suf[i] = mxsum;
        	res = max(res, sum * mxsum);
        }
                
        ll l[n + 1]{0}, r[n + 1]{0};
        
        stack<ll> s;
        s.push(0);
        for(ll i = 1; i <= n; i++){
        	if(a[i] < 0){
        		ll x = s.top();
        		while(a[x] <= a[i]){
        			s.pop();
        			x = s.top();
        		}
        		s.push(i);
        		l[i] = x;
        	} 
        	else s.push(i);    	
        }
        
        while(!s.empty()){
        	s.pop();
        }
        
        s.push(n + 1);
        for(ll i = n; i >= 1; i--){
        	if(a[i] < 0){
        		ll x = s.top();
        		while(a[x] <= a[i]){
        			s.pop();
        			x = s.top();
        		}
        		s.push(i);
        		r[i] = x - 1;
        	} 
        	else s.push(i);    	
        }
                
        for(ll i = 1; i <= n; i++){
        	ll val = 0;
        	if(a[i] < 0){
        		val = csum[r[i]] - csum[l[i]];
        		res = max(res, val * a[i]);
        	}
        }        
        cout << res << '\n';
               
    }
    
    
    return 0;
}