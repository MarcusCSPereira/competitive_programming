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
  int n,x; cin>> n >> x;
  vector<int> result;
  for(int i=n;i>0;i--){
    if(i%x != 0){
      result.push_back(i);
      break;
    }else{
      result.push_back(1);
    }
  }

  cout << result.size() << endl;
  for(int a : result){
    cout << a << " ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}