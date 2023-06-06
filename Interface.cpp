
#include "Interface.h"
#include <fstream>
void Interface::addStudent(const Student& student) {
    students.push_back(student);
}

void Interface::removeStudent(int studentId) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == studentId) {
            students.erase(it);
            break;
        }
    }
}

void Interface::modifyStudent(int studentId) {
    for (auto& student : students) {
        if (student.getId() == studentId) {
            std::string surname, firstName, dateOfBirth, phone, faculty, group;
            int course;

            std::cout << "Enter the updated data for the student:" << std::endl;
            std::cout << "Surname: ";
            std::getline(std::cin >> std::ws, surname);

            std::cout << "First Name: ";
            std::getline(std::cin >> std::ws, firstName);

            std::cout << "Date of Birth (YYYY-MM-DD): ";
            std::cin >> dateOfBirth;

            std::cout << "Phone: ";
            std::cin >> phone;

            std::cout << "Faculty: ";
            std::getline(std::cin >> std::ws, faculty);

            std::cout << "Course: ";
            std::cin >> course;

            std::cout << "Group: ";
            std::cin >> group;

            student.setSurname(surname);
            student.setFirstName(firstName);
            student.setDateOfBirth(dateOfBirth);
            student.setPhone(phone);
            student.setFaculty(faculty);
            student.setCourse(course);
            student.setGroup(group);

            std::cout << "Student data updated successfully." << std::endl;
            return;
        }
    }

    std::cout << "Student with ID " << studentId << " not found." << std::endl;
}

void Interface::displayAllStudents() const {
    std::cout << "All Students:" << std::endl;
    for (const Student& student : students) {
        std::cout << student << std::endl;
    }
}

void Interface::displayStudentsByFaculty(const std::string& faculty) const {
    std::cout << "Students of the " << faculty << " faculty:" << std::endl;
    for (const Student& student : students) {
        if (student.getFaculty() == faculty)
            std::cout << student << std::endl;
    }
}

void Interface::displayStudentsByFacultyAndCourse(const std::string& faculty, int course) const {
    std::cout << "Students of the " << faculty << " faculty and course " << course << ":" << std::endl;
    for (const Student& student : students) {
        if (student.getFaculty() == faculty && student.getCourse() == course)
            std::cout << student << std::endl;
    }
}

void Interface::displayStudentsBornAfterYear(int year) const {
    std::cout << "Students born after " << year << ":" << std::endl;
    for (const Student& student : students) {
        int studentYear = std::stoi(student.getDateOfBirth().substr(student.getDateOfBirth().length() - 4));
        if (studentYear > year)
            std::cout << student << std::endl;
    }
}

void Interface::displayStudentsByGroup(const std::string& group) const {
    std::cout << "Students of group " << group << ":" << std::endl;
    for (const Student& student : students) {
        if (student.getGroup() == group)
            std::cout << student << std::endl;
    }
}


void Interface::encryptAndWriteToFile(const std::string& filename) const {
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        std::string encryptionKey = "k"; // Encryption key

        for (const Student& student : students) {
            // Encrypt student data using XOR encryption
            std::string encryptedData = student.toString(); // Assuming toString() returns a string representation of the student data

            // Perform XOR encryption
            for (size_t i = 0; i < encryptedData.length(); ++i) {
                encryptedData[i] ^= encryptionKey[i % encryptionKey.length()];
            }

            // Write encrypted data to file
            outfile << encryptedData << std::endl;
        }
        outfile.close();
    }
}

