#include"header.h"

bool log_in(const char* asm1, int& flag) {//nhap thong tin cho giao vu va hoc sinh (done)
	system("cls");
	fstream f;
	f.open(asm1, ios::in);
	int n;
	f >> n;
	f.ignore();
	string* tk = new string[n];
	string* mk = new string[n];
	for (int i = 0; i < n; i++) {
		getline(f, tk[i]);
		getline(f, mk[i]);
	}
	cout << "nhap ten tai khoan: ";
	string x;
	getline(cin, x);
	for (int i = 0; i < n; i++) {
		if (x.compare(tk[i]) == 0) {
			flag = i;
			break;
		}
		if (i == n - 1 && x.compare(tk[i]) != 0) {
			cout << "ten nguoi dung khong ton tai " << endl;
			delete[] tk;
			delete[] mk;
			f.close();
			return false;
		}
	}
	string y;
	for (int i = 1; i <= 3; i++) {
		cout << "nhap mat khau: ";
		getline(cin, y);
		if (y.compare(mk[flag]) == 0) {
			cout << "dang nhap thanh cong" << endl;
			delete[] tk;
			delete[] mk;
			f.close();
			return true;
		}
		cout << "nhap mat khau sai lan " << i << endl;
	}
	cout << "thoat khoi he thong dang nhap" << endl;
	delete[] tk;
	delete[] mk;
	f.close();
	return false;
}

void thongtin_asm(const char* ttcn, giaovu& gv) { // thong tin cua giao vu (done)
	system("cls");
	fstream f;
	f.open(ttcn, ios::in);
	int n;
	f >> n;
	f.ignore();
	char a[40], b[20], c[10], d[15], e[15];

	//lay thong tin tu file
	f.getline(a,40);
	gv.ho = new char[strlen(a) + 1];
	strcpy_s(gv.ho, strlen(a) + 1, a);
	f.getline(b, 20);
	gv.ten = new char[strlen(b) + 1];
	strcpy_s(gv.ten, strlen(b) + 1, b);
	f.getline(c, 10);
	gv.gioitinh = new char[strlen(c) + 1];
	strcpy_s(gv.gioitinh, strlen(c) + 1, c);
	f.getline(d, 15);
	gv.ngaysinh = new char[strlen(d) + 1];
	strcpy_s(gv.ngaysinh, strlen(d) + 1, d);
	f.getline(e, 15);
	gv.cccd = new char[strlen(e) + 1];
	strcpy_s(gv.cccd, strlen(e) + 1, e);

	//xuat thong tin ra man hinh
	cout << setw(40) << left << "ho";
	cout << setw(20) << left << "ten";
	cout << setw(15) << left << "gioi tinh";
	cout << setw(15) << left << "ngay sinh";
	cout << setw(15) << right << "CCCD";
	cout << endl;
	cout << setw(40) << left << gv.ho;
	cout << setw(20) << left << gv.ten;
	cout << setw(15) << left << gv.gioitinh;
	cout << setw(15) << left << gv.ngaysinh;
	cout << setw(15) << right << gv.cccd;
	cout << endl;

	f.close();
}

void doimatkhau(const char* asm1, int flag) {//doi mat khau cho giao vu va sinh vien (done)
	system("cls");
	fstream f;
	f.open(asm1, ios::in);

	int n;
	f >> n;
	f.ignore();
	string* tk = new string[n];
	string* mk = new string[n];
	for (int i = 0; i < n; i++) {
		getline(f, tk[i]);
		getline(f, mk[i]);
	}
	f.close();

	//nhap mat khau cu
	string x;
	do {
		cout << "mat khau cu: ";
		getline(cin, x);
		if (x.compare(mk[flag]) != 0) {
			cout << "mat khau cu sai, nhap lai ";
		}
	} while (x.compare(mk[flag]) != 0);

	//nhap mat khau moi
	string y;
	do {
		cout << "mat khau moi: ";
		getline(cin, y);
		if (y.compare(mk[flag]) == 0) {
			cout << "mat khau moi giong mat khau cu, nhap lai ";
		}
	} while (y.compare(mk[flag]) == 0);

	//xac nhan lai mat khau moi
	system("cls");
	string z;
	do {
		cout << "nhap lai mat khau moi: ";
		getline(cin, z);
		if (z.compare(y) != 0) {
			cout << "khong hop le " << endl;
		}
	} while (z.compare(y) != 0);
	cout << "doi mat khau thanh cong " << endl;
	mk[flag] = y;
	f.open(asm1, ios::out);
	f << n << endl;
	for (int i = 0; i < n; i++) {
		f << tk[i] << endl;
		f << mk[i] << endl;
	}
	f.close();
	delete[] tk;
	delete[] mk;
}

void createSchoolyear(int& year) {//he thong chinh cho giao vu (school year) // 1 (done)
	system("cls");

	//tao nam hoc moi
	cout << "nhap nam hoc moi: ";
	cin >> year;
	fstream sd;
	sd.open("schooldates.txt", ios::out);// ghi nam vao file luu
	sd << year;
	sd << endl;
	sd.close();
}

void createclasses(int year) {// tao lop hoc 2(done)
	system("cls");

	//tao so luong lop hoc trong nam (cho nam nhat)
	int n;
	cout << "so luong lop hoc trong nam " << year << " : ";
	cin >> n;
	cin.ignore();
	string* m = new string[n];
	for (int i = 0; i < n; i++) {
		cout << "ten lop " << i + 1 << " : ";
		getline(cin, m[i]);
		for (int j = 0; j < i; j++) {
			while (m[i].compare(m[j]) == 0) {
				cout << "lop nay co duoc khoi tao, nhap lai: ";
				getline(cin, m[i]);
			}
		}
	}
	cout << "tao lop thanh cong" << endl;
	for (int i = 0; i < n; i++) {
		cout << setw(5) << left << i + 1;
		cout << setw(15) << left << m[i];
		cout << endl;
	}
	fstream f;
	f.open("1stclasses.txt", ios::out);
	f << n << endl;
	for (int i = 0; i < n; i++) {
		f << m[i] << endl;
	}
	f.close();
	delete[] m;
}

void nhapsinhvien(sinhvien& sv) {// AMS nhap thong tin sinh vien de them vao lop, bo sung cho ham "themsinhvienvaolop" (done)
	char a[10], b[40], c[20], d[15], e[15], f[15];
	cout << "ma so sinh vien: ";
	cin.getline(a, 10);
	sv.mssv = new char[strlen(a) + 1];
	strcpy_s(sv.mssv, strlen(a) + 1, a);
	cout << "ho: ";
	cin.getline(b, 40);
	sv.ho = new char[strlen(b) + 1];
	strcpy_s(sv.ho, strlen(b) + 1, b);
	cout << "ten: ";
	cin.getline(c, 20);
	sv.ten = new char[strlen(c) + 1];
	strcpy_s(sv.ten, strlen(c) + 1, c);
	cout << "gioi tinh: ";
	cin.getline(f, 15);
	sv.gioitinh = new char[strlen(f) + 1];
	strcpy_s(sv.gioitinh, strlen(f) + 1, f);
	cout << "ngay sinh: ";
	cin.getline(d, 15);
	sv.ngaysinh = new char[strlen(d) + 1];
	strcpy_s(sv.ngaysinh, strlen(d) + 1, d);
	cout << "can cuoc cong dan: ";
	cin.getline(e, 15);
	sv.cccd = new char[strlen(e) + 1];
	strcpy_s(sv.cccd, strlen(e) + 1, e);
}

void themsvvaolop(const char* claRoster, int year) {//them sinh vien vao lop nua //3 & 4 & 5(done)
	system("cls");
	int x;
	cout << "chon 1 neu muon nhap tung sinh vien vao tung lop, chon 2 neu muon lay san tu file csv: ";
	do {
		cin >> x;
		if (x != 1 && x != 2) {
			cout << "x chi co the bang 1 hoac bang 2: ";
		}
	} while (x != 1 && x != 2);
	if (x == 1) { // done
		createclasses(year);
		fstream f;
		f.open(claRoster, ios::in);//1stclasses.txt
		int n;
		f >> n;
		f.ignore();
		string* m = new string[n];
		for (int i = 0; i < n; i++) {
			getline(f, m[i]);
		}
		for (int i = 0; i < n; i++) {
			system("cls");
			string p = m[i];
			m[i] += ".csv";
			fstream f1;
			f1.open(m[i], ios::out);//tung lop hoc
			f1 << "stt";
			f1 << ",";
			f1 << "mssv";
			f1 << ",";
			f1 << "ho";
			f1 << ",";
			f1 << "ten";
			f1 << ",";
			f1 << "gioi tinh";
			f1 << ",";
			f1 << "ngay sinh";
			f1 << ",";
			f1 << "cccd";
			f1 << endl;
			int nsv;
			cout << "lop " << p << endl;
			cout << "nhap so luong sinh vien: ";
			cin >> nsv;
			sinhvien* sv = new sinhvien[nsv];
			cin.ignore();
			for (int i = 0; i < nsv; i++) {
				cout << "sinh vien " << i + 1 << " : " << endl;
				nhapsinhvien(sv[i]);
				cout << endl;
			}
			//xuat thong tin sinh vien
			for (int i = 0; i < nsv; i++) {
				f1 << i + 1;
				f1 << ",";
				f1 << sv[i].mssv;
				f1 << ",";
				f1 << sv[i].ho;
				f1 << ",";
				f1 << sv[i].ten;
				f1 << ",";
				f1 << sv[i].gioitinh;
				f1 << ",";
				f1 << sv[i].ngaysinh;
				f1 << ",";
				f1 << sv[i].cccd;
				f1 << endl;
			}
			delete[] sv;
		}
		delete[] m;
		f.close();
	}
	else {
		fstream f;
		f.open("1stclasses.txt", ios::out);
		f << 3 << endl;
		string a, b, c;
		a += "22CTT2";
		b += "22CTT3";
		c += "22CTT4";
		f << a << endl;
		f << b << endl;
		f << c << endl;
	}
}

