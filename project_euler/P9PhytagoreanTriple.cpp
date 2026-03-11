/*
    * author: xSaidanMka
*/

    /*We're asked for the product of the 3 sides of a triangle such that
    a + b + c = 1000
    being a,b,c natural numbers
    
    when the length of the sides of a recangle triangle are natural numbers,
    its called pythagorean triple
    
    The most famous phytagorean triple is:
    
    a=3, b=4, c=5
    
    There are two types of phytagorean triples:

    Primitive vs Multiple

    Primivite: They are those that don't have any common divisor, it means
    gcd(a,c,b) = 1
    Multiplie / Composite = They are those that are linear combination from a 
    primitive triple, multiplied by a natural number...



    There's a formula to generate infinite phytagorean triples, it's called
    euclide's formula

    Given m, n parameters such that m & n are natural numbers and m > n:

    a= m² - n²
    b=2mn
    c= m² + n²


    this formula can generate both primitive triples and composite triples:
    but, to generate primitive triples, m & n will have to satisfy certain conditions:

    m & n are coprimes
    m & n will have different parity

    There exist infiite combinations that satisfie this condition, so, there are 
    infinite primitive triples...


    Fun facts:
    1.There existe a infinit triples family where the hypotenuse and the largest leg
    only has a 1 difference length.

    2.Multiples of 3,4,5: All triple, it doesnt matter if the triple is primitive 
    or not, at least one of the sides will be divisible by 3, at least one side
    will be divisible by 4, and at least one side will be divisible by 5, ¡Always!

    3.The area of a tringle with a phytagorean ternary will always be a integer
    number...

    The approach to this problem is using the euclide's formula:

    a= m² - n²
    b=2mn
    c= m² + n²

    So a + b + c = 1000
    Symplifying:

    you will get at here:

    m(m+n)=500

    So the proble reduces to search divisors of 500

    m=10 n=40 X (m has to be greater than n)
    m=5 n=96 X (the same condition aplies)
    m=20 n= 5 Yes, we find it... its feasible because 500 has few divisors.

    So by substituting m & n:

    a=375
    b=200
    c=425

    So abc = 31875000


    We didn´t even have to code

    Fun fact:
A
    The values of a,b,c (375,200,425) -> 25(15,8,17) this is a primitive triple
    */