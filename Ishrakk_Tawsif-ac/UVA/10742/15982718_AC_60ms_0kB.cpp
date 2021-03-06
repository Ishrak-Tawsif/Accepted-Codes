#include <cstdio>
#include <vector>
using namespace std;

int binarySearch(int n);
void sieve(int n);
int numList[1000100]={0};
vector<int> prims;
int main()
{
    int n=0, t=1;
    sieve(1000000);

    for(int i=2; i<=1000000; i++)
        if(numList[i]==0) prims.push_back(i);

    while(scanf("%d", &n))
    {
        if(n==0) break;
        long c=1, diff=0, tmpc=0;
        for(int i=0; prims[i]<=n/2; i++)
        {
            diff=n-prims[i];
            if(diff==prims[i]) continue;
            while(diff)
            {
                if(numList[diff]==0) break;
                diff--;
            }
            tmpc= binarySearch(diff);
            c+=(tmpc-i);
        }
        printf("Case %d: %ld\n", t++, --c);
    }
    return 0;
}

int binarySearch(int n)
{
    int b=0, e=prims.size(), m=0, val=0, r=-1;

    while(b<=e)
    {
        m=(b+e)/2;
        val=prims[m];
        if(n==val)
        {
            r=m;
            break;
        }

        else if(n>val) b=m+1;
        else if(n<val) e= m-1;
    }

    return r;
}

void sieve(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(numList[i]!=0) continue;

        for(int j=i*2; j<=n; j+=i)
            numList[j]=1;
    }
}