

#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<windows.h>
#define MAX_APPOINTMENTS 100
#define DAYS_IN_MONTH 31
#define TIME_SLOTS_PER_DAY 24


//generic-stuff
int bid = 1001;
void bookAppointment();
int authstat = 0;
int table();//done
void display(struct node*);//done
void waitprint(char []);//done
char str1[100] = "Logging in............\n";
char str2[100] = "Processing ...............\n";
int numAppointments = 0;
int appointments[MAX_APPOINTMENTS];
int appointmentCalendar[DAYS_IN_MONTH][TIME_SLOTS_PER_DAY];
void payments();
void displayappointmentsd();
void displayappointmentss();

//staff
void staffdisplay();
void stafflogin();//done
int slogin();//done

//citizen
void citizendisplay();
void citizenlogin();//done
int slogin();//done

//doctor
void doctorlogin();//done
int dlogin();//done
void doctordisplay();


//structure
struct node
{
    char* name[25];
    int age;
    char* address[30];
    int phone[13];
    char bloodgroup[3];
    int id;
    int priority;

    struct node* next;
};

struct node* start = NULL;
struct node* insert(struct node*);
struct node* delete(struct node*);


int main()
{
    int ch;
    
    label1:
    printf("\t\t\t-------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t   WELCOME TO v3 HOSPITAL!\n");
    printf("\t\t\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t-------------------------------\n");
    printf("\t\t\t\t   LOGIN  \n\n");
    printf("\t\t\t[1].Staff[2].Citizen[3].Doctor\n\n");
    printf("\t\t\t         [4].Exit   \t\n\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        
        stafflogin();
        break;

    case 2:
        
        citizenlogin();
        break;

    case 3:
        
        doctorlogin();
            break;
    case 4:exit(0);
        break;
    default:
        printf("\nEnter valid choice..!\n");
        goto label1;
    }
}





//staff
void stafflogin() {
    system("cls");
    printf("STAFF-LOGIN-PAGE");
    if (slogin()) {
        waitprint(str1);
        system("COLOR C0");
        staffdisplay();
    }
    else {
        main();
    }
}
int slogin() {
    int i;
    FILE* fp;
    fp = fopen("pws.txt", "r");
    char uname[10], pass[10], data[10], input[10],ch[10];
    printf("\nUSERNAME:");
    scanf("%s", uname);
    printf("\nPASSWORD:");
    for (i = 0; i < 8; i++)
    {
        char ch;
        ch = getch();
        input[i] = ch;
        ch = '*';
        printf("%c", ch);
    }
    input[i] = '\0';
    fscanf(fp, "%s", data);
    if (strcmp(data, input) == 0)
    {
        system("cls");
        printf("\nAuthentication Succesfull.\n");
        authstat = 1;
    }
    else
    {
        printf("\nAuthentication unsuccesful.\n");

    }
    fclose(fp);
    return authstat;
}
void staffdisplay()
{
    labelmagic:
    int option;
    system("cls");
    printf("\t\t\t1.ADD A PATIENT\n");
    printf("\t\t\t2.DELETE A PATIENT\n");
    printf("\t\t\t3.DISPLAY ALL PATIENTS\n");
    printf("\t\t\t4.DISPLAY ALL APPOINTMENTS\n");

    printf("\t\t\t5.EXIT\n");
    printf("\t\t\tEnter your choice:");

    scanf("%d", &option);
    switch (option)
    {
    case 1:
        start = insert(start);
        
        getchar();
        system("cls");
        break;
    case 2:
        start = delete(start);
        
        getchar();
        system("cls");
        break;
    case 3:
        display(start);
              
        getchar();
        
        
        break;
    case 4:
        system("cls");
        displayappointmentss();
        _sleep(2000);
        getchar();
        
        break;
    case 5:
        main();
        break;
    }
    goto labelmagic;
}



