
#include "Interface.h"
#include "Logger.h"

int main() {

    Interface interface;
    Logger logger("log.txt");
    // Create some student objects
    Student student1(1, "Doe", "John", "1995-05-10", "123456789", "Engineering", 2, "A");
    Student student2(2, "Smith", "Alice", "1996-07-15", "987654321", "Science", 1, "B");
    Student student3(3, "Johnson", "Robert", "1994-03-20", "456789123", "Engineering", 3, "A");
    Student student4(4, "Williams", "Emily", "1997-09-25", "321654987", "Arts", 2, "C");

    logger.log("add prototypes");

    // Add students to the interface
    interface.addStudent(student1);
    interface.addStudent(student2);
    interface.addStudent(student3);
    interface.addStudent(student4);
while(1){
    int choice;
    std::string faculty, group, filename;
    int course, year;
    int studentId;

    std::cout << "Student Management System" << std::endl;
    std::cout << "1. Add student" << std::endl;
    std::cout << "2. Remove student" << std::endl;
    std::cout << "3. Modify student" << std::endl;
    std::cout << "4. Display all students" << std::endl;
    std::cout << "5. Display students by faculty" << std::endl;
    std::cout << "6. Display students by faculty and course" << std::endl;
    std::cout << "7. Display students born after a year" << std::endl;
    std::cout << "8. Display students by group" << std::endl;
    std::cout << "9. Save students to file" << std::endl;

    std::cout << "Enter your choice (1-9): ";
    logger.log("print menu");
    std::cin >> choice;
    switch (choice) {
        case 1: {
            logger.log("1. Add student");
            int id;
            std::string surname, firstName, dateOfBirth, phone, faculty, group;
            int course;
            std::cout << "Enter student ID: ";
            std::cin >> id;
            std::cout << "Enter surname: ";
            std::cin.ignore();
            std::getline(std::cin, surname);
            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter date of birth (yyyy-mm-dd): ";
            std::getline(std::cin, dateOfBirth);
            std::cout << "Enter phone: ";
            std::getline(std::cin, phone);
            std::cout << "Enter faculty: ";
            std::getline(std::cin, faculty);
            std::cout << "Enter course: ";
            std::cin >> course;
            std::cout << "Enter group: ";
            std::cin.ignore();
            std::getline(std::cin, group);

            Student newStudent(id, surname, firstName, dateOfBirth, phone, faculty, course, group);
            interface.addStudent(newStudent);
            std::cout << "Student added successfully." << std::endl;
            break;
        }
        case 2:
            logger.log("2. Remove student");
            std::cout << "Enter student ID to remove: ";
            std::cin >> studentId;
            interface.removeStudent(studentId);
            break;
        case 3:
            logger.log("3. Modify student");
            std::cout << "Enter student ID to modify: ";
            std::cin >> studentId;
            interface.modifyStudent(studentId);
            break;
        case 4:
            logger.log("4. Display all students");
            interface.displayAllStudents();
            break;
        case 5:
            logger.log("5. Display students by faculty");
            std::cout << "Enter faculty: ";
            std::cin.ignore();
            std::getline(std::cin, faculty);
            interface.displayStudentsByFaculty(faculty);
            break;
        case 6:
            logger.log("6. Display students by faculty and course");
            std::cout << "Enter faculty: ";
            std::cin.ignore();
            std::getline(std::cin, faculty);
            std::cout << "Enter course: ";
            std::cin >> course;
            interface.displayStudentsByFacultyAndCourse(faculty, course);
            break;
        case 7:
            logger.log("7. Display students born after year");
            std::cout << "Enter year: ";
            std::cin >> year;
            interface.displayStudentsBornAfterYear(year);
            break;
        case 8:
            logger.log("8. Display students by group");
            std::cout << "Enter group: ";
            std::cin.ignore();
            std::getline(std::cin, group);
            interface.displayStudentsByGroup(group);
            break;
        case 9:
            logger.log("9. write to file");
            std::cout << "Enter filename: ";
            std::cin.ignore();
            std::getline(std::cin, filename);
            logger.log("filename:"+filename);
            interface.encryptAndWriteToFile(filename);
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
    }
    std::cout << std::endl<<std::endl<<"-------------------------------------------------------"
    <<std::endl;//GAP

}

    return 0;
}
