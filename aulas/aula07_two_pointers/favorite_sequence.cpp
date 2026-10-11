#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;

bool many_cases = true;

void solve(){
  ll n; cin >> n;
  vector<ll> v(n);
  ll l = 0;
  ll r = n-1;
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  vector<ll> v2(n);
  for(int i=0;i<n;i++){
    if(i%2==0){
      v2[i] = v[l];
      l++;
    }else {
      v2[i] = v[r];
      r--;
    }
  }

  for(int i=0;i<n;i++) cout << v2[i] << " ";
  cout << endl;  
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll t =1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}