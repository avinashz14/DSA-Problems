using namespace std;
#define ll long long 

ll modPower(ll a, ll b, ll X) 
{ 
	ll res = 1; 
	while (b) { 
		if (b & 1) 
			res = res * a % X; 
		a = a * a % X; 
		b >>= 1; 
	} 
	return res; 
} 


int main()
{
	ll A, B, X;
	cin>>A>>B>>X;

	ll lastX = modPower(A, B, (1LL) * pow(10, X)); 
	ll firstX; 
	double y = (double)B * log10(A * 1.0); 
	y = y - (ll)y; 
	double temp = pow(10.0, y); 
	firstX = temp * (1LL) * pow(10, X - 1); 
    
	cout << firstX << " " ;

    
	int n = lastX==0?X :X-(int)(log10(lastX)+1);
	while(n)
	{
		cout<<'0';
		n--;
	}

	if(lastX!=0)cout<< lastX;
	 cout<< endl; 

}
