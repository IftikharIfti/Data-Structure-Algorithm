#include<iostream>
using namespace std;
void init(int *arr,int *seg_tree,int node,int b,int e)
{
   if(b==e){
        seg_tree[node] = arr[b];
        return;
    } 
    int left = 2*node;
    int right = left +1;
    int mid = (b+e)/2;
    init(arr, seg_tree , left , b , mid);
    init(arr, seg_tree , right , mid+1 ,e);
    seg_tree[node] = min(seg_tree[left],seg_tree[right]);
   //seg_tree[node] = seg_tree[left]+seg_tree[right]; //for sum
}
int query(int * arr , int * seg_tree ,int node ,  int b , int e , int i , int j){
    if(b >= i && e<= j){
        return seg_tree[node];
    }
    if( b > j || e < i){
        //return 0 ;// in case of sum
        return INT_MAX;
    }
    int left = 2 * node;
    int right = 2*node + 1;
    int mid = (b+e)/2;

    int q1 = query(arr, seg_tree , left , b,mid,i,j);
    int q2 = query(arr, seg_tree , right , mid+1,e,i,j);

    return min(q1,q2);
    //return q1+q2 //for sum
}
int seg_tree_update(int * arr , int * seg_tree ,int val ,int ind ,int node ,  int b , int e ){
    if(b==e){
        if(b == ind ){
            seg_tree[node] = val;
            arr[ind] = val;
            return val;
        } 
        
        return arr[b];
    } 
    int left = 2*node;
    int right = left +1;
    int mid = (b+e)/2;
    int l =seg_tree_update(arr, seg_tree , val, ind ,left , b , mid);
    int r = seg_tree_update(arr, seg_tree , val ,ind ,right  , mid+1 ,e);
    seg_tree[node] = min(l,r) ;
    //seg_tree[node]=l+r;//sum
    return seg_tree[node];
}
void lazy_propagation_update(int *arr,int *seg_tree,int node,int b,int e,int i, int j, int x)
{
    if(lazy_tree[node]!=0)
    {
        seg_tree[node]+=lazy_tree[node];
        if(b!=e)
        {
            lazy_tree[node*2]+=lazy_tree[node];
            lazy_tree[node*2+1]+=lazy_tree[node];
        }
        lazy_tree[node]=0;
    }
    if(b>j||e<i) return;
    if(b>=i&&e<=j)
    {
        seg_tree[node]+=x;
        if(b!=e)
        {
            lazy_tree[node*2]+=x;
            lazy_tree[node*2+1]+=x;
        }
        return;
    }
    int left = 2*node;
    int right = left +1;
    int mid = (b+e)/2;
    lazy_propagation_update(arr,seg_tree,left,b,mid,i,j,x);
    lazy_propagation_update(arr,seg_tree,right,mid+1,e,i,j,x);

    seg_tree[node]=min(seg_tree[left],seg_tree[right]);
}
int query_lazy(int *arr,int *seg_tree,int node,int b,int e,int i,int j)
{
    if(lazy_tree[node]!=0)
    seg_tree[node]+=lazy_tree[node];

    if(b!=e)
    {
        lazy_tree[node*2]+=lazy_tree[node];
        lazy_tree[node*2+1]+=lazy_tree[node];
    }
    lazy_tree[node]=0;
     if(b >= i && e<= j){
        return seg_tree[node];
    }
    if( b > j || e < i){
        return INT_MAX;
    }
    int left = 2 * node;
    int right = 2*node + 1;
    int mid = (b+e)/2;

    int q1 = query_lazy(arr, seg_tree , left , b,mid,i,j);
    int q2 = query_lazy(arr, seg_tree , right , mid+1,e,i,j);
    //return q1+q2 // for sum
    return min(q1,q2);
}
