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
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int i=0; i<n; i++){
    cin >> b[i];
  }
  vector<ll> long_subarray_a(2*n+1, 0);
  vector<ll> long_subarray_b(2*n+1, 0);

  ll count = 1;

  //Calcular o maior subarray de valores iguais no array a
  for(int i=1;i<n;i++){
    if(a[i]==a[i-1]){
      count++;
    }else{
      long_subarray_a[a[i-1]] = max(long_subarray_a[a[i-1]], count);
      count = 1;
    }
  }

  //atualizar a ultima sequeência no array a
  long_subarray_a[a[n-1]] = max(long_subarray_a[a[n-1]], count);

  count=1;

  // Calcular o maior subarray para b agora
  for(int i=1;i<n;i++){
    if(b[i]==b[i-1]){
      count++;
    }else{
      long_subarray_b[b[i-1]] = max(long_subarray_b[b[i-1]], count);
      count = 1;
    }
  }

  //atualizar a ultima sequeência no array b
  long_subarray_b[b[n-1]] = max(long_subarray_b[b[n-1]], count);

  ll max_freq = -1;
  for(int i=1; i<=2*n; i++){
    max_freq = max(max_freq,long_subarray_a[i]+long_subarray_b[i]);
  }

  cout << max_freq << endl;

}


int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}