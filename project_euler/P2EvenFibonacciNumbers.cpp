/*
    * author: xSaidanMka
*/
#include <bits/stdc++.h>
using namespace std;
#define X '\n'
#define ll long long
/*Explanation:

The magic of this problem resides on the golden number, phi = 1.61...
This number also called auric ratio is the aproximate ratio between two consecutive
elements in the fibbonacci sequence, so, if we observe the behavior of the function,
 every 3 elements appears a even number, so if in two consecutive elements there is a golden
ratio, every 3 elements there is phi^3 ratio so, we can "jump" 3 by 3 elements in the sequence
only generating even elements and carry the current sum, all of this while the current value
dont exceed 4e6
F_n+1=F_n * phi -> approximately
F_(n+3)=F_n * phi^3 -> approximately

From this derivates a important formula:
The binet's Formula:

F(n)=(phi^n)/sqrt(5) -> aproximately

Thus, we can generate the n element in the sequence only with this formula, the proof is a great 
practice!
*/
const double phi = (1.0 + sqrt(5.0)) / 2.0;    
const double phiCubic = phi * phi * phi;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int even = 2,sum = 0,iterations = 0;
    while (even <= 4000000){
        sum += even;
        iterations ++;
        even = (int)(even * phiCubic +0.5);/*Or we can use the round(x) function, it rounds to the nearest integer*/
    }
    cout <<"Sum of the values that doesnt exceed 4000000: "<< sum << ": Processed in: "<<iterations << " operations...";
    return 0;
}