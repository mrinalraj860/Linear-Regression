//
//  main.c
//  linear-regression in c
//
//  Created by MRINAL RAJ on 02/01/22.
//

#include <stdio.h>
#include <stdlib.h>
#define double double

const double eata=0.1;
double x[]={1,2,3,4};//training purpose
double y[]={2,4,6,8};//training purpose
const int M=1e+4;
double error[M];

int partition(double *a,int i,int j);

void sort(double *a,double i,double j)//quick sort
{
    if(i<j)
    {
        int pos=partition(a,i,j);
        sort(a,i,pos-1);
        sort(a,i+1,j);
    }
}

void swap(double *a,double *b)
{
    double k=*a;
    *a=*b;
    *b=k;
}


int partition(double *a,int i,int j)
{
    int l,u;
    double piv;
    l=i;
    u=j;
    piv=a[i];
    while(l<u)
    {
        while(a[l]<=piv && l<j)
        {
            l++;
        }
        while(a[u]>piv){
            u--;
        }
        if(l<u)
        {
            swap(&a[l],&a[u]);
        }
    }
    swap(&a[i],&a[u]);
    return u;
}


void change(double *a,int  size)
{
    for(int i=0;i<=size;i++)
    {
        if(a[i]<0)
        {
            a[i]=a[i]*-1;
        }
    }
}

int main() {
    double error_local;
    int  counter=0;
    double m=0;
    double c=0;
    for(int i=0;i<12;i++){
        int index=i%4;
        double test=c+m*x[index];
        error_local=y[index]-test;
        c=c+eata*error_local;
        m=m+eata*error_local*x[index];
        error[counter]=error_local;
        printf("%f\t%f\t%f\n",m,c,error_local);
        counter++;
    }
    change(error,counter);
    sort(error,0,counter);
    for(int i=0;i<=counter;i++)
    {
        printf("%lf ", error[i]);
    }
    printf("\n");
    printf("final ans is :");
    printf("%f\t%f\t%f\n",m,c,error[0]);
    printf("enter test case: ");
    double test;
    scanf("%lf", &test);
    double out=c+m*test;
    printf("result is : %f\n", out);
    
}
