#include <iostream> // Thu vi?n cho d?u vào và d?u ra chu?n
#include <string>   // Thu vi?n cho x? lý chu?i
#include <vector>   // Thu vi?n cho m
#include <iomanip>
using namespace std;
	int id_IT=20119266;
    int id_Manager=21167881;
    int id_Human_Resource=22145677;
    int id_Electric=23116776;
class Employee {
private:
	// Khoi tao thong tin ca nhan
    string name;
    string birth;
    string address;
    string department;
    
    int identity;
    //Khoi tao ID cho tung bo phan cong ty
    
    
    //Khoi tao nghi,vang,luong,thgian lam viec o day
    int worked_here;
    float salary;
    float absent;
    float overtime;

public:
    Employee() {} // Constructor m?c d?nh không có tham s?
	Employee(string hoten, string ngaysinh, string diachi, string bophan)
        : name(hoten), birth(ngaysinh), address(diachi), department(bophan) {}
        
    Employee(string hoten, string ngaysinh, string diachi, string bophan,int nam_lam_viec,float vang, float tangca)
        : name(hoten), birth(ngaysinh), address(diachi), department(bophan), worked_here(nam_lam_viec), absent(vang), overtime(tangca) {}
	
	//display danh cho admin
    void display_info() {
        cout << "Ho Ten: " << name << "\t" << "Ngay Sinh: " << birth << "\t" << "Dia Chi: " << address << "\t\t" << "Bo Phan: " << department << "\t\t"<<"da lam viec duoc :"<<worked_here<<"nam"<<"\t"<<"vang: "<<absent<<" ngay trong thang"<<"\t"<<"lam them gio: "<<overtime<<" ngay"<<endl;
    }
    static void display_all(vector<Employee>& employees) {
        for (int i = 0; i < employees.size(); i++) {
            employees[i].display_info();
        }
    }

	string get_name() {
        return name;
    }
    string get_birth() {
        return birth;
    }
    string get_address() {
        return address;
    }
    string get_department() {
        return department;
    }
    int get_worked() {
        return worked_here;
    }
   
    float get_absent(){
    	return absent;
	}
   	float get_overtime(){
   		return overtime;
	}
    void set_Salary(float luong) {
           salary=luong;
        }
    float get_salary(){
    	return salary;
	}
	
        //display danh cho nhan vien
    void display_personal(){
//    	cout << "Ho Ten: " << name << "\t" << "Ngay Sinh: " << birth << "\t" << "Dia Chi: " << address << "\t\t" << "Bo Phan: " << department <<"\t\t\t"<<"luong: "<<fixed << setprecision(0)<<salary<<endl;
		
		cout<<"Ho Ten: " << name <<"\t" <<"Ngay Sinh: "<< birth<<"\t"<<"Dia Chi: "<<address<< "\t"<<"Bo Phan: "<<department<<"\t"<<"ID la : "<<identity<<"\t"<<"vang: "<<absent<<" ngay trong thang"<<"\t"<<"lam them gio: "<<overtime<<" ngay"<<"\t\t"<<"luong: "<<fixed << setprecision(0)<<salary<<endl;
	}
	static void display_find_personal(vector<Employee>& employees) {
    int id;
    string hoten;
    string ns;
    bool found = false;

    do {
        cout << "Nhap ID: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap ngay sinh (d/m/y): ";
        getline(cin, ns);

        for (int i = 0; i < employees.size(); i++) {
            if (id == employees[i].identity && hoten == employees[i].name && ns == employees[i].birth) {
                employees[i].display_personal();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Khong tim thay nhan vien. Ban co muon nhap lai khong? (y/n): ";
            char choice;
            cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                break;
            }
        }
    } while (!found);
}
    
    // ma dinh danh cho nhan vien (ID)
    static void Identity(vector<Employee>& employees) {
        for (int i = 0; i < employees.size(); i++) {
            if(employees[i].get_department()=="IT"){
            	employees[i].identity=id_IT;
            	id_IT=id_IT+119;
			}
			if(employees[i].get_department()=="Manager"){
            	employees[i].identity=id_Manager;
            	id_Manager=id_Manager+119;
			}
			if(employees[i].get_department()=="Electric"){
            	employees[i].identity=id_Electric;
            	id_Electric=id_Electric+119;
			}
			if(employees[i].get_department()=="Human Resource"){
            	employees[i].identity=id_Human_Resource;
            	id_Human_Resource=id_Human_Resource+119;
			}		
        }
    }
};

