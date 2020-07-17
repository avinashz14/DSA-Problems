# include <stdio.h>
int main()
{
   int t; scanf("%d", &t);
   while (t--)
   {
       int n, m,k;
       scanf("%d %d %d", &n, &m, &k);
       for(int i=0; i< n; i++)
       {    int a; 
           for(int j=0; j< k; j++)
                scanf("%d",&a );
       }
    
       for(int i=0; i<n; i++)
          printf("%d ", i%m+1);
       /* code */
        printf("\n");
   }
   
}
