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
  int n; cin >>n;
  vector<ll> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
    if(v[i] == 1){
      v[i]++;
    }
  }

  for(int i=0; i<n-1;i++){
    if(v[i+1] % v[i] ==0){
      v[i+1]++;
    }
  }

  for(int i=0;i<n;i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}