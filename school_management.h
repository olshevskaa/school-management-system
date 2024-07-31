#include <stdbool.h>

#ifndef SCHOOL_MANAGEMENT_H
#define SCHOOL_MANAGEMENT_H

typedef struct student {
  char name[20];
  unsigned int id;
  unsigned int grade;
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

Student* createStudent();
Course* createCourse();
School* createSchool();

void updateAverageGrade(Course* course);
void upgradeStudentGrade(Course* course, unsigned int studentID, unsigned int newGrade);
void updateCourseName(Course* course, char* newName);
void deleteSchool(School* school);

bool checkIfCourseIsInSchool(School* school, char* courseName);

void printStudentDetails(Student* student);
void printCourseDetails(Course* course);
void printSchoolDetails(School* school);

void printStudentCourses(School* school, int studentID);
void printStudentsWhoFailed(Course* course, int cutOffGrade);
void printStudentWhoPassed(Course* course, int cutOffGrade);
void printCoursesWithPassAverageGrade(School* school, double cutOffGrade);
void printCoursesWithFailAverageGrade(School* school, double cutOffGrade);
void printAverageGradeBetweenAllCourses(School* school);
void printCourseWithHighestGrade(School* school);

#endif