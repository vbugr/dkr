
#include "Student.h"

// Constructors
Student::Student() {
    // Initialize member variables to default values
    id = 0;
    course = 0;
}

Student::Student(int id, const std::string& surname, const std::string& firstName, const std::string& dateOfBirth,
        const std::string& phone, const std::string& faculty, int course, const std::string& group) {
    this->id = id;
    this->surname = surname;
    this->firstName = firstName;
    this->dateOfBirth = dateOfBirth;
    this->phone = phone;
    this->faculty = faculty;
    this->course = course;
    this->group = group;
}

// Getter methods
int Student::getId() const {
    return id;
}

std::string Student::getSurname() const {
    return surname;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getDateOfBirth() const {
    return dateOfBirth;
}

std::string Student::getPhone() const {
    return phone;
}

std::string Student::getFaculty() const {
    return faculty;
}

int Student::getCourse() const {
    return course;
}

std::string Student::getGroup() const {
    return group;
}

// Setter methods
void Student::setId(int id) {
    this->id = id;
}

void Student::setSurname(const std::string& surname) {
    this->surname = surname;
}

void Student::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Student::setDateOfBirth(const std::string& dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

void Student::setPhone(const std::string& phone) {
    this->phone = phone;
}

void Student::setFaculty(const std::string& faculty) {
    this->faculty = faculty;
}

void Student::setCourse(int course) {
    this->course = course;
}

void Student::setGroup(const std::string& group) {
    this->group = group;
}

// Other methods
std::string Student::toString() const {
    std::string info = "ID: " + std::to_string(id) + "\n";
    info += "Surname: " + surname + "\n";
    info += "First Name: " + firstName + "\n";
    info += "Date of Birth: " + dateOfBirth + "\n";
    info += "Phone: " + phone + "\n";
    info += "Faculty: " + faculty + "\n";
    info += "Course: " + std::to_string(course) + "\n";
    info += "Group: " + group + "\n";
    return info;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.toString();
    return os;
}
