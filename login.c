#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"

int register_user(char *newuser) {
    char yn;
    char founduser[21];
    FILE *fptr;
    regis:
    printf("Register");
    do{
        printf("\nEnter less than 20 characters");
        printf("\nUsername : ");
        scanf("%s", newuser);

        if (strlen(newuser)>20){
            printf("\nError: Username too long!");
        }
    }while(strlen(newuser)>20);
    fptr = fopen("usernames.txt", "r");
    // อ่านชื่อผู้ใช้แต่ละบรรทัดจากไฟล์และตรวจสอบ
    while (fgets(founduser, sizeof(founduser), fptr) != NULL) {
        // ลบ '\n' ที่อยู่ท้ายสตริงออก
        founduser[strcspn(founduser, "\n")] = '\0';
        // เปรียบเทียบชื่อที่ป้อนเข้ามากับชื่อในไฟล์
        if (strcmp(newuser, founduser) == 0) {
            printf("\033[31m!!You have already registered\033[0m\n");
            printf("Do you want to go to the login page?\n");
            do{
            printf("Yes or no (y/n): ");
            scanf(" %c", &yn);
            system("color 0A");
            }while(yn!='y' && yn!='n');
            if (yn=='n'){
                system("cls");
                goto regis;
            }else if(yn=='y'){
                return 1;
                goto done;
            }
        }
    }
    fclose(fptr);
    fptr = fopen("usernames.txt", "a");  // open username file write mode
    fprintf(fptr, "%s\n", newuser); //put on file
    fclose(fptr); //close file
    done:
    system("cls");
    return 0 ;
}

int login(char *loguser){
    char founduser[20];
    char yn;
    int found = 0;
    FILE *fptr;
    againlogin:
    printf("Login\n");
    printf("Username: ");
    scanf(" %s", loguser);
    fptr = fopen("usernames.txt", "r");
    // อ่านชื่อผู้ใช้แต่ละบรรทัดจากไฟล์และตรวจสอบ
    while (fgets(founduser, sizeof(founduser), fptr) != NULL) {
        // ลบ '\n' ที่อยู่ท้ายสตริงออก
        founduser[strcspn(founduser, "\n")] = '\0';
        // เปรียบเทียบชื่อที่ป้อนเข้ามากับชื่อในไฟล์
        if (strcmp(loguser, founduser) == 0) {
            found = 1;
        }
    fclose(fptr);
    }
    if (!found){
            printf("\033[31m!!You have never registered\033[0m\n");
            printf("Do you want to go to the register page?\n");
            do{
            printf("Yes or no (y/n): ");
            scanf(" %c", &yn);
            system("color 0A");
            }while(yn!='y' && yn!='n');
            if (yn=='y'){
                system("cls");
                return 1;
            }else if(yn=='n'){
                system("cls");
                goto againlogin;
            }
        }
    system("cls");
    return 0;
}