void createSemester(int& semester, int year) {//nhap hoc ky //6 (done)
	system("cls");

	//nhap hoc ky
	cout << "co 3 hoc ky: " << endl;
	cout << "hoc ky 1: vao mua thu " << endl;
	cout << "hoc ky 2: vao mua he " << endl;
	cout << "hoc ky 3: vao mua xuan " << endl;
	cout << "nhap hoc ky can tao: ";
	do {
		cin >> semester;
		if (semester > 3 || semester < 1) {
			cout << "nhap sai, nhap lai hoc ky: ";
		}
	} while (semester > 3 || semester < 1);

	//nhap thoi gian bat dau
	ngaythang x;
	cout << "thoi gian bat dau: " << endl;
	cout << "ngay: ";
	cin >> x.ngay;
	cout << "thang: ";
	cin >> x.thang;
	cout << "nam: ";
	do {
		cin >> x.nam;
		if (x.nam < year) {
			cout << "nhap lai nam, nam bat dau khong duoc be hon nam hoc" << endl;
			cout << "nam: ";
		}
	} while (x.nam < year);

	//nhap thoi gian ket thuc
	ngaythang y;
	cout << "thoi gian ket thuc: " << endl;
	do {
		cout << "ngay: ";
		cin >> y.ngay;
		cout << "thang: ";
		cin >> y.thang;
		cout << "nam: ";
		cin >> y.nam;
		if ((y.nam < x.nam) || (y.nam == x.nam && y.thang < x.thang) || (y.nam == x.nam && y.thang == x.thang && y.ngay <= x.ngay)) {
			cout << "thoi gian ket thuc phai sau thoi gian bat dau " << endl;
			cout << "nhap lai: " << endl;
		}
	} while ((y.nam < x.nam) || (y.nam == x.nam && y.thang < x.thang) || (y.nam == x.nam && y.thang == x.thang && y.ngay <= x.ngay));
	cout << "nhap hoc ky thanh cong" << endl;

	//ghi nam, ky, ngay bat dau, ngay ket thuc file
	fstream f;
	f.open("schooldates.txt", ios::app);
	f << semester;
	f << endl;

	f << x.ngay << endl;
	f << x.thang << endl;
	f << x.nam << endl;

	f << y.ngay << endl;
	f << y.thang << endl;
	f << y.nam << endl;
	return;
}

void add_1_course(course& c, const char* stdcourse, int i) {//them 1 khoa hoc trong ds // 7 bonus 1 (done)
	system("cls");

	//nhap thong tin tung khoa hoc
	cout << "course id: ";
	getline(cin,c.id);
	cout << "course name: ";
	getline(cin, c.name);
	cout << "class name: ";
	getline(cin, c.inclass);
	cout << "teacher name: ";
	getline(cin, c.teacher);
	cout << "number of credits: ";
	getline(cin, c.credits);
	cout << "maximum students: ";
	getline(cin, c.maxst);
	cout << "day of week (mon/tue/wed/thu/fri/sat): ";
	getline(cin, c.dow);
	cout << "session: s1 (7:30), s2 (9:30), s3 (13:30), s4 (15:30): ";
	getline(cin, c.ses);

	//them thong tin tung khoa hoc vao ds cac khoa hoc csv
	fstream f;
	f.open(stdcourse, ios::app);//ds cac khoa hoc csv
	f << c.id;
	f << ",";
	f << c.name;
	f << ",";
	f << c.inclass;
	f << ",";
	f << c.teacher;
	f << ",";
	f << c.credits;
	f << ",";
	f << c.maxst;
	f << ",";
	f << c.dow;
	f << ",";
	f << c.ses;
	f << endl;
	f.close();

	//them thong tin tung khoa hoc vao ds cac khoa hoc txt
	fstream f1;
	f1.open("dscourse.txt", ios::app);
	f1 << i;
	f1 << endl;
	f1 << c.id;
	f1 << endl;
	f1 << c.name;
	f1 << endl;
	f1 << c.inclass;
	f1 << endl;
	f1 << c.teacher;
	f1 << endl;
	f1 << c.credits;
	f1 << endl;
	f1 << c.maxst;
	f1 << endl;
	f1 << c.dow;
	f1 << endl;
	f1 << c.ses;
	f1 << endl;
	f1.close();
}

void add_list_course(int n, course* c) {//cau 7 (done)
	//them so luong ds vao khoa hoc csv
	fstream f1;
	f1.open("dskhoa_hoc.csv", ios::out);
	f1 << n;
	f1 << endl;
	f1.close();

	//them so luong ds vao khoa hoc txt
	fstream f;
	f.open("dscourse.txt", ios::out);
	f << n;
	f << endl;
	f.close();

	//them thong tin tung khoa hoc
	for (int i = 0; i < n; i++) {
		system("cls");
		cout << "khoa hoc thu " << i + 1 << " : ";
		add_1_course(c[i], "dskhoa_hoc.csv", i + 1);
	}
}

void upload_studentincourse() {//upload list student in class csv to course csv //8 (done)
	system("cls");

	//su dung ds khoa hoc de tao course csv
	fstream f;
	f.open("dscourse.txt", ios::in);
	int n;
	f >> n;
	for (int i = 0; i < n; i++) {

		//lay du lieu tung khoa hoc
		int x;
		f >> x;
		f.ignore();
		course y;
		getline(f, y.id);
		getline(f, y.name);
		getline(f, y.inclass);
		getline(f, y.teacher);
		getline(f, y.credits);
		getline(f, y.maxst);
		getline(f, y.dow);
		getline(f, y.ses);

		string temp1;//ten lop chua sinh vien
		temp1 += y.inclass;
		temp1 += ".csv";// ten_lop.csv
		fstream f1;
		f1.open(temp1, ios::in);//mo file lop hoc csv chua sinh vien da tao o cau 3 4 5
		if (f.bad()) {
			cout << "khong ton tai sinh vien trong lop de thiet lap ds course.csv" << endl;
			f1.close();
			continue;
		}
		else {
			string temp2;//ten khoa hoc csv
			temp2 += y.id;
			temp2 += ".csv";// ten_khoa.csv
			fstream f2;
			f2.open(temp2, ios::out);

			//lay thong tin tung sinh vien tu lop sau do dua qua khoa 
			while (!f1.eof()) {
				string a1, a2, a3, a4, a5, a6, a7;
				getline(f1, a1, ',');
				getline(f1, a2, ',');
				getline(f1, a3, ',');
				getline(f1, a4, ',');
				getline(f1, a5, ',');
				getline(f1, a6, ',');
				getline(f1, a7);

				f2 << a1 << ",";
				f2 << a2 << ",";
				f2 << a3 << ",";
				f2 << a4 << ",";
				f2 << a5 << ",";
				f2 << a6 << ",";
				f2 << a7 << endl;
			}

			f2.close();
		}
		f1.close();
	}
	f.close();
}

void view_list_course(const char*courselist) {//xem ds lop hoc da tao va thong tin lop hoc //9 & 17 (done)
	system("cls");

	//mo file txt de lay thong tin luu tru
	fstream f;
	f.open(courselist, ios::in);
	int m;
	f >> m;//so luong khoa hoc
	cout << "list of course: " << endl;
	cout << setw(10) << left << "ma";
	cout << setw(40) << left << "ten khoa hoc";
	cout << setw(20) << left << "ten lop hoc";
	cout << setw(40) << left << "ten giao vien";
	cout << setw(10) << left << "tin chi";
	cout << setw(15) << left << "sinh vien";
	cout << setw(5) << "thu";
	cout << setw(5) << "buoi";
	cout << endl;

	//xuat tung thong tin file txt ve cac khoa hoc den het
	while (!f.eof()) {
		int n;
		course lc;
		if (f >> n) {
			f.ignore();
			getline(f, lc.id);
			getline(f, lc.name);
			getline(f, lc.inclass);
			getline(f, lc.teacher);
			getline(f, lc.credits);
			getline(f, lc.maxst);
			getline(f, lc.dow);
			getline(f, lc.ses);
			cout << setw(10) << left << lc.id;
			cout << setw(40) << left << lc.name;
			cout << setw(20) << left << lc.inclass;
			cout << setw(40) << left << lc.teacher;
			cout << setw(10) << left << lc.credits;
			cout << setw(15) << left << lc.maxst;
			cout << setw(5) << lc.dow;
			cout << setw(5) << lc.ses;
			cout << endl;
		}
		else {
			break;
		}
	}
}

