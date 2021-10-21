#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// structures
typedef struct student {
    char* name;
    int  id;
    struct clist* courses;
} student;

typedef struct course {
    char* title;
    int  number;
    struct slist* students;
} course;

typedef struct slist {
    student* info;
    struct slist* next;
} slist;

typedef struct clist {
    course* info;
    struct clist* next;
} clist;


// prototypes
slist* add_student(slist* students, char* name, int id);
clist* add_course(clist* courses, char* title, int number);
void reg_student(slist* students, clist* courses, int id, int number);
void unreg_student(slist* students, int id, int number);
void print_students(slist* students);
void print_courses(clist* courses);
void free_all(slist* sl, clist* cl);

// Linked list prototypes utilities
slist* search_student(slist* students, int id);
clist* search_course(clist* course, int number);
slist* add_node_to_slist(slist* nodeList, slist* nodeToAdd);
clist* add_node_to_clist(clist* nodeListHead, clist* nodeToAdd);
clist* delete_course_node(clist* courses, int number);
slist* delete_student_node(slist* students, int studentId);
void free_students(slist* sl);
void free_course_list(clist* courseList);
void free_student_list(slist* studentList);
void free_courses(clist* cl);

// General utilities prototypes
void* memory_allocation(size_t size_in_bytes);

//DO NOT TOUCH THIS FUNCTION
static void getstring(char* buf, int length) {
    int len;
    buf = fgets(buf, length, stdin);
    len = (int)strlen(buf);
    if (buf[len - 1] == '\n')
        buf[len - 1] = '\0';
}

//DO NOT TOUCH THIS FUNCTION 
int main() {
    slist* students = 0;
    clist* courses = 0;
    char  c;
    char  buf[100];
    int   id, num;

    do {
        printf("Choose:\n"
            "    add (s)tudent\n"
            "    add (c)ourse\n"
            "    (r)egister student\n"
            "    (u)nregister student\n"
            "    (p)rint lists\n"
            "    (q)uit\n");

        while ((c = (char)getchar()) == '\n');
        getchar();

        switch (c) {
        case 's':
            printf("Adding new student.\n");

            printf("Student name: ");
            getstring(buf, 100);

            printf("Student ID: ");
            scanf("%d", &id);

            students = add_student(students, buf, id);

            break;

        case 'c':
            printf("Adding new course.\n");

            printf("Course name: ");
            getstring(buf, 100);

            printf("Course number: ");
            scanf("%d", &num);

            courses = add_course(courses, buf, num);

            break;

        case 'r':
            printf("Registering a student to a course.\n");

            printf("Student ID: ");
            scanf("%d", &id);

            printf("Course number: ");
            scanf("%d", &num);

            reg_student(students, courses, id, num);

            break;

        case 'u':
            printf("Unregistering a student from a course.\n");

            printf("Student ID: ");
            scanf("%d", &id);

            printf("Course number: ");
            scanf("%d", &num);

            unreg_student(students, id, num);

            break;

        case 'p':
            printf("Printing Information.\n");

            print_students(students);
            print_courses(courses);

            break;

        case 'q':
            printf("Quitting...\n");
            break;
        }

        if (c != 'q')
            printf("\n");
    } while (c != 'q');

    free_all(students, courses);
    return 0;
}

/**
 * @summary Creating new student via allocating memory in the heap, fills his relevant info and adds it to the students list
 *
 * @param head pointer to the students linked list
 * @param name string, student's name.
 * @param id integer, student's id
 * @return slist* a pointer to the head of the new student's list
 */
slist* add_student(slist* students, char* name, int id)
{
    // Creating Student Node
    slist* studentNode = (struct slist*)memory_allocation(sizeof(struct slist));
    studentNode->next = NULL;

    studentNode->info = (struct student*)memory_allocation(sizeof(struct student));
    studentNode->info->name = (char*)memory_allocation(strlen(name) + 1);
    
    // Properties
    strcpy(studentNode->info->name, name);
    studentNode->info->id = id;
    studentNode->info->courses = NULL;

    return add_node_to_slist(students, studentNode);
}

/**
 * @summary Creating new course via allocating memory in the heap, fills his relevant info and adds it to the courses list
 *
 * @param head pointer to the students linked list
 * @param title string, course's title
 * @param number int, course number 
 * @return slist* a pointer to the head of the new courses's list
 */
clist* add_course(clist* courses, char* title, int number)
{
    // Creating Student Node
    clist* courseNode = (struct clist*)memory_allocation(sizeof(struct clist));
    courseNode->next = NULL;

    courseNode->info = (struct course*)memory_allocation(sizeof(struct course));
    courseNode->info->title = (char*)memory_allocation(strlen(title) + 1);

    // Properties 
    strcpy(courseNode->info->title, title);
    courseNode->info->number = number;
    courseNode->info->students = NULL;

    return add_node_to_clist(courses, courseNode);
}

/**
 * @summary adding a Student node to the students linked list while keeps it in order
 * @param nodeListHead a pointer to the head of a student linked list.
 * @param nodeToAdd pointer to a new student node to be added.
 * @return slist* A head pointer to the new students linked list.
 */
