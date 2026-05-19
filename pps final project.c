#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define STUDENTS 30
#define SUBJECTS 5

// Student Structure
struct Student
{
    char name[50];
    long prn;
    int marks[SUBJECTS];
};

// Teacher Structure
struct Teacher
{
    char id[20];
    char password[20];
    int subjectIndex;
    char subjectName[20];
};

// Function to calculate grades
char* getGrade(int marks)
{
    if(marks >= 90)
        return "AA";
    else if(marks >= 81)
        return "AB";
    else if(marks >= 71)
        return "BB";
    else if(marks >= 61)
        return "BC";
    else if(marks >= 51)
        return "CC";
    else if(marks >= 41)
        return "CD";
    else
        return "FF";
}

int main()
{
    int i, j, choice;
    int subjectChoice;
    char searchName[50];
    long searchPRN;

    // Student Data
    struct Student s[STUDENTS] = {
        {"Amit Sharma",1001},
        {"Priya Patil",1002},
        {"Rahul Verma",1003},
        {"Sneha Kulkarni",1004},
        {"Rohit Gupta",1005},
        {"Anjali Deshmukh",1006},
        {"Karan Mehta",1007},
        {"Neha Joshi",1008},
        {"Vikas Singh",1009},
        {"Pooja Yadav",1010},
        {"Arjun Nair",1011},
        {"Kavita Shah",1012},
        {"Manoj Kumar",1013},
        {"Riya Das",1014},
        {"Suresh Reddy",1015},
        {"Meena Iyer",1016},
        {"Deepak Mishra",1017},
        {"Swati Chavan",1018},
        {"Nikhil Jain",1019},
        {"Asha Pawar",1020},
        {"Yogesh More",1021},
        {"Komal Shinde",1022},
        {"Sanjay Patil",1023},
        {"Divya Bansal",1024},
        {"Aditya Roy",1025},
        {"Tanvi Kale",1026},
        {"Harsh Agrawal",1027},
        {"Payal Gupta",1028},
        {"Omkar Jadhav",1029},
        {"Simran Kaur",1030}
    };

    // Teacher Data
    struct Teacher t[SUBJECTS] = {
        {"t1","pass1",0,"Maths"},
        {"t2","pass2",1,"Physics"},
        {"t3","pass3",2,"Chemistry"},
        {"t4","pass4",3,"English"},
        {"t5","pass5",4,"Computer"}
    };

    // Subject Names
    char subjects[SUBJECTS][20] = {
        "Maths",
        "Physics",
        "Chemistry",
        "English",
        "Computer"
    };

    // Generate Random Marks
    srand(time(0));

    for(i=0; i<STUDENTS; i++)
    {
        for(j=0; j<SUBJECTS; j++)
        {
            s[i].marks[j] = rand()%101;
        }
    }

    do
    {
        printf("\n========================================");
        printf("\n STUDENT RESULT ANALYSIS SYSTEM");
        printf("\n========================================");

        printf("\n1. Display Student Names and PRN");
        printf("\n2. Display Subject-wise Marks");
        printf("\n3. Teacher Login");
        printf("\n4. Subject Result Analysis");
        printf("\n5. Admin Login");
        printf("\n6. Exit");

        // Main Menu Validation
        do
        {
            printf("\n\nEnter Choice: ");
            scanf("%d",&choice);

            if(choice < 1 || choice > 6)
            {
                printf("\nIncorrect Choice! Please Enter Again.\n");
            }

        } while(choice < 1 || choice > 6);

        switch(choice)
        {

            // TASK 1
            case 1:

                printf("\n===== STUDENT LIST =====\n");

                for(i=0; i<STUDENTS; i++)
                {
                    printf("%d. %s (PRN: %ld)\n",
                           i+1,
                           s[i].name,
                           s[i].prn);
                }

                break;

            // TASK 2
            case 2:

                printf("\nSelect Subject");
                printf("\n1. Maths");
                printf("\n2. Physics");
                printf("\n3. Chemistry");
                printf("\n4. English");
                printf("\n5. Computer");

                do
                {
                    printf("\nEnter Subject Choice: ");
                    scanf("%d",&subjectChoice);

                    if(subjectChoice < 1 || subjectChoice > 5)
                    {
                        printf("\nInvalid Subject Choice! Enter Again.\n");
                    }

                } while(subjectChoice < 1 || subjectChoice > 5);

                subjectChoice--;

                printf("\n===== %s Marks =====\n",
                       subjects[subjectChoice]);

                for(i=0; i<STUDENTS; i++)
                {
                    printf("%s (PRN %ld) = %d\n",
                           s[i].name,
                           s[i].prn,
                           s[i].marks[subjectChoice]);
                }

                break;

            // TASK 3 - TEACHER LOGIN
            case 3:
            {
                char id[20], pass[20];
                int loginSuccess = -1;

                printf("\n===== TEACHER LOGIN =====");

                printf("\nEnter ID: ");
                scanf("%s",id);

                printf("Enter Password: ");
                scanf("%s",pass);

                // Login Check
                for(i=0; i<SUBJECTS; i++)
                {
                    if(strcmp(id,t[i].id)==0 &&
                       strcmp(pass,t[i].password)==0)
                    {
                        loginSuccess = i;
                        break;
                    }
                }

                if(loginSuccess != -1)
                {
                    printf("\nLogin Successful!");
                    printf("\nSubject Access: %s\n",
                           t[loginSuccess].subjectName);

                    int sub = t[loginSuccess].subjectIndex;
                    int updateChoice;
                    int found = 0;
                    int newMarks;

                    printf("\n1. Search by PRN");
                    printf("\n2. Search by Name");

                    do
                    {
                        printf("\nEnter Choice: ");
                        scanf("%d",&updateChoice);

                        if(updateChoice < 1 || updateChoice > 2)
                        {
                            printf("\nInvalid Choice! Enter Again.\n");
                        }

                    } while(updateChoice < 1 || updateChoice > 2);

                    // SEARCH BY PRN
                    if(updateChoice == 1)
                    {
                        printf("\nEnter PRN: ");
                        scanf("%ld",&searchPRN);

                        for(i=0; i<STUDENTS; i++)
                        {
                            if(s[i].prn == searchPRN)
                            {
                                found = 1;

                                printf("\nStudent Found");
                                printf("\nName: %s",s[i].name);

                                printf("\nCurrent Marks in %s = %d",
                                       subjects[sub],
                                       s[i].marks[sub]);

                                do
                                {
                                    printf("\nEnter New Marks: ");
                                    scanf("%d",&newMarks);

                                    if(newMarks < 0 || newMarks > 100)
                                    {
                                        printf("\nInvalid Marks! Enter Between 0 to 100.\n");
                                    }

                                } while(newMarks < 0 || newMarks > 100);

                                s[i].marks[sub] = newMarks;

                                printf("\nMarks Updated Successfully!");

                                break;
                            }
                        }
                    }

                    // SEARCH BY NAME
                    else if(updateChoice == 2)
                    {
                        printf("\nEnter Name: ");
                        scanf(" %[^\n]",searchName);

                        for(i=0; i<STUDENTS; i++)
                        {
                            if(strcmp(strlwr(s[i].name),strlwr(searchName))==0)
                            {
                                found = 1;

                                printf("\nStudent Found");
                                printf("\nPRN: %ld",s[i].prn);

                                printf("\nCurrent Marks in %s = %d",
                                       subjects[sub],
                                       s[i].marks[sub]);

                                do
                                {
                                    printf("\nEnter New Marks: ");
                                    scanf("%d",&newMarks);

                                    if(newMarks < 0 || newMarks > 100)
                                    {
                                        printf("\nInvalid Marks! Enter Between 0 to 100.\n");
                                    }

                                } while(newMarks < 0 || newMarks > 100);

                                s[i].marks[sub] = newMarks;

                                printf("\nMarks Updated Successfully!");

                                break;
                            }
                        }
                    }

                    if(found == 0)
                    {
                        printf("\nStudent Not Found!");
                    }

                }
                else
                {
                    printf("\nIncorrect ID or Password!");
                }

                break;
            }

            // TASK 4 - RESULT ANALYSIS
            case 4:
            {
                int aa=0, ab=0, bb=0, bc=0, cc=0, cd=0, ff=0;

                printf("\nSelect Subject for Result Analysis");
                printf("\n1. Maths");
                printf("\n2. Physics");
                printf("\n3. Chemistry");
                printf("\n4. English");
                printf("\n5. Computer");
                printf("\n6. All Subjects Analysis");

                do
                {
                    printf("\nEnter Subject Choice: ");
                    scanf("%d",&subjectChoice);

                    if(subjectChoice < 1 || subjectChoice > 6)
                    {
                        printf("\nInvalid Subject Choice! Enter Again.\n");
                    }

                } while(subjectChoice < 1 || subjectChoice > 6);

                // ALL SUBJECT ANALYSIS
                if(subjectChoice == 6)
                {
                    printf("\n================ ALL SUBJECT RESULT ANALYSIS ================\n");

                    printf("\n--------------------------------------------------------------------------");
                    printf("\n%-12s %-5s %-5s %-5s %-5s %-5s %-5s %-5s",
                           "Subject",">90",">80",">70",">60",">50",">40","Fail");
                    printf("\n--------------------------------------------------------------------------");

                    for(j=0; j<SUBJECTS; j++)
                    {
                        int d90=0, d80=0, d70=0, d60=0, d50=0, d40=0, fail=0;

                        for(i=0; i<STUDENTS; i++)
                        {
                            int marks = s[i].marks[j];

                            if(marks >= 90)
                                d90++;
                            else if(marks >= 80)
                                d80++;
                            else if(marks >= 70)
                                d70++;
                            else if(marks >= 60)
                                d60++;
                            else if(marks >= 50)
                                d50++;
                            else if(marks >= 40)
                                d40++;
                            else
                                fail++;
                        }

                        printf("\n%-12s %-5d %-5d %-5d %-5d %-5d %-5d %-5d",
                               subjects[j],
                               d90,
                               d80,
                               d70,
                               d60,
                               d50,
                               d40,
                               fail);
                    }
                }

                // SINGLE SUBJECT ANALYSIS
                else
                {
                    subjectChoice--;

                    printf("\n===== RESULT ANALYSIS : %s =====\n",
                           subjects[subjectChoice]);

                    printf("\n----------------------------------------------------------------");
                    printf("\nName\t\tPRN\tMarks\tGrade");
                    printf("\n----------------------------------------------------------------");

                    for(i=0; i<STUDENTS; i++)
                    {
                        char *grade = getGrade(s[i].marks[subjectChoice]);

                        printf("\n%s\t%ld\t%d\t%s",
                               s[i].name,
                               s[i].prn,
                               s[i].marks[subjectChoice],
                               grade);

                        // Grade Count
                        if(strcmp(grade,"AA")==0)
                            aa++;
                        else if(strcmp(grade,"AB")==0)
                            ab++;
                        else if(strcmp(grade,"BB")==0)
                            bb++;
                        else if(strcmp(grade,"BC")==0)
                            bc++;
                        else if(strcmp(grade,"CC")==0)
                            cc++;
                        else if(strcmp(grade,"CD")==0)
                            cd++;
                        else
                            ff++;
                    }

                    printf("\n\n=========== GRADE ANALYSIS ===========");

                    printf("\nAA Grade Students = %d", aa);
                    printf("\nAB Grade Students = %d", ab);
                    printf("\nBB Grade Students = %d", bb);
                    printf("\nBC Grade Students = %d", bc);
                    printf("\nCC Grade Students = %d", cc);
                    printf("\nCD Grade Students = %d", cd);
                    printf("\nFF Grade Students = %d", ff);
                }

                break;
            }

            // TASK 5 - ADMIN LOGIN
            case 5:
            {
                char adminId[20];
                char adminPass[20];

                printf("\n===== ADMIN LOGIN =====");

                do
                {
                    printf("\nEnter Admin ID: ");
                    scanf("%s",adminId);

                    printf("Enter Admin Password: ");
                    scanf("%s",adminPass);

                    if(strcmp(adminId,"admin") != 0 ||
                       strcmp(adminPass,"admin123") != 0)
                    {
                        printf("\nIncorrect Password! Please Enter Correct Password.\n");
                    }

                } while(strcmp(adminId,"admin") != 0 ||
                        strcmp(adminPass,"admin123") != 0);

                printf("\nLogin Successful!");

                printf("\n\n================ ALL SUBJECT MARKS ================\n");

                printf("\n-------------------------------------------------------------------------------------");
                printf("\nName\t\tPRN\tMaths\tPhysics\tChem\tEng\tComp");
                printf("\n-------------------------------------------------------------------------------------");

                for(i=0; i<STUDENTS; i++)
                {
                    printf("\n%s\t%ld\t%d\t%d\t%d\t%d\t%d",
                           s[i].name,
                           s[i].prn,
                           s[i].marks[0],
                           s[i].marks[1],
                           s[i].marks[2],
                           s[i].marks[3],
                           s[i].marks[4]);
                }

                break;
            }

            // EXIT
            case 6:

                printf("\nProgram Exited Successfully!");
                break;
        }

    } while(choice != 6);

    return 0;
}
