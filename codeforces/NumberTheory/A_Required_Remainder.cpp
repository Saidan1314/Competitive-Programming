/*
    * author: xSaidanMka
*/
#include <bits/stdc++.h>
using namespace std;
#define X '\n'
#define ll long long

/*Problem: 1374A*/

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--){
        int x,y,n; cin >> x >> y >> n;
        /*I want to find the maximum number k, 
        
        0 <= k <= n
        
        such that k mod x = y
        
        
        when dividing k by x the remainder will be y

        k = qx + y, where y = k mod x

        I can find all the multipies of x under n

        then we can establish the following inequality if k is less than n:
        
|       xq + y  <= n

            q <= (n-y)/x
            q = floor((n-y)/x) -> to maximize k...
        
        using the previous formula:

        k = floor((n-y)/x) * x + y


        */
        cout <<((n-y)/x)*x + y <<X;




    }
    
    return 0;
}