slist* add_node_to_slist(slist* nodeListHead, slist* nodeToAdd)
{
    slist* currNode = nodeListHead;

    // Adding the student node to the list
    if (!currNode)
    {
        return nodeToAdd;
    }
    if (nodeToAdd->info->id <= currNode->info->id)
    {
        nodeToAdd->next = currNode;
        return nodeToAdd;
    }
    while (currNode->next && nodeToAdd->info->id > currNode->next->info->id)
    {
        currNode = currNode->next;
    }
    nodeToAdd->next = currNode->next;
    currNode->next = nodeToAdd;

    return nodeListHead;
}

/**
 * @summary adding a Course node to the courses linked list while keeps it in order
 * @param nodeListHead a pointer to the head of a courses linked list.
 * @param nodeToAdd pointer to a new course node to be added.
 * @return slist* A head pointer to the new students linked list.
 */

clist* add_node_to_clist(clist* nodeListHead, clist* nodeToAdd)
{
    struct clist* currNode = nodeListHead;

    if (!currNode)
    {
        return nodeToAdd;
    }
    if (nodeToAdd->info->number <= currNode->info->number)
    {
        nodeToAdd->next = currNode;
        return nodeToAdd;
    }

    while (currNode->next && nodeToAdd->info->number > currNode->next->info->number)
    {
        currNode = currNode->next;
    }
    nodeToAdd->next = currNode->next;
    currNode->next = nodeToAdd;
    return nodeListHead;
}

/**
 * @summary searching a student node, and returns it's pointer
 *
 * @param students head pointer to the linked list to search upon
 * @param id an integer of the wanted student
 * @return slist* pointer to the matching student node.
 */

slist* search_student(slist* students, int id)
{
    while (students->info->id != id)
        students = students->next;
    return students;
}

/**
 * @summary searching a course node, and returns it's pointer
 *
 * @param courses head pointer to the linked list to search upon
 * @param number an integer of the wanted course
 * @return slist* pointer to the matching course node.
 */

clist* search_course(clist* courses, int number)
{
    while (courses->info->number != number)
        courses = courses->next;
    return courses;
}

/**
 * @summary Registering a student - A function which creates a new student node, adds it to the courses' registered students
 * the function creates a course node and add's it to the student's list of courses which it registered to.
 * @param students head pointer to the students linked list DB
 * @param courses head pointer to the courses linked list DB
 * @param number an integer representing the course to be registered
 * @param id an integer representing the id of the student to be registered.
 */
void reg_student(slist* students, clist* courses, int id, int number)
{
    // searching the objects to be registered.

    slist* studentToRegister = search_student(students, id);
    clist* courseToRegister = search_course(courses, number);

    // Create student node
    slist* studentNode = (slist*)memory_allocation(sizeof(slist));
    studentNode->info = studentToRegister->info;
    studentNode->next = NULL;

    // Create course node
    clist* courseNode = (clist*)memory_allocation(sizeof(clist));
    courseNode->info = courseToRegister->info;
    courseNode->next = NULL;
    
    // Register the student to the course
    courseToRegister->info->students = add_node_to_slist(courseToRegister->info->students, studentNode);

    // Register the course to the Student's list
    studentToRegister->info->courses = add_node_to_clist(studentToRegister->info->courses, courseNode);
}

/**
 * @summary Unregistering a student from a course - A function which removes a student node from the courses registered students,
 * the function removes the corresponded course from the student's course list.
 * @param students head pointer to the students linked list DB
 * @param number an integer representing the course to be unregistered
 * @param id an integer representing the id of the student to be unregistered.
 */

void unreg_student(slist* students, int id, int number)
{
    slist* studentToUnRegister = search_student(students, id);
    clist * courseNodeToRemove = search_course(studentToUnRegister->info->courses, number);

    slist* studentToBeFreed = search_student(courseNodeToRemove->info->students, id);
    clist* courseToBeFreed = search_course(studentToUnRegister->info->courses, number);
    
    courseNodeToRemove->info->students = delete_student_node(courseNodeToRemove->info->students, id);
    free(studentToBeFreed);
    studentToUnRegister->info->courses = delete_course_node(studentToUnRegister->info->courses, number);
    free(courseToBeFreed);

}

/**
 * @summary Deletes a student from a student linked list, and free's it's node resources keeping the actual student instance.
 * @param students head pointer to the students linked list DB
 * @param studentId the student's  to be deleted ID
 * @return slist* A pointer to the  head of the new  student linked list, after the deletion.
 */
slist* delete_student_node(slist* students, int studentId)
{
    slist *currentStudentNode = students, *prevStudentNode=NULL;

    if (currentStudentNode->info->id == studentId)
    {
        return students->next;
    }
    else
    {
        while (currentStudentNode)
        {
            if (currentStudentNode->info->id == studentId)
            {
                prevStudentNode->next = currentStudentNode->next;
                return students;
            }
            prevStudentNode = currentStudentNode;
            currentStudentNode = currentStudentNode->next;
        }
        return students;
    }

}

