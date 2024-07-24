#include <stdio.h>
#include <stdlib.h>

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

void updateAverageGrade(Course* course) {
  double totalGrades = 0;
  for (int i = 0; i < course->totalStudents; i++)
  {
    totalGrades += course->studentList[i].grade;
  }

  course->averageGrade = totalGrades / course->totalStudents;
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

void printStudentDetails(Student* student) {
  printf("Student name: %s\n", student->name);
  printf("Student grade: %u\n", student->grade);
  printf("Student ID: %u\n", student->id);
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

void deleteSchool(School* school) {
  for (int i = 0; i < school->totalCourses; i++)
  {
    Course* course = &(school->courses[i]);
    free(course->studentList);
  }

  free(school->totalCourses);
  free(school);
}

int main() {
  School* mySchool = createSchool();
  printCourseDetails(&(mySchool->courses[0]));
  printCoursesWithPassAverageGrade(mySchool, 70);
  printStudentWhoPassed(&(mySchool->courses[0]), 70);
  return 0;
}