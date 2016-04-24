class student {
public:
    int   student_id;
    float gpa;
    char  name[30];
    char  college[20];
    enum  {fresh, soph, junior, senior} year;
    char  major[10];
    void  print();
};

class grad_student : public student {
public:
    enum {ta, ra, fellowship, other} support;
    char dept[10];
    char thesis[80];
    void print();
};

int main() {

    return 0;
}

