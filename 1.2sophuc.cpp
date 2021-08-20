#include<iostream.h>
using namespace std;
class complex{
	int a,b;
	public :
		complex();
		friend istream&operator >>(istream&nhap,complex &l);
		friend ostream&operator<<(ostream&xuat,complex& l);
		complex operator +(const complex &l);
		complex operator =(const complex &l);
};
complex::complex(){
	a=0;
	b=0;
}
complex complex::operator =(const complex &l){
	a=l.a;
	b=l.b;
	
}
	istream&operator >>(istream&nhap,complex &l){
		int n,i;
	

	
	 	cout<<" \n nhap phan thuc :  ";
		nhap>>l.a;
		cout<<"\n nhap phan ao: ";
		nhap>>l.b;
			
	
		
	
		return nhap;
	}
	ostream&operator<<(ostream&xuat,complex& l){
		int n,i;
	
		
		xuat<<"\n so phuc vua nhap la : "<<l.a<<"+"<<l.b<<"i"<<endl;
						
					
		return xuat;
	}
complex complex::operator +(const complex&l){
		complex  kq;
		kq.a=l.a+a;
		kq.b=l.b+b;
		
		return kq;
	}


	int main (){
	
		complex	 a[100],s;
		int i,n;
		cout<<"\n nhap n so phuc :  ";
		cin>>n;
		for (i=1;i<=n;i++){
			cin>>a[i];
			
		}
		for(i=1;i<=n;i++){
			cout<<a[i];
		}
		
			for(i=1;i<=n;i++){
				s=s+a[i];
			}
			cout<<"\n tong tat ca cac so phuc la: "<<s;
	
	
	
				system("color 6");
				system("color 3");
				return 0;
				
		
	}
