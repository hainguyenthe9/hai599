#include "Helpper.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int Helpper :: numberLine(){ // hàm đếm số dòng trong file
    ifstream f1;
    char c;
    int numchars, numlines;

    f1.open("C:\\Users\\New folder\\ImportData.csv");

    numchars = 0;
    numlines = 0;
    f1.get(c);
    while (f1) {
        while (f1 && c != '\n') {
            numchars = numchars + 1;
            f1.get(c);
        }
        numlines = numlines + 1;
        f1.get(c);
    }
    //      cout << "The file has " << numlines << " lines and "
    //        << numchars << " characters" << endl;
    return(numlines);
}
vector<string> Helpper ::split(const string &s, char delim){
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}
//hàm so sánh 2 string
int Helpper::isSubstring(string s1, string s2)
{
    std::transform(s1.begin(), s1.end(),s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(),s2.begin(), ::tolower);
    int M = s1.length();
    int N = s2.length();
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}
int Helpper:: checkId(vector<Employee*> list, string id) // trùng id trả về 0 ,không trùng trả về 1
{;
    for (int i = 0; i < list.size(); i++ ){
        if (list[i]->getId()==id){
            return 0;
        }
    }
    return 1;
}
int Helpper:: checkDateOfBirth(string dateOfBirth){
    for (int i = 0; i < dateOfBirth.length(); i++) {
        if ((dateOfBirth[i] < 47) || (dateOfBirth[i] > 57)) {
            return 0;
        }
    }
    vector<string> birth;
    while(!dateOfBirth.empty()){
        birth.push_back(dateOfBirth.substr(0, dateOfBirth.find("/")));
        if (dateOfBirth.find("/") > dateOfBirth.size()) {
            break;
        }
        dateOfBirth.erase(0, dateOfBirth.find("/") + 1);
    }
    if (birth.size() != 3) {
        return 0;
    } else {
        if ((stoi(birth[0], 0, 10) > 31) || (stoi(birth[1], 0, 10) > 12)) {
            return 0;
        } else {
            switch (stoi(birth[1], 0, 10))
            {
            case 2:
                if (stoi(birth[0], 0, 10) > 29) {
                    return 0;
                }
                if (stoi(birth[0], 0, 10) == 29){
                    if((stoi(birth[2], 0, 10) % 400 == 0) || ((stoi(birth[2], 0, 10) % 4 == 0) && (stoi(birth[2], 0, 10) % 100 != 0))) {
                        return 1;
                    }
                    return 0;
                }
                return 1;
                break;

            case 4: case 6: case 9: case 11:
                if (stoi(birth[0], 0, 10) > 30) {
                    return 0;
                }
                return 1;
                break;
            }
        }
    }
    return 1;
}
int Helpper ::checkStatus(string status){ // hop le return 1 , khong hop le return 0
    if(status =="DL"||status =="DLNN"||status =="N"||status =="NP"){
        return 1;
    }
    return 0;
}




