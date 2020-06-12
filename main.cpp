#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Employee.h>
#include <Helpper.h>
#include <iostream>
#include <cstring>


#include <StatusDate.h>


using namespace std;


int main()
{
    vector<Employee*> list;


    Employee *employee;


    ifstream ifs("C:\\Users\\New folder\\ImportData.csv", ios::in);
    int n;
    string abc;
    n=Helpper ::numberLine();
    n=n-1;
    ifs >> abc;
    char ss[5];
    ifs.getline(ss, 3);// loai bo xuong dong



    int line=1 ;
    int *linePtr=&line;


    for (int i=0 ; i < n ; i++){
        employee = new Employee();
        employee->read(ifs ,list ,linePtr);
        list.push_back(employee);
    }


    int choiceSearch;
    int choice;
    do {
        cout <<"===========================================" << endl;
        cout <<"= 1-Nhap nhan vien                        =" << endl;
        cout <<"= 2-Tim nhan vien theo ma                 =" << endl;
        cout <<"= Chon khac de thoat                      =" << endl;
        cout <<"===========================================" << endl;
        cout << "Chon chuc nang (1-2 hoac khac):" << endl;
        cout << "Moi ban nhap lai lua chon = ";
        cin >> choice;

        if (choice == 1) {
            string a = "yes";
            while (a == "yes") {
                employee = new Employee();
                employee->enterEmployee(list,"C:\\Users\\New folder\\ImportData.csv");
                list.push_back(employee);


                cout << "Ban muon nhap tiep khong, an yes; neu muon thoat an phim bat ky \n" << endl;
                cin >> a;
            }
        }

        else if(choice == 2){


        employee->searchEmployee(list);

        }
        else if (choice ==3){

            if(list.size() == 0 ){
                cout << "Danh sach khong co nhan vien nao";
            }else{
                for (int i = 0; i < list.size(); i++ ){
                    list[i]->printEmployee();


                }
            }
        }

        else if (choice ==4) {
            for (int i=0 ; i < list.size(); i++) {
                std::ofstream o( "C:\\Users\\New folder\\fileSave\\"+list.at(i)->getId()+".csv");
            }

        }
        else if(choice ==5){
            StatusDate::read(list);

        }
        else{
            break;
        }

    }

    while (true);

    ifs.close();
    return 0;
}
