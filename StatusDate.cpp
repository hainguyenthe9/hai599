#include <StatusDate.h>
#include <Helpper.h>
#include <fstream>
#include <iostream>
void StatusDate ::read(vector<Employee*> list){
    cout<< "nhap id nhan vien muon diem danh" <<endl;
    string idNV;
    cin >> idNV;
    while (Helpper::checkId(list, idNV) == 1) {
        cout << "khong co nhan vien, xin nhap lai:  " << endl;
        cin >>idNV;

    }


    // mo file csv nhan viên điểm danh
    ifstream ifs("C:\\Users\\New folder\\fileSave\\"+idNV+".csv", ios::in);


    // mở đọc file để check xem có ngày trùng không nếu trùng thì thay đổi trạng thái điểm danh thôi
//    int n=Helpper ::numberLine(); // lấy ra số dòng
//    for (int i=0 ; i < n ; i++){
//        char lines[500];
//        fflush(stdin);
//        ifs.getline(lines,500);
//        string str = lines;
//        vector<string> v = Helpper::split (str, ',');

//    }




    cout<< "nhap ngay nhan vien muon diem danh" <<endl;
    string date;
    cin >> date;
    while (Helpper::checkDateOfBirth(date) == 0) {
        cout << "Ngay thang nam sinh khong hop le, vui long nhap lai:" << endl;
        cin>> date;
    }

    cout<< "nhap trang thai nhan vien muon diem danh" <<endl;
    string status;
    cin >> status;
    while(Helpper::checkStatus(status) ==0){
        cout<<"dinh dang sai , xin nhap lai "<<endl;
        cin >> status;
    }



    // ghi vào
    fstream output("C:\\Users\\New folder\\fileSave\\"+idNV+".csv", ios::app);
    output << date<<","<<status<<endl;

    // đóng đọc file
    output.close();
    ifs.close();


}
