#include <iostream>
#include <string>
#include <vector>

// 前向声明
class Teacher;
class Student;

class Course {
    std::string courseName;
    Teacher* teacher;
    std::vector<Student*> students;
public:
    Course(std::string name, Teacher* t);
    void addStudent(Student* student);
    void showCourseInfo();
};

// 实现
Course::Course(std::string name, Teacher* t) 
    : courseName(name), teacher(t) {}

void Course::addStudent(Student* student) {
    students.push_back(student);
    std::cout << student->name << " 加入了课程: " << courseName << std::endl;
}

void Course::showCourseInfo() {
    std::cout << "\n课程: " << courseName << std::endl;
    std::cout << "授课教师: ";
    teacher->display();
    std::cout << "选课学生:" << std::endl;
    for(auto s : students) {
        s->display();
    }
}