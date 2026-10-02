#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BOOK_FILE "books.dat"
#define ISSUE_FILE "issued.dat"

#define TITLE_SIZE 100
#define AUTHOR_SIZE 100
#define NAME_SIZE 100

#define FINE_PER_DAY 5.0
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


/* =========================
   STRUCTURES
   ========================= */

typedef struct {
    int bookId;
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    int quantity;
} Book;

typedef struct {
    int issueId;
    int bookId;
    int userId;
    char userName[NAME_SIZE];

    char issueDate[11];   // DD-MM-YYYY
    char dueDate[11];     // DD-MM-YYYY
    char returnDate[11];  // DD-MM-YYYY

    float fineAmount;
    int returned;         // 0 = Not returned, 1 = Returned
} Issue;


/* =========================
   FUNCTION PROTOTYPES
   ========================= */

void clearInputBuffer(void);
void readLine(char *str, int size);
int getInt(const char *prompt);
void pauseScreen(void);

void mainMenu(void);

void addBook(void);
void updateBook(void);
void removeBook(void);
void searchBook(void);
void viewAllBooks(void);

void issueBook(void);
void returnBook(void);
void listIssuedBooks(void);

void saveAllData(void);
void loadAllData(void);

int bookExists(int bookId);
int findBookById(int bookId, Book *book);
int updateBookQuantity(int bookId, int change);

int containsIgnoreCase(const char *text, const char *pattern);
void toLowerString(char *dest, const char *src);

void updateBookById(void);
void updateBookByName(void);

void removeBookById(void);
void removeBookByName(void);

void searchById(void);
void searchByName(void);
void searchByAuthor(void);

void getCurrentDate(char *date);
void getDueDate(char *issueDate, char *dueDate);

time_t convertToTime(const char *date);
int calculateLateDays(const char *dueDate, const char *returnDate);

int getNextIssueId(void);
void printBook(const Book *book);


#endif
