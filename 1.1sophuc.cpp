#include<iostream>
using namespace std;
class complex{
	int a,b,i;
	public :
		complex();
		friend istream&operator >>(istream&nhap,complex &l);
		friend ostream&operator<<(ostream&xuat,complex& l);
		complex operator +(const complex &l);
		complex operator -(const complex &l);
};
complex::complex(){
	a=0;
	b=0;
}
	istream&operator >>(istream&nhap,complex &l){
		cout<<" \n nhap phan thuc :  ";
		nhap>>l.a;
		cout<<"\n nhap phan ao: ";
		nhap>>l.b;
		
		return nhap;
	}
	ostream&operator<<(ostream&xuat,complex& l){
		xuat<<"\n so phuc vua nhap la : "<<l.a<<"+"<<l.b<<"i"<<endl;
		return xuat;
	}
complex complex::operator +(const complex&l){
		complex  kq;
		kq.a=l.a+a;
		kq.b=l.b+b;
		
		return kq;
	}
complex complex::operator -(const complex &l){
	complex tr;
	tr.a=l.a-a;
	tr.b=l.b-b;
	return tr;
}	
	int main (){
		complex l1,l2,l3;
		cout<<" \nnhap so phuc thu nhat : ";
		cin>>l1;
		cout<<" \nnhap so phuc thu 2 : ";
		cin>>l2;
		cout<<"\n so phuc vua nhap la :"<<l1<<"\n"<<l2;
		char t;
		cout<<"\n moi ban nhap phep tinh (+,-): ";
		cin>>t;
		switch(t){
			case '+':
				l3=l1+l2;
				cout<<"\n phep cong : "<<l3<<endl;
				break;
			case '-':
				l3=l1-l2;
				cout<<"\n phep tru : "<<l3<<endl;
				
		}
	}
