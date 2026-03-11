/*
    * author: xSaidanMka
*/
#include <bits/stdc++.h>
using namespace std;
#define X '\n'
#define ll long long

/*Solution: 
We're asked for the 10001st number prime...
So leet's see:
1 is not prime
2 is prime and its multiples are not
A number n can have at most one prime factor greater than sqrt(n)

Now, we have a tool we can use: The primes numbers theorem:

The n-th prime (Pn) can be aproximated with the following formula

Pn = nln(n) ->aproximately
This means that
By substituting n = 10001
P_10001  is nearby to (10001)Ln(10001)
which is = The 10001st prime number will be close to 92113 aproximately


To provaide an adecuate search margin, we'll use a limit of 200000, ensuring 
we find the requested prime number within this aproximate range

*/
vector<bool> criba(200'000+5,false);


constexpr ll limit = 200'000;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int primes=0;
    ll candidate;
    int target=10001;
    for(ll i = 2; i <= limit; i++){
        if(!criba[i]){
            primes++;
            if(primes==target){
                candidate = i;
                break;
            }
            for (ll j = i*i; j <= limit; j+=i)/*We start in the square (Optimization)*/
            {
                criba[j]=true;
            }
            
        }
    }
    cout << "The: " << target << " prime is: " << candidate <<X;
    return 0;
}