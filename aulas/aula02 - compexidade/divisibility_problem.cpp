#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v;

  for(int i = 0; i < n ; i++){
    int a;
    int b;
    cin >> a >> b;
    if(a%b != 0){
      v.push_back((b - a%b));
    }else{
      v.push_back(0);
    }
  }

  for (int x : v) {
    cout << x << "\n";
  }

  return 0;
}