void update_1_course(course& c, const char* stdcourse, int i) {// 10 bonus 1 (done)

	//update thong tin file csv
	fstream f;
	f.open(stdcourse, ios::app);//danh sach cac khoa hoc va thong tin
	f << i;
	f << ",";
	f << c.id;
	f << ",";
	f << c.name;
	f << ",";
	f << c.inclass;
	f << ",";
	f << c.teacher;
	f << ",";
	f << c.credits;
	f << ",";
	f << c.maxst;
	f << ",";
	f << c.dow;
	f << ",";
	f << c.ses;
	f << endl;
	f.close();

	//update thong tin file txt
	fstream f1;
	f1.open("dscourse.txt", ios::app);
	f1 << i;
	f1 << endl;
	f1 << c.id;
	f1 << endl;
	f1 << c.name;
	f1 << endl;
	f1 << c.inclass;
	f1 << endl;
	f1 << c.teacher;
	f1 << endl;
	f1 << c.credits;
	f1 << endl;
	f1 << c.maxst;
	f1 << endl;
	f1 << c.dow;
	f1 << endl;
	f1 << c.ses;
	f1 << endl;
	f1.close();
}

void update_course() {//update a course // 10 (done)
	system("cls");

	while (1) {
		system("cls");
		cout << "nhap lua chon" << endl;
		cout << "1. them khoa hoc" << endl;
		cout << "2. thay doi thong tin khoa hoc" << endl;
		cout << "3. thoat" << endl;
		int y;
		cout << "nhap lua chon: ";
		cin >> y;
		cin.ignore();

		//them khoa hoc
		if (y == 1) {
			system("cls");

			//lay thong tin cac khoa hoc tu dscourse.txt
			int n;
			fstream f;
			f.open("dscourse.txt", ios::in);
			f >> n;//so luong khoa hoc
			course* dc = new course[n];//danh sach khoa hoc  
			for (int i = 0; i < n; i++) {
				int m;
				f >> m;
				f.ignore();
				getline(f, dc[i].id);
				getline(f, dc[i].name);
				getline(f, dc[i].inclass);
				getline(f, dc[i].teacher);
				getline(f, dc[i].credits);
				getline(f, dc[i].maxst);
				getline(f, dc[i].dow);
				getline(f, dc[i].ses);
			}
			f.close();

			//cap nhat thong tin csv
			fstream f1;
			f1.open("dskhoa_hoc.csv", ios::out);
			f1 << n + 1;
			f1 << endl;
			f1.close();

			//cap nhat thong tin txt
			fstream f2;
			f2.open("dscourse.txt", ios::out);
			f2 << n + 1;
			f2 << endl;
			f2.close();

			//cap nhat thong tin tung file
			for (int i = 0; i < n; i++) {
				update_1_course(dc[i], "dskhoa_hoc.csv", i);
			}

			course cc;
			add_1_course(cc, "dskhoa_hoc.csv", n);
			delete[] dc;
		}

		//thay doi thong tin
		else if (y == 2) {
			system("cls");

			//lay thong tin cac khoa hoc tu dscourse.txt
			int n;
			fstream f;
			f.open("dscourse.txt", ios::in);
			f >> n;//so luong khoa hoc
			course* dc = new course[n];//danh sach khoa hoc  
			for (int i = 0; i < n; i++) {
				int m;
				f >> m;
				f.ignore();
				getline(f, dc[i].id);
				getline(f, dc[i].name);
				getline(f, dc[i].inclass);
				getline(f, dc[i].teacher);
				getline(f, dc[i].credits);
				getline(f, dc[i].maxst);
				getline(f, dc[i].dow);
				getline(f, dc[i].ses);
			}
			f.close();

			//nhap ma so lop hoc can update;
			string id;
			cout << "nhap id khoa hoc can thay doi: ";
			getline(cin, id);
			int cu;//course update
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (id.compare(dc[i].id) == 0) {
					cu = i;
					flag = 1;
					break;
				}
			}

			//truong hop khong tim thay id khoa hoc can update
			if (flag == 0) {
				cout << "khong tin thay id khoa hoc can doi ten" << endl;
			}

			//truong hop tim thay id khoa hoc can update
			else {
				while (1) {
					system("cls");
					int x;
					cout << endl << "nhap lua chon can thay doi: " << endl;
					cout << "1. thay doi id khoa hoc" << endl;
					cout << "2. thay doi ten khoa hoc" << endl;
					cout << "3. thay doi ten lop hoc" << endl;
					cout << "4. thay doi giao vien" << endl;
					cout << "5. thay doi so tin chi" << endl;
					cout << "6. thay doi so luong hoc sinh toi da" << endl;
					cout << "7. thay doi ngay trong tuan" << endl;
					cout << "8. thay doi tiet trong ngay" << endl;
					cout << "9. thoat" << endl;
					cout << "nhap lua chon: ";
					cin >> x;
					cin.ignore();
					if (x == 1) {
						system("cls");
						string ch;
						cout << "id khoa hoc moi : ";
						getline(cin, ch);
						dc[cu].id = ch;

						//cap nhat thong tin csv
						fstream f1;
						f1.open("dskhoa_hoc.csv", ios::out);
						f1 << n;
						f1 << endl;
						f1.close();

						//cap nhat thong tin txt
						fstream f;
						f.open("dscourse.txt", ios::out);
						f << n;
						f << endl;
						f.close();

						//cap nhat thong tin tung file
						for (int i = 0; i < n; i++) {
							update_1_course(dc[i], "dskhoa_hoc.csv", i);
						}
					}
					else if (x == 2) {
						system("cls");
						string ch;
						cout << "ten khoa hoc moi: ";
						getline(cin, ch);
						dc[cu].name = ch;

						//cap nhat thong tin csv
						fstream f1;
						f1.open("dskhoa_hoc.csv", ios::out);
						f1 << n;
						f1 << endl;
						f1.close();

						//cap nhat thong tin txt
						fstream f;
						f.open("dscourse.txt", ios::out);
						f << n;
						f << endl;
						f.close();

						//cap nhat thong tin tung file
						for (int i = 0; i < n; i++) {
							update_1_course(dc[i], "dskhoa_hoc.csv", i);
						}
					}
					else if (x == 3) {
						system("cls");
						string ch;
						cout << "ten lop hoc moi: ";
						getline(cin, ch);
						dc[cu].inclass = ch;

						//cap nhat thong tin csv
						fstream f1;
						f1.open("dskhoa_hoc.csv", ios::out);
						f1 << n;
						f1 << endl;
						f1.close();

						//cap nhat thong tin txt
						fstream f;
						f.open("dscourse.txt", ios::out);
						f << n;
						f << endl;
						f.close();

						//cap nhat thong tin tung file
						for (int i = 0; i < n; i++) {
							update_1_course(dc[i], "dskhoa_hoc.csv", i);
						}
					}
					else if (x == 4) {
						system("cls");
						string ch;
						cout << "ten giao vien moi: ";
						getline(cin, ch);
						dc[cu].teacher = ch;

						//cap nhat thong tin csv
						fstream f1;
						f1.open("dskhoa_hoc.csv", ios::out);
						f1 << n;
						f1 << endl;
						f1.close();

						//cap nhat thong tin txt
						fstream f;
						f.open("dscourse.txt", ios::out);
						f << n;
						f << endl;
						f.close();

						//cap nhat thong tin tung file
						for (int i = 0; i < n; i++) {
							update_1_course(dc[i], "dskhoa_hoc.csv", i);
						}
					}
					else if (x == 5) {
						system("cls");
						string ch;
						cout << "tin chi moi: ";
						getline(cin, ch);
						dc[cu].credits = ch;

						//cap nhat thong tin csv
						fstream f1;
						f1.open("dskhoa_hoc.csv", ios::out);
						f1 << n;
						f1 << endl;
						f1.close();

						//cap nhat thong tin txt
						fstream f;
						f.open("dscourse.txt", ios::out);
						f << n;
						f << endl;
						f.close();

						//cap nhat thong tin tung file
						for (int i = 0; i < n; i++) {
							update_1_course(dc[i], "dskhoa_hoc.csv", i);
						}
					}
					else if (x == 6) {
						system("cls");
						string ch;
						cout << "so luong hoc sin toi da moi: ";
						getline(cin, ch);
						dc[cu].maxst = ch;

						//cap nhat thong tin csv
						fstream f1;
						f1.open("dskhoa_hoc.csv", ios::out);
						f1 << n;
						f1 << endl;
						f1.close();

						//cap nhat thong tin txt
						fstream f;
						f.open("dscourse.txt", ios::out);
						f << n;
						f << endl;
						f.close();

						//cap nhat thong tin tung file
						for (int i = 0; i < n; i++) {
							update_1_course(dc[i], "dskhoa_hoc.csv", i);
						}
					}
					else if (x == 7) {
						system("cls");
						string ch;
						cout << "ngay trong tuan moi (mon/tue/wed/thu/fri/sat): ";
						getline(cin, ch);
						dc[cu].dow = ch;

						//cap nhat thong tin csv
						fstream f1;
						f1.open("dskhoa_hoc.csv", ios::out);
						f1 << n;
						f1 << endl;
						f1.close();

						//cap nhat thong tin txt
						fstream f;
						f.open("dscourse.txt", ios::out);
						f << n;
						f << endl;
						f.close();

						//cap nhat thong tin tung file
						for (int i = 0; i < n; i++) {
							update_1_course(dc[i], "dskhoa_hoc.csv", i);
						}
					}
					else if (x == 8) {
						system("cls");
						string ch;
						cout << "buoi hoc moi: s1 (7:30), s2 (9:30), s3 (13:30), s4 (15:30): ";
						getline(cin, ch);
						dc[cu].ses = ch;

						//cap nhat thong tin csv
						fstream f1;
						f1.open("dskhoa_hoc.csv", ios::out);
						f1 << n;
						f1 << endl;
						f1.close();

						//cap nhat thong tin txt
						fstream f;
						f.open("dscourse.txt", ios::out);
						f << n;
						f << endl;
						f.close();

						//cap nhat thong tin tung file
						for (int i = 0; i < n; i++) {
							update_1_course(dc[i], "dskhoa_hoc.csv", i);
						}
					}
					else if (x == 9) {
						system("cls");
						break;
					}
				}
			}

			delete[] dc;
		}
		else if (y == 3) {
			system("cls");
			break;
		}
	}

}

