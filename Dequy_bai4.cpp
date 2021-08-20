#include<iostream>
#include<string.h>
using namespace std;
char stringkytu( char s[100],char nhapkt[100],int k,int n){
	if(k>1 ){
		if (s[k-1] == nhapkt[n-1]){
			return 0;
		}
		else
			return stringkytu(s,nhapkt, k - 1,n);
	}
}

int main(){
	char s[100],nhapkt[100];
	cout<<"Moi nhap vao 1 chuoi ki tu: ";
	fflush(stdin);
	gets(s);
	cout<<"Chuoi vua nhap la: "<<s;
	cout<<"\nMoi nhap vao 1 ki tu can tim trong chuoi: ";
	fflush(stdin);
	gets(nhapkt);
	if( stringkytu(s,nhapkt,strlen(s),strlen(nhapkt)) ==0 ){
		cout<<"\nCo Ky Tu can Tim";
	}
	else{
		cout<<"\nKhong co ky tu can tim";
	}
}
