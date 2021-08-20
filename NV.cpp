#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#define luongcb 300000 
using namespace std;
class NhanVien
{
protected:
	string hoten;
	double cmnd;
	string phongban;
public:
	NhanVien() {
		hoten = "NULL";
		cmnd = 0;
		phongban = "NULL";
	}
	NhanVien(string ht, double cm, string pb) {
		hoten = ht;
		cmnd = cm;
		phongban = pb;
	}
	NhanVien(const NhanVien &nv) {
		hoten = nv.hoten;
		cmnd = nv.cmnd;
		phongban = nv.phongban;
	}
	~NhanVien() {

	}
	virtual istream& In(istream& in) {
		cin.ignore();
		cout << "\nNhap Ho Ten: ";
		getline(in, hoten);
		cout << "\nCMND: ";
		in >> cmnd;
		cin.ignore();
		cout << "\nPhong ban: ";
		getline(in, phongban);
		return in;
	}
	virtual ostream& Out(ostream& out) {
		out << "\n___________________________________";
		out << "\nHo Ten: " << hoten;
		out << "\nCMND: " << cmnd;
		out << "\nPhong ban: " << phongban;
		return out;
	}
	friend istream& operator >> (istream& in, NhanVien &p) {
		p.In(in);
		return in;
	}
	friend ostream& operator << (ostream& out, NhanVien &p) {
		p.Out(out);
		return out;
	}
	virtual double tinhluong() = 0;
};
class NVBienChe :public NhanVien
{
private:
	int bacluong;
	double phucap;
public:
	istream& In(istream& in)
	{
		NhanVien::In(in);
		cout << "\nBac luong: ";
		in >> bacluong;
		cout << "\nPhu cap: ";
		in >> phucap;
		return in;
	}
	ostream& Out(ostream& out)
	{
		NhanVien::Out(out);
		out << "\nBac luong: " << bacluong;
		out << "\nLuong co ban: " << luongcb;
		out << "\nPhu cap: " << phucap;
		out << "\nLuong: " << tinhluong();
		return out;
	}
	friend istream& operator >> (istream& in, NVBienChe &nv) {
		nv.In(in);
		return in;
	}
	friend ostream& operator << (ostream& out, NVBienChe &nv) {
		nv.Out(out);
		return out;
	}
	double tinhluong() {
		return bacluong*luongcb + phucap;
	}
};
class NVHopDong :public NhanVien
{
private:
	int giolam;
	const double luong1h = 10000;
public:
	istream& In(istream& in) {
		NhanVien::In(in);
		cout << "\nNhap gio lam: ";
		in >> giolam;
		return in;
	}
	friend istream& operator >> (istream& in, NVHopDong &nv) {
		nv.In(in);
		return in;
	}
	ostream& Out(ostream& out) {
		NhanVien::Out(out);
		out << "\nGio lam: " << giolam;
		out << "\nLuong: " << tinhluong();
		return out;
	}
	friend ostream& operator << (ostream& out, NVHopDong &nv) {
		nv.Out(out);
		return out;
	}
	double tinhluong() {
		return giolam*luong1h;
	}
};
int main()
{
	int n1, n2;
	double luong1 = 0, luong2 = 0;
	// NHAP NHAN VIEN
	cout << "\nNhap so luong nhan vien Bien che: ";
	cin >> n1;
	NhanVien **s1 = new NhanVien*[n1];
	for (int i = 0; i < n1; i++) {
		s1[i] = new NVBienChe;
		cout << "\n-----Nhap nhan vien thu " << i + 1 << "-----";
		cin >> *s1[i];
		luong1 += s1[i]->tinhluong();
	}
	cout << "\nNhap so luong nhan vien Hop dong: ";
	cin >> n2;
	NhanVien **s2 = new NhanVien*[n2];
	for (int i = 0; i < n2; i++) {
		s2[i] = new NVHopDong;
		cout << "\n-----Nhap nhan vien thu " << i + 1 << "-----";
		cin >> *s2[i];
		luong2 += s2[i]->tinhluong();
	}
	// XUAT NHAN VIEN
	cout << "\n_______Nhan vien Bien che________";
	for (int i = 0; i < n1; i++) {
		cout << "\n-----Nhap nhan vien thu " << i + 1 << "-----";
		cout << *s1[i];
	}
	cout << "\n\n<<<<<<<<<<<<< Tong luong: " << luong1 << " >>>>>>>>>>>>>>>>>";
	ofstream ha2;
	ha2.open ("LuongThapNhat.txt", ios::out);
	// NHAN VIEN LUONG THAP NHAT
	cout << "\nNhan vien co luong thap nhat: ";
	ha2 << "\nNhan vien BIEN CHE co luong thap nhat: ";
	double min = s1[0]->tinhluong();
	for (int i = 0; i < n1; i++) {
		if (s1[i]->tinhluong() < min)
			min = s1[i]->tinhluong();
	}
	for (int i = 0; i < n1; i++) {
		if (s1[i]->tinhluong() == min)
		{
			cout << *s1[i];
			ha2 << *s1[i];
		}
	}
	// NHAN VIEN HOP DONG
	cout << "\n_______Nhan vien Hop dong________";
	for (int i = 0; i < n2; i++) {
		cout << "\n-----Nhap nhan vien thu " << i + 1 << "-----";
		cout << *s2[i];
	}
	cout << "\n\n<<<<<<<<<<<<< Tong luong: " << luong2 << " >>>>>>>>>>>>>>>>>";
	// NHAN VIEN LUONG THAP NHAT
	cout << "\nNhan vien co luong thap nhat: ";
	ha2 << "\nNhan vien HOP DONG co luong thap nhat: ";
	min = s2[0]->tinhluong();
	for (int i = 0; i < n2; i++) {
		if (s2[i]->tinhluong() < min)
			min = s2[i]->tinhluong();
	}
	for (int i = 0; i < n2; i++) {
		if (s2[i]->tinhluong() == min)
		{
			cout << *s2[i];
			ha2 << *s2[i];
		}
	}
	// CAU 5 THONG KE
	double max = s2[0]->tinhluong();
	for (int i = 0; i < n2; i++) {
		if (s2[i]->tinhluong() < max)
			max = s2[i]->tinhluong();
	}
	int dem = 0;
	for (int i = 0; i < n1; i++) {
		if (s1[i]->tinhluong() > max|| s1[i]->tinhluong() == max)
			dem++;
	}
	cout << "\nCo " << dem << " NV theo bien che luong cao hon NV theo hop dong" << endl;
	ha2 << "\nCo " << dem << " NV theo bien che luong cao hon NV theo hop dong" << endl;
	ha2.close();
	// XUAT FILE
	ofstream ha;
	ha.open("hadethuong.txt", ios::out);
	for (int i = 0; i < n1; i++) {
		ha << "\n-----Nhap nhan vien thu " << i + 1 << "-----";
		ha << *s1[i];
	}
	for (int i = 0; i < n2; i++) {
		ha << "\n-----Nhap nhan vien thu " << i + 1 << "-----";
		ha << *s2[i];
	}
	ha.close();
	for (int i = 0; i < n1; i++) {
		delete s1[i];
	}
	for (int i = 0; i < n2; i++) {
		delete s2[i];
	}
	delete[]s1;
	delete[]s2;
	system("pause");
}