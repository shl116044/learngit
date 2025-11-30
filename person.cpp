#include <iostream>
#include <string>
//123456789
class Person {
protected:
    int id;
    std::string name;
public:
    Person(int i, std::string n) : id(i), name(n) {}
    virtual void display() = 0;
};

class Student : public Person {
    int grade;
public:
    Student(int i, std::string n, int g);
    void display() override;
};

class Teacher : public Person {
    std::string subject;
public:
    Teacher(int i, std::string n, std::string s);
    void display() override;
    void assignGrade(Student& student, int grade);
};

// 实现
Student::Student(int i, std::string n, int g) : Person(i, n), grade(g) {}

void Student::display() {
    std::cout << "学生ID: " << id << ", 姓名: " << name 
              << ", 年级: " << grade << std::endl;
}

Teacher::Teacher(int i, std::string n, std::string s) 
    : Person(i, n), subject(s) {}

void Teacher::display() {
    std::cout << "教师ID: " << id << ", 姓名: " << name 
              << ", 科目: " << subject << std::endl;
}

void Teacher::assignGrade(Student& student, int newGrade) {
    std::cout << name << "老师正在为" << student.name 
              << "分配成绩: " << newGrade << std::endl;
}