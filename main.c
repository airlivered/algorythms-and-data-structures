#include<stdio.h>
#include<conio.h>
#include<string.h>




int main()
{
//Варіант алгоритму взятий з мережі

//Звільнення пам'яті для таблиці
int table[500];

//Змінна t відповідає за зберігання введеного для пошуку тексту
//Змінна c - за шуканий підрядок 
char t[100],p[25];

//Необхідні цілочисленні змінні, n зберігає довжину тексту, m-підрядка
//k служить для проходження по тексту, i та j для заповнення таблиці
int n,i,k,j,m,flag=0;

printf("Enter the text : ");
gets(t);
n=strlen(t);

printf("Enter the pattren : ");
gets(p);
m=strlen(p);

//Заповнення таблиці довжинами підрядка
for(i=0; i<500; i++)
table[i]=m;

//Присвоєння елементам таблиці з символьними індексами відповідних значень 
//відступів
for(j=0;j<m-2;j++)
table[p[j]]=m-1-j;


i=m-1;
//Цикл для проходження по тексту
while(i<=n-1)
{
    //Змінна k застосовується при збігу літер тексту з підрядком
    //Тотожність k довжині підрядка є ознакою шуканого слова
    k=0;
    while(k<=m-1 && p[m-1-k]==t[i-k])
    k++;
    if(k==m)
    {
        printf("The position of the pattern is %d\n",i-m+2);
        flag=1;
        break;
    }
    //Зсув на табличне знечення
    else
        i=i+table[t[i]];
 }
//flag, коли слова немаэ в тексті
if(!flag){
    printf("Pattern is not found in the given text ");
}

return 0;
}
