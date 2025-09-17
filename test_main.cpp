#include <cassert>
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

int findStudentById(const std::vector<Student> &database, int id)
{
  for (size_t i = 0; i < database.size(); i++)
  {
    if (database[i].id == id)
      return static_cast<int>(i);
  }
  return -1;
}

void testAddStudent()
{
  std::vector<Student> db;
  Student s1 = {1, "Alex", 20, "CS", 4.5};
  db.push_back(s1);

  assert(db.size() == 1);
  assert(db[0].name == "Alex");
  assert(db[0].gpa == 4.5);
  std::cout << "testAddStudent passed!\n";
}

void testFindStudentById()
{
  std::vector<Student> db = {
      {1, "Alex", 20, "CS", 4.5},
      {2, "Maria", 21, "Math", 4.8}};

  int index = findStudentById(db, 2);
  assert(index == 1);
  assert(db[index].name == "Maria");
  std::cout << "testFindStudentById passed!\n";
}

void testDeleteStudent()
{
  std::vector<Student> db = {
      {1, "Alex", 20, "CS", 4.5},
      {2, "Maria", 21, "Math", 4.8}};

  int index = findStudentById(db, 1);
  assert(index == 0);
  db.erase(db.begin() + index);

  assert(db.size() == 1);
  assert(db[0].id == 2);
  std::cout << "testDeleteStudent passed!\n";
}

void testNotFoundStudent()
{
  std::vector<Student> db = {
      {1, "Alex", 20, "CS", 4.5}};

  int index = findStudentById(db, 99);
  assert(index == -1);
  std::cout << "testNotFoundStudent passed!\n";
}

void testMultipleStudents()
{
  std::vector<Student> db;
  db.push_back({1, "Alex", 20, "CS", 4.5});
  db.push_back({2, "Maria", 21, "Math", 4.8});
  db.push_back({3, "John", 22, "Physics", 3.9});

  assert(db.size() == 3);
  assert(db[2].name == "John");
  assert(db[1].major == "Math");
  std::cout << "testMultipleStudents passed!\n";
}

int main()
{
  testAddStudent();
  testFindStudentById();
  testDeleteStudent();
  testNotFoundStudent();
  testMultipleStudents();

  std::cout << "All tests passed successfully!\n";
  return 0;
}