long long max2Div(long long n)
{
    long long k = 0;
    long long p = 1;
    while (n % p == 0)
    {
        k++;
        p = p * 2;
    }
    return k - 1;
}