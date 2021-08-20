#include<iostream>
using namespace std;
class complex {
private:
	int thuc, ao;
public:
	complex();
	complex(int x, int y);
	friend istream& operator>>(istream &in, complex &z);
	friend ostream& operator<<(ostream &out, const complex &z);
	complex operator+(const complex &z);
	complex operator-(const complex &z);
	~complex();
};
complex::complex(){
	thuc = 0;
	ao = 0;
}
complex::complex(int x, int y){
	thuc = x;
	ao = y;
}
complex::~complex(){
}
istream& operator >>(istream &in, complex &z) {
	cout << "So thuc : ";
	in >> z.thuc;
	cout << "So ao : ";
	in >> z.ao;
	return in;
}
ostream& operator<<(ostream &out, const complex &z) {
	if (z.ao > 0)
		out << z.thuc << "+" << z.ao << "i" << endl;
	else
		out << z.thuc << z.ao << "i" << endl;
	return out;	
}
complex complex::operator+(const complex &z){
	complex tong;
	tong.thuc = thuc+ z.thuc;
	tong.ao = ao + z.ao;
	return tong;
}
complex complex::operator-(const complex &z){
	complex hieu;
	hieu.thuc = thuc- z.thuc;
	hieu.ao = ao - z.ao;
	return hieu;
}
int main()
{
	complex *z,tong,hieu;
	int n, i ;
	cout <<"so phan tu can nhap :";
	cin >> n;
	z= new complex[n+1];
	for(i=1;i<=n;i++){
		cout << "Nhap so phuc thu " <<i << endl;
		cin >> z[i];
	}
	for(i=1;i<=n;i++){
		tong = tong + z[i];
	}
	cout << "Tong=" << tong;
	hieu = z[1];
	for(i=2;i<=n;i++){
		hieu = hieu - z[i];
	}
	cout << "Hieu=" << hieu;
	system("pause");
}

