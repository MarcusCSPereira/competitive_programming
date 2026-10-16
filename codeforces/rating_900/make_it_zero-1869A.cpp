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
  int n, sum =0; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i]; sum += a[i];
  }
  if(sum == 0) COUT(sum); 
  if(n %2 == 0){
    cout << 2 << endl;
    cout << 1 << " " << n << endl; cout << 1 << " " << n << endl;
  }else{
    cout << 4 << endl;
    cout << 1 << " " << n-1 << endl; cout << 1 << " " << n-1 << endl;
    cout << n-1 << " " << n << endl; cout << n-1 << " " << n  << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}