void add_sttocourse() {//add a student to course //11(done)
	system("cls");

	while (1) {
		cout << "chon lua chon " << endl;
		cout << "1. them 1 sinh vien vao 1 khoa hoc" << endl;
		cout << "2. thoat" << endl;
		int x;
		cout << "nhap lua chon: ";
		cin >> x;
		if (x == 1) {
			system("cls");

			//lay ds cac khoa hoc
			fstream f;
			f.open("dscourse.txt", ios::in);
			int n;
			f >> n;
			course* dsc = new course[n];
			for (int i = 0; i < n; i++) {
				int m;
				f >> m;
				f.ignore();
				getline(f, dsc[i].id);
				getline(f, dsc[i].name);
				getline(f, dsc[i].inclass);
				getline(f, dsc[i].teacher);
				getline(f, dsc[i].credits);
				getline(f, dsc[i].maxst);
				getline(f, dsc[i].dow);
				getline(f, dsc[i].ses);
			}
			f.close();

			//nhap id khoa hoc can them
			string cr;
			cout << "nhap id khoa hoc can them sinh vien: ";
			cin.ignore();
			getline(cin, cr);
			int flag = 0;//kiem tra co ton tai lop hoc trong ds khong
			for (int i = 0; i < n; i++) {
				if (cr.compare(dsc[i].id) == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				cout << "khong ton tai khoa hoc do trong ds" << endl;
				continue;
			}
			else {
				//ghi them sv vao khoa hoc
				sinhvien sv;
				nhapsinhvien(sv);
				cr += ".csv";
				fstream f1;//khoa hoc can them sv vo

				//doc file de lay so luong
				f1.open(cr, ios::in);
				string a1, a2, a3, a4, a5, a6, a7;
				getline(f1, a1, ',');
				getline(f1, a2, ',');
				getline(f1, a3, ',');
				getline(f1, a4, ',');
				getline(f1, a5, ',');
				getline(f1, a6, ',');
				getline(f1, a7);
				int l = 0;
				while (!f1.eof()) {
					string a1, a2, a3, a4, a5, a6, a7;
					getline(f1, a1, ',');
					getline(f1, a2, ',');
					getline(f1, a3, ',');
					getline(f1, a4, ',');
					getline(f1, a5, ',');
					getline(f1, a6, ',');
					getline(f1, a7);
					l++;
				}
				f1.close();

				//ghi thong tin sv moi vao khoa hoc
				fstream f2;
				f2.open(cr, ios::app);
				f2 << l << ",";
				f2 << sv.mssv << ",";
				f2 << sv.ho << ",";
				f2 << sv.ten << ",";
				f2 << sv.gioitinh << ",";
				f2 << sv.ngaysinh << ",";
				f2 << sv.cccd << endl;
				f2.close();
			}
			delete[] dsc;
		}
		else if (x == 2) {
			break;
		}
	}
}

void remove_st_course() {//xoa 1 sinh vien ra khoi khoa hoc // 12(done)
	system("cls");

	while (1) {
		cout << "chon lua chon: " << endl;
		cout << "1. xoa 1 sinh vien ra khoi khoa hoc" << endl;
		cout << "2.thoat" << endl;
		int x;
		cout << "nhap lua chon: ";
		cin >> x;
		cin.ignore();
		if (x == 1) {
			system("cls");

			//lay thong tin cac khoa hoc tu file txt
			fstream f;
			f.open("dscourse.txt", ios::in);
			int n;
			f >> n;
			course* dsc = new course[n];//danh sach cac khoa hoc
			for (int i = 0; i < n; i++) {
				int x;
				f >> x;
				f.ignore();
				getline(f, dsc[i].id);
				getline(f, dsc[i].name);
				getline(f, dsc[i].inclass);
				getline(f, dsc[i].teacher);
				getline(f, dsc[i].credits);
				getline(f, dsc[i].maxst);
				getline(f, dsc[i].dow);
				getline(f, dsc[i].ses);
			}
			f.close();

			string c;
			cout << "nhap id khoa hoc can xoa sinh vien: ";
			getline(cin, c);
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (c.compare(dsc[i].id) == 0) {
					flag = 1;
					break;
				}
			}
			delete[] dsc;

			if (flag == 0) {
				cout << "khong ton dai khoa hoc duoc de cap" << endl;
				continue;
			}
			else {

				//lay thong tin tat ca sinh vien tu khoa hoc do
				fstream f1;
				c += ".csv";
				f1.open(c, ios::in);
				string a1, a2, a3, a4, a5, a6, a7;
				getline(f1, a1, ',');
				getline(f1, a2, ',');
				getline(f1, a3, ',');
				getline(f1, a4, ',');
				getline(f1, a5, ',');
				getline(f1, a6, ',');
				getline(f1, a7);

				sinhvien G[100];
				int j = 0;
				while (!f1.eof()) {
					string b1, b2, b3, b4, b5, b6, b7;
					getline(f1, b1, ',');//no
					getline(f1, b2, ','); //mssv
					getline(f1, b3, ',');//ho
					getline(f1, b4, ',');//ten
					getline(f1, b5, ',');//gioi tinh
					getline(f1, b6, ',');//ngay sinh
					getline(f1, b7);//cccd

					G[j].mssv = new char[b2.length()];//
					copy(b2.begin(), b2.end(), G[j].mssv);
					G[j].mssv[b2.length()] = '\0';

					G[j].ho = new char[b3.length()];//
					copy(b3.begin(), b3.end(), G[j].ho);
					G[j].ho[b3.length()] = '\0';

					G[j].ten = new char[b4.length()];//
					copy(b4.begin(), b4.end(), G[j].ten);
					G[j].ten[b4.length()] = '\0';

					G[j].gioitinh = new char[b5.length()];//
					copy(b5.begin(), b5.end(), G[j].gioitinh);
					G[j].gioitinh[b5.length()] = '\0';

					G[j].ngaysinh = new char[b6.length()];//
					copy(b6.begin(), b6.end(), G[j].ngaysinh);
					G[j].ngaysinh[b6.length()] = '\0';

					G[j].cccd = new char[b7.length()];//
					copy(b7.begin(), b7.end(), G[j].cccd);
					G[j].cccd[b7.length()] = '\0';

					j++;
				}
				f1.close();

				string ID;
				cout << "mssv sinh vien can xoa: ";
				getline(cin, ID);
				int cl = 0;
				flag = 0;
				for (int i = 0; i < j; i++) {
					if (ID.compare(G[i].mssv) == 0) {
						cl = i;
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					cout << "khong ton tai sinh vien trong khoa hoc" << endl;
					continue;
				}
				else {

					//cap nhat lai sv trong lop
					fstream f2;
					f2.open(c, ios::out);
					f2 << "stt" << ",";
					f2 << "mssv" << ",";
					f2 << "ho" << ",";
					f2 << "ten" << ",";
					f2 << "gioi tinh" << ",";
					f2 << "ngay sinh" << ",";
					f2 << "cccd" << endl;
					for (int i = 0; i < j - 1; i++) {
						if (i == cl) {
							continue;
						}
						else {
							f2 << i + 1 << ",";
							f2 << G[i].mssv << ",";
							f2 << G[i].ho << ",";
							f2 << G[i].ten << ",";
							f2 << G[i].gioitinh << ",";
							f2 << G[i].ngaysinh << ",";
							f2 << G[i].cccd << endl;
						}
					}
					f2.close();
				}
			}
		}
		else {
			break;
		}
	}
}

void delete_course() {//delete course //13 (done)
	system("cls");
	while (1) {
		system("cls");
		cout << "nhap lua chon: " << endl;
		cout << "1. xoa 1 khoa hoc" << endl;
		cout << "2. thoat" << endl;
		int x;
		cout << "nhap lua chon: ";
		cin >> x;
		cin.ignore();

		//xoa 1 khoa hoc
		if (x == 1) {
			system("cls");

			//lay thong tin cac khoa hoc tu dscourse.txt
			int n;
			fstream f;
			f.open("dscourse.txt", ios::in);
			f >> n;//so luong khoa hoc
			course* dc = new course[n];//danh sach khoa hoc  
			for (int i = 0; i < n; i++) {
				int m;
				f >> m;
				f.ignore();
				getline(f, dc[i].id);
				getline(f, dc[i].name);
				getline(f, dc[i].inclass);
				getline(f, dc[i].teacher);
				getline(f, dc[i].credits);
				getline(f, dc[i].maxst);
				getline(f, dc[i].dow);
				getline(f, dc[i].ses);
			}
			f.close();

			//danh sach khoa hoc rong thi thoat
			if (n == 0) {
				system("cls");
				cout << "danh sach khoa hoc rong";
				return;
			}

			//nhap ma khoa hoc can xoa
			string ch;
			cout << "nhap ma khoa hoc can xoa: ";
			getline(cin, ch);
			int cu;
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (ch.compare(dc[i].id) == 0) {
					flag = 1;
					cu = i;
					break;
				}
			}
			if (flag == 0) {
				cout << "khong ton tai khoa hoc trong ds";
			}
			else {

				//cap nhat thong tin csv
				fstream f1;
				f1.open("dskhoa_hoc.csv", ios::out);
				f1 << n - 1;
				f1 << endl;
				f1.close();

				//cap nhat thong tin txt
				fstream f2;
				f2.open("dscourse.txt", ios::out);
				f2 << n - 1;
				f2 << endl;
				f2.close();

				//cap nhat thong tin tung file
				for (int i = 0; i < n; i++) {
					if (i != cu) {
						update_1_course(dc[i], "dskhoa_hoc.csv", i);
					}
				}
			}
			delete[] dc;
		}
		else if (x == 2) {
			break;
		}
	}
	return;
}

