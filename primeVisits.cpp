#include <bits/stdc++.h>
using namespace std;

void primeSeive(vector<int> &primes)
{
    primes[0] = primes[1] = 0;
    for (int i = 2; i <= 1000; i++)
    {
        if (primes[i] == 1)
        {
            // then it is a prime
            // we mark its multiples starting from square as non primes
            for (int j = i * i; j <= 1000; j += i)
            {
                primes[j] = 0;
            }
        }
    }
}

int main()
{
    vector<int> primes(1001, 1);

    primeSeive(primes);

    vector<int> csum(1001, 0);
    for (int i = 1; i <= 1000; i++)
    {
        csum[i] = csum[i - 1] + primes[i];
    }

    int a, b;
    cin >> a >> b;

    cout << csum[b] - csum[a - 1] << endl;

    return 0;
}