// for O(n+k)
//Used for small range from LtoR 
//Exceed memory for large values of the array
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int arr[]={2,2,5,2,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int L=INT_MAX,R=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<L)
        {
            L=arr[i];
        }
        if(arr[i]>R)
        {
            R=arr[i];
        }
        //finding the rightmost and leftmost value
    }
    int k=R-L+1;//determine the size of the frequency array
     vector<int> f(k,0);
    for(int i=0;i<n;i++)
    {
        ++f[arr[i]-L];  
    }
    for(int i=1;i<k;i++)
    {
        f[i]=f[i]+f[i-1];//apply prefix sum int the frequency array
    }
    vector<int> v(n);//take another array which will have sorted value
    for(int i=0;i<n;i++)
    {
     v[f[arr[i]-L]-1]=arr[i];
       //the operation done inside determines the new index for the unsorted array values
     f[arr[i]-L]--;//next we decreament to place the repeating values in front 
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<' ';
    }
}