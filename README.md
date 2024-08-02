
# School Management System

## Overview

The **School Management System** is a console-based application written in C for managing student and course data. It allows for adding and managing students, courses, and schools, calculating grades, and displaying detailed information.

## Features

- Add and manage students and courses
- Calculate and display average grades
- Display detailed information about students and courses
- Identify students who passed or failed
- List courses with the highest average grades
- Efficient memory management with dynamic allocation

## Installation

1. Clone the repository:
   ```
   git clone https://github.com/olshevskaa/school-management-system.git
   ```
2. Navigate to the project directory:
   ```
   cd school-management-system
   ```
3. Compile the source code:
   ```
   gcc Source.c student.c course.c school.c -o SchoolManagementSystem
   ```

## Usage

Run the compiled program:
```
./SchoolManagementSystem
```

Follow the on-screen instructions to manage students, courses, and grades.

## Project Structure

- `school_management.h`: Header file with function declarations and data structures
- `main.c`: Main program file
- `student.c`: Implementation of student-related functions
- `course.c`: Implementation of course-related functions
- `school.c`: Implementation of school-related functions
