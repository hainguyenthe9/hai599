#include "Employee.h"
#include "Helpper.h"

#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>


Employee::Employee(const std::string &id,
                   const std::string &name,
                   const std::string &dateOfBirth,
                   const std::string &address,
                   const std::string &department)
    : _id(id),
      _name(name),
      _dateOfBirth(dateOfBirth),
      _address(address),
      _department(department)
{

}
//get
const std::string &Employee:: getId() const{
    return this->_id;
}
const std::string &Employee:: getName() const{
    return this->_name;
}
const std::string &Employee:: getAddress() const{
    return this->_address;
}
const std::string &Employee:: getDateOfBirth() const{
    return this->_dateOfBirth;
}
const std::string &Employee:: getDepartment() const{
    return this->_department;
}
//set
void Employee::setId(const std::string &id){
    this->_id = id;
}
void Employee::setName(const std::string &name){
    this->_name = name;
}
void Employee::setDateOfBirth(const std::string &dateOfBirth){
    this->_dateOfBirth = dateOfBirth;
}
void Employee::setAddress(const std::string &address){
    this->_address = address;
}
void Employee::setDepartment(const std::string &department){
    this->_department = department;
}

void Employee::enterEmployee(vector<Employee*> list ,string url){
    fstream output(url, ios::app);;
    cout << "" << endl;
    cin.ignore();
    cout << "ID : ";
    getline(cin,_id);
    while (Helpper::checkId(list, _id) == 0) {
        cout << "trung id, xin nhap lai:  " << endl;
        getline(cin, _id);


    }
    cout << "Ten Nhan Vien: ";
    getline(cin, _name);
    cout << "Ngay Sinh Nhan Vien: ";
    getline(cin, _dateOfBirth);
    while (Helpper::checkDateOfBirth(_dateOfBirth) == 0) {
        cout << "Ngay thang nam sinh khong hop le, vui long nhap lai:" << endl;
        getline(cin, _dateOfBirth);
    }
    cout << "Dia chi Nhan vien:  ";
    getline(cin, _address);

    while (_address == ""){
        cout << "Khong duoc de trong muc nay vui long nhap lai !  "<< endl;

        getline(cin, _address);
    }


    cout << "Phong ban Nhan vien: ";
    getline(cin,_department);
    while (_department == ""){
        cout << "Khong duoc de trong muc nay vui long nhap lai !  \n"<< endl;
        getline(cin, _department);
    }

    output <<_id <<","<<_name<<","<<_dateOfBirth<<","<<_address<<","<<_department<<endl;

    output.close();
    fflush(stdin);
}

void Employee::printEmployee(){
    cout << "" << endl;
    cout << "Id Nhan Vien: " << _id << endl;
    cout << "Ten Nhan Vien: " << _name << endl;
    cout << "Ngay Sinh Nhan Vien: " << _dateOfBirth << endl;
    cout << "Dia Chi Nhan Vien: " << _address << endl;
    cout << "Phong Ban Nhan Vien: " << _department << endl;
    cout << "" <<endl;
    //cout << _id <<"   "<<_name<<"   "<<_dateOfBirth<<"   "<<_address<<"   "<<_department << endl;

}



void Employee::read(ifstream &in ,vector<Employee*> list ,int *linePtr){
    char lines[500];
    //    char id[10], na[40], birth[20], ad[20], de[20];
    fflush(stdin);
    in.getline(lines,500);
    *linePtr=*linePtr+1;


    //    in.getline(id, 40);
    //    in.getline(na, 40);
    //    in.getline(birth, 20);
    //    in.getline(ad, 20);
    //    in.getline(de, 20);
    string str = lines;
    vector<string> v = Helpper::split (str, ',');

    if(   Helpper::checkId(list ,v.at(0))  ==0){
        //cout<< "id bi trung o dong thu "<<*line <<endl;
         cout<<"bi trung id o dong thu "<<*linePtr <<endl;

        return; // nếu bị trùng không lưu vào list nữa
    }

    if(   Helpper::checkDateOfBirth(v.at(2))  ==0){

         cout<<"Ngay sinh khong phu hop "<<*linePtr <<endl;

        return; // nếu bị trùng không lưu vào list nữa
    }

    this->setId(v.at(0));
    this->setName(v.at(1));
    this->setDateOfBirth(v.at(2));
    this->setAddress(v.at(3));
    this->setDepartment(v.at(4));

}
void Employee::write(ofstream &ofs){
    ofs	<< this->getId() << endl
        << this->getName() << endl
        <<  this->getDateOfBirth() << endl
         <<  this->getAddress() << endl
          <<  this->getDepartment() << endl;

}