//citizen
void citizenlogin() {
    system("cls");
    printf("CITIZEN-LOGIN-PAGE");
    if (clogin()) {
        waitprint(str1);
        system("COLOR B0");
        citizendisplay();
    }
    else {
        main();
    }

}
int clogin() {
    FILE* fp;
    int i;
    fp = fopen("pwc.txt", "r");
    char uname[10], pass[10], data[10], input[10];
    printf("\nUSERNAME:");
    scanf("%s", uname);
    printf("\nPASSWORD:");
    for (i = 0; i < 8; i++)
    {
        char ch;
        ch = getch();
        input[i] = ch;
        ch = '*';
        printf("%c", ch);
    }
    input[i] = '\0';
    fscanf(fp, "%s", data);
    if (strcmp(data, input) == 0)
    {
        system("cls");
        printf("\nAuthentication Succesfull.\n");
        authstat = 1;
    }
    else
    {
        printf("\nAuthentication unsuccesful.\n");

    }
    fclose(fp);
    return authstat;
}
void citizendisplay()
{
    int option;
    system("cls");
    printf("\t\t\t1.BOOK APPOINTMENT\n");
    printf("\t\t\t2.EXIT\n");
    printf("\t\t\tEnter your choice:");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        bookAppointment();
        getchar();
        system("cls");
        break;
    
    case 2:
        main();
        break;
    }
}


//doctor
void doctorlogin() {
    system("cls");
    printf("\t\t\tDOCTOR-LOGIN-PAGE\n\n");
    if (dlogin()) {
        waitprint(str1);
        system("COLOR 70");
        doctordisplay();
    }
    else {
        main();
    }

}
int dlogin() {
    FILE* fp;
    int i;
    fp = fopen("pwd.txt", "r");
    char uname[10], pass[10], data[10], input[10];
    printf("\nUSERNAME:");
    scanf("%s", uname);
    printf("\nPASSWORD:");
    for (i = 0; i < 8; i++)
    {
        char ch;
        ch = getch();
        input[i] = ch;
        ch = '*';
        printf("%c", ch);
    }
    input[i] = '\0';
    fscanf(fp, "%s", data);
    if (strcmp(data, input) == 0)
    {
        system("cls");
        printf("\nAuthentication Succesfull.\n");
        authstat = 1;
    }
    else
    {
        printf("\nAuthentication unsuccesful.\n");

    }
    fclose(fp);
    return authstat;
}
void doctordisplay() {
    int option;
    system("cls");
    
    printf("\t\t\tDOCTOR's MENU");
    printf("\t\t\t1.CHECK APPOINTMENTs\n");
    printf("\t\t\t2.EXIT\n");
    printf("\t\t\tEnter your choice:");
    scanf("%d", &option);
    switch (option) {
    case 1:
        printf("Displaying upcoming appointments\n");
        waitprint(str2);
        displayappointmentsd();
        getchar();
        break;
    case 2: main();
        break;
    default:main();
    }
    
}

//generic
void waitprint(char str[]) {
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        printf("%c", str[i]);
        Sleep(150);
    }
}

struct node* insert(struct node* start)
{
    int val2, val4, val6, pri;
    char val1, val3, val5;
    struct node* ptr, * p;
    char* name[100];
    char* address[100];
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter patient Name:");
    scanf(" %[^\n]*%c", ptr->name);
    printf("Enter the patient's age:");
    scanf("%d", &val2);
    printf("Enter your home address:");
    scanf(" %[^\n]*%c", ptr->address);
    printf("Enter your phone number:");
    scanf("%d", &val4);
    printf("Enter the blood group of Patient:");
    scanf(" %s", ptr->bloodgroup);
    printf("Your id no : %d",++bid);
    printf("Enter your disease Number:");
    int dis;
    dis=table();
    printf("\nEnter priority:");
    scanf("%d", &pri);
    //ptr->name=name;
    ptr->age = val2;
    //ptr->address=address;
    ptr->priority = pri;
    if ((start == NULL) || pri < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        p = start;
        while (p->next != NULL && p->next->priority <= pri)
            p = p->next;
        ptr->next = p->next;
        p->next = ptr;
    }
    return start;
};


struct node* delete(struct node* start)
{
    struct node* ptr;
    if (start == NULL)
    {
        printf("\n NO PATIENT RECORD TO DELETE");
        return;
    }
    else
    {
        ptr = start;
        printf("\n Deleted Record is : %d", ptr->id);
        start = start->next;
        free(ptr);
    }
    return start;
};


void display(struct node* start)
{
    struct node* ptr;
    ptr = start;
    if (start == NULL)
        printf("\nNO PATIENTS RECORDED...");
    else
    {
        printf("\nPriority wise appointments are:");
        while (ptr != NULL)
        {
            printf("Patient Name : %s\n", ptr->name);
            printf("Age : %d\n", ptr->age);
            printf("Address : %s\n", ptr->address);
            printf("Phone Number : %d\n", ptr->phone);
            printf("Blood group : %s\n", ptr->bloodgroup);
            printf("---------------------------------------------------\n");
            ptr = ptr->next;
        }
    }
    getchar();
}


