#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b;
    int n;
    int caso = 1;

    while (cin >> a >> b >> n) {
        // c = a + bi
        // z começa em z0 = 0 + 0i
        double x = 0.0; // parte real de z
        double y = 0.0; // parte imaginária de z

        bool divergiu = false;

        for (int i = 0; i < n; i++) {
            // z_novo = z_atual^2 + c
            double novo_x = x * x - y * y + a;
            double novo_y = 2 * x * y + b;

            x = novo_x;
            y = novo_y;

            // |z| > 2  equivale a  x² + y² > 4
            if (x * x + y * y > 4.0) {
                divergiu = true;
                break;
            }
        }

        cout << "Case " << caso << ": ";

        if (divergiu) {
            cout << "OUT\n";
        } else {
            cout << "IN\n";
        }

        caso++;
    }

    return 0;
}