void merge_course_st() {//gop ds sinh vien trong tung course csv lai voi nhau thanh 1 file sinhvien// 14(bonus)
	system("cls");

	//lay cac khoa hoc all ra ds
	fstream f;
	f.open("allcourse.txt", ios::in);
	int n;
	f >> n;
	course* dsc = new course[n];
	for (int i = 0; i < n; i++) {
		int x;
		f >> x;
		f.ignore();
		getline(f, dsc[i].id);
		getline(f, dsc[i].name);
		getline(f, dsc[i].inclass);
		getline(f, dsc[i].teacher);
		getline(f, dsc[i].credits);
		getline(f, dsc[i].maxst);
		getline(f, dsc[i].dow);
		getline(f, dsc[i].ses);
	}
	f.close();

	//tao ds chi chua sinh vien 
	fstream svRo;
	svRo.open("dssv.csv", ios::out);
	svRo << "stt" << ",";
	svRo << "mssv" << ",";
	svRo << "ho" << ",";
	svRo << "ten" << ",";
	svRo << "gioi tinh" << ",";
	svRo << "ngay sinh" << ",";
	svRo << "cccd" << ",";
	svRo << "khoa hoc" << endl;

	for (int i = 0; i < n; i++) {
		//lay thong tin sinh vien tung file course
		string m = dsc[i].id;
		m += ".csv";
		fstream f1;
		f1.open(m, ios::in);

		string b1, b2, b3, b4, b5, b6, b7;
		getline(f1, b1, ',');//stt
		getline(f1, b2, ',');//mssv
		getline(f1, b3, ',');//ho
		getline(f1, b4, ',');//ten
		getline(f1, b5, ',');//gioi tinh
		getline(f1, b6, ',');//ngay sinh
		getline(f1, b7);//cccd

		while (!f1.eof()) {
			string a1, a2, a3, a4, a5, a6, a7;
			getline(f1, a1, ',');
			getline(f1, a2, ',');
			getline(f1, a3, ',');
			getline(f1, a4, ',');
			getline(f1, a5, ',');
			getline(f1, a6, ',');
			getline(f1, a7);

			//ghi vao file tat ca sv
			svRo << a1 << ",";
			svRo << a2 << ",";
			svRo << a3 << ",";
			svRo << a4 << ",";
			svRo << a5 << ",";
			svRo << a6 << ",";
			svRo << a7 << ",";
			svRo << dsc[i].id << endl;
		}
		f1.close();
	}
	svRo.close();
}

void sv_view_course() {//sinh vien xem khoa hoc da dang ky //14(done)
	system("cls");

	//nhap thong tin mssv can tim khoa hoc
	string m;
	cout << "ma so sinh vien: ";
	getline(cin, m);

	//lay so luong toi da cac khoa hoc
	fstream f1;
	f1.open("allcourse.txt", ios::in);
	int n;
	f1 >> n;
	f1.ignore();
	f1.close();
	string* co = new string[n];

	//bat dau tim course sinh vien da dang ky tham gia
	fstream f;
	f.open("dssv.csv", ios::in);
	int j = 0;
	while (!f.eof()) {

		//lay thong tin tung sinhv vien trong lop
		string a1, a2, a3, a4, a5, a6, a7, a8;
		getline(f, a1, ',');//stt
		getline(f, a2, ',');//mssv
		getline(f, a3, ',');//ho
		getline(f, a4, ',');//ten
		getline(f, a5, ',');//gioi tinh
		getline(f, a6, ',');//ngay sinh
		getline(f, a7, ',');//cccd
		getline(f, a8);//khoa hoc

		//kiem tra dieu kien mssv de xem khoa hoc
		if (m.compare(a2) == 0) {
			co[j] = a8;
			j++;
		}
	}
	f.close();

	//xuat thong tin cac khoa hoc da dang ky
	cout << "cac khoa hoc sinh vien da dang ky: " << endl;
	for (int i = 0; i < j; i++) {
		cout << co[i] << endl;
	}

	delete[] co;
}

void merge_all_classes() {// gop 2 ds lop hoc all va moi vao ds all //(bonus 15-18) (done)
	fstream f1;
	fstream f2;
	f1.open("1stclasses.txt", ios::in);
	f2.open("allclasses.txt", ios::in);
	int n, m;
	f1 >> m;//so lop moi
	f2 >> n;//so lop all
	n += m;
	f1.ignore();
	f2.ignore();
	string* lc = new string[n];//mang chua danh sach cac lop hoc (all)

	//luu cac lop hoc moi 
	for (int i = 0; i < m; i++) {
		getline(f1, lc[i]);
	}

	//luu cac lop hoc cu
	for (int i = m; i < n; i++) {
		getline(f2, lc[i]);
	}
	f1.close();
	f2.close();

	//them tat ca cac lop hoc moi luu vao danh sach all
	fstream f;
	f.open("allclasses.txt", ios::out);
	f << n << endl;
	for (int i = 0; i < n; i++) {
		f << lc[i] << endl;
	}
	delete[] lc;
	f.close();
}

void view_list_classes() {//view list classes //15 (done)
	system("cls");
	fstream f;
	f.open("allclasses.txt", ios::in);//file chua cac lop hoc
	int n;
	f >> n;
	f.ignore();
	string* lc = new string[n];

	//luu cac lop hoc
	for (int i = 0; i < n; i++) {
		getline(f, lc[i]);
	}

	//xuat ra man hinh cac lop hoc
	cout << "danh sach cac lop hoc: " << endl;
	for (int i = 0; i < n; i++) {
		cout << lc[i] << endl;
	}
	delete[] lc;
	f.close();
	return;
}

void view_stclass() {//xem ds sinh vien trong lop //16(done)
	system("cls");

	while (1) {
		cout << "nhap lua chon: " << endl;
		cout << "1. xem ds sinh vien trong 1 lop" << endl;
		cout << "2. thoat" << endl;
		int x;
		cout << "nhap lua chon:";
		cin >> x;
		cin.ignore();
		if (x == 1) {
			system("cls");

			//lay thong tin tat ca cac lop tu truoc toi gio
			fstream f;
			f.open("allclasses.txt", ios::in);//lay tat ca cac lop
			int n;
			f >> n;
			f.ignore();
			string* allcl = new string[n];
			for (int i = 0; i < n; i++) {
				getline(f, allcl[i]);
			}
			f.close();

			//lay lop hoc can xem va kiem tra
			string c;
			cout << "lop hoc can xem ds sinh vien: ";
			getline(cin, c);
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (c.compare(allcl[i]) == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				cout << "khong ton tai lop hoc tren" << endl;
				continue;
			}
			else {
				system("cls");

				c += ".csv";
				fstream f1;
				f1.open(c, ios::in);
				cout << setw(5) << left << "stt";
				cout << setw(10) << left << "mssv";
				cout << setw(40) << left << "ho";
				cout << setw(20) << left << "ten";
				cout << setw(15) << left << "gioi tinh";
				cout << setw(15) << "ngay sinh";
				cout << setw(15) << "cccd";
				cout << endl;

				string b1, b2, b3, b4, b5, b6, b7;
				getline(f1, b1, ',');
				getline(f1, b2, ',');
				getline(f1, b3, ',');
				getline(f1, b4, ',');
				getline(f1, b5, ',');
				getline(f1, b6, ',');
				getline(f1, b7);

				while (!f1.eof()) {
					string a1, a2, a3, a4, a5, a6, a7;
					getline(f1, a1, ',');
					getline(f1, a2, ',');
					getline(f1, a3, ',');
					getline(f1, a4, ',');
					getline(f1, a5, ',');
					getline(f1, a6, ',');
					getline(f1, a7);

					cout << setw(5) << left << a1;
					cout << setw(10) << left << a2;
					cout << setw(40) << left << a3;
					cout << setw(20) << left << a4;
					cout << setw(15) << left << a5;
					cout << setw(15) << a6;
					cout << setw(15) << a7;
					cout << endl;
				}
				f1.close();
			}
		}
		else {
			break;
		}
	}
}

