#include <stdio.h>
#include <string.h>

int main()
{
    struct Skyliftairlines
    {
        char fname[20];
        char lname[20];
        long long int passportnumber;
        char source[15];
        char destination[15];
        int date;
        int month;
        int year;
        char seatnumber1[2];
        int seatnumber2;
        char classtype[20];
        float price;
        int bookingstatus;
    } S[5];

    int Businessseatsstatus[75] = {0};
    int Economyseatsstatus[100] = {0};
    int Seatsstatus2ndClass[200] = {0};

    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t                        WELCOME TO SKYLIFT AIRLINES                 \t\t\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");

    int n, totalbookings = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("A = BUISNESS CLASS \n");
        printf("B = ECONOMY CLASS \n");
        printf("C = 2ND CLASS \n");
        printf("1. BOOK YOUR TICKET \n");
        printf("2. CANCEL YOUR TICKET \n");
        printf("Enter your choice(1-2)\n");
        scanf("%d", &n);

        if (n == 1)
        {
            printf("ENTER YOUR NAME \n");
            scanf("%s %s", S[i].fname, S[i].lname);
            printf("ENTER YOUR PASSPORT NUMBER \n");
            scanf("%lld", &S[i].passportnumber);
            printf("ENTER YOUR SOURCE \n");
            scanf("%s", S[i].source);
            printf("ENTER YOUR DESTINATION \n");
            scanf("%s", S[i].destination);
            printf("ENTER DATE MONTH YEAR \n");
            scanf("%d%d%d", &S[i].date, &S[i].month, &S[i].year);
            printf("ENTER YOUR PREFERRED SEAT NUMBER \n");
            printf("format--->A1,B12,C13: \n");
            scanf("%s %d", S[i].seatnumber1, &S[i].seatnumber2);

            if (S[i].seatnumber1[0] == 'A')
            {
                strcpy(S[i].classtype, "BUSINESS CLASS");
                S[i].price = 200.00; // Price for business class
            }
            else if (S[i].seatnumber1[0] == 'B')
            {
                strcpy(S[i].classtype, "ECONOMY CLASS");
                S[i].price = 100.00; // Price for economy class
            }
            else if (S[i].seatnumber1[0] == 'C')
            {
                strcpy(S[i].classtype, "2ND CLASS");
                S[i].price = 50.00; // Price for 2nd class
            }
            else
            {
                printf("INVALID CLASS\n");
                continue;
            }

            int seatNum = S[i].seatnumber2;
            if (seatNum < 1 || (S[i].seatnumber1[0] == 'A' && seatNum > 75) ||
                (S[i].seatnumber1[0] == 'B' && seatNum > 100) ||
                (S[i].seatnumber1[0] == 'C' && seatNum > 200))
            {
                printf("INVALID SEAT NUMBER\n");
                continue;
            }

            if (S[i].seatnumber1[0] == 'A' && Businessseatsstatus[seatNum - 1])
            {
                printf("SEAT ALREADY BOOKED IN BUSINESS CLASS\n");
                continue;
            }
            else if (S[i].seatnumber1[0] == 'B' && Economyseatsstatus[seatNum - 1])
            {
                printf("SEAT ALREADY BOOKED IN ECONOMY CLASS\n");
                continue;
            }
            else if (S[i].seatnumber1[0] == 'C' && Seatsstatus2ndClass[seatNum - 1])
            {
                printf("SEAT ALREADY BOOKED IN 2ND CLASS\n");
                continue;
            }

            // Mark seat as booked
            if (S[i].seatnumber1[0] == 'A')
                Businessseatsstatus[seatNum - 1] = 1;
            else if (S[i].seatnumber1[0] == 'B')
                Economyseatsstatus[seatNum - 1] = 1;
            else if (S[i].seatnumber1[0] == 'C')
                Seatsstatus2ndClass[seatNum - 1] = 1;

            // Store booking details
            S[i].bookingstatus = 1; // Mark as booked
            totalbookings++;

            // Print booking confirmation
            printf("\n\n\n");
            printf("NAME: %s %s \n", S[i].fname, S[i].lname);
            printf("PASSPORT NUMBER: %lld \n", S[i].passportnumber);
            printf("SOURCE: %s \n", S[i].source);
            printf("DESTINATION: %s \n", S[i].destination);
            printf("DATE/MONTH/YEAR: %d/%d/%d \n", S[i].date, S[i].month, S[i].year);
            printf("YOUR SEAT HAS BEEN SUCCESSFULLY CONFIRMED!\n");
            printf("YOUR SEAT NUMBER IS: %s%d \n", S[i].seatnumber1, S[i].seatnumber2);
            printf("CLASS: %s \n", S[i].classtype);
            printf("TICKET PRICE: $%.2f\n", S[i].price);
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t\t                           !! HAVE A SAFE JOURNEY !!                  \t\t\t \n\n");
            printf("-------------------------------------------------------------------------------------------------------------------------\n");

            // Show all current bookings
            printf("\n\n\n");
            printf("CURRENT BOOKINGS:\n");
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            for (int j = 0; j < totalbookings; j++)
            {
                if (S[j].bookingstatus == 1) // Only show confirmed bookings
                {
                    printf("NAME: %s %s \n", S[j].fname, S[j].lname);
                    printf("PASSPORT NUMBER: %lld \n", S[j].passportnumber);
                    printf("SOURCE: %s \n", S[j].source);
                    printf("DESTINATION: %s \n", S[j].destination);
                    printf("DATE/MONTH/YEAR: %d/%d/%d \n", S[j].date, S[j].month, S[j].year);
                    printf("SEAT NUMBER: %s%d \n", S[j].seatnumber1, S[j].seatnumber2);
                    printf("CLASS: %s \n", S[j].classtype);
                    printf("TICKET PRICE: $%.2f\n", S[j].price);
                    printf("-------------------------------------------------------------------------------------------------------------------------\n");
                }
            }
        }
        else if (n == 2)
        {
            // Cancellation process
            printf("ENTER YOUR NAME: ");
            scanf("%s %s", S[i].fname, S[i].lname);
            printf("ENTER YOUR PASSPORT NUMBER: ");
            scanf("%lld", &S[i].passportnumber);
            printf("ENTER DATE MONTH YEAR (DD MM YYYY): ");
            scanf("%d %d %d", &S[i].date, &S[i].month, &S[i].year);

            // Find and cancel the ticket
            int found = 0;
            for (int j = 0; j < totalbookings; j++)
            {
                if (S[j].passportnumber == S[i].passportnumber &&
                    strcmp(S[j].fname, S[i].fname) == 0 &&
                    strcmp(S[j].lname, S[i].lname) == 0)
                {
                    // Mark as cancelled
                    S[j].bookingstatus = 0;
                    found = 1;

                    // Free the booked seat
                    if (S[j].seatnumber1[0] == 'A')
                        Businessseatsstatus[S[j].seatnumber2 - 1] = 0;
                    else if (S[j].seatnumber1[0] == 'B')
                        Economyseatsstatus[S[j].seatnumber2 - 1] = 0;
                    else if (S[j].seatnumber1[0] == 'C')
                        Seatsstatus2ndClass[S[j].seatnumber2 - 1] = 0;

                    printf("YOUR TICKET HAS BEEN SUCCESSFULLY CANCELLED\n\n\n");
                    break;
                }
            }
            if (!found)
            {
                printf("TICKET NOT FOUND\n");
            }

            // Show all current bookings
            printf("\n\n\n");
            printf("CURRENT BOOKINGS:\n");
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            for (int j = 0; j < totalbookings; j++)
            {
                if (S[j].bookingstatus == 1) // Only show confirmed bookings
                {
                    printf("NAME: %s %s \n", S[j].fname, S[j].lname);
                    printf("PASSPORT NUMBER: %lld \n", S[j].passportnumber);
                    printf("SOURCE: %s \n", S[j].source);
                    printf("DESTINATION: %s \n", S[j].destination);
                    printf("DATE/MONTH/YEAR: %d/%d/%d \n", S[j].date, S[j].month, S[j].year);
                    printf("SEAT NUMBER: %s%d \n", S[j].seatnumber1, S[j].seatnumber2);
                    printf("CLASS: %s \n", S[j].classtype);
                    printf("TICKET PRICE: $%.2f\n", S[j].price);
                    printf("-------------------------------------------------------------------------------------------------------------------------\n");
                }
            }
        }
        else
        {
            printf("INVALID CHOICE\n");
        }
    }

    return 0;
}
