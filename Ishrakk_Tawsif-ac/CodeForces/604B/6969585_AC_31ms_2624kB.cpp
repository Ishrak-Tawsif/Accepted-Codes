#include<stdio.h>
#include<algorithm>
using namespace std;
long long n,k,s[100005],maxs;
int main(){
    scanf("%lld%lld",&n,&k);
    for(long long i=0;i<n;i++)
        scanf("%lld",&s[i]);
    maxs=s[n-1];
    for(long long i=0;i<n-k;i++)
        maxs=max(maxs,s[i]+s[(n-k)*2-i-1]);
 
    printf("%lld\n",maxs);
    return 0;
}