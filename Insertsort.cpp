#include<iostream>
using namespace std;
int  sizea=11;
//插入排序
void insertsort(int a[],int n)
{
    for(int j=1;j<n;j++)
    {
        int key=a[j];
        int i=j-1;
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
    cout<<"InsertSort:";
      for(int m=0;m<10;m++)
        {
        cout<<a[m]<<" ";
        }
    cout<<endl;
}

//冒泡排序
void BubbleSort(int a[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
              temp=a[i];
              a[i]=a[j];
              a[j]=temp;
            }
        }
    }
    cout<<"BubbleSort:";
     for(int m=0;m<10;m++)
    {
        cout<<a[m]<<" ";
    }
    cout<<endl;
}

//归并
void Merges(int a[],int low,int mid,int high)
{
    int b[10];
    int i,j,m;
    for(int i=low;i<=high;i++)
    {
        b[i]=a[i];
    }
    for(i=low,j=mid+1,m=i;i<=mid&&j<=high;m++)
    {
        if(b[i]<=b[j])
        {
            a[m]=b[i++];
        }
        else
        {
            a[m]=a[j++];
        }
    }
    while(i<=mid)
    {
        a[m++]=b[i++];
    }
    while(j<=high)
    {
        a[m++]=b[j++];
    }
}

//归并排序
void MergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merges(a,low,mid,high);
    }
}

//最大堆调整
void MaxHeapify(int a[],int i)
{
    int largest;
    int l=2*i;
    int r=2*i+1;
    if(l<sizea&&a[l]>a[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if(r<sizea&&a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        MaxHeapify(a,largest);

    }
}
//建最大堆
void BuildMaxHeap(int a[],int len)
{
    for(int i=len/2;i>0;i--)
    {
        MaxHeapify(a,i);
    }
}
//堆排序
void HeapSort(int a[])
{
    BuildMaxHeap(a,11);
    for(int i=10;i>=2;i--)
    {
        swap(a[1],a[i]);
        sizea--;
        MaxHeapify(a,1);
    }
}

//选择排序
void SelectSort(int a[],int len)
{
    int mins;
    for(int i=0;i<len-1;i++)
    {
        mins=i;
        for(int j=i+1;j<len;j++)
        {
            if(a[j]<a[mins]) mins=j;
        }
        if(mins!=i)
        {
            swap(a[mins],a[i]);
        }
    }
    cout<<"SelectSort:";
    for(int m=0;m<10;m++)
    {
        cout<<a[m]<<" ";
    }
    cout<<endl;
}

//快排划分
int Partitions(int a[],int p,int r)
{
    int q;
    int x=a[p];
    int i=p;
    for(int j=p+1;j<=r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[p],a[i]);
    return i;
}
//快速排序
void quicksort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=Partitions(a,p,r);
        quicksort(a,p,q);
        quicksort(a,q+1,r);
    }
}

//计数排序
void CountingSort(int a[],int len)
{
    int maxnum=0;
    int b[len];
    for(int i=0;i<len;i++)
    {
        if(a[i]>a[maxnum])
        {
            maxnum=i;
        }
    }
    int c[a[maxnum]];
    for(int i=0;i<a[maxnum];i++)
    {
        c[i]=0;

    }
    for(int i=0;i<len;i++)
    {
        c[a[i]-1]++;
    }
    for(int i=1;i<a[maxnum];i++)
    {
        c[i]=c[i-1]+c[i];
    }
    for(int i=0;i<a[maxnum];i++)
    {
        cout<<c[i]<<"";
    }
    for(int i=len-1;i>=0;i--)
    {
        b[c[a[i]-1]-1]=a[i];
        c[a[i]-1]--;
    }
    cout<<"CountingSort:";
    for(int m=0;m<len;m++)
    {
        cout<<b[m]<<" ";
    }
    cout<<endl;
}
int main()
{
    int a[10]={1,2,3,0,212,213,143,152,111,19};
    insertsort(a,10);
    int b[10]={1,2,3,0,212,213,143,152,111,19};
    BubbleSort(b,10);
    int c[10]={1,2,3,0,212,213,143,152,111,19};
    MergeSort(c,0,9);
     cout<<"MergeSort:";
     for(int m=0;m<10;m++)
    {
        cout<<c[m]<<" ";
    }
    cout<<endl;
    int d[11]={0,1,2,3,0,212,213,143,152,111,19};
    HeapSort(d);
    cout<<"HeapSort:";
    for(int m=1;m<11;m++)
    {
        cout<<d[m]<<" ";
    }
    cout<<endl;
    int e[10]={1,2,3,0,212,213,143,152,111,19};
    SelectSort(e,10);
    int f[10]={1,2,3,0,212,213,143,152,111,19};
    quicksort(f,0,9);
    cout<<"QuickSort:";
    for(int m=0;m<10;m++)
    {
        cout<<f[m]<<" ";
    }
    cout<<endl;
    int g[5]={4,1,3,4,3};
    CountingSort(g,5);
    return 0;
}
