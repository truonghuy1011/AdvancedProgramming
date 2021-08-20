#include<iostream>
using namespace std;
#define Max 100
int n;
int Min(int a[Max],int n){
  	if (n == 0)
		return -1;
	if (n == 1)
		return a[0];
	else{
		if (a[n - 1] < Min(a, n - 1))
			return a[n - 1];
		else
			return Min(a, n - 1);
	}
}

int main(){
  	int a[Max];
  	cout<<"Nhap Vao n: ";
	cin>>n;
  	for(int i=0;i<n;i++){
  		cout<<"Nhap a["<<i+1<<"]";
  		cin>>a[i];
	}
	cout<<"\nDay so vua nhap la: ";
	for(int i=0;i<n;i++){
  		cout<<"\t"<<a[i];
	}
	cout<<"\nSo nho nhat la: "<<Min(a,n);
  	system("pause");
  	return 0;
}
