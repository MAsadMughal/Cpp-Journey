#include <iostream>
#include <vector>
using namespace std;

// Sieve of Eratosthenes =>Segmented Sieve for in a range primes
int main()
{
    int n = 50;
    int count = 0;
    vector<bool> primes(n + 1, true);
    for (int i = 2; i < n; i++)
    {
        if (primes[i])
        {
            count++;
            for (int j = i * 2; j < n; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    return count;
}

