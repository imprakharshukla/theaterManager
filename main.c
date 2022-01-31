#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <ctype.h>

typedef l;;
struct tm date;


void choices();

void getMovieName(char *, int);


int main() {
    choices();
    return 0;
}

struct Movie {
    char name[1000];
    char date[100];
    char desc[1000];
    char star[10];
    char eco_price[5];
    char prem_price[5];
    char sup_price[5];
    char timings24[100];
};

//  1 2 3 4 5 6 7 8
//1 x x x x x x x x
//2 x x x x x x x x
//3 x x x x x x x x
//4 x x x x x x x x



struct Ticket {
    char name[100];
    char date[100];
    char time[100];
    char price[100];
    char movieName[100];
    char seatNumber[100];
    char seatType;
};

void getSeating(char *seating[][8], struct Ticket ticket);

void updateSeating(char *seating[][8], struct Ticket ticket);

void ticketPrinter(struct Ticket ticket);

void saveTicket(struct Ticket ticket);

void choices() {
    int choice;
    printf("Please choose the desired option from the following menu: \n");
    printf("1. Add Movie \n 2. Remove movie \n 3. Update movie \n 4. List movies \n 5. Book tickets \n 6. Refund tickets \n");
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            struct Movie movie;
            system("clear");
            printf("Welcome to add movie wizard. Please answer the following questions \n");
            int nameLength = 0;
            int descLength = 0;

            //name
            printf("Enter the number of words in the title... ");
            scanf("%d", &nameLength);
            char temp[100][1000];

            printf("Name- ");
            for (int i = 0; i < nameLength; ++i) {
                scanf("%s[^\n]", temp[i]);
            }
            int l = 0;
            printf("\n");
            for (int i = 0; i < nameLength; ++i) {
                if (i != nameLength && i != 0) {
                    movie.name[l++] = '_';
                }
                for (int j = 0; j < strlen(temp[i]); ++j) {
                    movie.name[l++] = temp[i][j];
                }
            }
            movie.name[l] = '\0';

            //desc
            printf("Enter the number of words in the description...  ");
            char tempDesc[100][1000];
            scanf("%d", &descLength);
            printf("Description- ");
            for (int i = 0; i < descLength; ++i) {
                scanf("%s[^\n]", tempDesc[i]);
            }

            int k = 0;
            for (int i = 0; i < descLength; ++i) {
                if (i != descLength && i != 0) {
                    movie.desc[k++] = '_';
                }
                for (int j = 0; j < strlen(tempDesc[i]); ++j) {
                    movie.desc[k++] = tempDesc[i][j];
                }
            }

            movie.desc[k] = '\0';

            //star
            printf("Enter the number of stars the movie has received... ");
            scanf("%s", &movie.star);

            //prices
            printf("Enter the price of the economy tickets... ");
            scanf("%s", &movie.eco_price);
            printf("Enter the price of the premium tickets... ");
            scanf("%s", &movie.prem_price);
            printf("Enter the price of the supreme tickets... ");
            scanf("%s", &movie.sup_price);

            printf("Enter the date the movie is put up for show (DD/MM/YYYY)...");
            scanf("%s", &movie.date);

            int n = 0;
            printf("Enter the number of times the show will be up...");
            scanf("%d", &n);
            printf("Enter the show timings in HH:MM (24 Hrs)");
            int b[100][1000];
            for (int i = 0; i < n; ++i) {
                scanf("%s", b[i]);
            }
            for (int i = 0; i < n; ++i) {
                if (i != n && i != 0) {
                    movie.timings24[l++] = '_';
                }
                for (int j = 0; j < strlen(temp[i]); ++j) {
                    movie.timings24[l++] = temp[i][j];
                }
            }

            movie.timings24[n] = '\0';
            printf("%s", movie.timings24);

            FILE *fp = fopen("movies.csv", "a+");
            if (!fp) {
                // Error in file opening
                printf("Can't open file\n");
            }
            fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s \n",
                    movie.name, movie.desc,
                    movie.star, movie.date,
                    movie.eco_price, movie.prem_price,
                    movie.sup_price, movie.timings24);
            fclose(fp);
        }
            break;
        case 2: {
            //deleting movies
            int nameLength = 0;
            char name[10000];
            printf("Enter the number of words in the title... ");

            printf("Name- ");
            char temp[100][1000];

            printf("Name- ");
            for (int i = 0; i < nameLength; ++i) {
                scanf("%s[^\n]", temp[i]);
            }
            int l = 0;
            printf("\n");
            for (int i = 0; i < nameLength; ++i) {
                printf("%s %d %d\n", temp[i], strlen(temp[i]), i);
                if (i != nameLength && i != 0) {
                    name[l++] = '_';
                }
                for (int j = 0; j < strlen(temp[i]); ++j) {
                    name[l++] = temp[i][j];
                }
            }

            name[l] = '\0';

            FILE *file = fopen("movies.csv", "r");
            if (file == NULL) {
                perror("Unable to read movies from the file.");
                exit(1);
            }
            char line[100000];
            struct Movie movie;
            while (fgets(line, sizeof(line), file)) {

                char *token;
                token = strtok(line, ",");
                char row[10000];
                int k = 0;
                int i = 0;
                while (token != NULL) {
                    // printf("%d \n", i);
                    switch (i++) {
                        case 0: {
                            //name
                            strcpy(movie.name, token);
                        }
                            break;
                        case 1: {
                            strcpy(movie.desc, token);
                        }
                            break;
                        case 2: {
                            strcpy(movie.star, token);
                        }
                            break;
                        case 3: {
                            strcpy(movie.date, token);
                        }
                            break;
                        case 4: {
                            strcpy(movie.eco_price, token);
                        }
                            break;
                        case 5: {
                            strcpy(movie.prem_price, token);
                        }
                            break;
                        case 6: {
                            strcpy(movie.sup_price, token);
                        }
                            break;
                        case 7: {
                            strcpy(movie.timings24, token);
                        }
                            break;
                        default: {
                            printf("Default");
                        }
                            break;
                    }
                    token = strtok(NULL, ",");
                }
                FILE *fp = fopen("movies2.csv", "a+");
                if (!fp) {
                    // Error in file opening
                    printf("Can't open file\n");
                }

                if (strcmp(movie.name, name) != 0) {
                    fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n", movie.name, movie.desc, movie.star, movie.date,
                            movie.eco_price, movie.prem_price,
                            movie.sup_price, movie.timings24);
                }
                fclose(fp);
                // write the lines here

            }
            fclose(file);
            if (remove("movies.csv") == 0) {
                //deleted file now renaming movies2 to movies.csv
                if (rename("movies2.csv", "movies.csv") == 0) {
                    printf("Deletion completed and file is renamed! \n");
                }
            }
        }
            break;
        case 3: {
            // update movies
        }
            break;
        case 4: {
            printf(
                    "Printing the movie list... \n"
            );
            FILE *file = fopen("movies.csv", "r");
            if (file == NULL) {
                perror("Unable to read movies from the file.");
                exit(1);
            }
            char line[10000];
            int movieId = 0;
            struct Movie movie;
            while (fgets(line, sizeof(line), file)) {
                ++movieId;
                char *token;
                token = strtok(line, ",");
//                int spaces = 0;

//                char temp[10000];
//                int m = 0;
                int i = 0;
                while (token != NULL) {
                    // printf("%d \n", i);
                    switch (i++) {
                        case 0: {
                            //name
                            strcpy(movie.name, token);
                        }
                            break;
                        case 1: {
                            strcpy(movie.desc, token);
                        }
                            break;
                        case 2: {
                            strcpy(movie.star, token);
                        }
                            break;
                        case 3: {
                            strcpy(movie.date, token);
                        }
                            break;
                        case 4: {
                            strcpy(movie.eco_price, token);
                        }
                            break;
                        case 5: {
                            strcpy(movie.prem_price, token);
                        }
                            break;
                        case 6: {
                            strcpy(movie.sup_price, token);
                        }
                            break;
                        case 7: {
                            strcpy(movie.timings24, token);
                        }
                            break;
                        default: {
                            printf("Default");
                        }
                            break;
                    }


                    token = strtok(NULL, ",");
                }
                system("clear");
                printf("\n");
                printf("Movie ID- %d \n", movieId);
                getMovieName(&movie.name, strlen(movie.name));
                printf("Name- %s \n", movie.name);
                getMovieName(&movie.desc, strlen(movie.desc));
                printf("Description- %s \n", movie.desc);
                printf("Rating- %s\n", movie.star);
                printf("Pricing- \n");
                printf("  Economy- ₹%s\n", movie.eco_price);
                printf("  Premium- ₹%s\n", movie.prem_price);
                printf("  Supreme- ₹%s\n", movie.sup_price);
                printf("Timing- \n");
                printf("%s \n", movie.timings24);
                printf("\n");
            }
            fclose(file);
        }


            break;
        case 5: {

            struct Ticket ticket;
            printf("Welcome to the ticket booking system. Please provide the following details- \n");
            printf("First Name- \n");
            scanf("%s", &ticket.name);


            printf("Enter Movie- \n");
            scanf("%s", &ticket.movieName);

            printf("Enter the showtime- \n");
            scanf("%s", &ticket.time);


            printf("Enter seat type number- \n");
            printf("   1. Economical seats \n");
            printf("   2. Premium seats \n");
            printf("   3. Supreme seats \n");
            scanf(" %c", &ticket.seatType);


            char *seating[4][8];
            getSeating(seating, ticket);
            printf("\n");
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 8; ++j) {
                    printf("%c", seating[i][j]);
                }
                printf("\n");
            }


            if (ticket.seatType == '3') {
                //checking for seat availability
                int flag = -1;
                int posRow = -1;
                int posCol = -1;
                for (int i = 0; i < 1; i++) {
                    for (int j = 0; j < 8; ++j) {
                        if (seating[i][j] == 'x') {
                            posRow = j;
                            posCol = i;
                            ++flag;
                            break;
                        }
                    }
                }

                if (flag > -1) {
                    printf("\n Tickets are available! \n");
//                    char buff[100];
//                    time_t now = time(0);
//                    strftime(buff, 100, "%Y-%m-%d %H:%M:%S.000", localtime(&now));
//                    strcpy(buff, ticket.date);
                    printf("row- %d, col- %d", posRow, posCol);
                    seating[posRow][posCol] = 'b';
                    //strcpy(strcat(posRow + '0', posCol + '0'), ticket.seatNumber);

                    updateSeating(&seating, ticket);
                    saveTicket(ticket);
                    ticketPrinter(ticket);
                }
            } else if (ticket.seatType == '2') {

            } else if (ticket.seatType == '1') {

            }

            printf("seatNumber- \n");
            scanf("%s", &ticket.name);

            printf("First Name- \n");
            scanf("%s", &ticket.name);

            printf("First Name- \n");
            scanf("%s", &ticket.name);


            // book tickets
        }
            break;
        case 6: {
            // refund tickets
        }
            break;

        default: {

        }
    }

}

