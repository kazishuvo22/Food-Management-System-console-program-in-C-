#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct food
{
    char name[100];
    char quality[100];
    char catagory[100];
    char code[100];
    float protine;
    float fat;
    float calorie;
    float price;


};
void main_menu();
void add_food();
void search();
void list();
void Delete();

int main()
{
    main_menu();

    return 0;
}

void main_menu()
{
    int n;

    system("COLOR 89");

    printf("\n\n");
    printf("\t\t\t$$$$$============================$$$$$");
    printf("\n\t\t\t\tFood Management System");
    printf("\n\t\t\t$$$$$============================$$$$$");
    printf("\n\n");
    printf("\n\t\t   Projected By Kamruzzman Shuvo");
    printf("\n\t\t\t.........................................\t\t\t\n\n");
    printf("\n\t\t\t1.Add Food's Record:\t\t\t");
    printf("\n\t\t\t2.Foods List:\t\t\t");
    printf("\n\t\t\t3.Search Food:\t\t\t");
    printf("\n\t\t\t4.Delete Food Record:\t\t\t");
    printf("\n\t\t\t5.Exit");
    printf("\n\n");
    printf("\n\t\t\t@@Select an integer of 1 to 5 for next step@@\t\t\t");

do
    {
        printf("\n\t\t\tEnter your integer in main menu:");
        scanf("%d",&n);
        printf("\n\n\n");

        switch(n)
        {
             case 1:
                add_food();
                break;
            case 2:
                list();
                break;
            case 3:
                search();
                break;
            case 4:
                Delete();
                break;
            case 5:
                printf("\n\t\t\tThank you for using the program..... :)\n\n\n");
                break;
            default:
                printf("\n\t\t\tWrong choice....Check the MAIN MENU again...\n");

        }
    }
    while(n!=5);

}

void add_food()
{

    struct food f;

    FILE *fp;
    fp=fopen("record.txt","a");

    printf("\t\t\t=======================\n");
    printf("\t\t\tADD FOOD RECORD\n");
    printf("\t\t\t=======================\n\n");

    if(fp==NULL)
        printf("Error!!!!\n");
    else
    {
        getc(stdin);
        printf("Enter Food's code:\t");
        scanf("%s",f.code);
        fflush(stdin);

        printf("\nEnter Food's Name:\t");
        scanf("%s",f.name);
        fflush(stdin);

        printf("\nEnter Food's Catagory:\t");
        scanf("%s",f.catagory);
        fflush(stdin);

        printf("\nEnter Food's Quality:\t");
        scanf("%s",f.quality);
        fflush(stdin);

        printf("\nEnter Food's Protine(in Percent):\t");
        scanf("%f",&f.protine);
        fflush(stdin);

        printf("\nEnter Food's Calorie(in Percent):\t");
        scanf("%f",&f.calorie);
        fflush(stdin);

        printf("\nEnter Food's Fat(in Percent):\t");
        scanf("%f",&f.fat);
        fflush(stdin);

        printf("\nEnter Food's Price(in TK):\t");
        scanf("%f",&f.price);

        fprintf(fp,"\n%s %s %s %s %f %f %f %f\n",f.code,f.name,f.catagory,f.quality,f.protine,f.calorie,f.fat,f.price);


        printf("\n\t\t\tThe Record is successfully added....\n");


    }
    fclose(fp);
}


void search()
{

    char target[20];
    struct food f;
    FILE *fp;
    fp=fopen("record.txt","r");

    printf("\t\t\t========================\n");
    printf("\t\t\tSearch Food Record\n");
    printf("\t\t\t========================\n\n");
    printf("\n\t\t\tEnter the Food code to search: ");
    scanf("%s",target);

    if(fp==NULL)
    {
        printf("\n\t\t\tThe Files does not exist..Try Again...\n");
    }
    else
    {
        while(fscanf(fp,"\n%s %s %s %s %f %f %f %f\n",f.code,f.name,f.catagory,f.quality,&f.protine,&f.calorie,&f.fat,&f.price)!=EOF)
        {
            if(strcmp(target,f.code)==0)
            {
                printf("\n\t\t\tFood Code: %s",f.code);
                printf("\n\t\t\tFood Name: %s",f.name);
                printf("\n\t\t\tFood catagory: %s",f.catagory);
                printf("\n\t\t\tFood Qualitiy: %s",f.quality);
                printf("\n\t\t\tFood's Protine: %f",f.protine);
                printf("\n\t\t\tFood's Calorie: %f",f.calorie);
                printf("\n\t\t\tFood's Fat: %f",f.fat);
                printf("\n\t\t\tFood's Price: %f",f.price);

            }
            else
            {
                printf("\n\t\t\tFood information is not found....\n");
            }

        }

    }
    fclose(fp);


}
void list()
{
    printf("\t\t\t========================\n");
    printf("\t\t\tALL FOODS RECORDS....\n");
    printf("\t\t\t========================\n\n");

    struct food f;
    int count=0;
    FILE *fp;
    fp=fopen("record.txt","r");
    if(fp==NULL)
    {
        printf("\n\t\t\tThe Record Files does not Exist....Try Again...\n");
    }
    else
    {
        while(fscanf(fp,"\n%s %s %s %s %f %f %f %f\n",f.code,f.name,f.catagory,f.quality,&f.protine,&f.calorie,&f.fat,&f.price)!=EOF)
        {

                printf("\n\t\t\tFood Code: %s",f.code);
                printf("\n\t\t\tFood Name: %s",f.name);
                printf("\n\t\t\tFood Catagory: %s",f.catagory);
                printf("\n\t\t\tFood Qualitiy: %s",f.quality);
                printf("\n\t\t\tFood's Protine: %f",f.protine);
                printf("\n\t\t\tFood's Calorie: %f",f.calorie);
                printf("\n\t\t\tFood's Fat: %f",f.fat);
                printf("\n\t\t\tFood's Price: %f",f.price);
                printf("\n\n");

                count++;
        }
        printf("\n\t\t\tTotal Number of Foods = %d\n",count);
    }
    fclose(fp);
}

void Delete()
{
    printf("\t\t\t=======================\n");
    printf("\t\t\tDELETE FOOD RECORDS\n");
    printf("\t\t\t=======================\n\n");

    struct food f;
    char target[20];

    printf("\n\t\t\tEnter the food code to delete: ");
    scanf("%s",target);

    FILE *fp,*fq;

    fp=fopen("record.txt","r");
    fq=fopen("temp.txt","a");

        while(fscanf(fp,"\n%s %s %s %s %f %f %f %f\n",f.code,f.name,f.catagory,f.quality,&f.protine,&f.calorie,&f.fat,&f.price)!=EOF)
        {
            if(strcmp(target,f.code)!=0)
            {
              fprintf(fq,"\n%s %s %s %s %f %f %f %f\n",f.code,f.name,f.catagory,f.quality,f.protine,f.calorie,f.fat,f.price);

            }
        }

    fclose(fp);
    fclose(fq);

    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("\n\t\t\tThe Food record is deleted successfully....\n");

}