int table()
{
    int n;
    printf("\nPlease Refer this Table for your symptom//disease!\n");
    printf("[1].Heart attack\n");
    printf("[2].Severe wound/Bleeding\n");
    printf("[3].Cancer\n");
    printf("[4].Chest pain\n");
    printf("[5].Fracture\n");
    printf("[6].Diabetes Checkup\n");
    printf("[7].Infection\n");
    printf("[8].Viral Fever\n");
    printf("[9].Common Cold/Head ache\n");
    scanf("%d", &n); return n;
}

void displayCalendar(int, int, int, int);
void bookAppointment()
{
    FILE* fp = fopen("appointments.csv", "a + ");
    FILE* fp1 = fopen("dr_abc.csv", "a+");
    FILE* fp2 = fopen("dr_xyz.csv", "a+");
    FILE* fp3 = fopen("dr_aaa.csv", "a+");

    char patient[10];
    int time, date, ch;

    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }

    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Error: No available appointments\n");
        return;
    }

    printf("Enter patient name: ");
    scanf("%s", patient);
    labeld:
    printf("Choose Doctor: \n");
    printf("1.Dr ABC\n2.Dr XYZ\n3.Dr AAA\n4.Go back");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("View Calender to check available slots:");
        getch();
        displayCalendar(1, 10, 10, 15);
        label1a:
        printf("Enter appointment date (1-10): ");
        scanf("%d", &date);
        if (date <= 10 && date >= 1)
            ;
        else
            goto label1a;

        label1b:
        printf("Enter appointment time (10-15): ");
        scanf("%d", &time);
        if (time <= 15 && time >= 10)
            ;
        else
            goto label1b;

        char doctor[] = "DrABC";
        if (appointmentCalendar[date ][time] == 1)
        {
            printf("Appointment for this slot is already booked\n");
            printf("Choose another slot\n\n");
            return;
        }
        else
        {
            appointmentCalendar[date][time] = 1;
            numAppointments++;
        }
        printf("Appointment booked successfully\n\n");
        fprintf(fp1, "%s, %d, %d:00\n", patient, date, time);
        fprintf(fp, "%s, %s, %d, %d:00\n", patient,doctor,date, time);
        break;

    case 2:
        printf("View Calender to check available slots:");
        getch();
        displayCalendar(15, 30, 10, 20);
        label2a:
        printf("Enter appointment date (15-30): ");
        scanf("%d", &date);
        if (date <= 30 && date >= 15)
            ;
        else
            goto label2a;
        label2b:
        printf("Enter appointment time (10-20): ");
        scanf("%d", &time);
        if (date <= 20 && date >= 10)
            ;
        else
            goto label2b;
        char doctor1[] = "DrXYZ";
        if (appointmentCalendar[date][time] == 1)
        {
            printf("Appointment for this slot is already booked\n");
            printf("Choose another slot\n\n");
            return;
        }
        else
        {
            appointmentCalendar[date ][time] = 1;
            numAppointments++;
        }
        printf("Appointment booked successfully\n\n");
        fprintf(fp2, "%s, %d, %d:00\n", patient, date, time);
        fprintf(fp, "%s, %s, %d, %d:00\n", patient, doctor1, date, time);
        break;

    case 3:
        printf("View Calender to check available slots:");
        getch();
        displayCalendar(1, 15, 10, 18);
        label3a:
        printf("Enter appointment date (1-15): ");
        scanf("%d", &date);
        if (date <= 15 && date >= 1)
            ;
        else
            goto label3a;
        label3b:
        printf("Enter appointment time (10-18): ");
        scanf("%d", &time);
        if (date <= 18 && date >= 10)
            ;
        else
            goto label3b;
        char doctor2[] = "DrAAA";
        if (appointmentCalendar[date][time] == 1)
        {
            printf("Appointment for this slot is already booked\n");
            printf("Choose another slot\n\n");
            return;
        }
        else
        {
            appointmentCalendar[date][time] = 1;
            numAppointments++;
        }
        printf("Appointment booked successfully\n\n");
        fprintf(fp3, "%s, %d, %d:00\n", patient, date, time);
        fprintf(fp, "%s, %s, %d, %d:00\n", patient, doctor2, date, time);
        break;
    case 4:
        break;
    default:printf("Enter valid choice :");
        goto labeld;
    }
    fcloseall();
    return main();
}


