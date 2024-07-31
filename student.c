#include <stdlib.h>
#include <stdio.h>

#include "school_management.h"

Student* createStudent() {
  Student* newStudent = (Student*)malloc(sizeof(Student));
  if(newStudent == NULL) {
    printf("Something went wrong");
    exit(1);
  }

  printf("Enter student name: ");
  scanf("%s", newStudent->name);

  printf("Enter student id: ");
  scanf("%u", &(newStudent->id));

  printf("Enter student grade: ");
  scanf("%u", &(newStudent->grade));

  return newStudent;
}

void upgradeStudentGrade(Course* course, unsigned int studentID, unsigned int newGrade) {
  for (int i = 0; i < course->totalStudents; i++)
  {
    if(course->studentList[i].id == studentID) {
      course->studentList[i].grade = newGrade;
      updateAverageGrade(course);
      return;
    }
  }
  printf("Student was not found");
}

void printStudentDetails(Student* student) {
  printf("Student name: %s\n", student->name);
  printf("Student grade: %u\n", student->grade);
  printf("Student ID: %u\n", student->id);
}


void printStudentCourses(School* school, int studentID) {
  printf("Courses for student with ID %d:\n", studentID);
  for(int i = 0; i < school->totalCourses; i++) {
    Course course = school->courses[i];
    for(int j = 0; j < course.totalStudents; j++) {
      if(course.studentList[j].id == studentID) {
        printf(" - %s\n", course.name);
        break;
      }
    }
  }
  printf("-------------\n");
}

void printStudentsWhoFailed(Course* course, int cutOffGrade) {
  printf("Students who failed in %s:\n");

  for (int i = 0; i < course->totalStudents; i++)
  {
    if(course->studentList[i].grade < cutOffGrade) {
      printStudentDetails(&(course->studentList[i]));
    }
  }
}

void printStudentWhoPassed(Course* course, int cutOffGrade) {
  printf("Students who passed in %s:\n");

  for (int i = 0; i < course->totalStudents; i++)
  {
    if(course->studentList[i].grade >= cutOffGrade) {
      printStudentDetails(&(course->studentList[i]));
    }
  }
}
