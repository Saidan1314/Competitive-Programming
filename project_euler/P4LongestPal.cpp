/*
    * author: xSaidanMka
*/
#include <bits/stdc++.h>
using namespace std;
#define X '\n'
#define ll long long
/*Explanation:

A palindromic 6-digit number can be written as follows:

100000a+10000b+1000c+100c+10b+a=
11*(9091a+910b+100c) -> then, every palindromic 6-digit number
is divisibly by 11, which is prime.

then 11*(9091a+910b+100c)=mn, where
m & n are 3 digit number for this problem, and:
1<=a,b,c<=9, (being 1-digit number)

So we can do the reverse procces, instead of generate all products from 3-digit numbers and then
checking if the product is palindrome, we can generate palindromic 6-digits number and then cheking
if there exist numbers numbers m & n, such that m & n are 3-digits numberes and at least
one of them is divisible by 11.
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int ans=0;
    for (int a = 9; a>=1; a--)/*if a=0 the required answer wont be a 6-digit number*/
    {
        for (int b = 9; b>=0; b--)
        {
            for (int c = 9; c>=0; c--)
            {
                int current=9091*a+910*b+100*c;/*Now , current is a 5-digits number*/
                int pal=current*11;
                for (int divisor = 90; divisor >=10; divisor--)
                {/*we define this range because its the range such that 11 * divisor has 3 - digit-if divisor>90 then 11*divisor has 4-digit*/
                    int aux=11*divisor;
                    if(pal%aux==0){/*We assume that the n will be 3 digit*/
                        int n=pal/aux;/*verify if the remainder is a 3-digit number*/
                        if(n>=100 && n<=999){
                            ans=max(ans,pal);
                        }
                    }
                }
            }
        }
    }
    /*The complexity time es O(81x10x10x9){
    0(72900) -> 0(1) (it doesn´t depend from the input) wich is a great time complexity because we dont verify if the number is palindrome
    we directly generate them...
    }*/
    cout << ans;
    return 0;
}