#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

typedef struct student{
    char name[100];
    char roll[100];
    int batch;
    char cgpa[100];
    char mobile[100];
    char pass[100];
}st;

    FILE *fp;
    char ro[100];
    int ind;
void authority();
void add();
void print(int a);
void info(char c[]);
void fill_info();
void student(int a);
int login();
void change_p(char c[]);
void update_cgpa(char c[]);
void reset();

int main(){

    int choice;
    do{
    printf("\n\tInformation of CSE Department Student's\n\n");
    printf("1 : Authority\n");
    printf("2 : Fill Information\n");
    printf("3 : Log in to your Account\n");
    printf("4 : Exit\n\n");
    printf("Enter your Choice.....\t");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    authority();
        break;
    case 2:
    fill_info();
        break;
    case 3:
        student(login());
        break;
    case 4:
        break;
    default:
        printf("\nInvalid choice ! \n");
        printf("\nPress any key to continue...");
        getch();
        break;
    }

    }while(choice != 4);
    return 0;
}

void authority()
{
    char nm[100],pass[100];
    printf("\nEnter Name : ");
    scanf("%s",&nm);
    printf("Enter Password : ");
    scanf("%s",&pass);
    if(strcmp(nm,"teacher")==0 && strcmp(pass,"1234")==0){}
    else{
        printf("Login failed \n");
        return;
    }
    int ch;
    do{
    printf("\n1.Add a student\n");
    printf("2.Update CGPA\n");
    printf("3.Batch wise Info\n");
    printf("4.Individual Info\n");
    printf("5.reset\n");
    printf("6.Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    int b;
    char c[100];
    switch (ch)
    {
        case 1:
        add();
        break;

        case 2:
        printf("\nEnter student Roll : ");
        scanf("%s", &c);
        update_cgpa(c);
        break;

        case 3:
        printf("\nEnter Batch Number : ");
        scanf("%d", &b);
        print(b);
        break;

        case 4:
        printf("\nEnter student Roll : ");
        scanf("%s", &c);
        info(c);
        break;

        case 5:
            reset();
        break;
        case 6:
            break;

        default:
        printf("\nInvalid choice\n");
    }
    }while(ch!=6);

}

void add()
{
    st st1;
    fp=fopen("info.txt","a+b");
    printf("\nEnter student's Batch :");
    scanf("%d",&st1.batch);
    printf("Enter student roll :");
    scanf("%s",&st1.roll);
    printf("Enter student's CGPA : ");
    scanf("%s",&st1.cgpa);
    printf("\nStudent Added.\n");

    fwrite(&st1, sizeof(st), 1, fp);
    fclose(fp);
}

void print(int a)
{
    int j=1;
    st st1;
    fp=fopen("info.txt","rb");
    printf("\n\t Batch %d\n\n",a);
    for(int i=0;i<100;i++)printf("-");
    printf("\n%-10s%-22s%-15s%-20s%-20s\n","Sl No","Roll Number","Name","CGPA","Mobile");
    for(int i=0;i<100;i++)printf("-");

    while(fread(&st1,sizeof(st),1,fp)){
    if(st1.batch==a){
    printf("\n  %-10d%-20s%-15s%-20s%-20s\n",j,st1.roll,st1.name,st1.cgpa,st1.mobile);
    for(int i=0;i<100;i++)printf("-");
    j++;}

    }
    fclose(fp);

    printf("\n\nPress any key to continue...");
    getch();

}

void fill_info()
{
    fp=fopen("info.txt", "r+b");
    st st1;
    char ch[100];
    int done=0,ct=0;
    printf("\nEnter your Roll : ");
    scanf("%s", &ch);

    while(fread(&st1, sizeof(st),1,fp))
    {
        if(strcmp(ch,st1.roll)==0)
        {
            done=1;
            printf("\nEnter your Name : ");
            scanf("%s", st1.name);
            printf("Enter your Mobile  : ");
            scanf("%s", st1.mobile);
            printf("Create a Password : ");
            scanf("%s", st1.pass);
            printf("\nInformation Stored \n");

            fseek(fp,ct*sizeof(st),SEEK_SET);
            fwrite(&st1,sizeof(st),1,fp);

            break;
        }
        ct++;
    }
    fclose(fp);
    if(done==0)printf("\nInvalid Roll\n");
}

void student(int a)
{
    if(a==1){
 int cho;
    do{
    printf("\n1 : Account information\n");
    printf("2 : Change Password\n");
    printf("3 : Exit\n\n");
    printf("Enter your Choice.....\t");
    scanf("%d",&cho);
    switch (cho)
    {
    case 1:
    info(ro);
        break;
    case 2:
    change_p(ro);
        break;
    case 3:
        break;
    default:
        printf("\nInvalid choice ! \n");
        printf("\nPress any key to continue...");
        getch();
        break;
    }

    }while(cho != 3);
    }
    else printf("Log in failed\n");
}

int login()
{
    st st1;
    fp=fopen("info.txt", "rb");
    char r[100];
    int ct1=0;
    printf("\nEnter your roll : ");
    scanf("%s", &r);
    int done=0;
    while(fread(&st1, sizeof(st),1,fp))
    {
        if(strcmp(st1.roll,r)==0)
        {
            done =1;
            char p[100];
            printf("Enter your Password: ");
            scanf("%s", &p);
            strcpy(ro,r);
            if(strcmp(p,st1.pass)==0){ind=ct1; return 1;}
            return 0;
        }
        ct1++;
    }
    if(!done)return 0;
}

void info(char c[])
{
    st st1;
    int done =0;
    fp=fopen("info.txt","rb");

    while(fread(&st1,sizeof(st),1,fp))
    {
        if(strcmp(c,st1.roll)==0)
        {
            done =1;
            printf("\nName : %s\n",st1.name);
            printf("Roll : %s\n",st1.roll);
            printf("Batch : %d\n",st1.batch);
            printf("CGPA : %s\n",st1.cgpa);
            printf("Mobile Number : %s\n",st1.mobile);
            break;
        }
    }
    fclose(fp);
}

void change_p(char c[])
{
    fp=fopen("info.txt", "r+b");
    st st1;
    while(fread(&st1, sizeof(st), 1, fp)){
        if(strcmp(st1.roll,ro)==0)break;
    }
    printf("Enter new Password :");
    scanf("%s", &st1.pass);
    fseek(fp,ind*sizeof(st), SEEK_SET);
    fwrite(&st1, sizeof(st), 1, fp);
    fclose(fp);
    printf("Password Changed");
}

void update_cgpa(char c[])
{
    st st1;
    fp=fopen("info.txt", "r+b");
    int in=0;
    while(fread(&st1,sizeof(st1), 1, fp))
    {
        if(strcmp(c,st1.roll)==0){
            printf("Enter new CGPA : ");
            scanf("%s",&st1.cgpa);
            break;
        }
        in++;
    }
    fseek(fp,in*sizeof(st),SEEK_SET);
    fwrite(&st1,sizeof(st),1,fp);
    fclose(fp);
}

void reset()
{
    remove("info.txt");
}

