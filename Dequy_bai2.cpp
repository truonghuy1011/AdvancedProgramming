#include<iostream>
using namespace std;
class USCLN{
	public:
		int number;
		friend istream &operator>>(istream &, USCLN &);
		friend ostream &operator<<(ostream &, USCLN &);
		float recursive(int &, int &);
};

istream &operator>>(istream &input, USCLN &Num){
	input>>Num.number;
	return input;
}

ostream &operator<<(ostream &output, USCLN &Num){
	output<<Num.number;
	return output;
}

float USCLN::recursive(int &Num1, int &Num2){
	int temp;
	if (Num1==0 ||Num2==0)
        return Num1+Num2;
	else if(Num1<Num2){
		temp=Num1;
		Num1=Num2;
		Num2=temp;
	}
	return ((temp=Num1 % Num2) ? recursive(Num2,temp) : Num2);
}

int main(){
	USCLN Num1, Num2, Num3;
	cout<<"Moi nhap so thu 1: ";
	cin>>Num1;
	cout<<"Moi nhap so thu 2: ";
	cin>>Num2;cout<<"Hai so vua nhap: "<<Num1<<" & "<<Num2;
	cout<<"\nUoc so chung lon nhat cua 2 so: "<<Num3.recursive(Num1.number,Num2.number);
	system("pause");
	return 0;
}
