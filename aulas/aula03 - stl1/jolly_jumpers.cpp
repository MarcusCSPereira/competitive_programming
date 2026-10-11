#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll n;
  while(cin >> n){
    vector<ll> v(n);
    map<ll, int> mem;
    for (auto &i : v) cin >> i;

    for(int i = 0; i<n-1; i++){
      mem[abs(v[i] - v[i+1])] = 1;
    }

    bool jolly = true;
    for(int i = 1; i<n;i++){
      if (!(mem[i])) jolly = false;
    }

    cout << (jolly == true ? "Jolly" : "Not jolly") << endl;
  }

  return 0;
}