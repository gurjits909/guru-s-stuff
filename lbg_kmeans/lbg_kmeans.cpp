
#include "stdafx.h"


#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include <vector>
#include<stdlib.h>
#include<cmath>
using namespace std;
double long work[125][12],split_arr[20][12];
int belong[125];
long double w[]={1,3,7,13,19,22,25,33,42,50,56,61};
void fun(string temp)
{
    long double arr[5][12];
    ifstream in;
    in.open(temp.c_str(),ios::in);
    ofstream myfile;
    myfile.open("ci's.txt",std::fstream::app);
    int i=0,j=0;
    while(!in.eof())
    {
        long double number;
        in>>number;
        arr[i][j]=number;
        j++;
        if(j==12)
        {
            i++;
            j=0;
        }
     }
     for(int i=0;i<5;i++)
     {
         for(int j=0;j<12;j++)
         {
             arr[i][j]=w[j]*arr[i][j];
             myfile<<arr[i][j];
             myfile<<" ";
         }
         myfile<<"\n";
     }

  //   getc(stdin);
}
void k_means(int count)
{
    long double *sum_arr;
    sum_arr = (long double*)malloc((count+1)*sizeof(long double));
    int *count_arr;
    count_arr=(int*)malloc((count+1)*sizeof(int));

    for(int i =1;i<=count;i++)
    {
        sum_arr[i]=0.0;
        count_arr[i]=0;
    }
    long double d_new=0.0,d=0.0;
    while(1)
    {
        printf("inside\n");
        d=d_new;
        long double distortion=0.0;
        for(int i=0;i<125;i++)
        {
            long double sum=0.0;
            long double min=9999999.0;
            for(int j=1;j<=count;j++)
            {
                for(int k=0;k<12;k++)
                {
                    sum = sum + ((split_arr[j][k]-work[i][k])*(split_arr[j][k]-work[i][k]));
                }
                if(sum<min)
                {
                    min = sum;
                    belong[i]=j;
                }
            }
            distortion=distortion+min;
        }
        d_new=distortion/(count);
        cout<<d_new-d<<"\n";
        getc(stdin);
        if((d_new-d)==0.0)
            break;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<125;j++)
            {
                sum_arr[belong[j]]=sum_arr[belong[j]]+work[j][i];
                count_arr[belong[j]]++;
            }
            for(int k=1;k<=count;k++)
            {
                split_arr[k][i]=sum_arr[k]/(count_arr[k]);
            }
        }

    }
}
void lbg()
{
    int count = 1;
    while((count*2)<=8)
    {
        int itr=count;
        //splitting module
        while(itr>=1)
        {
           for(int i=0;i<12;i++)
           {
               split_arr[itr*2][i]=split_arr[itr][i]-0.03;
           }
           for(int i=0;i<12;i++)
           {
               split_arr[(itr*2)-1][i]=split_arr[itr][i]+0.03;
           }
           itr--;
        }
        //splitting_done
        count=count*2;
        k_means(count);
       cout<<"for "<<count<<" done\n";;
       /*for(int i=1;i<=count;i++)
        {
            for(int j=0;j<12;j++)
            {
                cout<<split_arr[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n\n\n";*/
    }
}
int main()
{
     ifstream in;
    in.open("universe.txt",ios::in);
    double long centroid[12],ep_vector_disc[12],em_vecotr_disc[12];
    int i=0,j=0;
    while(!in.eof())
    {
        long double temp;
        in>>temp;
        work[i][j]=temp;
        j++;
        if(j==12)
        {
            j=0;
            i++;
        }
     }
     cout<<"avg = ";
     for(int i=0;i<12;i++)
     {
         long double sum=0.0;
         for(int j=0;j<125;j++)
         {
             sum=sum+work[j][i];
         }
         split_arr[1][i]=sum/(125);
         cout<<split_arr[1][i]<<" ";
         //ep_vector_disc[i]=vector_disc[i]+0.03;
         //em_vecotr_disc[i]=vector_disc[i]-0.03;
     }
     cout<<"\n";
     lbg();
    return 0;
}
