#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "login.h"

static int score[5]={0};

void Loadingber(){
    char a = 177, b = 219;
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\tLoading....... \n");
    printf("\n\t\t\t\t\t");
    for(int n=0;n<=29;n++){
    printf("%c", a);
    }
    printf("\r");
    printf("\t\t\t\t\t");
    for(int n=0;n<=29;n++){
    printf("%c", b);
    Sleep(200);
    }
    system("cls");
}

void explain(){
    char y;
    printf("Before we begin!!\n");
    printf("Let's introduce the rules of playing.\n");
    printf("**********************************************************\n");
    printf("1.There are 5 questions in the game.\n");
    printf("2.Choose answer 1 or 2 or 3.\n");
    printf("3.Scores are counted, if less than 3 points are considered lost.\n\n");
    do{
        printf("Do you understand? (y) : ");
        scanf(" %c", &y);
    }while(y!='y');
}

int Game(){
    int ans, c;
    int count[5]={0};
    printf("Choose the answer\n");
    for(int a=1;a<=5;a++){
        printf("\n%d. ",a);
        re:
        c = rand()%5+1;
            for(int i=0;i<5;i++){
                if(c==count[i]){
                    goto re;
                }
            }
        count[a-1]=c;
        switch(c){
        case 1:
            printf("How many people have premier of Thailand?");
            printf("\n   1. 29 people");
            printf("\n   2. 30 people");
            printf("\n   3. 31 people\n");
            do{
                printf("Answer : ");
                scanf("%d", &ans);
            }while(ans!=1 && ans!=2 &&ans!=3);
            if(ans==3){
                score[a-1]=1;
            }
            break;
        case 2:
            printf("Who is the 30th premier of Thailand?");
            printf("\n   1. Settha Thaweesin");
            printf("\n   2. Prayut Chan-o-cha");
            printf("\n   3. Paetongtarn Shinawatra\n");
            do{
                printf("Answer : ");
                scanf("%d", &ans);
            }while(ans!=1 && ans!=2 &&ans!=3);
            if(ans==1){
                score[a-1]=1;
            }
            break;
        case 3:
            printf("Whose father is Paetongtarn Shinawatra?");
            printf("\n   1. Settha Thaweesin");
            printf("\n   2. Thaksin Shinawatra");
            printf("\n   3. Prayut Chan-o-cha\n");
            do{
                printf("Answer : ");
                scanf("%d", &ans);
            }while(ans!=1 && ans!=2 &&ans!=3);
            if(ans==2){
                score[a-1]=1;
            }
            break;
        case 4:
            printf("What is regime of Thailand?");
            printf("\n   1. a democracy");
            printf("\n   2. a communism");
            printf("\n   3. absolute monarchy\n");
            do{
                printf("Answer : ");
                scanf("%d", &ans);
            }while(ans!=1 && ans!=2 &&ans!=3);
            if(ans==1){
                score[a-1]=1;
            }
            break;
        case 5:
            printf("What color is national flag of Thailand");
            printf("\n   1. Red, White, Brown");
            printf("\n   2. Red, White, Blue");
            printf("\n   3. Red, White, Green\n");
            do{
                printf("Answer : ");
                scanf("%d", &ans);
            }while(ans!=1 && ans!=2 &&ans!=3);
            if(ans==2){
                score[a-1]=1;
            }
            break;
        }
        system("cls");
        while(a<=4){
            printf("Choose the answer\n");
            break;
        }
    }
    return score;
}

void resetScores() {
    for (int i = 0; i<5; i++) {
        score[i] = 0;
    }
}

int main()
{
    int *scoremain;
    char user[21];
    int wtlogin, wtregis;
    int sumscore;
    char yn;
    system("color 0A");
    srand(time(NULL));

    Loadingber();

    printf("\t\t\t\tWelcome to Game\n");
    printf("\t\t\t\t Ask the Answer\n");
    printf("Do you have account?\n");
    printf("************************\n");
    do{
        printf("Yes or no (y/n): ");
        scanf(" %c", &yn);
    }while(yn!='y' && yn!='n');
    system("cls");
    if (yn=='n'){
        regis:
        wtlogin = register_user(user);
        if (wtlogin==1){
            system("cls");
            wtregis = login(user);
        }
    }else if(yn=='y'){
        wtregis = login(user);
    }
    if(wtregis==1){
        goto regis;
    }
    start:
    sumscore = 0;

    explain();

    system("cls");
    scoremain = Game();

    for(int a=0;a<5;a++){
        sumscore += scoremain[a];
    }
    printf("You end game\n\n");
    printf("Your score is %d", sumscore);
    if(sumscore>=3){
        printf("\n************************************************");
        printf("\nCongratulations, You Win");
        printf("\n************************************************");
    }else{
        printf("\n************************************************");
        printf("\nSorry, You Lose");
        printf("\n************************************************");
    }
    printf("\n\nDo you want to start again\n");
    do{
        printf("Yes or No (y,n) : ");
        scanf(" %c", &yn);
        if(yn=='y'){
            system("cls");
            resetScores();
            goto start;
        }
    }while(yn!='n');
    system("cls");
    printf("\nThank %s very much\n", user);
    printf("\n************************************************");
    printf("\n\nGame Over\n");
    printf("\n************************************************");
    return 0;
}
