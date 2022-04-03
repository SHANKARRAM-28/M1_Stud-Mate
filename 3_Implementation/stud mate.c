#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct student
{
    char name[35];
    char ID_no[20];
    char std&sec[30];
    long int mobile_no;
    char address[50];
    char father_name[35];
    char mother_name[30];
    char gender[8];

    };
void menu();
void got();
void start();
void back();
void adda();
void lista();
void modifya();
void deletea();
void searcha();
int main()
{
    system("color B");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
printf("\t\t**********STUDMATE*************");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.ADD STUDENT   \t2.LIST   \t3.EXIT  \n\t4.MODIFY \t5.SEARCH\t6.DELETE");

switch(getch())
{
    case '1':

                adda();
    break;
   case '2': lista();
    break;
    case '3': exit(0);
    break;
    case '4': modifya();
    break;
    case '5': searcha();
    break;
    case '6': deletea();
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n ENTER ANY KEY");
                getch();

menu();
}
}
        void adda()
{
        system("cls");
        FILE *f;
        struct student s;
        f=fopen("project","ab+");
        printf("\n ENTER NAME: ");
        got(s.name);
        printf("\nENTER STUDENT ID: ");
        got(s.ID_no);
        printf("\nSTD & SEC:");
        scanf("%ld",&s.std&sec);
        printf("ENTER MOBILE NUMBER:");
        got(s.mobile_no);
        printf("\nENTER ADDRESS:");
        got(s.address);
	printf("\nENTER FATHER NAME: ");
        got(s.father_name);
        printf("\nENTER MOTHER NAME: ");
        got(s.mother_name);
        printf("\nENTER GENDER:");
        got(s.gender);
        fwrite(&s,sizeof(s),1,f);

      fflush(stdin);
        printf("\nDETAILS SAVED SUCCESSFULLY");

fclose(f);

    printf("\n\nENTER ANT KEY");

	 getch();
    system("cls");
    menu();
}
void lista()
{
    struct student s;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nFILE OPENING ERROR :");

exit(1);
}
while(fread(&s,sizeof(s),1,f)==1)
{
     printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nNAME=%s\nSTUDENT ID=%s\nSTD & SEC=%s\nENTER MOBILE NUMBER=%s\nENTER ADDRESS=%ld\nENTER FATHER NAME=%s\nENTER MOTHER NAME=%s\nENTER GENDER=%s",s.name,s.ID_no,s.std&sec,s.mobile_no,s.address,s.father_name,s.mother_name,s.gender);

	 getch();
	 system("cls");
}
fclose(f);
 printf("\n ENTER ANT KEY");
 getch();
    system("cls");
menu();
}
void searcha()
{
    struct student s;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\n ERROR IN OPENING\a\a\a\a");
    exit(1);

}
printf("\nENTER THE NAME FOR SEARCH\n");
got(name);
while(fread(&s,sizeof(s),1,f)==1)
{
    if(strcmp(s.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nNAME:%s\nSTUDENT ID:%s\nSTD & SEC:%s\nMOBILE NUMBER:%s\nADDRESS:%ld\nFATHER NAME:%s\nMOTHER NAME:%s\nGENDER:%s",s.name,s.ID_no,s.std&sec,s.mobile_no,s.address,s.father_name,s.mother_name,s.gender);
    }
        else
        printf("FILE NOT FOUND");

}
 fclose(f);
  printf("\n ENTER ANY KEY");

	 getch();
    system("cls");
menu();
}
void deletea()
{
    struct student s;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("FILE OPENING ERROE");
		else

        {


		printf("ENTER CONTACT'S NAME:");
		got(name);

		fflush(stdin);
		while(fread(&s,sizeof(s),1,f)==1)
		{
			if(strcmp(s.name,name)!=0)
				fwrite(&s,sizeof(s),1,ft);
			if(strcmp(s.name,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("NO CONACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf("RECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n ENTER ANY KEY");

	 getch();
    system("cls");
menu();
}

void modifya()
{
    int c;
    FILE *f;
    int flag=0;
    struct student s,z;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            got(name);
            while(fread(&s,sizeof(s),1,f)==1)
            {
                if(strcmp(name,s.name)==0)
                {



                    printf("\n ENTER NAME: ");
                    got(z.name);
                    printf("\nENTER STUDENT ID: ");
                    got(z.ID_no);
                    printf("\nSTD & SEC:");
                    scanf("%ld",&p.std&sec);
                    printf("ENTER MOBILE NUMBER:");
                    got(z.mobile_no);
          	    printf("\nENTER ADDRESS:");
        	    got(z.address);
		    printf("\nENTER FATHER NAME: ");
       		    got(z.father_name);
        	    printf("\nENTER MOTHER NAME: ");
        	    got(z.mother_name);
        	    printf("\nENTER GENDER:");
        	    got(z.gender);
                    fseek(f,-sizeof(s),SEEK_CUR);
                    fwrite(&z,sizeof(s),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n YOUR DATA ID MODIFIED");

            }
            else
            {
                    printf(" \n DATA NOT FOUND");

            }
            fclose(f);
	}
	 printf("\n ENTER ANY KEY");
	 getch();
    system("cls");
	menu();

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