void ticketPrinter(struct Ticket ticket) {
    printf("============================================================");
    printf("Ticket Confirmed! Find the details below: \n");
    printf("Name- %s \n", ticket.name);
    printf("Movie Name- %s \n", ticket.movieName);
    if (ticket.seatType == '1') {
        printf("Ticket Type- Economic \n");
    } else if (ticket.seatType == '2') {
        printf("Ticket Type- Premium \n");
    } else if (ticket.seatType == '3') {
        printf("Ticket Type- Supreme \n");
    }

    printf("Date- %s \n", ticket.date);
    printf("Time- %s \n", ticket.time);
    printf("Price- %s \n", ticket.price);

    printf("============================================================");
}

void saveTicket(struct Ticket ticket) {

    FILE *fp = fopen(strcat(strcat(ticket.movieName, ticket.time), ".csv"), "a+");
    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
    }
    fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s \n",
            ticket.name, ticket.time,
            ticket.movieName, ticket.seatType,
            ticket.date, ticket.price,
            ticket.seatNumber);
    fclose(fp);
}

void updateSeating(char *seating[][8], struct Ticket ticket) {
    printf("Hello jo \n");
    FILE *fptr;
    printf("\n");
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%c", seating[i][j]);
        }
        printf("\n");
    }
    if ((fptr = fopen(strcat(strcat(strcat(ticket.movieName, ticket.time), "-sitting"), ".txt"), "a")) == NULL) {
        printf("Error opening the seating arr. file \n");
    } else {
        printf("\n hererere");
        char seat[32];
        int k = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; ++j) {
                printf("%c", seating[i][j]);
                seat[k++] = seating[i][j];
            }
        }
        fprintf(fptr, "%s", seat);
    }
}

