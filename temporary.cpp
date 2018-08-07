#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
if(a<=b && a<=c)
return a;
else if(b<=a && b<=c)
return b;
else
return c;
}
int m_binary_search(int arr[],int count,int n)
{
   int begin=0,end=count,mid;
   while(begin < end)
   {
     mid =(end+begin)/2;
     if(arr[mid]==n)
     {
        return mid;
        break;
     }
     else if(arr[mid]>n)
     {
        end=mid-1;
     }
     else
     {
        begin = mid+1;
     }
   }
   return begin;
}
int main()
{
int  arr[10000],count=0,flag=0,n;
for(int i=0;i<=30;i++)
{
    for(int j=i+1;j<=30;j++)
    {
    if(i!=j)
    {
    long long int k ;
    k=pow(2,i)+pow(2,j);
    arr[count]=k;
    count++;
    }
    }
}
sort(arr, arr+count);
/*for(int i=0;i<count;i++)
{
cout<<arr[i]<<" \n";
}*/
int test;
cin>>test;
while(test--)
{
cin>>n;
int index;
index=m_binary_search(arr,count,n);
//cout<<"index="<<index<<"\n";
int a,b,c;
if(index==0)
{
a=arr[index];
b=arr[index];
c=arr[index+1];
}
else if(index==count-1)
{
a=arr[index-1];
b=arr[index];
c=arr[index];
}
else
{
a=arr[index-1];
b=arr[index];
c=arr[index+1];
}
int result ;
result = min(abs(n-a),abs(n-b),abs(n-b));
cout<<result<<"\n";
}
return 0;
}

