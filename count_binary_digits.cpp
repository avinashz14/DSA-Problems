
int count_binary_digits(ll a)
{
    int cnt=0; 
    while (a)
    {
        cnt++;
        a>>=1;
    }
    return cnt;

}