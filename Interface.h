
#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include "Student.h"

class Interface {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student);
    void removeStudent(int studentId);
    void modifyStudent(int studentId);
    void displayAllStudents() const;
    void displayStudentsByFaculty(const std::string& faculty) const;
    void displayStudentsByFacultyAndCourse(const std::string& faculty, int course) const;
    void displayStudentsBornAfterYear(int year) const;
    void displayStudentsByGroup(const std::string& group) const;
    void encryptAndWriteToFile(const std::string& filename) const;
    };

#endif  // INTERFACE_H