void merge_all_course() {//gop 2 ds khoa hoc moi va all // (15-18)bonus
	fstream f1;
	fstream f2;
	f1.open("dscourse.txt", ios::in);//danh sach khoa moi
	f2.open("allcourse.txt", ios::in);//danh sach khoa all
	int n, m;
	f1 >> m;//so khoa moi
	f2 >> n;//so khoa all
	n += m;
	course* lc = new course[n];//danh sach cac khoa hoc all

	//luu ds cac khoa hoc moi
	for (int i = 0; i < m; i++) {
		int x;
		f1 >> x;
		f1.ignore();
		getline(f1, lc[i].id);
		getline(f1, lc[i].name);
		getline(f1, lc[i].inclass);
		getline(f1, lc[i].teacher);
		getline(f1, lc[i].credits);
		getline(f1, lc[i].maxst);
		getline(f1, lc[i].dow);
		getline(f1, lc[i].ses);
	}

	//luu ds cac khoa hoc all
	for (int i = m; i < n; i++) {
		int x;
		f2 >> x;
		f2.ignore();
		getline(f2, lc[i].id);
		getline(f2, lc[i].name);
		getline(f2, lc[i].inclass);
		getline(f2, lc[i].teacher);
		getline(f2, lc[i].credits);
		getline(f2, lc[i].maxst);
		getline(f2, lc[i].dow);
		getline(f2, lc[i].ses);
	}
	f1.close();
	f2.close();

	fstream f;
	f.open("allcourse.txt", ios::out);
	f << n << endl;
	//ghi lai vao ds all
	for (int i = 0; i < n; i++) {
		f << i + 1 << endl;
		f << lc[i].id << endl;
		f << lc[i].name << endl;
		f << lc[i].inclass << endl;
		f << lc[i].teacher << endl;
		f << lc[i].credits << endl;
		f << lc[i].maxst << endl;
		f << lc[i].dow << endl;
		f << lc[i].ses << endl;
	}
	delete[] lc;
	f.close();
}

void view_stcourse() {//xem ds sinh vien trong khoa hoc // 18(done)
	system("cls:");

	while (1) {
		cout << "nhap lua chon: " << endl;
		cout << "1. xem ds sinh vien trong khoa hoc" << endl;
		cout << "2.thoat" << endl;
		cout << "nhap lua chon: ";
		int x;
		cin >> x;
		cin.ignore();
		if (x == 1) {
			system("cls");

			//lay thong tin cac course
			fstream f;
			f.open("allcourse.txt", ios::in);//ds tat ca cac khoa hoc
			int n;
			f >> n;
			course* dsc = new course[n];
			for (int i = 0; i < n; i++) {
				int x;
				f >> x;
				f.ignore();
				getline(f, dsc[i].id);
				getline(f, dsc[i].name);
				getline(f, dsc[i].inclass);
				getline(f, dsc[i].teacher);
				getline(f, dsc[i].credits);
				getline(f, dsc[i].maxst);
				getline(f, dsc[i].dow);
				getline(f, dsc[i].ses);
			}
			f.close();

			//kiem tra xem khoa hoc co ton tai
			string c;
			cout << "id khoa hoc can xem ds sinh vien: ";
			getline(cin, c);
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (c.compare(dsc[i].id) == 0) {
					flag = 1;
					break;
				}
			}
			delete[] dsc;

			if (flag == 0) {
				cout << "khong ton tai khoa hoc duoc de cap" << endl;
				continue;
			}
			else {
				system("cls");

				c += ".csv";
				fstream f1;
				f1.open(c, ios::in);
				cout << setw(5) << left << "stt";
				cout << setw(10) << left << "mssv";
				cout << setw(40) << left << "ho";
				cout << setw(20) << left << "ten";
				cout << setw(15) << left << "gioi tinh";
				cout << setw(15) << "ngay sinh";
				cout << setw(15) << "cccd";
				cout << endl;

				string b1, b2, b3, b4, b5, b6, b7;
				getline(f1, b1, ',');
				getline(f1, b2, ',');
				getline(f1, b3, ',');
				getline(f1, b4, ',');
				getline(f1, b5, ',');
				getline(f1, b6, ',');
				getline(f1, b7);

				while (!f1.eof()) {
					string a1, a2, a3, a4, a5, a6, a7;
					getline(f1, a1, ',');
					getline(f1, a2, ',');
					getline(f1, a3, ',');
					getline(f1, a4, ',');
					getline(f1, a5, ',');
					getline(f1, a6, ',');
					getline(f1, a7);

					cout << setw(5) << left << a1;
					cout << setw(10) << left << a2;
					cout << setw(40) << left << a3;
					cout << setw(20) << left << a4;
					cout << setw(15) << left << a5;
					cout << setw(15) << a6;
					cout << setw(15) << a7;
					cout << endl;
				}
				f1.close();
			}
		}
		else {
			break;
		}
	}
}

void scoreboard_course() {//export a scoreboard of course// 19(done)
	system("cls");

	//lay ds cac course
	fstream f;
	f.open("allcourse.txt", ios::in);
	int n;
	f >> n;
	course* dsc = new course[n];
	for (int i = 0; i < n; i++) {
		int x;
		f >> x;
		f.ignore();
		getline(f, dsc[i].id);
		getline(f, dsc[i].name);
		getline(f, dsc[i].inclass);
		getline(f, dsc[i].teacher);
		getline(f, dsc[i].credits);
		getline(f, dsc[i].maxst);
		getline(f, dsc[i].dow);
		getline(f, dsc[i].ses);
	}
	f.close();

	for (int i = 0; i < n; i++) {

		//file diem khoa hoc csv
		fstream f1;
		string na = dsc[i].id;
		na += "_scoreboard.csv";
		f1.open(na, ios::out);
		f1 << "stt" << ",";
		f1 << "mssv" << ",";
		f1 << "ho ten" << ",";
		f1 << "diem TK" << ",";
		f1 << "diem CK" << ",";
		f1 << "diem GK" << ",";
		f1 << "diem khac" << endl;

		fstream f2;
		string c = dsc[i].id;
		c += ".csv";
		f2.open(c, ios::in);
		string b1, b2, b3, b4, b5, b6, b7;
		getline(f2, b1, ',');
		getline(f2, b2, ',');
		getline(f2, b3, ',');
		getline(f2, b4, ',');
		getline(f2, b5, ',');
		getline(f2, b6, ',');
		getline(f2, b7);
		while (!f2.eof()) {
			string a1, a2, a3, a4, a5, a6, a7;
			getline(f2, a1, ',');//stt
			getline(f2, a2, ',');//mssv
			getline(f2, a3, ',');//ho
			getline(f2, a4, ',');//ten
			getline(f2, a5, ',');//gioi tinh
			getline(f2, a6, ',');//ngay sinh
			getline(f2, a7);//cccd

			f1 << a1 << ",";
			f1 << a2 << ",";
			string k;
			k += a3;
			k += " ";
			k += a4;
			f1 << k << ",";
			f1 << ",";
			f1 << ",";
			f1 << ",";
			f1 << endl;
		}
		f1.close();
		f2.close();
	}
}

void inp_course_scoreboard() {//import scoreboard to course_scoreboard //20(done)
	system("cls");

	while (1) {
		cout << "nhap lua chon: " << endl;
		cout << "1. nhap diem bang file" << endl;
		cout << "2. nhap diem bang link path" << endl;
		cout << "3. thoat" << endl;
		cout << "nhap lua chon: ";
		int x;
		cin >> x;
		cin.ignore();
		if (x == 1) {
			system("cls");

			fstream f;
			f.open("allcourse.txt", ios::in);
			int n;
			f >> n;
			course* dsc = new course[n];
			for (int i = 0; i < n; i++) {
				int x;
				f >> x;
				f.ignore();
				getline(f, dsc[i].id);
				getline(f, dsc[i].name);
				getline(f, dsc[i].inclass);
				getline(f, dsc[i].teacher);
				getline(f, dsc[i].credits);
				getline(f, dsc[i].maxst);
				getline(f, dsc[i].dow);
				getline(f, dsc[i].ses);
			}
			f.close();

			string co;
			cout << "id khoa hoc import diem: ";
			getline(cin, co);
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (co.compare(dsc[i].id) == 0) {
					flag = 1;
					break;
				}
			}
			delete[] dsc;

			if (flag == 0) {
				cout << "khong ton tai khoa hoc tren" << endl;
				continue;
			}
			else {
				system("cls");

				string co_s;
				co_s += co;
				co_s += "_full.csv";//ten file gv nhap diem san
				fstream sco;//file giao vien nhap diem san
				sco.open(co_s, ios::in);
				if (!sco.is_open()) {
					cout << "chua co file diem import" << endl;
					sco.close();
					continue;
				}
				else {
					sco.close();
					co += "_scoreboard.csv";

					char* a = new char[co.length() + 1];//id_scoreboard.csv
					copy(co.begin(), co.end(), a);
					a[co.length()] = '\0';

					char* b = new char[co_s.length() + 1];//id_full.csv
					copy(co_s.begin(), co_s.end(), b);
					b[co_s.length()] = '\0';

					remove(a);
					int ret = rename(b, a);
					sco.close();

					system("cls");
				}
			}
		}
		else if (x == 2) {
			system("cls");

			fstream f;
			f.open("allcourse.txt", ios::in);
			int n;
			f >> n;
			course* dsc = new course[n];
			for (int i = 0; i < n; i++) {
				int x;
				f >> x;
				f.ignore();
				getline(f, dsc[i].id);
				getline(f, dsc[i].name);
				getline(f, dsc[i].inclass);
				getline(f, dsc[i].teacher);
				getline(f, dsc[i].credits);
				getline(f, dsc[i].maxst);
				getline(f, dsc[i].dow);
				getline(f, dsc[i].ses);
			}
			f.close();

			string co;
			cout << "id khoa hoc import diem: ";
			getline(cin, co);
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (co.compare(dsc[i].id) == 0) {
					flag = 1;
					break;
				}
			}
			delete[] dsc;

			if (flag == 0) {
				cout << "khong ton tai khoa hoc tren" << endl;
				continue;
			}
			else {
				system("cls");

				//nhap duong dan link
				string pa;
				cout << "nhap link path import file: ";
				getline(cin, pa);

				//xoa ky tu " trong link
				for (int i = 0; i < pa.length(); i++) {
					while (pa[i] == '"') {
						pa.erase(pa.begin() + i);
					}
				}

				fstream f1;
				f1.open(pa, ios::in);
				if (!f1.is_open()) {
					cout << "khong ton tai file nay " << endl;
					continue;
				}
				else {
					co += "_scoreboard.csv";
					fstream f2;
					f2.open(co, ios::out);
					while (!f1.eof()) {
						string a1, a2, a3, a4, a5, a6, a7;
						getline(f1, a1, ',');
						getline(f1, a2, ',');
						getline(f1, a3, ',');
						getline(f1, a4, ',');
						getline(f1, a5, ',');
						getline(f1, a6, ',');
						getline(f1, a7);

						f2 << a1 << ",";
						f2 << a2 << ",";
						f2 << a3 << ",";
						f2 << a4 << ",";
						f2 << a5 << ",";
						f2 << a6 << ",";
						f2 << a7 << endl;
					}
					f1.close();
					f2.close();

					system("cls");
				}
			}
		}
		else {
			break;
		}
	}
}

