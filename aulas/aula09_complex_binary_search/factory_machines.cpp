#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;

ll l = 0;
ll ans = 0;
ll t; 

bool f(vector<ll> &v, ll m){
    ll x = 0;
    for(int i= 0; i < v.size(); i++){
        x += m/v[i];
    }
    return (x >= t);
}

void solve(){
    ll n; cin >> n;
    cin >> t;
    vector<ll> v(n);
    ll menor_t = LLONG_MAX;
    for(int i = 0; i<n ; i++){
        ll y; cin >> y;
        if (y<menor_t){
            menor_t = y;
        }
        v[i] = y;
    }
    ll r = menor_t * t;
    
    while(l<=r){
        ll m;
        m = l + (r-l) / 2;

        if(f(v,m)){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }

    cout << ans;
    
}

bool many_cases = false;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll t = 1;
    if(many_cases) cin >> t;
    while(t--) solve();
    return 0;
}