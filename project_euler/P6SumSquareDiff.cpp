/*
    * author: xSaidanMka
*/
#include <bits/stdc++.h>
using namespace std;
#define X '\n'
#define ll long long

/*Explanation:

Use gaussian formula for the square of the sum

So we have:

n(n+1)/2 -> (100(101)/2)^2 -> (50*101)^2

Thus, on the other hand, we can compute the sum of the squares with the summation formula

sum( from i=1 up to 100) i^2 which is a very common expression, we have the closed formula:

n(n+1)(2n+1)/6

we can use this formula to achieve both better performance and O(1) time complexity


so we have:

100(101)(201)/6 -> Sum of the squares...

*/

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n=100;
    int sumOfSquares = n*(n+1)*(2*n+1)/6;
    int squareOfTheSum = (n*(n+1)/2)*(n*(n+1)/2);
    cout << squareOfTheSum - sumOfSquares;
    return 0;
}