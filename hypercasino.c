/*

Hyper Casino 1

Developed by Hyper Lab Inc.

Current Beta(20210606-Now available Release v.1.0.0)

Developed on Code::Blocks & Windows Notepad

Developing Language: C99

Open Source

*/

//Header file
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define _CRT_SECURE_NO_WARNINGS //Prevent Error

//Global Vars
int money=100; //Your money

//Main
int main(int argc, char** argv){
    //Console Setting
    system("title Hyper Casino 1");//Console Name
    system("mode con:cols=200 lines=50");//Make Console Biggest

    //Intro
    printf("#################################################################################\n#################################################################################\n\n");
    printf("Hyper Casino 1\nWelcome to Hyper Casino 1!\nDeveloped by Hyper Lab Inc.");
    printf("#################################################################################\n#################################################################################\n\n");

    //Basic variables
    int menuchoice; //Menu Choice Num
    int rewardrec=0; //do you received once reward
    int fontcolor; //Font Color
    srand(time(0));//randomtime
    //Menu
    do{
        //Menu explain
        printf("\n\n####  Menu    ####\nChoice game or menu's number that you want.\n1. Once Reward\n2. Tutorial\n3. View your cash\n4. Slot machine\n5. Random Betting\n6. Standard Betting\n7. Exit\nYour Choice>");
        scanf("%d", &menuchoice);
        switch(menuchoice){
            case 1 :
                //Once Reward
                if (rewardrec==0){
                    printf("\n\nYou have received once reward.(Cash+100)\n");
                    money+=100;
                    rewardrec=1;
                    break;
                } else {printf("\n\nYou already have received once reward.\n\n");}
                break;
            case 2 :
                //Tutorial
                printf("\n\nEnter 1-7 to play game, check your cash, or exit.\n");
                printf("You can get 100 cash reward only once at Once Reward.\n");
                printf("You can select the number of pattern and bet money to it, if you wrong, you will lose all of your betted cash, but if you correct, you can get $(betted money)*(numberofpattern). If you are jackpot, you can get $2*(betted money)*(numberofpattern). ");
                printf("You can bet at Random Betting without any informations. If you win you will get two times of your betted money, but if you lose, you will lose your betted money.");
                printf("You can bet at Standard Betting with odds of sports game. You can see the results of game, and you will receive team infos before betting. If you win, you will get $(betted money)*(opponent odds), if you lose, you will lose your betted money.");
                break;
            case 3 :
               //View your cash
                printf("\nYour Cash:%d\n", money);
                break;
            case 4 :
                //Slot Machine
                slotmachine();
                break;
            case 5 :
                //Random Betting
                randombetting();
                break;
            case 6 :
                //Standard Betting
                standardbetting();
                break;

            default :printf("Thank you for using Hyper Casino 1. \nPress any key to close the window.\n\n");
        }
      } while (menuchoice < 7); //menu's nums
      //if not enter 1-(menu except exit), exit
      exit(0);
}

/**********************************************************************************************************************************************************************************/
/*Functions*/

/**************************************************************************************************************************/

//Slot Machine
void slotmachine(){
    int pattern;
    int betting;
    int result1;
    int result2;
    int result3;
    do{
        printf("\n\nPlease enter the number of patterns you want. It must be more that five(>5)\n>");
        scanf("%d", &pattern);
    } while (pattern < 6); //check patterns
    do{
        printf("\nPlease enter money to bet. It must be lower than your money and more than 10.");
        scanf("%d", &betting);
    } while ((betting < 9) && (betting > (money+1))); //betting
    money-=betting;
    printf("\nPlease wait......");
    //rolling
    result1=(rand() % pattern) + 1;
    result2=(rand() % pattern) + 1;
    result3=(rand() % pattern) + 1;
    //same?
    if ((result1==result2) || ((result1==result3) || (result2==result3))){
        if ((result1 == result2) && (result1==result3))
        { printf("\nYou are the jackpot! Congratulations!");
          printf("\n\nCash +%d", betting*pattern*2);
          money+=betting*pattern*2;}
        else{
            printf("\nYou have same pattern. Congratulations!");
            printf("\n\nCash +%d", betting*pattern);
            money+=betting*pattern;}
    }
    else{printf("\nYou failed. Please try again. You will lose your money.\n");}
}

//RandomBetting
void randombetting(){
    int bettingrand;
    do{
        printf("\nPlease enter money to bet. It must be lower than your money and more than 10.");
        scanf("%d", &bettingrand);
    } while ((bettingrand < 9) && (bettingrand > (money+1))); //betting
    money-=bettingrand;
    int randresult=rand() % 1;
    if (randresult){
        printf("\nCongratulations! You won!\n\n"); money+=bettingrand*2;
    }
    else{printf("\nYou failed. Please try again. You will lose your money.\n");}
}

/**************************************************************************************************************************/

//Standard Betting
void standardbetting(){
    //team infos
    int home=(rand() % 99) + 1;
    int away=(rand() % 99) + 1;
    int homeodd=(100-home)/10;
    int awayodd=(100-away)/10;
    int minute=0;
    int homescorei, awayscorei = 0;
    char betteam[10];
    int gamei=0;
    int bettingmoneystandard, homescore, awayscore = 0;
    printf("\n\nStandard Betting Team Informations\n\n");
    printf("Home Team\nTeam strategy:%d\nOdd:%d\n\nAway Team\nTeam strategy:%d\nOdd:%d\n\n", home, homeodd, away, awayodd);
    //betting
    printf("Betting Team?(H/A)");
    scanf("%s", betteam);
    do{
        printf("\nMoney to bet? It must be lower than your money and more than 10.");
        scanf("%d", &bettingmoneystandard);
    } while ((bettingmoneystandard < 9) && (bettingmoneystandard > (money+1))); //betting
    money-=bettingmoneystandard;
    //Match Engine

    homescorei=floor(90/(homeodd*10));
    awayscorei=floor(90/(homeodd*10));
    int homescorerand=0;
    int awayscorerand=0;
    homescore=0; awayscore=0;
    int whomore=(homescore > awayscore);
    if (whomore) {
        while (gamei < homescorei){
            homescorerand=(floor(homeodd));
            awayscorerand=(floor(awayodd));
            if (((rand() % 9) + 1) == homescorerand){
                homescore++;
            }
            if (((rand() % 9) + 1) == awayscorerand){
                awayscore++;
            }
            gamei++;
        }
    }
    else{
        while (gamei < awayscorei){
            homescorerand=(floor(homeodd));
            awayscorerand=(floor(awayodd));
            if (((rand() % 9) + 1) > homescorerand){
                homescore++;
            }
            if (((rand() % 9) + 1) > awayscorerand){
                awayscore++;
            }
            gamei++;
        }
    }
    printf("Final Score: %d vs. %d", homescore, awayscore);

    if (((betteam=="H")&&(homescore>awayscore))|((betteam=="A")&&(homescore<awayscore))){
        printf("\n\nYou won at betting! Congratulation!");
        if (betteam=="H"){
            money+=awayodd*bettingmoneystandard;
        }
        else{
            money+=homeodd*bettingmoneystandard;
        }
    }
    else{printf("\n\nYou failed. Please Try again. You will lose your money.");}
}

/**************************************************************************************************************************/
