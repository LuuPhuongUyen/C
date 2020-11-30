//Luu Phuong Uyen - SE1401
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define MAXN 100
char code[MAXN][50],name[MAXN][50];
double salary[MAXN],allowance[MAXN];
int n=0;
//KIEM TRA DINH DANG CODE----------------------------------------
int checkCode(char*s)
{
    int spaceCount=0;
    int i;
    for ( i=0;i<strlen(s);i++){
        if ((s[i]>='A')&&(s[i]<='Z')) continue;
        else if ((s[i]>='a')&&(s[i]<='z')) continue;
        else if ((s[i]>='0')&&(s[i]<='9')) continue;
        else if (s[i]==' ') spaceCount++;
        else return 0;
    }
    if (spaceCount==strlen(s)) return 0;
    return 1;
}
//KIEM TRA DINH DANG NAME----------------------------------------
int checkName(char*s)
{
    int spaceCount=0;
    int i;
    for (i=0;i<strlen(s);i++){
        if ((s[i]>='A')&&(s[i]<='Z')) continue;
        else if ((s[i]>='a')&&(s[i]<='z')) continue;
        else if (s[i]==' ') spaceCount++;
        else return 0;
    }
    if (spaceCount==strlen(s)) return 0;
    return 1;
}
int Search(char*s)
{  int i;
    for ( i=1;i<=n;i++)
        if ((strcmp(name[i],s)==0)||(strcmp(code[i],s)==0)) return i;
    return 0;
}
void corectCode(char*s)
{
    //Mang CODE dung de luu lai CODE khi da correct
    char*code=(char*)calloc(50,sizeof(char));
    int j=-1;
    int i;
    for (i=0;i<strlen(s);i++)
        //XOA TAT CA DAU CACH
        if (s[i]==' ') continue;
        else{
            j++;
            code[j]=toupper(s[i]);       
        }
    strcpy(s,code);
    free(code);
}
void corectName(char*s)
{
    char*name=(char*)calloc(50,sizeof(char));
    int j=-1;
    int i;
    for (i=0;i<strlen(s);i++)
        //Nhieu dau cach
        if ((s[i]==' ')&&(s[i+1]==' ')) continue;
        //dau cach o dau ten
        else if ((j==-1)&&(s[i]==' ')) continue;
        //dau cach o cuoi ten
        else if ((i==strlen(s)-1)&&(s[i]==' ')) continue;
        else{
            j++;
            name[j]=s[i];
            if (name[j-1]==' ') name[j]=toupper(name[j]);
            else name[j]=tolower(name[j]);            
        }
    //Chu cai dau viet hoa
    name[0]=toupper(name[0]);
    strcpy(s,name);
    free(name);
}
void Input()
{  
    char *s1=(char*)calloc(50,sizeof(char));
    char *s2=(char*)calloc(50,sizeof(char));
    int j=-1;
        printf("Type employee's code to add: \n");
        fflush(stdin); scanf("%[^\n]",s1); 
        corectCode(s1);
        if (checkCode(s1)==0)
        {     
            printf("WRONG CODE FORMAT!\n");
            return;
        }
        printf("Enter employee's name: \n");
        fflush(stdin); scanf("%[^\n]",s2);
        corectName(s2);
        if (checkName(s2)==0){
            printf("WRONG NAME FORMAT!\n");
            return;
        }
        //Kiem tra ten da co hay chua
        if ((Search(s1)!=0)||(Search(s2)!=0)) 
        {
            printf("Name or Code are Adready Exits!\n");
            return;
        } 
    n++;
    strcpy(code[n],s1);
    strcpy(name[n],s2);
    printf("Enter salary : "); scanf("%lf",&salary[n]);
    printf("Enter allowance: "); scanf("%lf",&allowance[n]);
    free(s1);
    free(s2);
    
}
void Find()
{
    char*s=(char*)calloc(50,sizeof(char));
    printf("Enter employee's name to find: ");
    fflush(stdin); scanf("%[^\n]",s);  
    corectName(s);
    int possition=Search(s);
    if (possition!=0){
        printf("-----------------------------------------------\n");
        printf("Employee \"%s\" is at possition: %d\n",name[possition],possition);
        printf("Code of the employee: %s\n", code[possition]);
        printf("Salary: %.0lf\n",salary[possition]);
        printf("Allowance: %.0lf\n",allowance[possition]);
        printf("-----------------------------------------------\n");
    }
    else printf("Name not found!\n");
    free(s);
}
void Remove()
{
    char*s=(char*)calloc(50,sizeof(char));
    printf("Type CODE of employees to remove: ");
    fflush(stdin); scanf("%[^\n]",s);
    corectCode(s);
    //Tim vi tri xoa
    int possition=Search(s);
    if (possition==0){
        printf("Code \"%s\" not found!\n",s);
        return;
    }
    //update list 
    strcpy(code[possition],code[n]);
    strcpy(name[possition],name[n]);
    salary[possition]=salary[n];
    allowance[possition]=allowance[n];
    n--;
    printf("Employee remove!\n");
    free(s);
}

void swapInt(double*a,double*b)
{
    double t=*a;
    *a=*b;
    *b=t;
}
void swapString(char*a,char*b)
{
    char *c=(char*)calloc(50,sizeof(char));
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
    free(c);
}
void Sort()
{
    double soft[100];
    int i, j;
    for ( i=1;i<=n;i++) soft[i]=salary[i]+allowance[i];
    for ( i=1;i<n;i++)
        for (j=i+1;j<=n;j++)
            if (soft[i]<soft[j]){
                swapInt(&soft[i],&soft[j]);
                swapInt(&salary[i],&salary[j]);
                swapInt(&allowance[i],&allowance[j]);
                swapString(code[i],code[j]);
                swapString(name[i],name[j]);
            }
}
void Output()
{
    Sort();
    int i;
    for (i=1;i<=n;i++){
        printf("CODE: --%s--\n",code[i]);
        printf("NAME: %s\n",name[i]);
        printf("SALARY: %.0lf\n",salary[i]);
        printf("ALLOWANCE: %.0lf\n",allowance[i]);
    }
}
//---------------------------------------------------------------
int getKey()
{
    char*key=(char*)calloc(50,sizeof(char));
    system("cls");
    printf("1- Adding a new employee\n");
    printf("2- Find data about employees unsing a name inputted\n");
    printf("3- Remove an employee based on a code inputted\n");
    printf("4- Print the list in descending order based on salary + allowance\n");
    printf("5- Quit\n");
    printf("YOUR CHOICE (1/2/3/4/5) ?\n");
    fflush(stdin); scanf("%[^\n]",key);
    if (strlen(key)!=1) return 0;
    if ((key[0]<'0')||(key[0]>'9')) return 0;
    return (int)(key[0])-48;
    free(key);
}
//---------------------------------------------------------------
int main()
{
    int key=0;
    while (key!=5)
    {
        key=getKey(); 
        switch(key)
        {
            case 1:
                Input();
                break;
            case 2:
                Find();
                break;
            case 3:
                Remove();
                break;
            case 4:
                Output();
                break;
            case 5: 
                printf("Program excuted !\n");
                break;
            default:
                printf("Choice again\n");
                break;
        }
        system("pause");
    }
    return 0;
}