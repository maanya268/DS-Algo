#include <bits/stdc++.h>
using namespace std;

vector<int> primeSeive()
{
    vector<int> primes(1001, 1);
    vector<int> output;
    for (int i = 2; i <= 1000; i++)
    {
        if (primes[i] == 1)
        {
            output.push_back(i);
            for (int j = i * i; j <= 1000; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    return output;
}

int main()
{
    vector<int> prime = primeSeive();

    int n;
    cin >> n;

    vector<int> factors;
    int i = 0;
    int p = prime[i];
    while (p * p <= n)
    {
        if (n % p == 0)
        {
            factors.push_back(p);
            while (n % p == 0)
            {
                n = n / p;
            }
        }
        i++;
        if (i == n + 1)
        {
            break;
        }
        p = prime[i];
    }
    if (n != 1)
    {
        factors.push_back(n);
    }

    for (auto x : factors)
    {
        cout << x << " ";
    }
    return 0;
}