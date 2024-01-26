#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setAction();
int doAction(int action);
void addContact();
void listContacts();
void searchContact();
void deleteContact();
int strcmpCustom(char* s1,char* s2);
void writeText(char* name,char* phone);
void writeNewText();
void getContactFromFile();


int last = 0;
int capacity = 50;

struct contact{
	char name[30];
	char phone[30];
}A[50];

void main()
{
    getContactFromFile();
    setAction();
}

void setAction(){

    int action;
    printf("------------------- \n");
    printf("- what do yo want ? \n");
    printf("+ for add contact press 1 \n");
    printf("+ for search contact press 2 \n");
    printf("+ for delete contact press 3 \n");
    printf("+ for watch list of contacts press 4 \n");
    scanf("%d",&action);

    doAction(action);
}

int doAction(int action){

    system("cls");
    switch(action)
    {
        case(1) :
            printf("add contact : \n");
            addContact();
        break;
        case(2) :
            printf("search name of contact: \n");
            searchContact();
        break;
        case(3) :
            printf("delete contact with name: \n");
            deleteContact();
        break;
        case(4) :
            printf("list of contacts : \n");
            listContacts();
        break;
        default:
            printf("404 !!! \n");

    }
    setAction();
}


void addContact(){

    if(last == capacity){
        printf("phone book is full !!! \n");
    }else{

    system("cls");
    char name[50];
    char phone[50];

    fgets(name, sizeof(name), stdin);
    printf("- Enter name : \n");
    gets(name);

    system("cls");

    printf("- Enter phone number : \n");
    fgets(phone, sizeof(phone), stdin);

     strcpy(A[last].name,name);
     strcpy(A[last].phone,phone);

     system("cls");
     puts(A[last].name);
     puts(A[last].phone);
     writeText(A[last].name,A[last].phone);
     last++;
    }
}

void listContacts(){

    if(last == 0){
        printf("- the list is empty !!! \n");
    }
    else{
        for (int i = 0; i < last; i++)
        {
            printf("------------------- \n");
            printf("\n - %d : \n",i + 1);
            printf("\n + name : \n");
            puts(A[i].name);
            printf("\n + phone : \n");
            puts(A[i].phone);

        }
    }
}


void searchContact(){

    int i;
    int find = 0;
    char search[30];
    gets(search);
    fgets(search,sizeof(search),stdin);


    for(i=0;i<last;i++){;
        if(strcmpCustom(&search,&A[i].name)==0)
        {
            find = 1;
            break;
        }
    }

    if(find == 0){
        printf("404 !!! \n");
    }
    else{

        printf("------------------- \n");
        printf("\n - %d : \n",i + 1);
        printf("\n + name : \n");
        puts(A[i].name);
        printf("\n + phone : \n");
        puts(A[i].phone);

    }
}


void deleteContact(){
    int i,j;
    int find = 0;
    char search[30];
    gets(search);
    fgets(search,sizeof(search),stdin);


    for(i=0;i<last;i++){;
        if(strcmpCustom(&search,&A[i].name)==0)
        {
            find = 1;
            break;
        }
    }

        if(find == 0){
        printf("404 !!! \n");
    }
    else{
        for(j=i;j<=last;j++){
            A[j]=A[j+1];
        }
        printf("is deleted \n");
        last--;

        writeNewText();
    }



}

int strcmpCustom(char* s1,char* s2){

    int ns2 = strlen(s2);

    int result = 0;
    for(int i = 0; i < ns2 ;i++){
        if(s1[i] == s2[i]){
            result = 0;
        }
        else{
          result = 1;
        }
    }
    return result;
}


void writeText(char* name,char* phone){

    FILE *fptr;
    fptr = fopen("contacts.txt","a");
    if(fptr == NULL){
        printf("error");
        exit(1);
    }
    fprintf(fptr,"%s %s \n",name,phone);
    fclose(fptr);
}

void writeNewText(){

    FILE *fptr;
    fptr = fopen("contacts.txt","w");
    if(fptr == NULL){
        printf("error");
        exit(1);
    }

    for(int i = 0 ; i < last; i++){
        fprintf(fptr,"%s %s \n",A[i].name,A[i].phone);
    }
    fclose(fptr);
}


void getContactFromFile(){

    char name[50];
    char phone[50];
    FILE *fptr;
    fptr = fopen("contacts.txt","r");
    if(fptr == NULL){
        printf("error");
        exit(1);
    }
    int myScan;
    // eof => end of file
    while(myScan != EOF){
        if(feof(fptr)){
            break;
        }
        myScan = fscanf(fptr,"%s %s \n",&name,&phone);
        strcpy(A[last].name,name);
        strcpy(A[last].phone,phone);
        last++;
    }


}

