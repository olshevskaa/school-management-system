#include <stdio.h>

typedef struct student {
  char name[20];
  unsigned int id;
} Student;

typedef struct course {
  char name[20];
  double averageGrade;
  unsigned int totalStudents;
  Student* studentList;
} Course;

typedef struct school {
  char name[20];
  unsigned int id;
  Course* courses;
} School;

int main() {
  return 0;
}