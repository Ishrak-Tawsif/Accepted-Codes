#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100003
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

int main()
{
    int temp,len,m;
    string s;
    deque<int>dq;

        int tc;

            sf(tc);

                loop1(tt,tc)
                {
                    scanf("%d %d", &len,&m);
                    dq.clear();
                    pf("Case %d:\n",tt);
                    loop(i,m)
                    {
                        cin>> s;

                            if(s == "pushLeft")
                            {

                                sf(temp);

                                if(dq.size() == len)
                                {
                                    pf("The queue is full\n");
                                }
                                else
                                {
                                    dq.push_front(temp);
                                    pf("Pushed in left: %d\n",temp);
                                }
                            }
                            else if(s == "pushRight")
                            {

                                sf(temp);

                                if(dq.size() == len)
                                {
                                    pf("The queue is full\n");
                                }
                                else
                                {
                                    dq.push_back(temp);
                                    pf("Pushed in right: %d\n",temp);
                                }
                            }
                            else if(s == "popLeft")
                            {
                                if(dq.empty())
                                {
                                    pf("The queue is empty\n");
                                }
                                else
                                {
                                    int tt=dq.front();
                                    dq.pop_front();
                                    pf("Popped from left: %d\n",tt);
                                }
                            }
                            else
                            {
                                if(dq.empty())
                                {
                                    pf("The queue is empty\n");
                                }
                                else
                                {
                                    int tt=dq.back();
                                    dq.pop_back();
                                    pf("Popped from right: %d\n",tt);
                                }
                            }
                    }
                }
    return 0;
}