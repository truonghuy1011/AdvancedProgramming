#include<iostream>
#define Max 100
using namespace std;
int n;
void Swap(int *x, int *y)
{
  int tg;
  tg = *x;
  *x = *y;
  *y = tg;
}
int recursive (int a[Max],int b[Max], int k){
  if (k==1){
    for (int i=0;i<n;i++)
		b[i]=a[i];      		
}
  else
    for(int i=k-1;i>=0;i--){
        Swap(&a[k-1],&a[i]);
        recursive(a,b,k-1);
        Swap(&a[i],&a[k-1]);
    }
}
int main(){
	int a[Max],b[Max];
	cout<<"Nhap vao 1 chuoi co: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Chuoi vua nhap la: ";
	for(int i=0;i<n;i++){
		cout<<"\t"<<a[i];
	}
	recursive(a,b,n);
	cout<<"\nChuoi vua hoan vi la: ";
	for(int i=0;i<n;i++){
		cout<<"\t"<<b[i];
	}
	system("pause");
	return 0;
}
