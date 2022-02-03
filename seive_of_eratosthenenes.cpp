#include <bits/stdc++.h>
using namespace std;

void primeSeive(int n)
{
    if (n == 0 || n == 1)
    {
        cout << "No prime exist" << endl;
        return;
    }

    int primes[150] = {0};

    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == 0)
        {
            cout << i << " ";
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 1;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    primeSeive(n);
    return 0;
}