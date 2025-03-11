#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

struct Book books[100];
int bookCount = 0;

void addBook() {
    printf("Enter Book ID: ");
    scanf("%d", &books[bookCount].id);
    getchar();
    printf("Enter Book Title: ");
    fgets(books[bookCount].title, 50, stdin);
    printf("Enter Book Author: ");
    fgets(books[bookCount].author, 50, stdin);

    // Remove newline characters
    books[bookCount].title[strcspn(books[bookCount].title, "\n")] = 0;
    books[bookCount].author[strcspn(books[bookCount].author, "\n")] = 0;

    bookCount++;
    printf("Book added successfully!\n");
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nBook List:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("--------------------\n");
    }
}

void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            printf("Book Found!\n");
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            return;
        }
    }

    printf("Book not found.\n");
}

void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Book deleted successfully!\n");
            return;
        }
    }

    printf("Book not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
