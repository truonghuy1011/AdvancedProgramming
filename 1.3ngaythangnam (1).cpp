#include<iostream>
using namespace std;
class mydate{
	int ngay ,thang ,nam;
	public:
		mydate();
		friend istream&operator>>(istream&is,mydate &m);
		friend ostream&operator<<(ostream&os,mydate &m);
		int operator <=(const mydate&m);
		int operator >(const mydate&m);
};
		mydate::mydate(){
			ngay=00;
			thang=00;
			nam=0000;	
		}
	 istream&operator>>(istream&is,mydate &m){
	 	
	 		
		cout<<"\n nhap ngay: ";
	 	is>>m.ngay;
	 	cout<<"\n nhap thang: ";
	 	is>>m.thang;
	 	cout<<"\n nhap nam : ";
	 	is>>m.nam;
	 	
	 	
	 	return is;
	 }
	ostream&operator<<(ostream&os,mydate &m) {
		os<<"\n ngay thang nam vua nhap la : "<<m.ngay<<"/"<<m.thang<<"/"<<m.nam;
		return os;
	}
	int mydate::operator <=(const mydate&m){
		mydate d;
		if (d.nam<m.nam){
			return 1;
			
		}
		else{
			return 0;
		}
		if(d.nam=m.nam&&d.thang<m.thang){
			return 1;
		}
		else{
			return 0;
		
			
		}
		if(d.nam=m.nam&&(d.thang=m.thang)&&d.ngay<m.ngay){
			return 1;
		}
		else{
			return 0;
		}
		
	}
	int mydate::operator >(const mydate&m){
		mydate d;
		if(d.nam>m.nam&&d.thang>m.thang&&d.ngay){
			return 1;
		}
		else{
			return 0;
		}
	
		
	}
int main(){
	mydate t[100],b[100];
	int n,i,j;
	cout<<"\n nhap n=5 : ";
	cin>>n;
	cout<<"\nhap ngay/thang/nam  ---->   ";
	for(i=1;i<=n;i++){
		cout<<"\n lan thu  "<<i<<":";
			cin>>t[i];
	}
	

	cout<<"\n xuat  ngay/thang/nam  ---->  ";
	for(i=1;i<=n;i++){
		cout<<t[i];
	}
	for(i=1;i<=n;i++){
	
			if(b[i]<=t[i]){
			
			}
	}
		cout<<"\n nho nhat :"<< b[i] ;
	for(i=1;i<=n;i++){
		if (b[i]>t[i]){
			
		}
	}
	cout<<"\n lon nhat : "<<b[i];
	system("color 4 ");
	return 0;
}
