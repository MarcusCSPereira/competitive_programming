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
  int n,k; cin >> n >> k;
  ll q; cin >> q;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    ll x; cin >> x;
    x <= q ? a[i] = 1 : a[i] = 0;
  }

  int c = 0;
  ll ans = 0;
  ll an = 0;
  for(int i=0;i<n;i++){
    if(a[i] == 1){
      c++;
    }else{
      if(c>=k){
        an = (c-k+1);
        ans += (an * (an+1))/2;
      }
      c=0;
    }
  }

  if(c >= k){
    an = (c-k+1);
    ans += (an * (an+1))/2;
  }

  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}