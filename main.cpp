#include <iostream>
using namespace std;
void exchange(int *x,int *y)
    {
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}
void exchangeC(char *x,char *y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;

}

int Part(int A[],char B[] , int p, int r)
{
    int x=A[r];
    int i=p-1;
    for(int j = p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i++;
            exchange(&A[i],&A[j]);
            exchangeC(&B[i],&B[j]);



        }
    }
    exchange(&A[i+1],&A[r]);
    exchangeC(&B[i+1],&B[r]);
    return i+1;

}

void Qs(int A[],char B[],int p, int r)
{

    if (p<r)
    {
        int q;
        q=Part(A,B,p,r);
        Qs(A,B,p,q-1);
        Qs(A,B,q+1,r);
    }

}

int main()
{
int A[8]={6,56,3,8,9,3,7,1};
    char B[]={'a','b','c','d','e','f','g','h'};




    Qs(A,B,0,7);

            for (int i=0;i<8;i++) {
                cout<< B[i]<<"=" ;
                cout<<A[i]<<endl;
            }
}
