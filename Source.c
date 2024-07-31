#include "school_management.h"

int main() {
  School* mySchool = createSchool();
  printCourseDetails(&(mySchool->courses[0]));
  printCoursesWithPassAverageGrade(mySchool, 70);
  printStudentWhoPassed(&(mySchool->courses[0]), 70);
  return 0;
}