class Admin: public Employee {
	private:
    string identity;
    string password;
   
	public:
	Admin(string tk, string mk)
        : identity(tk), password(mk){}
	string get_id() {
        return identity;
    }
    string get_password() {
        return password;
    }
    
    void add_multiple(vector<Employee>& employees) {
        int n;
        cout << "nhap so luong nguoi muon them: " << endl;
        cin >> n;
        for(int i = 0; i < n; i++) {
            string hoten, ngaysinh, diachi, bophan;
            cout << "nhap ten nhan vien :    " << endl;
            cin.ignore();
            getline(cin, hoten);
            cout << "nhap ngay sinh :    " << endl;
            getline(cin, ngaysinh);
            cout << "nhap dia chi :    " << endl;
            getline(cin, diachi);
            cout << "nhap bo phan lam viec :    " << endl;
            getline(cin, bophan);
            Employee new_emp(hoten, ngaysinh, diachi, bophan);
            employees.push_back(new_emp);
        }
    }
   
 	void remove_multiple(vector<Employee>& employees) {
        int n;
        cout << "nhap so luong nguoi muon xoa: " << endl;
        cin >> n;
        int vitri;
        for(int i = 0; i < n; i++) {
            string hoten, ngaysinh, diachi, bophan;
            cout << "nhap ten nhan vien : " << endl;
            cin.ignore();
            getline(cin, hoten);
            cout << "nhap ngay sinh : " << endl;
            getline(cin, ngaysinh);
            cout << "nhap dia chi : " << endl;
            getline(cin, diachi);
            cout << "nhap bo phan lam viec : " << endl;
            getline(cin, bophan);
            Employee new_emp(hoten, ngaysinh, diachi, bophan);
            for (int i = 0; i < employees.size(); i++) {
            	if(employees[i].get_name()==hoten&&employees[i].get_birth()==ngaysinh&&employees[i].get_address()==diachi&&employees[i].get_department()==bophan){
            		vitri=i;
				}
        	}
			employees.erase(employees.begin()+vitri);
        }
    } 
};

	class Salary: public Employee{
		public:
			void salary(vector<Employee>& employees)
			{
				float luong;
				for (int i = 0; i < employees.size(); i++){
					if(employees[i].get_worked()<=2){
						if(employees[i].get_department()=="IT"||employees[i].get_department()=="Electric")
						{
							luong = 8000000-347826*employees[i].get_absent()+employees[i].get_overtime();
							employees[i].set_Salary(luong);
						}
						else{
							luong=7000000-347826*employees[i].get_absent()+employees[i].get_overtime();
							employees[i].set_Salary(luong);
						}
					}
					if(employees[i].get_worked()>2&&employees[i].get_worked()<=4){
						if(employees[i].get_department()=="IT"||employees[i].get_department()=="Electric")
						{
							luong = 18000000-347826*employees[i].get_absent()+employees[i].get_overtime();
							employees[i].set_Salary(luong);
						}
						else{
							luong=16000000-347826*employees[i].get_absent()+employees[i].get_overtime();
							employees[i].set_Salary(luong);
						}
					}
					if(employees[i].get_worked()>4&&employees[i].get_worked()<=5.5){
						if(employees[i].get_department()=="IT"||employees[i].get_department()=="Electric")
						{
							luong = 30000000-347826*employees[i].get_absent()+employees[i].get_overtime();
							employees[i].set_Salary(luong);
						}
						else{
							luong=28000000-347826*employees[i].get_absent()+employees[i].get_overtime();
							employees[i].set_Salary(luong);
						}
					}
				}
			}
	};
	int main() {
    vector<Employee> employees;
    Admin A("1","1");
    Salary S;
    int choice;
    employees.push_back(Employee("phi", "03/12/2002", "123 Main St", "IT",5,1,12));
    employees.push_back(Employee("khanh", "12/03/2002", "456 Second St", "Electric",5,2,11));
    employees.push_back(Employee("nhi", "08/01/2002", "191 Third St", "Human Resource",5,1.5,11));
    employees.push_back(Employee("Binh", "07/07/2002", "789 Fourth St", "Manager",5,3,12));
    employees.push_back(Employee("Nguyen", "09/09/2002", "321 Fifth St", "IT", 4, 2, 12));
	employees.push_back(Employee("Minh", "11/11/2002", "654 Sixth St", "Electric", 4.5, 1, 11));
	employees.push_back(Employee("Linh", "05/05/2002", "987 Seventh St", "Human Resource", 4, 2.5, 11));
	employees.push_back(Employee("Trung", "02/02/2002", "741 Eighth St", "Manager", 4.5, 3, 12));
	employees.push_back(Employee("Hoa", "10/10/2002", "852 Ninth St", "IT", 3, 1.5, 12));
	employees.push_back(Employee("Nam", "04/04/2002", "369 Tenth St", "Electric", 4, 2, 11));
	employees.push_back(Employee("An", "06/06/2002", "258 Eleventh St", "Human Resource", 3.5, 1.5, 11));
	employees.push_back(Employee("Quan", "01/01/2002", "147 Twelfth St", "Manager", 4, 3, 12));
	employees.push_back(Employee("Tuan", "03/03/2002", "963 Thirteenth St", "IT", 1, 1, 12));
	employees.push_back(Employee("Mai", "08/08/2002", "579 Fourteenth St", "Electric", 2, 2, 11));
	employees.push_back(Employee("Hieu", "09/09/2002", "321 Fifth St", "IT", 2, 2, 12));
	employees.push_back(Employee("Tien", "11/11/2002", "654 Sixth St", "Electric", 4.5, 1, 11));
	employees.push_back(Employee("Lan", "05/05/2002", "987 Seventh St", "Human Resource", 1, 2.5, 11));
	employees.push_back(Employee("Thang", "02/02/2002", "741 Eighth St", "Manager", 1, 3, 12));
	employees.push_back(Employee("Thuy", "10/10/2002", "852 Ninth St", "IT", 2.5, 1.5, 12));
	employees.push_back(Employee("Khoa", "04/04/2002", "369 Tenth St", "Electric", 3, 2, 11));
	employees.push_back(Employee("Phuong", "06/06/2002", "258 Eleventh St", "Human Resource", 2.5, 1.5, 11));
	employees.push_back(Employee("Duc", "01/01/2002", "147 Twelfth St", "Manager", 1, 3, 12));
	employees.push_back(Employee("Thu", "03/03/2002", "963 Thirteenth St", "IT", 2, 1, 12));
	employees.push_back(Employee("Van", "08/08/2002", "579 Fourteenth St", "Electric", 1, 2, 11));
	
	//Khoi tao ID cho toan nhan vien
	Employee::Identity(employees);
	//tinh tien luong cho toan bo nhan vien
	for(int i=0;i<1;i++){
        S.salary(employees);        		
	}
    while(true) {
    	cout<<"     Chi Co Admin moi truy cap "<<endl;
        cout << " An phim 1 de hien thi thong tin toan bo nhan vien " << endl;
        cout << " An phim 2 de them nhan vien " << endl;
        cout << " An phim 3 de xoa nhan vien " << endl;
        
        cout<<"     Nhan vien truy cap "<<endl;
        cout<<" An phim 4 de xem thong tin ban than va tien luong "<<endl;
        cout<<endl;
        cin >> choice;	
        string taikhoan;
        string matkhau;
        
        switch(choice) {
            case 1:
            	cin.ignore();
            	cout<<"nhap tai khoan admin: ";
            	getline(cin,taikhoan);
            	cout<<"nhap password: ";
            	getline(cin,matkhau);
            	if(taikhoan==A.get_id() && matkhau==A.get_password()){
            		Employee::display_all(employees);
				}
				else{
					cout<<"nhap sai thong tin"<<endl;
				}
                
                break;
            case 2:
            	cin.ignore();
            	cout<<"nhap tai khoan admin: ";
            	getline(cin,taikhoan);
            	cout<<"nhap password: ";
            	getline(cin,matkhau);
            	if(taikhoan==A.get_id() && matkhau==A.get_password()){
            		A.add_multiple(employees);
				}
				else{
					cout<<"nhap sai thong tin"<<endl;
				}
				taikhoan="";
				matkhau="";
                break;
            case 3:
            	cin.ignore();
            	cout<<"nhap tai khoan admin: ";
            	getline(cin,taikhoan);
            	cout<<"nhap password: ";
            	getline(cin,matkhau);
            	if(taikhoan==A.get_id() && matkhau==A.get_password()){
            		A.remove_multiple(employees);
				}
				else{
					cout<<"nhap sai thong tin"<<endl;
				}
				taikhoan="";
				matkhau="";
                
                break;
            case 4:
					cin.ignore();
            	
					for(int i=0;i<1;i++){
            		Employee::display_find_personal(employees);
            		
				}
				break;
            default:
                cout << "Chuc nang khong hop le \n";
                break;
        }
        
        cout << endl;
    }

    return 0;
}

