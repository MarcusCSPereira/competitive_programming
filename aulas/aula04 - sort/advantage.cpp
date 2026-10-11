#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t; cin >> t;
  while(t--){

    ll n; cin >> n;
    vector<ll> v(n);
    vector<ll> vs(n);
    for(int i=0; i<n ; i++){
      cin >> v[i];
      vs[i] = v[i];
    }

    sort(vs.rbegin(),vs.rend()); //O(n log n)

    for(int i=0; i<n ; i++){
      if (v[i] != vs[0]){
        cout << v[i] - vs[0] << " ";
      }else{
        cout << v[i] - vs[1] << " ";
      }
    }

    cout << endl;
  }

  return 0;
}