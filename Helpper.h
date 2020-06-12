#ifndef HELPPER_H
#define HELPPER_H
#include <vector>
#include <sstream>
#include <Employee.h>
using namespace std;
class Helpper{
public:
     static int numberLine(); // lấy ra số dòng trong file csv
     static vector<string> split (const string &s, char delim) ; // tách theo chuỗi theo dấu
     static int isSubstring(string s1, string s2);
     static int checkId(vector<Employee*> list, string id); // kiem tra id trung ko
     static int checkDateOfBirth(string dateOfBirth); // kiem tra ngay hop le ko
     static int checkStatus(string status);

};
#endif // HELPPER_H
