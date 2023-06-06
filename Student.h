
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
private:
    int id;
    std::string surname;
    std::string firstName;
    std::string dateOfBirth;
    std::string phone;
    std::string faculty;
    int course;
    std::string group;

public:
    // Constructors
    Student();
    Student(int id, const std::string& surname, const std::string& firstName, const std::string& dateOfBirth,
            const std::string& phone, const std::string& faculty, int course, const std::string& group);

    // Getter methods
    int getId() const;
    std::string getSurname() const;
    std::string getFirstName() const;
    std::string getDateOfBirth() const;
    std::string getPhone() const;
    std::string getFaculty() const;
    int getCourse() const;
    std::string getGroup() const;

    // Setter methods
    void setId(int id);
    void setSurname(const std::string& surname);
    void setFirstName(const std::string& firstName);
    void setDateOfBirth(const std::string& dateOfBirth);
    void setPhone(const std::string& phone);
    void setFaculty(const std::string& faculty);
    void setCourse(int course);
    void setGroup(const std::string& group);

    // Other methods
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif  // STUDENT_H