void getSeating(char *seating[][8], struct Ticket ticket) {
    char c[1000];
    FILE *fptr;
    if ((fptr = fopen(strcat(strcat(strcat(ticket.movieName, ticket.time), "-sitting"), ".txt"), "w+")) == NULL) {
        printf("Error opening the seating arr. file \n");
    }

    // reads text until newline is encountered
    fscanf(fptr,
           "%[^\n]", c);
//    printf("\n%s", c);
//    printf("The length of the file %ld", strlen(c));
    if (strlen(c) == 0) {
        printf("data empty \n");
        //the file is blank
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; ++j) {
                fprintf(fptr, "x");
                seating[i][j] = 'x';
            }
        }

    } else {
        printf("Data present \n");
        // data present in the file
        int row = 0, col = 0;
        for (int i = 0; i < strlen(c); ++i) {
            if (col == 8) {
                ++row;
                col = 0;
            }

            seating[row][col] = c[i];
            printf("\ni- %d r- %d c- %d item- %c", i, row, col, seating[row][col]);
            col++;
        }
    }
    fclose(fptr);
}

void getMovieName(char *name, int len) {
    //char formattedName[10000];
    name[0] = (toupper(name[0]));
    for (int i = 0; i < len; ++i) {
        if (name[i] == '_') {
            name[i] = ' ';
            name[i + 1] = toupper(name[i + 1]);
        }
    }
}

/* choices for the user-
 * 1. Add a movie
 * 2. Remove a movie
 * 3. Update a movie
 * 4. Book Ticket
 * 5. Refund Ticket
 * 6. List Movies
 * 7.
 *
 *
 * */
