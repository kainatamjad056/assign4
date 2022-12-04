#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void choice();
void addpatient();
void deletepatient();
void display();
struct patient //structure having patient record
{
    int id;
    char name[20];
    char cnic[13];
    char phone[11];
    char disease[20];
    char isadmitted[10];
};
int main()
{
     choice();  
}
void choice() //function to give choice to user to select
{
int cho=0;

while(cho!=6)
{
    printf(" 1. Add Patient\n 2. Delete Patient\n 3. Update Patient\n 4. Search Patient\n5. Display all records !\n 6. EXIT !\n");
printf("Enter your choice: ");
scanf("%d", &cho);
if (cho == 1)
{
    addpatient();
}
if (cho == 2)
{
    deletepatient();
}
if (cho == 3)
{
 update();
}
if (cho == 4)
{
 tosearch();
}
if (cho == 5)
{
 displayrecord();
}
if (cho == 6)
{
printf("exit");
exit(0);
}

}
}
void addpatient() //function to get patient's data from user
{
    struct patient patient1;
    FILE* ptr;
    
    printf("------PATIENT'S INFORMATION------\n");
    printf("Enter patient's ID\n");
     scanf("%d",&patient1.id);
     fflush(stdin);
    printf("Enter patient's NAME \n");
    gets(patient1.name);
    fflush(stdin);

    printf("Enter patient's PHONE NUMBER (i.e: XXXXXXXXXX)\n");
    gets(patient1.phone);
    fflush(stdin);
    while(strlen(patient1.phone)>11||strlen(patient1.phone)<11)
     {
        printf("Please enter only 11 digit phone number\n");
        gets(patient1.phone);
        fflush(stdin);
     }
    
     


    printf("Enter patient's CNIC (i.e: XXXXXXXXXXXXX)\n");
    gets(patient1.cnic);
    fflush(stdin);
    while(strlen(patient1.cnic)>13||strlen(patient1.cnic)<13)
     {
        printf("Please enter only 13 digit CNIC number\n");
        gets(patient1.cnic);
        fflush(stdin);
     }


    printf("Enter patient's Disease \n");
    gets(patient1.disease);
    fflush(stdin);

    printf("Patient is admitted or not? \n");
    gets(patient1.isadmitted);
    fflush(stdin);

    ptr = fopen("Precord.txt", "a"); //opening file to write data
    fwrite(&patient1,sizeof(struct patient),1,ptr);
    fclose(ptr);
    displayfile();
}
void deletepatient() //function to delete patient's record
{

    FILE* fp1, * fp2;  //pointers to file
    struct patient patient1;
    fp1 = fopen("Precord.txt", "r");
    fp2 = fopen("copy.txt", "w");

    if (fp1 == NULL)
    {
        fprintf(stderr, "Can't open file");
        exit(0);
    }
    if (fp1 != NULL) //incase the file is not empty
    {
    int id;
    printf("Enter the ID you want to delete");
     scanf("%d",&id);

    while (fread(&patient1,sizeof(struct patient),1,fp1))
    {
        if (id != patient1.id) 
        {
            fwrite(&patient1, sizeof(struct patient), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
fp1 = fopen("Precord.txt", "w");
    fp2 = fopen("copy.txt", "r");
    while (fread(&patient1, sizeof(struct patient), 1, fp2))
        {
            fwrite(&patient1, sizeof(struct patient), 1, fp1);
        }
fclose(fp1);
fclose(fp2);
remove("copy.txt");
printf("Record deleted successfully");
}
displayfile();
}
