#include<bits/stdc++.h>
using namespace std;

int arr[] = {5, 25, 125, 625, 3125, 15625, 78125,390625};
int arr2[] = {2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};

int calc_func(int N, int x)
{
    int counter = 0;
    while(N % x == 0)
    {
        counter++;
        N = N / x;
    }
    return counter;
}

int main(){

    int testcase,n,r,p,q,nn,rr,nr,nrnr;

        scanf("%d", &testcase);

            for(int t=1; t<=testcase; t++){
                scanf("%d %d %d %d", &n, &r, &p, &q);

                    nn=rr=nrnr=0;
                    nr = n-r;

                    for(int i=0; i<8; i++){
                        if(n>=arr[i]) nn += n/arr[i];
                        if(r>=arr[i]) rr += r/arr[i];
                        if(nr>=arr[i]) nrnr += nr/arr[i];
                    }//cout << nn << " " << rr << " " << nrnr << endl;
                    int no_5 = nn - (rr+nrnr);//cout << no_5 << endl;

                    nn=rr=nrnr=0;
                    for(int i=0; i<19; i++){
                        if(n>=arr2[i]) nn += n/arr2[i];
                        if(r>=arr2[i]) rr += r/arr2[i];
                        if(nr>=arr2[i]) nrnr += nr/arr2[i];
                    }//cout << nn << " " << rr << " " << nrnr << endl;
                    int no_2 = nn - (rr+nrnr);//cout << no_2 << endl;

                    int ncr_zero = nn - (rr+nrnr);
                        int pq_two = calc_func(p,2)*q;
                        no_2 += pq_two;
                        int pq_five = calc_func(p,5)*q;
                        no_5 += pq_five;//cout << no_2  << " " << no_5 << endl;
                        //int pq_zero = min(pq_five,pq_two); pq_zero *= q;
                        //cout << pq_two << " " << pq_five << " " << pq_zero << endl;
                        printf("Case %d: %d\n", t, min(no_2, no_5));
            }
return 0;
}