#include <iostream>

using namespace std;
typedef long long ll;

signed main() {

    int T;
    cin >> T;

    while (T--) {

        ll n, p, l, t;
        cin >> n >> p >> l >> t;

        ll numof_t = (n + 6) / 7;

        if (numof_t & 1 ) {

            ll p_of_t = (numof_t / 2 ) * (l + 2 * t) + (l + t);
            ll p_of_2t = (numof_t / 2 ) * (l + 2 * t);

            if (p <= p_of_2t) {

                ll days = p / (l + 2 * t);
                p -= days * (l + 2 * t);
                
                if (p > 0) {

                    days++;

                }

                cout << n - days << endl;

            } 

            else if (p <= p_of_t) {

                ll days = numof_t / 2 + 1;

                cout << n - days << endl;

            }

            else {

                p -= p_of_t;
                ll days = numof_t / 2 + 1;

                days += p / l;
                p %= l;

                if (p > 0) {

                    days++;

                }

                cout << n - days << endl;

            }

        }

        else {

            ll p_of_2t = (numof_t / 2 ) * (l + 2 * t);

            if (p <= p_of_2t) {

                ll days = p / (l + 2 * t);
                p -= days * (l + 2 * t);
                
                if (p > 0) {

                    days++;

                }

                cout << n - days << endl;

            }

            else {
                

                p -= p_of_2t;
                ll days = numof_t / 2 ;

                days += p / l;
                p %= l;

                if (p > 0) {

                    days++;

                }

                cout << n - days << endl;

            }


        }

    }

    return 0;
}