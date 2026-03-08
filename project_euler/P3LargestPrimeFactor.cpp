/*
    * author: xSaidanMka
*/
#include <bits/stdc++.h>
using namespace std;
#define X '\n'
#define ll long long

/*Explanation:

We can use a singular aproach, the Trial divison, it consists of
dividing by numbers in increasing order, keep track of the largest factor which is already prime, we dont have
to verify if ts is prime, the reason as follows:

We start in 2, for example, which is prime, we eliminate from n all factors of 2 that n has...
Its impossible for n to be divisible by a non-prime number (composite number) because
if it had happened, one of its primes had already divided n first.


We also dont have to check if its the largest because we iterate in increasing order.(2->sqrt(n))

Another optimization: We search until sqrt(n) because its impossible to have a prime factor
after sqrt(n)...There are a lot of visual proofs if you are interested in this optimization...

There is another aproach that consists of precomputing all the primes between 2 and sqrt(n) and then
check which of them is the largest when dividing n, using Sieve of Eratosthenes

A number n can have at most 1 prime factor larger than sqrt(n), so if(n>1) keep track of this possibility...
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int ans=1;
    ll target = 600851475143;
    for (int i = 2; i*i <= target; i++){
        while (target%i==0)
        {
            target/=i;
            ans=i;
        }
    }
    if(target>1){ /*The prime factor is larger than sqrt(n), which is the largest*/
        ans=target;
    }

    cout << ans;
    return 0;
}