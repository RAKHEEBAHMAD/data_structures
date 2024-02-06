#include <iostream>
using namespace std;

#define MOD 1000000007
#define ll long long int

int main() {
    ll n;
    cin >> n;

    ll result = 1;
    for (int i = 0; i < n; ++i) {
        result = (result * 2) % MOD;
    }

    cout << result << endl;

    return 0;
}
