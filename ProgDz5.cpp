#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<string.h> 
#include<locale.h>
#include<math.h>
#include<windows.h>
struct sity {
    int num;
    int yearAndPeople[2][100];
    int maxPeople;
    int minPeople;
    int maxR;
    char* sityName;
};

void main() {
 /*   setlocale(LC_ALL, "Russian");*/
 SetConsoleOutputCP(1251);	
 SetConsoleCP(1251);
    int newId=0, year,people,N, newMaxR,k=0,ch=0,num=0;
    int sumA=0,totalMax=0,totalMin,totalMaxR=0;
    int totalMaxName=0, totalMinName=0, totalMaxRName=0;
    bool newSity = true;
    char arrSityName[100][100];
    struct sity arr[100];
    printf("Введите количество блоков информации:\n");
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        printf("Введите название города:\n");
        ch = getchar();
     /*   scanf("%s", &arrSityName[i]);*/
        while (true) {
            ch = getchar();
            if (ch == int('\n')) break;
            arrSityName[i][num] = char(ch);
            num++;
        }
        arrSityName[i][num] = '\0';
        num = 0;
        for (int j = 0; j < newId; j++) {
            if (strcmp(arrSityName[i], arr[j].sityName) == 0) {
                printf("Введите год:\n");
                scanf("%d", &year);
                arr[j].yearAndPeople[0][arr[j].num] = year;
                printf("Введите количество жителей:\n");
                scanf("%d", &people);
                arr[j].yearAndPeople[1][arr[j].num] = people;
                if (arr[j].maxR < (arr[j].yearAndPeople[1][arr[j].num] - arr[j].yearAndPeople[1][(arr[j].num) - 1])) {
                    arr[j].maxR = (arr[j].yearAndPeople[1][arr[j].num] - arr[j].yearAndPeople[1][(arr[j].num) - 1]);
                }
                if (arr[j].maxPeople < arr[j].yearAndPeople[1][arr[j].num]) {
                    arr[j].maxPeople = arr[j].yearAndPeople[1][arr[j].num];
                }
                if (arr[j].minPeople > arr[j].yearAndPeople[1][arr[j].num]) {
                    arr[j].minPeople = arr[j].yearAndPeople[1][arr[j].num];
                }
                arr[j].num++;
                newSity = false;
                break;
            }
            
        }
        if (newSity) {
            arr[newId].num = 0;
            arr[newId].sityName = arrSityName[i];
            printf("Введите год:\n");
            scanf("%d", &year);
            arr[newId].yearAndPeople[0][arr[newId].num] = year;
            printf("Введите количество жителей:\n");
            scanf("%d", &people);
            arr[newId].yearAndPeople[1][arr[newId].num] = people;
            arr[newId].maxPeople = people;
            arr[newId].minPeople = people;
            arr[newId].maxR = 0;
            arr[newId].num++;
            newId++;
        }
        newSity = true;
    }
    printf("Введите суммарное количество жителей за какой год вы хотите получить:\n");
    scanf("%d",&year);
    totalMin = arr[0].yearAndPeople[1][0];
    for(int i=0;i<newId;i++){
        for (int j = 0; j < arr[i].num; j++) {
            if (arr[i].yearAndPeople[1][j] < totalMin) { totalMin = arr[i].yearAndPeople[1][j]; 
            totalMinName=i;
            }
            if (arr[i].yearAndPeople[1][j] > totalMax) {
                totalMax = arr[i].yearAndPeople[1][j];
                totalMaxName = i;
            }
            if (arr[i].maxR > totalMaxR) {
                totalMaxR = arr[i].maxR;
                totalMaxRName = i;
            }
            if (arr[i].yearAndPeople[0][j] == year) sumA += arr[i].yearAndPeople[1][j];
        }
}
    printf("a)%d\n", sumA);
    printf("б)\n");
    for (int i = 0; i < newId; i++) {
        printf("max в городе %s= %d\n",arr[i].sityName,arr[i].maxPeople);
    }
    printf("в) max= %s min= %s\nг)%s\n",arr[totalMaxName].sityName,arr[totalMinName].sityName,arr[totalMaxRName].sityName);
    _getch();
}