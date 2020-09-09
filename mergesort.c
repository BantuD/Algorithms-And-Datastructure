#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 10
void Merge(int arr[],int p,int q,int r);
void MergeSort(int arr[],int p,int r)
{

 if(p<r) 
 {
 int q=(p+r)/2;
 MergeSort(arr,p,q);
 MergeSort(arr,q+1,r);
 Merge(arr,p,q,r);
 }
}
void Merge(int arr[],int p,int q,int r)
{
    int B[SIZE];
    int i,j,k; 
    i=p;j=q+1;k=0;
    while(i<=q && j<=r)
    {
        if(arr[i]<arr[j])
        {
         B[k++]=arr[i++];
        }
        else
        {
            B[k++]=arr[j++];
        }
        
    }
    while(i<=q)
    {
        B[k++]=arr[i++];
    }
    while(j<=r)
    {
        B[k++]=arr[j++];
    }
 for(i=r;i>=p;i--)
 {
     arr[i]=B[--k];
 }
}
void Display_Array(int arr[])
{
    int i;
    printf("\n");
    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",arr[i]);
    }
}
int main()
{
    int arr[SIZE]={1,3,2,6,4,5,9,7,8,0};
    Display_Array(arr);
    printf("\n****Printing sorted Array****\n");
    MergeSort(arr,0,9);
    Display_Array(arr);
return 0;
}