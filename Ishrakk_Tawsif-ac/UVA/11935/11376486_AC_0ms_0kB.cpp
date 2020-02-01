 #include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007
#define endval                  1e-9
vector <string> inp;
string yo[11],str;

bool check(double val)
{
    double ans = 0.0,curans = 0.0,cost;
    int leak = 0,curdis = 0,consum;

    for(int i=0; i<inp.size(); i++)
    {
        string temp = inp[i];
        stringstream ss (inp[i]);

        if(temp.find("consumption") != string :: npos)
        {//out(1);
            int n1,n2;
            ss>> n1>> yo[1]>> yo[2]>> n2;
            curans += (n1-curdis) * (cost+(leak*1.0));
            curdis = n1;
            cost = (n2*1.0)/100.0;
        }
        else if(temp.find("Leak") != string :: npos)
        {//out(2);
            int n1;
            ss>> n1;
            curans += (n1-curdis) * (cost+(leak*1.0));
            leak++;
            curdis = n1;
        }
        else if(temp.find("Mechanic") != string :: npos)
        {
            int n1;
            ss>> n1;
            curans += (n1-curdis) * (cost+(leak*1.0));
            leak = 0;
            curdis = n1;
        }
        else if(temp.find("Gas") != string :: npos)
        {//out(3);
            int n1;
            ss>> n1;
            curans += (n1-curdis) * (cost+(leak*1.0));
            curdis = n1;
            ans = max(ans,curans);
            curans = 0;
        }
        else if(temp.find("Goal") != string :: npos)
        {
            int n1;
            ss>> n1;
            curans += (n1-curdis) * (cost+(leak*1.0));
            ans = max(ans,curans);
            break;
        }
    }//pf("%.3f %.3f ||| \n", ans,val);
    return ans<=val;
}

int main()
{//WRITE("in.txt");
    //string str;

    while(getline(cin,str))
    {
        if(str == "0 Fuel consumption 0") break;
//cout<<str<<endl;
        inp.pb(str);//cout<<inp[0]<<endl;

        double st = 0.0,en = 1000000.0,mid,res=0.0;
        int i=0;
        if(str.find("Goal") != string :: npos)
        {
            while(fabs(st-en)>=endval)
            {
                 mid = (st+en)/2.0;//cout<<st<<" "<<en<<endl;
                 if(check(mid))
                 {
                     res = mid;
                     en = mid;
                 }
                 else st = mid;
                 i++;
                 //if(i == 200) break;
            }
            pf("%.3f\n", res);
            inp.clear();
        }
    }

    return 0;
}