void view_scoreboard_course() {//xem bang diem cua khoa hoc //21(done)
	system("cls");

	while (1) {
		cout << "nhap lua chon: " << endl;
		cout << "1. xem bang diem khoa hoc" << endl;
		cout << "2. thoat" << endl;
		int x;
		cout << "nhap lua chon: ";
		cin >> x;
		cin.ignore();

		//xem bang diem
		if (x == 1) {
			system("cls");

			//lay ds khoa hoc
			fstream f1;
			f1.open("allcourse.txt", ios::in);
			int n;
			f1 >> n;
			course* dsc = new course[n];
			for (int i = 0; i < n; i++) {
				int x;
				f1 >> x;
				f1.ignore();
				getline(f1, dsc[i].id);
				getline(f1, dsc[i].name);
				getline(f1, dsc[i].inclass);
				getline(f1, dsc[i].teacher);
				getline(f1, dsc[i].credits);
				getline(f1, dsc[i].maxst);
				getline(f1, dsc[i].dow);
				getline(f1, dsc[i].ses);
			}
			f1.close();

			//lay ten khoa hoc
			string sc;
			cout << "ten khoa hoc can xem diem: ";
			getline(cin, sc);

			//kiem tra khoa hoc co ton tai
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (sc.compare(dsc[i].id) == 0) {
					flag = 1;
					break;
				}
			}
			delete[] dsc;

			if (flag == 0) {//khoa hoc khong ton tai
				cout << "khong ton tai khoa hoc tren" << endl;
				continue;
			}
			else {//khoa hoc ton tai
				sc += "_scoreboard.csv";
				fstream f;
				f.open(sc, ios::in);

				while (!f.eof()) {
					string a1, a2, a3, a4, a5, a6, a7;
					getline(f, a1, ',');
					getline(f, a2, ',');
					getline(f, a3, ',');
					getline(f, a4, ',');
					getline(f, a5, ',');
					getline(f, a6, ',');
					getline(f, a7);

					cout << setw(5) << left << a1;
					cout << setw(10) << left << a2;
					cout << setw(50) << left << a3;
					cout << setw(10) << a4;
					cout << setw(10) << a5;
					cout << setw(10) << a6;
					cout << setw(12) << a7;
					cout << endl;
				}
				f.close();
			}
		}
		else {
			break;
		}

	}
}

void update_score() {//cap nhat diem cua sinh vien //22(done)
	system("cls");

	while (1) {
		cout << "nhap lua chon: " << endl;
		cout << "1. cap nhat diem 1 sinh vien" << endl;
		cout << "2. thoat" << endl;
		int x;
		cout << "nhap lua chon: ";
		cin >> x;
		cin.ignore();
		if (x == 1) {
			system("cls");

			//lay thong tin cac khoa hoc
			fstream f;
			f.open("allcourse.txt", ios::in);
			int n;
			f >> n;
			course* dsc = new course[n];
			for (int i = 0; i < n; i++) {
				int m;
				f >> m;
				f.ignore();
				getline(f, dsc[i].id);
				getline(f, dsc[i].name);
				getline(f, dsc[i].inclass);
				getline(f, dsc[i].teacher);
				getline(f, dsc[i].credits);
				getline(f, dsc[i].maxst);
				getline(f, dsc[i].dow);
				getline(f, dsc[i].ses);
			}
			f.close();

			//ID khoa hoc
			cout << "ID khoa hoc can sua doi cho sinh vien: ";
			string co;
			getline(cin, co);
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (co.compare(dsc[i].id) == 0) {
					flag = 1;
					break;
				}
			}
			delete[] dsc;

			if (flag == 0) {
				cout << "khong ton tai khoa hoc trong ds" << endl;
				continue;
			}
			else {
				system("cls");

				//nhap thong tin sinh vien can sua diem
				cout << "mssv sinh vien can sua diem: ";
				string na;
				getline(cin, na);
				co += "_scoreboard.csv";
				fstream f1;
				f1.open(co, ios::in);

				//lay thong tin
				string a1, a2, a3, a4, a5, a6, a7;
				getline(f1, a1, ',');
				getline(f1, a2, ',');
				getline(f1, a3, ',');
				getline(f1, a4, ',');
				getline(f1, a5, ',');
				getline(f1, a6, ',');
				getline(f1, a7);

				stscore* z= new stscore[70];
				int j = 0;
				while (!f1.eof()) {
					getline(f1, z[j].stt, ',');
					getline(f1, z[j].mssv, ',');
					getline(f1, z[j].hoten, ',');
					getline(f1, z[j].diemTK, ',');
					getline(f1, z[j].diemCK, ',');
					getline(f1, z[j].diemGK, ',');
					getline(f1, z[j].diemkhac);
					j++;
				}
				f1.close();

				stscore* student_score = new stscore[j];
				for (int i = 0; i < j - 1; i++) {
					student_score[i] = z[i];
				}

				delete[] z;

				flag = 0;
				int hs;
				for (int i = 0; i < j - 1; i++) {
					if (na.compare(student_score[i].mssv) == 0) {
						flag = 1;
						hs = i;
					}
				}
				if (flag == 0) {
					cout << "khong ton tai sinh vien nay trong lop hoc" << endl;
					continue;
				}
				else {
					while (1) {
						system("cls");

						cout << "nhap lua chon sua diem: " << endl;
						cout << "1. sua diem TK" << endl;
						cout << "2. sua diem CK" << endl;
						cout << "3. sua diem GK" << endl;
						cout << "4. sua diem khac" << endl;
						cout << "5. thoat" << endl;
						cout << "nhap lua chon: ";
						int y;
						cin >> y;
						cin.ignore();
						if (y == 1) {
							cout << "diem TK duoc chinh sua: ";
							getline(cin, student_score[hs].diemTK);
						}
						else if (y == 2) {
							cout << "diem CK duoc chinh sua: ";
							getline(cin, student_score[hs].diemCK);
						}
						else if (y == 3) {
							cout << "diem GK duoc chinh sua: ";
							getline(cin, student_score[hs].diemGK);
						}
						else if (y == 4) {
							cout << "diem khac duoc chinh sua: ";
							getline(cin, student_score[hs].diemkhac);
						}
						else {

							//cap nhat lai diem
							fstream f2;
							f2.open(co, ios::out);
							f2 << "stt" << ",";
							f2 << "mssv" << ",";
							f2 << "ho ten" << ",";
							f2 << "diem TK" << ",";
							f2 << "diem CK" << ",";
							f2 << "diem GK" << ",";
							f2 << "diem khac" << endl;

							for (int i = 0; i < j - 1; i++) {
								f2 << student_score[i].stt << ",";
								f2 << student_score[i].mssv << ",";
								f2 << student_score[i].hoten << ",";
								f2 << student_score[i].diemTK << ",";
								f2 << student_score[i].diemCK << ",";
								f2 << student_score[i].diemGK << ",";
								f2 << student_score[i].diemkhac << endl;
							}
							f2.close();

							system("cls");
							break;
						}
					}
				}
				delete[] student_score;
			}
		}
		else {
			break;
		}
	}
}

void get_score(const char* inpCourse, string cl[], int n) {//lay diem cuoi ky trong tung khoa hoc

	stscore* ea_cou = new stscore[n];//luu du lieu tu csv 
	fstream f;
	f.open(inpCourse, ios::in);//khoa hoc csv

	//luu nhung thong tin khong dung
	string a1, a2, a3, a4, a5, a6, a7;
	getline(f, a1, ',');
	getline(f, a2, ',');
	getline(f, a3, ',');
	getline(f, a4, ',');
	getline(f, a5, ',');
	getline(f, a6, ',');
	getline(f, a7);

	//luu thong tin cac sv
	for (int i = 1; i < n; i++) {
		getline(f, ea_cou[i].stt, ',');
		getline(f, ea_cou[i].mssv, ',');
		getline(f, ea_cou[i].hoten, ',');
		getline(f, ea_cou[i].diemTK, ',');
		getline(f, ea_cou[i].diemCK, ',');
		getline(f, ea_cou[i].diemGK, ',');
		getline(f, ea_cou[i].diemkhac);
	}
	f.close();

	//chuyen diem cuoi ky ve mang
	for (int i = 1; i < n; i++) {
		cl[i] = ea_cou[i].diemCK;
	}
	delete[] ea_cou;
}

