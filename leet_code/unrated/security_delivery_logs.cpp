#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll maxSafeDeliveries(const vector<int>& deliveryLogs, int k) {
    int m = k / 2;

    int maior = 0;
    for (int a : deliveryLogs) {
        maior = max(maior, a);
    }

    ll resposta = 0;

    for (ll t = 1; t <= maior; ++t) {
        ll blocos = 0;
        vector<ll> restos;

        for (int a : deliveryLogs) {
            blocos += a / t;
            restos.push_back(a % t);
        }

        // Não conseguimos formar os m comprometidos.
        // Para limites maiores, a quantidade de blocos
        // só diminui, então podemos encerrar.
        if (blocos < m) {
            break;
        }

        // Temos blocos completos para todos os armazéns.
        if (blocos >= k) {
            resposta = max(resposta, m * t);
            continue;
        }

        // Reservamos m blocos completos aos comprometidos.
        ll completosSeguros = blocos - m;
        ll seguras = completosSeguros * t;

        // Quantas posições seguras ainda faltam preencher?
        ll faltam = m - completosSeguros;

        // Cada resto ocupa um armazém:
        // escolhemos os maiores.
        sort(restos.rbegin(), restos.rend());

        ll usar = min(faltam, (ll)restos.size());

        for (ll i = 0; i < usar; ++i) {
            seguras += restos[i];
        }

        resposta = max(resposta, seguras);
    }

    return resposta;
}

int main() {
    vector<int> deliveryLogs = {3, 5, 9, 6};
    int k = 4;

    cout << maxSafeDeliveries(deliveryLogs, k) << '\n';
    // 9
}