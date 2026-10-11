#include <bits/stdc++.h>
#define debug(x) cout << #x << "=" << x << endl
#define endl '\n'
using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  freopen("bcount.in", "r", stdin); freopen("bcount.out", "w", stdout);

  ll n, q; cin >> n >> q;

  ll a[n];
  ll r1[n] {};
  ll r2[n] {};
  ll r3[n] {};

  for(ll i=0 ; i< n; i++){
    cin >> a[i];
  }

  for(ll i=0 ; i< n; i++){
    if (a[i] == 1){
      r1[i] = 1; 
    }else if(a[i] == 2){
      r2[i] = 1;
    }else{
      r3[i] = 1;
    }
  }

   vector<ll> p1(n+1,0);
   vector<ll> p2(n+1, 0);
   vector<ll> p3(n+1,0);

  for(ll i=1; i <= n ;i++){
    p1[i] = p1[i-1] + r1[i-1];
    p2[i] = p2[i-1] + r2[i-1];
    p3[i] = p3[i-1] + r3[i-1]; 
  }

  while(q--){
    ll l, r; cin >> l >> r;
    cout << p1[r] - p1[l-1] << " " <<  p2[r] - p2[l-1] << " " << p3[r] - p3[l-1] << endl;
  }


  return 0;
}