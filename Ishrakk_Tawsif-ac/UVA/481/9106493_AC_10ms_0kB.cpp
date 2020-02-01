#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100005
#define ll long long int
#define mp make_pair
#define mod 1000000

int arr[1000005],ans[1000005],track[1000005],par[1000005];

void print_ans(int n)
{//cout<<par[n]<<endl;
    //if(par[n] == -1)cout<<n<<" ,,,, " << endl;
    if(par[n] != -1) //return;
    print_ans(par[n]);
    pf("%d\n", arr[n]);
}

int main()
{
    int temp,in=-1;

        //for(int i=0; i<1000005; i++) ans[i]=INT_MAX;

        int l,r,mid;

        while(sf(temp) == 1)
        {
            arr[++in] = temp;
        }

            /*for(int i=1; i<=in; i++)
            {
                temp=arr[i];

                    l=0,r=in+2;
                    //cout<<"temp : "<<temp<<endl;
                        while(r>l+1)
                        {
                            mid=(l+r)/2;
                            if(ans[mid]<temp) l=mid;
                            else r=mid;//cout<<l<<" " <<r<<" "<<mid<<endl;
                        }//cout<<" l+1 : "<<l+1 << " " << temp <<endl;

                 ans[l+1]=temp;
            }

            int fl;

            for(int i=in; i>=1; i--)
            {
                if(ans[i]!=INT_MAX)
                {//cout<<i<<"..."<<endl;
                    pf("%d\n-\n",i);
                    fl=i;
                    break;
                }
            }

            for(int i=1; i<=fl; i++)
            {
                if(ans[i] != INT_MAX) pf("%d\n",ans[i]);
            }*/

            //vector<int> ans;
            int last=0,len=0;
            for(int i=0; i<=in; i++)
            {
                int pos=lower_bound(ans,ans+len,arr[i])-ans;
                ans[pos]=arr[i];
                track[pos]=i;
                if(pos<=0) par[i]=-1;
                else par[i]=track[pos-1];

                    if(pos == len){len++;last=i;}
                    else if(pos+1 == len) last=i;
            }
            pf("%d\n-\n",len);
            print_ans(last);

    return 0;
}