/**
 * @summary Deletes a course from a course linked list, and free's it's node resources keeping the actual course instance.
 * @param courses head pointer to the courses linked list DB
 * @param courseNumber the courses's  to be deleted number
 * @return slist* A pointer to the  head of the new  courses linked list, after the deletion.
 */
clist* delete_course_node(clist* courses, int courseNumber)
{

    clist* currentCourseNode, * prevCourseNode = NULL;
    // Initialize the the pointer to the corresponded course
    currentCourseNode = courses;

    if (currentCourseNode->info->number == courseNumber)
    {

        return currentCourseNode->next;
    }
    while (currentCourseNode)
    {
        if (currentCourseNode->info->number == courseNumber)
        {
            prevCourseNode->next = currentCourseNode->next;

            return courses;
        }
        prevCourseNode = currentCourseNode;
        currentCourseNode = currentCourseNode->next;
    }
    return courses;
}

/**
 * @summary Prints all the students in the same format as the a2.exe which was supplied in the moodle
 * @param students head pointer to the students linked list to be printed
 */
void print_students(slist* students) {

    clist* currCourse;
    if (students == NULL) {
        printf("STUDENT LIST: EMPTY!\n");
        return;
    }
    printf("STUDENT LIST:\n");
    while (students != NULL) {
        printf("%d:%s\n", students->info->id, students->info->name);

        currCourse = students->info->courses;
        if (currCourse == NULL)
            printf("student is not registered for courses.\n");
        else
            printf("courses: ");

        while (currCourse != NULL) {
            printf("%d-%s", currCourse->info->number, currCourse->info->title);
            currCourse = currCourse->next;
            if (currCourse != NULL) 
                printf(", ");
            else
                printf("\n");
        }
        students = students->next;
    }
}

/**
 * @summary Prints all the courses in the same format as the a2.exe which was supplied in the moodle
 * @param courses head pointer to the students linked list to be printed
 */
void print_courses(clist* courses) {
    
    
    slist* currStudent;

    if (courses == NULL) {
        printf("COURSE LIST: EMPTY!\n");
        return;
    }
    printf("COURSE LIST:\n");
    while (courses != NULL) {
        printf("%d:%s\n", courses->info->number, courses->info->title);

        currStudent = courses->info->students;
        if (currStudent == NULL)
            printf("course has no students.\n");
        else
            printf("students: ");

        while (currStudent != NULL) {
            printf("%d-%s", currStudent->info->id, currStudent->info->name);
            currStudent = currStudent->next;
            if (currStudent != NULL)     // if not end of line
                printf(", ");
            else
                printf("\n");
        }
        courses = courses->next;
    }
}

/**
 * @summary frees all the program's memory resources - students and courses linked list & instances.
 * @param sl, pointer to the student list to be freed.
 * @param cl, pointer to the course list to be freed.
 */
void free_all(slist* sl, clist* cl)
{
    free_students(sl);
    free_courses(cl);
}

/**
 * @summary frees a students linked list, the programs frees all the students resources,
 each student has - a registered courses linked list, a name, instance info, a node in the students DB linked list to be freed
 * @param sl, pointer to the student list to be freed.
 *
 */
void free_students(slist* sl)
{
    while (sl)
    {
        slist* currStudent = sl;
        sl = sl->next;
        free_course_list(currStudent->info->courses);
        free(currStudent->info->name);
        free(currStudent->info);
        free(currStudent);
        
    }
}

/**
 * @summary frees the student's course list which it registered to. each student holds a linked list which it is registered to.
 * the function iterated all the list nodes and frees it's nodes.
 * @param courseList, pointer to the coureses list to be freed.
 */

void free_course_list(clist* courseList)
{
    clist* currentCourse;
    while (courseList)
    {
        currentCourse = courseList;
        courseList = courseList->next;
        free(currentCourse);  
    }
}

/**
 * @summary frees a courses linked list, the programs frees all the courses resources,
 each course has - a registered students linked list, a title, instance info, a node in the courses DB linked list to be freed
 * @param cl, pointer to the coureses list to be freed.
 */
void free_courses(clist* cl)
{
    while (cl)
    {
        clist* currCourse = cl;
        cl = cl->next;
        free_student_list(currCourse->info->students);
        free(currCourse->info->title);
        free(currCourse->info);
        free(currCourse);
    }
}

/**
 * @summary frees the courses's students list which it registered to. each course holds a linked list of students which are registered.
 * the function iterated all the list nodes and frees it's nodes.
 * @param studentList, pointer to the students list to be freed.
 */
void free_student_list(slist* studentList)
{
    slist* currentStudent;
    while (studentList)
    {
        currentStudent = studentList;
        studentList = studentList->next;
        free(currentStudent);
    }
}

/**
 * @summary Function which tries to allocate memory, if fails it exists the program
 * @param size_in_bytes how many bytes to allocate
 */
void* memory_allocation(size_t size_in_bytes) {
    void* memPointer = malloc(size_in_bytes);
    if (!memPointer) {
        exit(1);
    }
    return memPointer;
}