void Employee::searchEmployee(vector<Employee*> list){
    // map<string,Employee> list =  Staff::addMapStaff(urlFile);
    // vector<Employee*>::iterator itr;


    int choice;


    do {
        cout << ""<< endl;
        cout <<"------- MENU SEARCH-------" <<endl;
        cout <<"1-Tim kiem theo ID           -" <<endl ;
        cout <<"2-Tim kiem theo Name         -" <<endl;
        cout <<"3-Tim kiem theo Address      -"<<endl ;
        cout <<"4-Tim kiem theo Department   -"<<endl ;
        cout <<"0-Thoat   -"<<endl ;
        cout <<"--------------------------" <<endl;
        cout << " Nhap lua chon cua ban :  " ;
        cin >> choice;
        switch (choice) {
        case 1:
        {

            string idSearch;
            cout << "=> Tim kiem theo ID  " <<endl;
            cout << "Nhap id:= " ;
            cin >> idSearch;
            int check = 0;
            for (int i = 0; i < list.size(); i++ ){
                if (list[i]->getId() == idSearch){
                    list[i]->printEmployee();
                    check = 1;
                }
            }

            if(check == 0){

                cout << "Khong co nhan vien co id = "<< idSearch << endl;

            }
            break;
        }
        case 2:
        {
            cout << "=> Tim kiem theo NAME" << endl;
            cin.ignore();
            string name;
            cout << "nhap ten:= ";
            getline(cin,name);
            int check = 0;
            for (int i = 0; i < list.size(); i++ ){
                if(Helpper::isSubstring(name,list[i]->getName()) >= 0){
                    list[i]->printEmployee();
                    check = 1;
                }
            }
            if(check == 0){

                cout << "Khong co nhan vien co name = "<< name << endl;

            }
            fflush(stdin);
            break;
        }

        case 3:
        {

            cout << "=> Tim kiem theo Adress" << endl;
            cin.ignore();
            string address;
            cout << "nhap dia chi := ";
            getline(cin,address);
            int check = 0;
            cout << "----= danh sach dia chi = "<<address <<"=----" <<endl;
            for (int i = 0; i < list.size(); i++ ){
                if(Helpper::isSubstring(address,list[i]->getAddress()) >= 0){
                    list[i]->printEmployee();
                    check = 1;
                }
            }
            if(check == 0){

                cout << "Khong co nhan vien co dia chi = "<< address << endl;

            }
            fflush(stdin);
            break;
        }

        case 4:
        {
            cout << "=> Tim kiem theo Department" <<endl;
            cin.ignore();
            string department;

            cout << "Nhap phong ban:= ";
            getline(cin,department);
            cout << department <<"-------------";
            int check = 0;
            for (int i = 0; i < list.size(); i++ ){
                if(Helpper::isSubstring(department,list[i]->getDepartment()) >= 0){
                    list[i]->printEmployee();
                    check = 1;
                }
            }
            if(check == 0){
                cout << "Khong co nhan vien co phong ban = "<< department<< endl;

            }
            fflush(stdin);
            break;
        }
        }

    } while (choice != 0);



    fflush(stdin);
    cout << "\n-----=======================-----" <<endl;

}
