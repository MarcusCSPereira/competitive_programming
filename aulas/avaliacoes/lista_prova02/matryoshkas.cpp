#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;

void solve(){
  int n;cin >> n;
  vector<ll> v(n);
  map<ll, ll> freq;
  for(int i=0;i<n;i++){
    cin >> v[i];
    freq[v[i]]++;
  }
  ll ans =0;
  for(auto &[x,qtd] : freq){
    if(freq[x] > freq[x-1]){
      ans+= freq[x] - freq[x-1];
    }
  }

  cout << ans << endl;

}

bool many_cases = true;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}