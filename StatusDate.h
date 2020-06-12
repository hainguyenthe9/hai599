#ifndef STATUSDATE_H
#define STATUSDATE_H
#include <iostream>
#include<vector>
#include<Employee.h>
using namespace std;
class StatusDate{
private:
    std:: string _date;
    std:: string _status;

private:
    StatusDate(
               const std::string &date,
               const std::string &status
               );

public:

    void setDate(const std::string &date);
    void setStatus(const std::string &status);
public:
    const std::string &getDate() const;
    const std::string &getStatus() const;

    static void read(vector<Employee*> list);

};



#endif // STATUSDATE_H
