int gcd(int a, int b){
    if(b > a)
        swap(a,b);
    
    if(!b)
        return a;
    else
        gcd(b, a%b);
}

int lcm(int a, int b){
    if(a==b)
        return a;
    return a*b/gcd(a,b);
}