#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

void solve(){
  int n, q; cin >> n >> q;
  vector<ll> v(n);
  for(int i=0;i<n;i++){cin >> v[i];}

  vector<ll> pv(n+1,0);
  for(int i =1; i<n+1; i++){pv[i] = pv[i-1] + v[i-1];}

  ll total_sum = pv[n];
  for(int i=0;i<q;i++){
    ll l,r,k; cin >> l >> r >> k;
    ll prefix_value = pv[r] - pv[l-1];
    ll new_value = (r-l+1)*k;
    ll final_value = (total_sum - prefix_value) + new_value;
    if(final_value % 2 == 0){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}