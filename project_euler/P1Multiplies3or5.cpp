/*
    * author: xSaidanMka
*/
#include <bits/stdc++.h>
using namespace std;
#define X '\n'
#define ll long long

/*Explanation:

A naive approach is iterating from 3 to 1000 and if the current value is multiple of 3 or 5
we add it to the current sum.

A very good approach and further more efficient is that we can use summation directly from
multiples of 3 and 5 and subtracting the repeated ones, which can be calculated them using the 
summation from the lcm(3,5), so we can compute them as follows:

lcm(3,5)=15 where lcm is the: Least common multiple

sum(from i=1 to floor(n/3))(3i) + sum(from i=1 to floor(n/5))(5i) - sum(from i=1 to floor(n/15))(15i)

which can be writtens as follows using the gaussian sum formula:


3*(flor(n/3)*(floor(n/3)+1))/2 + 5*(flor((n-1)/5)*(floor((n-1)/5)+1))/2 - 15*(floor(n/15)*(floor(n/15)+1))/2 


Note: Note that we use n-1 in the case of the summation of the multiplies of 5 because because the
problem ask for the sum of the multiples of 3 or 5 BELOW 1000, 5 is a divisor of 1000, so
we dont have to count this iteration.

Its not necessary to use floor(x) function given that the integer type make that process directly when rounding
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n=1000;
    ll sum3 = 3*((n/3)*((n/3)+1))/2;
    ll sum5 = 5*(((n-1)/5)*(((n-1)/5)+1))/2;
    ll sum15 = 15*((n/15)*((n/15)+1))/2;
    cout << sum3 + sum5 - sum15;
    return 0;
}