double GPA_cal(string a[], int n) {//tinh diem TB tung khoa hoc
	double sum = 0;
	for (int i = 1; i < n; i++) {
		sum += stod(a[i]);
	}
	sum = (double)(sum / (n - 1));
	return sum;
}

double GPA_eachst(string** a, int k, int l) {// tinh diem TB tung sinh vien
	double sum = 0;
	for (int i = 0; i < k; i++) {
		sum += stod(a[i][l]);
	}
	sum = (double)(sum / (k));
	return sum;
}

void view_scoreboard_class() {//xem diem cua ca lop // 23
	system("cls");

	while (1) {
		cout << "nhap lua chon: " << endl;
		cout << "1. coi diem lop" << endl;
		cout << "2. thoat" << endl;
		cout << "nhap lua chon: ";
		int x;
		cin >> x;
		cin.ignore();
		if (x == 1) {
			system("cls");

			//lay ds cac lop hoc 
			fstream f;
			f.open("allclasses.txt", ios::in);
			int n;
			f >> n;//so luong cac lop
			f.ignore();
			string* cl = new string[n];//ds cac lop hoc
			for (int i = 0; i < n; i++) {
				getline(f, cl[i]);
			}
			f.close();

			//tim ten lop hoc 
			string c;//ten lop hoc
			cout << "id lop hoc: ";
			getline(cin, c);
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (cl[i].compare(c) == 0) {
					flag = 1;
					break;
				}
			}
			delete[] cl;

			if (flag == 0) {
				cout << "khong ton tai lop hoc do" << endl;
				continue;
			}
			else {

				//lay ds cac khoa hoc
				fstream f1;
				f1.open("allcourse.txt", ios::in);
				n = 0;//so luong cac khoa hoc
				f1 >> n;
				course* dsc = new course[n];
				for (int i = 0; i < n; i++) {
					int x;
					f1 >> x;
					f1.ignore();
					getline(f1, dsc[i].id);
					getline(f1, dsc[i].name);
					getline(f1, dsc[i].inclass);
					getline(f1, dsc[i].teacher);
					getline(f1, dsc[i].credits);
					getline(f1, dsc[i].maxst);
					getline(f1, dsc[i].dow);
					getline(f1, dsc[i].ses);
				}
				f1.close();

				//dem bao nhieu khoa hoc trong 1 lop
				int n_cla = 0;//so luong khoa hoc trong 1 lop 
				for (int i = 0; i < n; i++) {
					if (c.compare(dsc[i].inclass) == 0) {
						n_cla++;
					}
				}

				//dem so luong sinh vien trong lop hoc
				string c_csv;
				c_csv = c;
				c_csv += ".csv";
				fstream f2;
				f2.open(c_csv, ios::in);
				int mem = 0;//so luong sinh vien trong lop
				while (!f2.eof()) {
					string a1, a2, a3, a4, a5, a6, a7;
					getline(f2, a1, ',');
					getline(f2, a2, ',');
					getline(f2, a3, ',');
					getline(f2, a4, ',');
					getline(f2, a5, ',');
					getline(f2, a6, ',');
					getline(f2, a7);
					mem++;
				}
				mem--;
				f2.close();

				//mang chua diem cac sinh vien trong cac khoa hoc
				string** sec = new string * [n_cla];
				for (int i = 0; i < n_cla; i++) {
					sec[i] = new string[mem];
				}

				//lay diem tat ca cac mon cua lop hoc
				int ea = 0;
				for (int i = 0; i < n; i++) {
					if (c.compare(dsc[i].inclass) == 0) {
						c_csv = dsc[i].id;
						c_csv += "_scoreboard.csv";

						sec[ea][0] = dsc[i].id;
						//khoi tao const char
						char* cstch = new char[c_csv.length() + 1];
						copy(c_csv.begin(), c_csv.end(), cstch);
						cstch[c_csv.length()] = '\0';
						get_score(cstch, sec[ea], mem);
						delete[] cstch;
						ea++;
					}
				}

				//lay thong tin tung sinh vien
				stscore* dssv = new stscore[mem - 1];
				fstream tmp;
				tmp.open(c_csv, ios::in);
				string b1, b2, b3, b4, b5, b6, b7;
				getline(tmp, b1, ',');
				getline(tmp, b2, ',');
				getline(tmp, b3, ',');
				getline(tmp, b4, ',');
				getline(tmp, b5, ',');
				getline(tmp, b6, ',');
				getline(tmp, b7);
				for (int i = 0; i < mem - 1; i++) {
					getline(tmp, dssv[i].stt, ',');
					getline(tmp, dssv[i].mssv, ',');
					getline(tmp, dssv[i].hoten, ',');
					getline(tmp, dssv[i].diemTK, ',');
					getline(tmp, dssv[i].diemCK, ',');
					getline(tmp, dssv[i].diemGK, ',');
					getline(tmp, dssv[i].diemkhac);
				}
				tmp.close();

				//file chua diem cua ca lop
				c_csv = c;
				c_csv += "_scoreboard.csv";
				fstream nwsc;
				nwsc.open(c_csv, ios::out);
				nwsc << b1 << ",";
				nwsc << b2 << ",";
				nwsc << b3 << ",";
				for (int i = 0; i < n_cla; i++) {
					nwsc << sec[i][0] << ",";
				}
				nwsc << "GPA_semester" << endl;

				for (int i = 1; i < mem; i++) {
					nwsc << dssv[i - 1].stt << ",";
					nwsc << dssv[i - 1].mssv << ",";
					nwsc << dssv[i - 1].hoten << ",";
					for (int j = 0; j < n_cla; j++) {
						nwsc << sec[j][i] << ",";
					}
					double TL = GPA_eachst(sec, n_cla, i);
					string Lcute = to_string(TL);
					nwsc << setprecision(3) << fixed << Lcute << fixed << endl;
				}


				//tinh diem GPA tung mon
				string* Gpa = new string[n_cla];
				for (int i = 0; i < n_cla; i++) {
					double Linh = GPA_cal(sec[i], mem);
					Gpa[i] = to_string(Linh);
				}

				nwsc << "GPA" << ",";
				nwsc << "," << ",";
				for (int i = 0; i < n_cla; i++) {
					nwsc << Gpa[i];
					if (i == n_cla - 1) {
						nwsc << endl;
						break;
					}
					nwsc << ",";
				}
				nwsc.close();

				delete[] Gpa;
				delete[] dsc;
				delete[] dssv;
				delete[] sec;

				//xuat file vua tao ra man hinh
				/*fstream sb;
				sb.open(c_csv, ios::in);
				while (!sb.eof()) {
					string
				}*/
			}
		}
		else {
			break;
		}
	}
}

void hethongchinh(int& year, int& semester) {
	system("cls");
	cout << "---------MENU---------" << endl;
	cout << "1. tao nam hoc " << endl;
	cout << "2. tao hoc ky " << endl;
	cout << "3. tao khoa hoc " << endl;
	/*cout << "5. tao lop hoc" << endl;
	cout << "6. them hoc sinh vao lop " << endl;
	cout << "7. quay ve " << endl;*/
	int luachon;
	cout << "nhap lua chon: ";
	cin >> luachon;
	while (1) {
		switch (luachon) {
		case 1: 
			cout << "tao nam hoc " << endl;
			createSchoolyear(year);
			break;
		case 2:
			cout << "tao hoc ky " << endl;
			createSemester(semester, year);
			break;
		case 3:
			cout << "tao khoa hoc" << endl;
			int n;
			cout << "so luong khoa hoc can tao: ";
			cin >> n;
			course* c = new course[n];
			cin.ignore();
			add_list_course(n, c);
			break;
	
		}
	}
}

void menuascm(int i, giaovu gv, int flag, int& year, int& semester) {//menu giao vu
	system("cls");
	int luachon;
	cout << "---------MENU---------" << endl;
	cout << "1. he thong chinh " << endl;
	cout << "2. thong tin ca nhan " << endl;
	cout << "3. doi mat khau " << endl;
	cout << "4. dang xuat" << endl;
	cout << "5. thoat " << endl;
	cout << "nhap lua chon: ";
	cin >> luachon;
	while (1) {
		switch (luachon) {
		case 1:
			cout << "he thong chinh: " << endl;
			hethongchinh(year,semester);
			break;
		case 2:
			cout << "thong tin ca nhan: " << endl;
			if (flag == 0) {
				thongtin_asm("asm_1.txt", gv);
			}
			else if (flag == 1) {
				thongtin_asm("asm_2.txt", gv);
			}
			else if (flag == 2) {
				thongtin_asm("asm_3.txt", gv);
			}
			break;
		case 3:
			cout << "doi mat khau " << endl;
			doimatkhau("login_asm.txt", flag);
			break;
		case 4:
			return;
			break;
		case 5:
			cout << "cam on ban da su dung he thong";
			exit(1);
		}
	}
}
