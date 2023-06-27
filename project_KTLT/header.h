#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

struct giaovu {
	char* ho;
	char* ten;
	char* gioitinh;
	char* ngaysinh;
	char* cccd;
};

struct sinhvien {
	char* mssv;
	char* ho;
	char* ten;
	char* gioitinh;
	char* ngaysinh;
	char* cccd;
	char* lophoc;
};

struct ngaythang {
	int ngay;
	int thang;
	int nam;
};

struct course {
	string id;
	string name;
	string inclass;
	string teacher;
	string credits;
	string maxst;
	string dow;
	string ses;
};

struct stscore {
	string stt;
	string mssv;
	string hoten;
	string diemTK;
	string diemCK;
	string diemGK;
	string diemkhac;
};

bool log_in(const char* asm1, int& flag);//dang nhap cho giao vu va hoc sinh 

void thongtin_asm(const char* ttcn, giaovu& gv);//thong tin giao vu

void doimatkhau(const char* asm1, int flag);//doi mat khau cho giao vu va sinh vien

//ACADEMIC STAFF MEMBER

//-------------------------------------beginning of schoolyear/semester------------------------------------//

void createSchoolyear(int& year); //he thong chinh cho giao vu (school year) // 1  (done)

void createclasses(int year);//tao lop hoc 2(done)

void nhapsinhvien(sinhvien& sv); // AMS nhap thong tin sinh vien de them vao lop, bo sung cho ham "themsinhvienvaolop" & 11 (done)
void themsvvaolop(const char* claRoster, int year);//them sinh vien vao lop nua //3 & 4 & 5(done)

void createSemester(int& semester, int year);//nhap hoc ky //6 (done)

void add_1_course(course& c, const char* stdcourse, int i); //them 1 khoa hoc trong ds // 7 bonus 1 (done)
void add_list_course(int n, course* c); //cau 7 (done)

void upload_studentincourse(); //upload list student in class csv to course csv //8 (done)

void view_list_course(const char* courselist); //xem ds lop hoc da tao va thong tin lop hoc //9 & 17 (done)

void update_1_course(course& c, const char* stdcourse, int i);// 10 bonus 1 (done)
void update_course(); //update a course // 10 (done)

void add_sttocourse();//add a student to course // 11(done)

void remove_st_course(); //xoa 1 sinh vien ra khoi khoa hoc // 12(done)

void delete_course(); //delete course //13 (done)

//---------------------------------------------------------------------------------------------------------//



//----------------------------------------anytime---------------------------------------//

void merge_all_classes();// gop 2 ds lop hoc all va moi vao ds all //(bonus 15-18) (done)
void view_list_classes(); //view list classes //15 (done)

void view_stclass(); //xem ds sinh vien trong lop //16(done)

void merge_all_course();//gop 2 ds khoa hoc moi va all // (15-18)bonus

void view_stcourse();//xem ds sinh vien trong khoa hoc // 18(done)

//------------------------------------------------------------------------------------//




//------------------------------------end of semester----------------------------------//



void scoreboard_course(); //export a scoreboard of course// 19(done)

void inp_course_scoreboard(); //import scoreboard to course_scoreboard //20(done)

void view_scoreboard_course(); //xem bang diem cua khoa hoc //21(done)

void update_score(); //cap nhat diem cua sinh vien //22(done)

void get_score(const char* inpCourse, string cl[], int n);//lay diem cuoi ky trong tung khoa hoc
double GPA_cal(string a[], int n);//tinh diem TB tung khoa hoc
double GPA_eachst(string** a, int k, int l);// tinh diem TB tung sinh vien
void view_scoreboard_class(); //xem diem cua ca lop // 23


//------------------------------------------------------------------------------------//


//STUDENT

//----------------------------------view course---------------------------------------//

void merge_course_st();//gop ds sinh vien trong tung course csv lai voi nhau thanh 1 file sinhvien// 14(bonus)
void sv_view_course();//sinh vien xem khoa hoc da dang ky //14(done)

//------------------------------------------------------------------------------------//