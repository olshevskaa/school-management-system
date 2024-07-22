#include <stdio.h>
#include <stdlib.h>>

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

Student* createStudent() {
  Student* newStudent = (Student*)malloc(sizeof(Student));
  if(newStudent == NULL) {
    printf("Something went wrong");
    exit(1);
  }

  printf("Enter student name: ");
  scanf("%s", newStudent->name);

  printf("Enter student id: ");
  scanf("%s", newStudent->id);

  return newStudent;
}

int main() {
  return 0;
}