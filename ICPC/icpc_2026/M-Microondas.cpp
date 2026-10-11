#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;
const int tam_limit = 1e5 + 1;

// {custo, vertice, micro}
typedef tuple<ll,int,int> custo_vertice_micro;
vector<vector<custo_vertice_micro>> grafo;
vector<int> pai;
// linha é a distância da origem até a linha, e coluna é cada camada (numero de K's usados).
vector<vector<ll>> dist;

void dijkstra_with_states(int origem, int limite){
  priority_queue<custo_vertice_micro, vector<custo_vertice_micro>, greater<custo_vertice_micro>> propostas;
  dist[origem][0] = 0;
  propostas.push({0, origem,0});

  while(!propostas.empty()){
    auto [dist_proposta, u, used] = propostas.top();
    propostas.pop();

    if(dist_proposta > dist[u][used]) continue; // entrada obsoleta: u já tem distância melhor

    for(auto [peso_aresta, v, micro] : grafo[u]){
      // Usando fibra
      ll dist_candidata = dist_proposta + peso_aresta;

      if(dist_candidata < dist[v][used]){
        dist[v][used] = dist_candidata;
        pai[v] = u;
        propostas.push({dist_candidata, v, used});
      }

      //Usando micro
      if(micro != -1 && used < limite){
        ll dist_candidata = dist_proposta + micro;

        if(dist_candidata < dist[v][used + 1]){
          dist[v][used+1] = dist_candidata;
          pai[v] = u;
          propostas.push({dist_candidata, v, used+1});
        }
      }
    }
  }
}

bool many_cases = false;

void solve(){ 
  int N, M, K; cin >> N >> M >> K;
  grafo = vector<vector<custo_vertice_micro>>(N+1);
  dist = vector<vector<ll>>(N+1, vector<ll>(K+1,LLONG_MAX));
  pai = vector<int>(N+1);
  for (int i=0; i< M; i++){
    int aresta1, aresta2; cin >> aresta1 >> aresta2;
    ll peso; cin >> peso;
    ll w; cin >> w;
    grafo[aresta1].push_back({peso,aresta2,w});
    grafo[aresta2].push_back({peso,aresta1,w});
  }

  dijkstra_with_states(1,K);
  ll ans = LLONG_MAX;
  for(int i=0;i<=K; i++){
    ans = min(ans,dist[N][i]);
  }

  cout << ans << endl;
} 

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}