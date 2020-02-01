#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 100000007


string str[]={"bogus","January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November" ,"December"};


bool isLeapyear	(ll n)
{
    if(n%4 == 0 && n%100!=0) return 1;
    else if(n%4==0 && n%400==0) return 1;
    return 0;
}

int main()
{
    ll date1,date2,year1,year2;
    int tc;
    string month1,month2;

    map <string,int> mp;

    for(int i=1; i<=12; i++) mp[str[i]]=i;

        sf(tc);
            loop1(tt,tc)
            {
                cin>>month1;
                scanf("%lld,%lld",&date1,&year1);
                cin>>month2;
                scanf("%lld,%lld",&date2,&year2);

                    if(isLeapyear(year1))
                    {//cout<<"11111"<<endl;
                        if(mp[month1]>2) year1++;
                        else year1--;
                    }
                    if(isLeapyear(year2))
                    {//cout<<"22222"<<endl;
                        if(mp[month2]>2 || (mp[month2]==2 && date2==29)) year2++;
                        else year2--;
                    }//cout<<year1<<" "<<year2<<endl;
                    ll ans1 = (year1/4) - (year1/100) + (year1/400);
                    ll ans2 = (year2/4) - (year2/100) + (year2/400);
//cout<<ans1<<" "<<ans2<<endl;
                    pf("Case %d: %lld\n",tt,ans2-ans1);
            }

    return 0;
}