#include <iostream>
#include <string.h>

typedef enum _year{
    fresh, 
    soph,
    junior,
    senior
} year;

typedef enum _support{
    ta, 
    ra, 
    fellowship, 
    other
} support;

class student {
protected:
    int   student_id;
    float gpa;
public:
    student(int id, float g) { student_id = id; gpa = g; strcpy(name, ""); strcpy(college, ""); strcpy(major, ""); }
    char  name[30];
    char  college[20];
    year  yr;
    char  major[10];
    void  print();
    void read();
};

class grad_student : public student {
    support s;
public:
    grad_student(support x, int id, float g) : student(id, g) { s = x; }
    char dept[10];
    char thesis[80];
    void print();
    void read();
};

void student::print() {
    std::cout << "name=" << name << "; id=" << student_id << "; college=" << college << "; major=" << major << "; year=" << yr << "; gpa=" << gpa << "\n";
}

void grad_student::print() {
    student::print();
    std::cout << "dept=" << dept << "; s=" << s << "; thesis=" << thesis << "\n";
}

int main() {
    student       s1(100, 87.6);
    student       s2(101, 67.0);
    student*      ps;
    grad_student  gs1(ta, 200, 88.8);
    grad_student* pgs;

    ps = &s1;
    strcpy(ps->name, "Mae Pohl");
    ps->print();
    ps = pgs = &gs1;
    strcpy(ps->name, "Morris Pohl");
    strcpy(pgs->dept, "pharmacy");
    strcpy(pgs->thesis, "Pharmacies as retail outlets.");
    ps->print();
    pgs->print();

    return 0;
}

