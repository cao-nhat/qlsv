#include<bits/stdc++.h>
using namespace std;
//class
class sinhvien
{
	public:
		char hoten[20], gioitinh[20];
		char namsinh[20], diachi[30], lop[10];
		string masv;
		float tin1, tin2, tin3, tin4, anh1, anh2, DTB;
		void nhap();
		void hienthi();
};
//ham nhap
void sinhvien::nhap()
{
	cin.ignore();
	cout << "\n Nhap ho ten: "; cin.getline(hoten,20);
	cout << "\n Nhap gioi tinh: "; cin.getline(gioitinh,20);
	cout << "\n Nhap nam sinh: "; cin.getline(namsinh,20);
	cout << "\n Nhap dia chi: "; cin.getline(diachi,30);
	cout << "\n Nhap ma sinh vien: "; getline(cin,masv);
	cout << "\n Nhap lop: "; cin.getline(lop,10);
	cout << "\n Nhap diem tin 1: "; cin >> tin1;
	cout << "\n Nhap diem tin 2: "; cin >> tin2;
	cout << "\n Nhap diem tin 3: "; cin >> tin3;
	cout << "\n Nhap diem tin 4: "; cin >> tin4;
	cout << "\n Nhap diem anh 1: "; cin >> anh1;
	cout << "\n Nhap diem anh 2: "; cin >> anh2;
	cout << endl;
}
//ham xuat
void sinhvien::hienthi()
{
	DTB = (tin1 + tin2 + tin3 + tin4 + anh1 + anh2)/6;
	cout << left << setw(20) << hoten << setw(10) << gioitinh << setw(10) << namsinh << setw(20) << diachi << setw(15) << masv << setw(10) << lop << setw(8)  << tin1 << setw(8) 
	<< tin2 << setw(8)  << tin3 << setw(8)  << tin4 << setw(8)  << anh1 << setw(8)  << anh2 << setw(8)  << DTB << setw(15) << setprecision(2) << DTB << endl;
	if (DTB >=8) cout << "\nXep loai gioi";
	else if (DTB >=7) cout << "\nXep loai kha";
	else if (DTB >=5) cout << "\nXep loai trung binh";
	else if (DTB < 5) cout << "\nXep loai yeu";
}
//class
class quanlysv: public sinhvien
{
	public:
		sinhvien sv[100];
		int n;
		void nhap();
		void hienthi();
		void xeploaiHL();
		void dssvDTBtd();
		void dssvDTBgd();
		void timsvDTBMAX();
		void timkiemsv();	
};
//ham nhap dssv
void quanlysv::nhap()
{
	cout << "Nhap so luong sinh vien: "; cin >> n;
	for(int i = 0; i < n; i++){
		cout << "sinh vien thu " << i+1 << ":";
		sv[i].nhap();
	}
}
//ham xuat dssv
void quanlysv::hienthi()
{
	cout << left << setw(20) << "Ho ten"<< setw(10) << "Gioi tinh"<< setw(10) << "Nam sinh" << setw(20) << "Dia chi"<< setw(15) << "Ma sinh vien" << setw(10) << "Lop" << setw(8)  << "Tin1" << setw(8)
		 << "Tin2" << setw(8)  << "Tin3" << setw(8)  << "Tin4" << setw(8)  << "Anh1" << setw(8)  << "Anh2" << setw(8)  << "DTB" << setw(15) << "DTB Lam Tron";
	for(int i = 0; i < n; i++){
		cout << endl;
		sv[i].hienthi();
	}
}
//xep loai sinh vien
void quanlysv::xeploaiHL()
{
	cout << "\n Sinh vien xep loai gioi:\n";
	for(int i = 0; i < n; i++){
		if (sv[i].DTB >= 8){
			sv[i].hienthi();
		}
	}
}
//sap xep sv DTB tang 
void quanlysv::dssvDTBtd()
{
	sinhvien tg;
	cout << "\n Danh sach sinh vien co diem trung binh tang dan:\n";
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(sv[i].DTB > sv[j].DTB){
				tg = sv[i];
				sv[i] = sv[j];
				sv[j] = tg;
			}
		}
	}
	for(int i = 0; i < n; i++){
		sv[i].hienthi();
	}
}
//sap xep DTB giam
void quanlysv::dssvDTBgd()
{
	sinhvien tg;
	cout << "\n Danh sach sinh vien co diem trung binh giam dan:\n";
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(sv[i].DTB < sv[j].DTB){
				tg = sv[i];
				sv[i] = sv[j];
				sv[j] = tg;
			}
		}
	}
	for(int i = 0; i < n; i++){
		sv[i].hienthi();
	}
}
//sv DTB lon nhat
void quanlysv::timsvDTBMAX()
{
	cout << "\n Sinh vien co diem trung binh lon nhat:\n";
	float max = 0;
	for(int i = 0; i < n; i++){
		if(sv[i].DTB >= max) max = sv[i].DTB;
	}
	for(int i = 0; i < n; i++){
		if(sv[i].DTB == max) {
			sv[i].hienthi();
		}
	}
}
//tim kiem theo ma sinh vien
void quanlysv::timkiemsv()
{
	string msv;
	cin.ignore();
	cout << "Nhap ma sinh vien can tim:"; getline(cin,msv);
	int count = 0;
	for(int i = 0; i < n; i++){
		if(sv[i].masv == msv){
			sv[i].hienthi();
			count++;
		}
	}
	if(count = 0) cout << "Khong co sinh vien voi ma so can tim";
	
}
int main(){
	sinhvien a;
	quanlysv b;
	int luachon, n;
	cout <<"Chao mung ban den voi chuong trinh quan ly sinh vien";
	cout << "Nhap so lon hon 0 de bat dau:"; cin >> n;
	while(n > 0)
	{
		cout << "\n==============MENU==============";
		cout << "\n===Chuong trinh quan ly sinh vien===";
		cout << "\n Vui long chon yeu cau:";
		cout << "\n 1. Nhap thong tin sinh vien.";
		cout << "\n 2. Hien thi thong tin danh sach sinh vien.";
		cout << "\n 3. Xep loai sinh vien hoc luc gioi.";
		cout << "\n 4. Sap xep sinh vien theo diem trung binh tang dan.";
		cout << "\n 5. Sap xep sinh vien theo diem trung binh giam dan.";
		cout << "\n 6. Tim sinh vien co diem trung binh cao nhat.";
		cout << "\n 7. Tim sinh vien theo ma so sinh vien.";
		cout << "\n 8. Ket thuc chuong trinh.";
		cout << "\n Nhap lua chon cua ban:"; cin >> luachon;
		switch(luachon){
			case 1:
				b.nhap();
				break;
			case 2:
				b.hienthi();
				break;
			case 3:
				b.xeploaiHL();
				break;
			case 4:
				b.dssvDTBtd();
				break;
			case 5:
				b.dssvDTBgd();
				break;
			case 6:
				b.timsvDTBMAX();
				break;
			case 7:
				b.timkiemsv();
				break;
			case 8:
				return 0;
			default:
				cout << "\n Nhap sai lua chon. Vui long nhap lai.";
		} 
	}
	
	return 0;
}

