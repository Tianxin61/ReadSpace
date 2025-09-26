#define TUSHU_H

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 30

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int year;
    int is_borrowed;
} Book;

extern Book library[MAX_BOOKS];
extern int book_count;

void add_book();
void display_books();
void search_book();
void borrow_book();
void return_book();
