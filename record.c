void update();
void tosearch();
void displayrecord();
void displayfile();
void update()
{
    FILE* fp1, * fp2;
    struct patient patient1;
    fp1 = fopen("Precord.txt", "r");         //opening two files one in reading and other in writing
    fp2 = fopen("update.txt", "w");

    if (fp1 == NULL)
    {
        fprintf(stderr, "Can't open file");         //if file is not open then exit
        exit(0);
    }
    if (fp1 != NULL)
    {
    int id;
    printf("Enter the ID you want to update:");            //ask user to what id he wants to update
     scanf("%d",&id);

    while (fread(&patient1,sizeof(struct patient),1,fp1))         //read address of data from patientrecord file
    {
        if (id == patient1.id)
        {                                           // if ids are same then
            int choice=0;
            printf("updation is:");
            printf("type 1 to update phone no:\n type 2 to update disease:\ntype3 to update admit or not:\ntyppe 4 to continue:");
            printf("select:");
            scanf("%d",&choice);            //as we cant change user name and cnic because they are permanent 
            fflush(stdin);
            if(choice==1)
            {
            while(strlen(patient1.phone)>11||strlen(patient1.phone)<11)
            {  
        printf("Please enter only 11 digit phone number\n");
        gets(patient1.phone);
        fflush(stdin);
            }
            }
            else if(choice==2)
            {
                printf("\nenter disease:");
                gets(patient1.disease);
                fflush(stdin);
            }
            else if(choice==3)
            {
                printf("\nenter admit or not:");
                gets(patient1.isadmitted);
                fflush(stdin);
            }
            else if (choice==4)
            {
                id != patient1.id;
            }
        }
        fwrite(&patient1, sizeof(struct patient), 1, fp2);   //writing into 2 file
    }
    fclose(fp1);
    fclose(fp2);                                            // closing files
fp1 = fopen("Precord.txt", "w");
    fp2 = fopen("update.txt", "r");
    while (fread(&patient1, sizeof(struct patient), 1, fp2))
        {
            fwrite(&patient1, sizeof(struct patient), 1, fp1);          //now open both files and convert 2 data into 1
        }
fclose(fp1);
fclose(fp2);
remove("update.txt");
printf("Record is updated successfully");            //display message
}
displayfile();
}

void tosearch()
{
        FILE* fp;
    struct patient patient1;
    fp = fopen("Precord.txt", "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Can't open file");
        exit(0);
    }
    if (fp != NULL)
    {
    int id;
    int counter=0;
    printf("Enter the ID you want to search");
     scanf("%d",&id);

    while (fread(&patient1,sizeof(struct patient),1,fp))
    {
        if (id == patient1.id)
        {
            printf("id of patient = %d\n", patient1.id);              // to search a specific id and print it on console 
            printf("name of patient= %s\n", patient1.name);
            printf("cnic of patient= %s\n", patient1.cnic);
            printf("phone no of patient= %s\n", patient1.phone);
            printf("disease of patient= %s\n", patient1.disease);
            printf("Patient is admitted or not = %s\n\n", patient1.isadmitted);
            counter++;  
    }
    }
    fclose(fp);
}
displayfile();
}
void displayrecord()
{
    
    FILE* ptr;
    struct patient p;
int count = 0;
    ptr = fopen("Precord.txt", "r");
    if (ptr == NULL)
    {
        fprintf(stderr, "not open");
        exit(0);                                             //to display updated record on console
    }
    else
    {
        while (fread(&p, sizeof(struct patient), 1, ptr))
        {
            printf("ID = %d\n", p.id);
            printf("NAME = %s\n", p.name);
            printf("CNIC = %s\n", p.cnic);
            printf("PHONE = %s\n", p.phone);
            printf("DISEASE = %s\n", p.disease);
            printf("ISADMITTED = %s\n\n", p.isadmitted);
            count++;
        }
        fclose(ptr);
    }
    if (count == 0)
    {
        printf("there is no record\n");
    }
}
void displayfile()
{
    struct patient p;
    FILE *ptr1, *ptr2;                                      //to display changes in file we make another function
    
    ptr1 = fopen("Precord.txt","r");
    ptr2 = fopen("PATIENT'S_RECORD.txt","w");
    
    fprintf(ptr2,"%-2s\t\t%-20s%-13s%-11s%-20s%-10s\n","ID","NAME","CNIC","PHONE","DISEASE","ISADMIITED");
    while(fread(&p,sizeof(struct patient),1,ptr1))
    {
        fprintf(ptr2,"%-2d\t\t%-20s%-13s%-11s%-20s%-10s\n",p.id,p.name,p.cnic,p.phone,p.disease,p.isadmitted);  
    }
    fclose(ptr1);
    fclose(ptr2);
}