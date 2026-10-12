#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;

void solve(){
  ll n; cin >> n;
  vector<ll> p(n+1);
  p[0] = 0;
  for(int i=1;i<n+1;i++){
    cin >> p[i];
  }
  vector<ll> v(n);
  for (int i=n;i>0; i--){
    v[i-1] = p[i] - p[i-1];
  }

  for(int i=0;i<n;i++){
    cout << v[i] << " ";
  }


}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}