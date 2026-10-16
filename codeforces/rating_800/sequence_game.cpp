#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;
const int tam_limit = 1e5 + 1;

bool many_cases = true;

void solve(){
  READVEC(n, b, ll,ll);
  ll actual = b[0];
  vector<ll> a;
  for(int i=0;i<n;i++){
    if(actual <= b[i]){
      a.push_back(b[i]);
      actual = b[i];
    }else{
      a.push_back(1);
      a.push_back(b[i]);
      actual = b[i];
    }
  }
  cout << a.size() << endl;
  for(int i=0;i<a.size();i++){
    if(i == a.size()-1){
      cout << a[i] << endl;
    }else{
      cout << a[i] << " ";
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}