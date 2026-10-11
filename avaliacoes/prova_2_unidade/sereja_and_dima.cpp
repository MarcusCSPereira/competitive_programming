#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = false;

void solve(){
  READVEC(n, v, ll, ll);
  ll s_sum = 0, d_sum=0;
  ll l =0;
  ll r =n-1;
  ll i =0;
  while(l<=r){
    if(i % 2 == 0){
      if(v[r] >= v[l]){
        s_sum+= v[r];
        r--;
      }else{
        s_sum+= v[l];
        l++;
      }
    }else{
      if(v[r] >= v[l]){
        d_sum+= v[r];
        r--;
      }else{
        d_sum+= v[l];
        l++;
      }
    }
    i++;
  }

  cout << s_sum << " " << d_sum;

}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}