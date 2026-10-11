#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = false;

void solve(){
  int n; cin >> n;
  vector<int> c(n), k(n);
  vector<pair<int, pair<int,int>>> indx(n);
  for (int i =0; i<n; i++){
    cin >> c[i];
  }
  for(int i=0;i<n;i++){
    cin >> k[i];
  }
  for(int i=0;i<n;i++){
    if(k[i] > c[i]){
      cout << -1 << endl;
      return;
    }
    indx[i] = {c[i]-k[i],{c[i],k[i]}};
  }

  sort(indx.rbegin(), indx.rend());

  ll ans=0;
  for(int i=0;i<n;i++){
    if(i != n-1){
      ans+= indx[i].second.first;
    }else{
      ans+= (indx[i].second.second);
    }
  }

  cout << ans << endl;
  
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}