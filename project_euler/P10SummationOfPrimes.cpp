/*
    * author: xSaidanMka
*/
#include <bits/stdc++.h>
using namespace std;
#define X '\n'
#define ll long long

/*
Solution:

The most efficient approach for this problem is using the Sieve of Erathostenes

This is how it work, it stars at two, two is a prime number, i fact, the first, then, we know
all the multiples of two won't be primes because one of its factors is 2, we mark as composite
all the multiples of two, so we continue with tree, three is not cribes so, three is a prime number
so we mark as composite all the multiples of three and so on...

An optmim ization we can do, start at i squared because for every prime number the first multiple that 
it mark as composite is its square, there are a loot of proofs if you are interested...

Note: declare the iterators long long to avoid overflow



*/
constexpr ll limit = 2'000'000;
vector<bool> sieve(2e6+5,false);
ll ans=0;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (ll i = 2; i <= limit; i++){
        if(!sieve[i]){
            ans+=i;
            for (ll j = i*i; j <= limit; j+=i){
                sieve[j]=true;
            }
        }
    }
    cout << ans;
    return 0;
}