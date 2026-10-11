#include <bits/stdc++.h>
#define debug(x) cout << #x << "=" << x << endl
#define endl '\n'
using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll n , q; cin >> n >> q;

  ll a[n];

  for(ll i=0 ; i< n; i++){
    cin >> a[i];
  }

   vector<ll> p(n+1,0);

  for(ll i=1; i <= n ;i++){
    p[i] = p[i-1] + a[i-1]; 
  }

  while(q--){
    ll l, r; cin >> l >> r;
    cout << p[r] - p[l-1] << endl;
  }


  return 0;
}