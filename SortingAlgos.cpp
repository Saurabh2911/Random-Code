#include<bits/stdc++.h>
using namespace std;


// Best case Time complexity : Ω(n)	
// Average case Time complexity : θ(n^2)	
// Worst case Time complexity : O(n^2) 
// Space complexity : O(1)
void BubbleSort(int a[],int n)
{
	for (int i = 0; i <n-1; ++i)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
}

// Best case Time complexity : Ω(n^2)
// Average case Time complexity : θ(n^2)	
// Worst case Time complexity : O(n^2) 
// Space complexity : O(1)
void SelectionSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int index=i;
		for(int j=i+1;j<n;j++)
		{
			if (a[j]<a[index])
			{
				index=j;
			}	
		}
		swap(a[i],a[index]);
	}
}

// Best case Time complexity : Ω(n)	
// Average case Time complexity : θ(n^2)	
// Worst case Time complexity : O(n^2) 
// Space complexity : O(1)
void InsertionSort(int a[],int n)
{
	for (int i = 1; i <n; ++i)
	{
		int current = a[i];
		int j=i-1;
		while(j>=0 && current < a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=current;
	}
}

// Best case Time complexity : Ω(n log(n))
// Average case Time complexity : θ(n log(n))	
// Worst case Time complexity : O(n log(n))
// Space complexity : O(n)
void Merge(int a[],int s,int mid,int e)
{
	int n=e-s+1;
	int merged[n];
	int idx1=s;
	int idx2=mid+1;
	int i=0;

	// for(int j=0;j<n;j++)
	// {
	// 	cout << a[j] <<" "; 
	// }
	// cout << endl;

	//O(n)
	while(idx1<=mid && idx2<=e)
	{
		if(a[idx1]<=a[idx2])
		{
			merged[i++]=a[idx1++];
		}
		else
		{
			merged[i++]=a[idx2++];
		}
	}
	while(idx1<=mid)
	{
		merged[i++]=a[idx1++];
	}
	while(idx2<=e)
	{
		merged[i++]=a[idx2++];
	}
	for(int j=0,k=s;j<n;j++,k++)
	{
		a[k]=merged[j];
	}
}

void MergeSort(int a[],int s,int e)
{
	if(s>=e)
	{
		return;
	}

	//O(logn)
	int mid=(s+e)/2;
	MergeSort(a,s,mid);
	MergeSort(a,mid+1,e);
	Merge(a,s,mid,e);
}

// Best case Time complexity : Ω(n log(n))
// Average case Time complexity : θ(n log(n))	
// worst case occurs, when pivot is always the smallest or the largest element
// Worst case Time complexity : O(n^2)  
// Space complexity : O(log(n))

int partition(int a[],int l,int h)
{
	int pivot=a[h];
	int i=l-1; //track to how many element less then pivot comes in my array
	for(int j=l;j<h;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	i++;
	swap(a[i],a[h]);
	return i; //pivot index
}

void QuickSort(int a[],int l,int h)
{
	if(h>l)
	{
		int pidx = partition(a,l,h);
		QuickSort(a,l,pidx-1);
		QuickSort(a,pidx+1,h);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE


	// int a[]={6,3,9,5,2,8};
	// int n=sizeof(a)/sizeof(int);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i <n; ++i)
	{
		cin >> a[i];
	}
	//BubbleSort(a,n);
	//SelectionSort(a,n);
	//InsertionSort(a,n);
	//MergeSort(a,0,n-1);
	QuickSort(a,0,n-1);
	for (int i = 0; i <n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}