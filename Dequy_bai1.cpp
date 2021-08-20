#include<iostream>
#include<cmath>
#define Max 100
using namespace std;
int x,n;
class Polynomial{
	public: 
		int *a;
		~Polynomial();
		friend istream &operator>>(istream &,Polynomial &);
		friend ostream &operator<<(ostream &,Polynomial &);
		float recursive (Polynomial &,int n,int x);
};

Polynomial::~Polynomial(){
	delete(a);
}

istream& operator>>(istream &input, Polynomial &Po){
	Po.a=new int (n);
	for(int i=0;i<=n;i++){
		cout<<"a["<<i+1<<"]: ";
		input>>Po.a[i];
	}
	return input;
}

ostream& operator<<(ostream &output,Polynomial &Po){
	for(int i=n;i>=0;i--){
		if(i>1){
			if(Po.a[i]!=0){
				output<<Po.a[i]<<"X^"<<i;
				if(Po.a[i-1]!=0){
					output<<" + ";
				}
			}
			else if(Po.a[i]==0){
				output<<"";
			}
		}
		else if(i==1){
			if(Po.a[i]!=0){
				output<<Po.a[i]<<"X"<<i;
				if(Po.a[i-1]!=0){
					output<<" + ";
				}
			}
			else if(Po.a[i]==0){
				output<<"";
			}
		}
		else{
			if(Po.a[i]==0){
				output<<" ";
			}
			else{
				output<<"1";
			}
		}
	}
	return output;
}

float Polynomial::recursive(Polynomial &Po,int n,int x){
	if (n == 0)
		return x;
	else
		return recursive(Po,x,n-1) + Po.a[n]*pow(x,n);
}

int main(){
	cout<<"Moi nhap so bac: ";
	cin>>n;
	Polynomial Po1;	
	cout<<"Moi nhap cac he so cua da thuc\n";
	cin>>Po1;
	cout<<Po1;
	cout<<"\nMoi nhap vao x= ";
	cin>>x;
	float kq=Po1.recursive(Po1,n,x);
	cout<<"\nKet qua la: "<<kq;
	system("pause");
	return 0;
}

