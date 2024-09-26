#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person 
{
    char name[30];
    char country_code[4];
    unsigned long long int mble_no;
    char gender[8];
    char mail[100];
};

typedef struct person person;

void remove_all();
void print_menu();
void add_person();
void list_record();
void search_person();
void remove_person();
void update_person();
void take_input(person *p);
void start();

int main() 
{
    start();
    return 0;
}

void start() 
{
    int choice;
    while (1) 
    {
        print_menu();
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                list_record();
                getchar();
                getchar();
                break;
            case 2:
                add_person();
                getchar();
                getchar();
                break;
            case 3:
                search_person();
                getchar();
                getchar();
                break;
            case 4:
                remove_person();
                getchar();
                getchar();
                break;
            case 5:
                update_person();
                getchar();
                getchar();
                break;
            case 6:
                remove_all();
                getchar();
                getchar();
                break;
            default:
                system("cls");
                printf("Exiting the Phonebook.\n");
                getchar();
                getchar();
                exit(1);
        }
    }
}

void print_menu() 
{
    system("cls");
    printf("\t\t---------------------------------------------------------------\n");
    printf("\t\t Welcome TO Phone Book using C\n");
    printf("\t\t---------------------------------------------------------------\n\n");
    printf("\t\t\t1) Show records\n\n");
    printf("\t\t\t2) Add person\n\n");
    printf("\t\t\t3) Search person Details\n\n");
    printf("\t\t\t4) Remove person\n\n");
    printf("\t\t\t5) Update person\n\n");
    printf("\t\t\t6) Delete all contacts\n\n");
    printf("\t\t\t7) Exit Phonebook\n\n\n");

    printf("\t\t\t\tEnter your Choice : ");
}

void add_person() 
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook_db", "ab+");
    if (fp == NULL) 
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } 
    else 
    {
        person p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        system("cls");
        printf("Record added Successfully\n");
        printf("Press any key to continue ....\n");
    }
}

void take_input(person *p) 
{
    system("cls");
    getchar();
    printf("Enter name : ");
    scanf("%[^\n]s", p->name);

    printf("Enter Country code : ");
    scanf("%s", p->country_code);

    printf("Enter Mobile no : ");
    scanf("%llu", &p->mble_no); 

    printf("Enter Gender : ");
    scanf("%s", p->gender);

    printf("Enter Email : ");
    scanf("%s", p->mail);
}

void list_record() 
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook_db", "rb"); 
    if (fp == NULL) 
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } 
    else 
    {
        person p;
        printf("\n\t\t\t\t----------------------------------------------------------------------------\n");
        printf("\t\t\t\t  Here is all records listed in phonebook\n");
        printf("\t\t\t\t------------------------------------------------------------------------------\n\n\n");
        printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    GENDER\t\t             EMAIL\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&p, sizeof(p), 1, fp) == 1) 
        {
            int i;
            int len1 = 40 - strlen(p.name);
            int len2 = 19 - strlen(p.country_code);
            int len3 = 15;
            int len4 = 21 - strlen(p.gender);
            printf("%s", p.name);
            for (i = 0; i < len1; i++) printf(" ");

            printf("%s", p.country_code);
            for (i = 0; i < len2; i++) printf(" ");

            printf("%llu", p.mble_no);  // Use %llu for unsigned long long
            for (i = 0; i < len3; i++) printf(" ");

            printf("%s", p.gender);
            for (i = 0; i < len4; i++) printf(" ");

            printf("%s", p.mail);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }
}

void search_person() 
{
    system("cls");
    unsigned long long int phone;
    printf("Enter Phone number of the person you want to search : ");
    scanf("%llu", &phone); 

    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL) 
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } 
    else 
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1) 
        {
            if (p.mble_no == phone) {
                printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    GENDER\t\t             EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
                int i;
                int len1 = 40 - strlen(p.name);
                int len2 = 19 - strlen(p.country_code);
                int len3 = 15;
                int len4 = 21 - strlen(p.gender);
                printf("%s", p.name);
                for (i = 0; i < len1; i++) printf(" ");

                printf("%s", p.country_code);
                for (i = 0; i < len2; i++) printf(" ");

                printf("%llu", p.mble_no);  
                for (i = 0; i < len3; i++) printf(" ");

                printf("%s", p.gender);
                for (i = 0; i < len4; i++) printf(" ");

                printf("%s", p.mail);
                printf("\n");

                flag = 1;
                break;
            } 
            else 
                continue;
        }
        if (flag == 0) 
        {
            system("cls");
            printf("Person is not in the Phonebook\n");
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }
}

void remove_person()
{
    system("cls");
    unsigned long long int phone;
    printf("Enter Phone number of the person you want to remove from phonebook : ");
    scanf("%llu", &phone); 

    FILE *fp, *temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp", "wb+");
    if (fp == NULL) 
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } 
    else 
    {
        person p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1) 
        {
            if (p.mble_no == phone) 
            {
                system("cls");
                printf("Person removed successfully\n");
                flag = 1;
            } 
            else 
                fwrite(&p, sizeof(p), 1, temp);
            fflush(stdin);
        }
        if (flag == 0) 
        {
            system("cls");
            printf("No record found for %llu number\n", phone); \
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp", "phonebook_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}

void update_person() 
{
    system("cls");
    unsigned long long int phone;
    printf("Enter Phone number of the person you want to update details : ");
    scanf("%llu", &phone); 

    FILE *fp, *temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp", "wb+");
    if (fp == NULL) 
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } 
    else 
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1) 
        {
            if (p.mble_no == phone) 
            {
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("cls");
                printf("Data updated successfully\n");
                flag = 1;
            } 
            else 
                fwrite(&p, sizeof(p), 1, temp);
            fflush(stdin);
        }
        if (flag == 0) 
        {
            system("cls");
            printf("No record found for %llu number\n", phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp", "phonebook_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}

void remove_all() 
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook_db", "wb");
    if (fp == NULL) 
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } 
    else 
    {
        fclose(fp);
        printf("All records deleted successfully !\n");
        printf("Press any key to continue....\n");
    }
}
