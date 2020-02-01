#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846
 
typedef long long ll ;
typedef unsigned long long ull ;
 
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
 
const int blockSZ = 400 ;
int N , Q , tree[180][10000+10] , arr[30000+10] ;
 
void update(int block,int k,int val)
{
    while( k>0 )
    {
        tree[block][k]+=val;
        k-=k&-k;
    }
}
 
int sum(int block,int k)
{
    int s = 0 ;
    while( k<=10000 )
    {
        s+=tree[block][k];
        k+=k&-k;
    }
    return s ;
}
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&N);
 
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&arr[i]);
        update(i/blockSZ,arr[i],1);
    }
 
    scanf("%d",&Q);
 
    while( Q-- )
    {
        int flag ;
        scanf("%d",&flag);
        if(flag==0)
        {
            int i , v ;
            scanf("%d%d",&i,&v);
            update(i/blockSZ,arr[i],-1);
            update(i/blockSZ,v,1);
            arr[i] = v ;
        }
        else
        {
            int L , R , k ;
            scanf("%d%d%d",&L,&R,&k);
            int ans = 0 ;
 
            while(L<=R&&L%blockSZ!=0) ans+= arr[L++]>k ;
            while(L<=R&&R%blockSZ!=blockSZ-1) ans+=arr[R--]>k ;
 
            if(L<R)
            {
                int bl = L/blockSZ ;
                int br = R/blockSZ ;
                for(int i=bl;i<=br;i++) ans+=sum(i,k+1);
            }
 
            printf("%d\n",ans);
        }
    }
 
    return 0;
}