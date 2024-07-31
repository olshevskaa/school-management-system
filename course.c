#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "school_management.h"

Course* createCourse() {
  Course* newCourse = (Course*)malloc(sizeof(Course));
  if(newCourse == NULL) {
    printf("Something went wrong");
    exit(1);
  }

  printf("Enter course name: ");
  scanf("%s", newCourse->name);

  printf("Enter number of students: ");
  scanf("%u", &(newCourse->totalStudents));

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
  updateAverageGrade(newCourse);
  printf("-------------\n");
  return newCourse;
}

void updateAverageGrade(Course* course) {
  double totalGrades = 0;
  for (int i = 0; i < course->totalStudents; i++)
  {
    totalGrades += course->studentList[i].grade;
  }

  course->averageGrade = totalGrades / course->totalStudents;
}

void updateCourseName(Course* course, char* newName) {
  strcpy(course->name, newName);
}

bool checkIfCourseIsInSchool(School* school, char* courseName) {
  for (int i = 0; i < school->totalCourses; i++)
  {
    if(strcmp(school->courses[i].name, courseName) == 0) {
      return true;
    }
  }
  return false;
}

void printCourseDetails(Course* course) {
  printf("Course name: %s\n", course->name);
  printf("Course Average Grade: %.2lf\n", course->averageGrade);
  printf("Course Total Students: %u\n", course->totalStudents);
  for (int i = 0; i < course->totalStudents; i++)
  {
    printf("Details for student #%d:\n", i + 1);
    printStudentDetails(&(course->studentList[i]));
  }
  printf("-------------\n");
}

void printCoursesWithPassAverageGrade(School* school, double cutOffGrade) {
  printf("Courses with pass average grade:\n");

  for (int i = 0; i < school->totalCourses; i++)
  {
    if(school->courses[i].averageGrade >= cutOffGrade) {
      printCourseDetails(&(school->courses[i]));
    }
  }
}

void printCoursesWithFailAverageGrade(School* school, double cutOffGrade) {
  printf("Courses with fail average grade:\n");

  for (int i = 0; i < school->totalCourses; i++)
  {
    if(school->courses[i].averageGrade < cutOffGrade) {
      printCourseDetails(&(school->courses[i]));
    }
  }
}

void printAverageGradeBetweenAllCourses(School* school) {
  double totalGrade = 0.0;

  for (int i = 0; i < school->totalCourses; i++)
  {
    totalGrade += school->courses[i].averageGrade;
  }

  double average = totalGrade / school->totalCourses;
  printf("Average grade for all courses is %.2lf", average);
  printf("-------------\n");
}

void printCourseWithHighestGrade(School* school) {
  Course* course = NULL;

  for (int i = 0; i < school->totalCourses; i++)
  {
    if(course == NULL || school->courses[i].averageGrade > course->averageGrade) {
      course = &(school->courses[i]);
    }
  }

  printf("Course with the highest average grade:\n");
  printCourseDetails(course);
}