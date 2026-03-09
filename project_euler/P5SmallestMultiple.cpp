/*
    * author: xSaidanMka
*/
#include <bits/stdc++.h>
using namespace std;
#define X '\n'
#define ll long long

/*Solution:

We´re asked for the smallest number which can be divisible by the numbers from 1 to 20
There´s a confusion in a lof of people, interpreting that n has to be divisible by 1 to 20
like a chained divison, sequential divison, which means:
((..(n / 1) ) / 2 ) / 3 ) / 4 .... ) / 20 ) has to be an integer, 
that isnt the meaning, evenly divisible means 
that n has to be divisible by 1 to 20 independently
n mod 1 = 0, n mod 2 = 0, n mod 3 = 0, .... , n mod 20 = 0

Now, having clear the idea and what´s they´re asking for, there´s an approach:

If the number has to be divisible by all the number in that range, then the number we´re looking 
for has to be a construction of all the numbers in the range, INDEPENDENTLY, then, we´re asked for
the smallest numbers which certainly satisfies the condition, and that´s exactly the lcm definition,
the lcm (Least common multiple) of all the numbers from 1 to 20 fulfills the condition,
let´s say, the lcm takes the factor of all of the numbers, without unnecessary factor to construct
the others, for example:
4 needs 2 x 2
6 needs 2 x 3, the lcm will take 2,2,3 not 2,2,2,3 only with 2 twos factor, we can construct all the 
others.

Hence, we want to calculate the lcm(1,2,3,4,...,20):
So it reduces to the following formula:

        lcm(a,b)=  |axb| / gcd(a,b)

We can calculate the lcm(1,2,..,20) using a chained focusing, carrying the lcm onto the current
value, so now, How we can calculate the gcd(a,b)?

You can use the function gcd(a,b) of the <numeric> librery, or __gcd(a,b) function if you have 
GNU version, GCC compiler (lower than the C++17 version) from the <algorithm> librery...

Or you can implement your own function to try to have more understanding how it works...

Remember that both gcd(a,b) and __gcd(a,b) uses a fast implementation of the Euclidean´s Algorithm
which involves:

a = b*q1 + r_1
b = r_1*q2 + r_2
r_1 = r_2*q3 + r_3
r_2 = r_3*q4 + r_4
...    ...
...    ... 
...    ...
r_n-3 = r_n-2*q_n-1 + r_n-1
r_n-2 = r_n-1*q_n + 0

then gcd(a,b) = r_n-1

(Using the division algorithm)

Some of the gcd(a,b) properties are:
     for b>a:
gcd(a,b) = gcd(a,b-a);

gcd(0,n) = |n|

Commutative: gcd(a,b) = gcd(b,a)

gcd(0,0) is not defined

If you want to calculate the gcd of more than two numbers you can do:

gcd(a,b,c) = gcd(a, gcd(b,c))


The supreme propertie:
Given q,r integers such that a=bq+r then gcd(a,b) = gcd(b,r)


Little explanation:
If g divides to a and b then g also divides a-b which means -> (g | a and a | b) -> (g | a-b)
So if g divides b and a-b then 
gcd(a,b) = gcd(b,a-b)
So we´ll do that, note that a is the remainder subtracting b at least floor(a/b)
so we can sustitute a-b with

a-floor(a/b)*b = a mod b to speed up...

So...

          | |a| if b=0
gcd(a,b) =| 
          | gcd(b, a mod b) otherwise


Analyzis complexity: we are subtracting b from a floor(a/b) times, so, the worst case of this 
algorithm is when we want to calculate the gcd from two consecutive elements of the fibbonacci sequence
given that the fibbonacci sequence grows exponentialy, in the worst case we have:

O(log(min(a,b))) -> F_n and F_n+-1

Take care when one of them (a or b) or both are negatives, C++ will compute bad the remainder...



GCD -> the intersection between the factors of a and b
LCM -> the product of the necesary factors to construct both a and b


gcd(a,b)xlcm(a,b) = ab



*/


auto gcdRecursive(int a, int b) -> int{
    return b ? gcdRecursive(b,a%b):abs(a); /*recursive implementation*/
}

auto gcdIterative(int a, int b) -> int{
    while (b)/*while b is positive*/
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int answer=1;
    /*We'll compute the lcm of 1 to 20
    
    Remember:

    lcd(a,b,c) = lcm(a, lcm(b,c))
    
    */

    for (int i = 2; i <= 20; i++){
        answer= i / gcd(answer,i) * answer;/*Firt divide and then multiply to avoid overflow*/
    }
    cout << answer;
    
    return 0;
}