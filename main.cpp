// 声明外部类（在其他文件中定义）
class Teacher;
class Student;
class Course;

// 声明外部函数（在其他文件中实现）
Teacher* createTeacher(int id, std::string name, std::string subject);
Student* createStudent(int id, std::string name, int grade);
Course* createCourse(std::string name, Teacher* teacher);

int main() {
    // 创建教师和学生
    Teacher* teacher1 = createTeacher(101, "张老师", "数学");
    Teacher* teacher2 = createTeacher(102, "李老师", "英语");
    
    Student* student1 = createStudent(201, "小明", 1);
    Student* student2 = createStudent(202, "小红", 1);
    Student* student3 = createStudent(203, "小刚", 2);

    // 创建课程
    Course* mathCourse = createCourse("高等数学", teacher1);
    Course* englishCourse = createCourse("大学英语", teacher2);

    // 学生选课
    mathCourse->addStudent(student1);
    mathCourse->addStudent(student2);
    englishCourse->addStudent(student1);
    englishCourse->addStudent(student3);

    // 显示信息
    teacher1->display();
    teacher2->display();
    
    mathCourse->showCourseInfo();
    englishCourse->showCourseInfo();

    // 教师分配成绩
    teacher1->assignGrade(*student1, 95);
    teacher2->assignGrade(*student3, 88);

    // 清理内存
    delete teacher1;
    delete teacher2;
    delete student1;
    delete student2;
    delete student3;
    delete mathCourse;
    delete englishCourse;

    return 0;
}

// 工厂函数实现
#include "person.cpp"
#include "course.cpp"

Teacher* createTeacher(int id, std::string name, std::string subject) {
    return new Teacher(id, name, subject);
}

Student* createStudent(int id, std::string name, int grade) {
    return new Student(id, name, grade);
}

Course* createCourse(std::string name, Teacher* teacher) {
    return new Course(name, teacher);
}