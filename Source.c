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
  unsigned int totalCourses;
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
  scanf("%u", newStudent->id);

  return newStudent;
}

Course* createCourse() {
  Course* newCourse = (Course*)malloc(sizeof(Course));
  if(newCourse == NULL) {
    printf("Something went wrong");
    exit(1);
  }

  printf("Enter course name: ");
  scanf("%s", newCourse->name);

  printf("Enter number of students: ");
  scanf("%u", newCourse->totalStudents);

  newCourse->studentList = (Student*)malloc(sizeof(Student) * newCourse->totalStudents);
  if(newCourse->studentList == NULL) {
    printf("Something went wrong");
    exit(1);
  }

  for(int i = 0; i < newCourse->totalStudents; i++) {
    printf("Enter details for student #%d\n", i + 1);
    Student* newStudent = createStudent();
    newCourse->studentList[i] = *newStudent;
    free(newStudent);
  }
}

School* createSchool() {
  School* newSchool = (School*)malloc(sizeof(School));
  if(newSchool == NULL) {
    printf("Something went wrong");
    exit(1);
  }

  printf("Enter school name: ");
  scanf("%s", newSchool->name);

  printf("Enter number of courses: ");
  scanf("%u", newSchool->totalCourses);

  newSchool->courses = (Course*)malloc(sizeof(Course) * newSchool->totalCourses);
  if(newSchool->courses == NULL) {
    printf("Something went wrong");
    exit(1);
  }

  for(int i = 0; i < newSchool->totalCourses; i++) {
    printf("Enter details for course #%d\n", i + 1);
    Course* newCourse = createCourse();
    newSchool->courses[i] = *newCourse;
    free(newCourse);
  }
}

int main() {
  return 0;
}