void displayCalendar(int d, int days, int t, int time) {
    printf("Calendar:\n");
    printf("       ");
    for (int i = d; i <= days; i++) {
        printf("[%d]\t", i);
    }
    printf("\n");
    for (int i = t; i <= time; i++) {
        printf("[%d:00]\t", i);
        for (int j = d; j <= days; j++) {
            printf("%d\t", appointmentCalendar[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void displayappointmentss() {
    FILE* fp = fopen("appointments.csv", "a+");
    if (!fp)
        printf("Can't open file\n");

    else {
       
        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer,
            1024, fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(buffer, ", ");

            while (value) {
                // Column 1
                if (column == 0) {
                    printf("Patient :");
                }

                // Column 2
                if (column == 1) {
                    printf("\tDoctor :");
                }

                // Column 3
                if (column == 2) {
                    printf("\tDate :");
                }

                if (column == 3) {
                    printf("\tTime :");
                }

                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }

            printf("\n");
        }

        // Close the file
        fclose(fp);
    }
    

}


void displayappointmentsd() {
    FILE* fp = fopen("dr_abc.csv", "a+");
    if (!fp)
        printf("Can't open file\n");

    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];

        int row = 0;
        int column = 0;
        printf("\n\n");
        while (fgets(buffer,
            1024, fp)) {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(buffer, ", ");

            while (value) {
                // Column 1
                if (column == 0) {
                    printf("Name :");
                }

                // Column 2
                if (column == 1) {
                    printf("\tDate :");
                }

                // Column 3
                if (column == 2) {
                    printf("\tTime :");
                }

                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }

            printf("\n");
        }

        // Close the file
        fclose(fp);
    }


}

//void payments() {
//    int ch;
//    printf("\n{1} Proceed to payment . {2} Exit from payment\n");
//    scanf("%d",&ch);
//    switch (ch) {
//    case 1:
//        printf(\n
//            ##################################################################
//            ##################################################################
//            ####              ##        ##  ##  ##    ######              ####
//            ####  ##########  ########    ##  ######    ####  ##########  ####
//            ####  ##      ##  ####  ##  ##      ############  ##      ##  ####
//            ####  ##      ##  ######    ########    ########  ##      ##  ####
//            ####  ##      ##  ######      ##            ####  ##      ##  ####
//            ####  ##########  ####  ##  ################  ##  ##########  ####
//            ####              ##  ##  ##  ##  ##  ##  ##  ##              ####
//            ####################    ####    ##    ####  ######################
//            ####    ##    ##  ####  ####  ######    ########  ##########  ####
//            ########      ##########  ####        ##    ##  ##    ##    ######
//            ######  ##  ##    ##    ####  ####  ##    ##  ####    ##  ########
//            ####  ##  ##  ######  ##########  ####  ####        ##  ####  ####
//            ########      ##  ####    ##    ####  ####  ####    ########  ####
//            ########    ############  ##    ##    ##########              ####
//            ####      ####        ##  ####  ##  ##            ##  ##  ##  ####
//            ######    ########  ##      ####  ##  ##    ######    ##  ##  ####
//            ####  ##          ####    ##  ####  ######      ######  ##########
//            ####  ##  ##########  ##  ##  ##    ####    ########  ##    ######
//            ####          ##  ##  ####    ##    ######  ########    ####  ####
//            ####    ######  ####      ####    ########  ####  ####    ########
//            ####    ##  ##    ##  ##  ####    ##    ####                ######
//            ####################      ####      ####  ##  ######    ##########
//            ####              ####  ##  ##  ##    ####    ##  ##    ##########
//            ####  ##########  ######  ##  ##              ######  ####  ######
//            ####  ##      ##  ##  ##        ##    ####              ##########
//            ####  ##      ##  ##  ##########      ##  ####  ############  ####
//            ####  ##      ##  ####    ########  ##  ####    ##    ##      ####
//            ####  ##########  ##  ##  ######  ##  ##  ######    ##    ##  ####
//            ####              ##  ##      ############    ##  ##  ############
//            ##################################################################
//            ##################################################################");
//            break;
//
//    case 2:return;
//        break;
//    }
//}