#include <stdlib.h>
#include <stdio.h>

#include "school_management.h"

School* createSchool() {
  School* newSchool = (School*)malloc(sizeof(School));
  if(newSchool == NULL) {
    printf("Something went wrong");
    exit(1);
  }

  printf("Enter school name: ");
  scanf("%s", newSchool->name);

  printf("Enter number of courses: ");
  scanf("%u", &(newSchool->totalCourses));

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
  printf("-------------\n");
  return newSchool;
}

void deleteSchool(School* school) {
  for (int i = 0; i < school->totalCourses; i++)
  {
    Course* course = &(school->courses[i]);
    free(course->studentList);
  }

  free(school->courses);
  free(school);
}

void printSchoolDetails(School* school) {
  for (int i = 0; i < school->totalCourses; i++)
  {
    printCourseDetails(&(school->courses[i]));
  }
}