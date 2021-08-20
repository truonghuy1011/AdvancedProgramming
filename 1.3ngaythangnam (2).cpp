#include<iostream.h>
using namespace std;
class mydate{
	int day ,month ,year;
	public:
		mydate();
		friend istream&operator>>(istream&is,mydate &m);
		friend ostream&operator<<(ostream&os,mydate &m);
		int operator >=(const mydate &m);
	
};
		mydate::mydate(){
			day=00;
			month=00;
			year=0000;	
		}
	 istream&operator>>(istream&is,mydate &m){
	 	again:
	 		
		cout<<"\n Input day: ";
	 	is>>m.day;
	 	cout<<"\n Input month: ";
	 	is>>m.month;
	 	cout<<"\n Input year : ";
	 	is>>m.year;
	 	if(m.day<31&&m.month<12&&m.year<0){
	 		goto again;
		 }
	 	
	 	return is;
	 }
	ostream&operator<<(ostream&os,mydate &m) {
		os<<"\n Output: "<<m.day<<"/"<<m.month<<"/"<<m.year;
		return os;
	}
mydate::operator >=(const mydate &m)
{
	if (year > m.year) return 1;
	if (year == m.year&&month > m.month) return 1;
	if (year == m.year&&month == m.month&&day >= m.day) return 1;
	return 0;
}
int main(){
		mydate M[5], max;
	int i;
	for (i = 0; i < 5; i++)
	{
		cout << "Nhap phan tu thu: " << i + 1 << "\n";
		cin>>M[i];
	}

	max = M[0];
	for (i = 1; i < 5; i++)
		if (M[i] >= max) 
		    max = M[i];
	cout << "Thoi gian lon nhat: "<<max;

	return 0;
}
