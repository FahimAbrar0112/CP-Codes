int binExpItr(int a, int b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            // ans = ans * a;

            ans = (ans * a) % M;
        }
        b >>= 1;
        // a = a * a;
        a = (a * a) % M;
    }
    return ans;
}
