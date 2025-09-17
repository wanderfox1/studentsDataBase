#include <iostream>
#include <vector>
#include <string>

struct Student
{
    int id;
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student> &database)
{
    Student student;
    student.id = database.size() + 1;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных с ID: " << student.id << "\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student> &database)
{
    std::cout << "Список студентов:\n";
    for (const Student &student : database)
    {
        std::cout << "ID: " << student.id << "\n";
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Функция для поиска студента по ID
int findStudentById(const std::vector<Student> &database, int id)
{
    for (int i = 0; i < database.size(); i++)
    {
        if (database[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

// Функция для вывода информации о студенте по ID
void displayStudentById(const std::vector<Student> &database)
{
    int id;
    std::cout << "Введите ID студента: ";
    std::cin >> id;

    int index = findStudentById(database, id);
    if (index != -1)
    {
        const Student &student = database[index];
        std::cout << "Найден студент:\n";
        std::cout << "ID: " << student.id << "\n";
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
    else
    {
        std::cout << "Студент с ID " << id << " не найден.\n";
    }
}

int main()
{
    std::vector<Student> database;

    int choice;
    do
    {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Удалить студента\n";
        std::cout << "4. Найти студента по ID\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent(database);
            break;
        case 2:
            displayStudents(database);
            break;
        case 4:
            displayStudentById(database);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
