#include <stdio.h>

typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

void total_price(book_t books[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += books[i].price;
    }

    printf("Total price: %d\n", total);
}

void list_books(book_t books[], int n) {
    printf("\nID\tPrice\tTitle\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%s\n",
               books[i].id,
               books[i].price,
               books[i].title);
    }
}

int main() {
    book_t books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    FILE *fp = fopen("Book.bin", "wb");

    if (fp == NULL) {
        printf("File open error!\n");
        return 1;
    }

    fwrite(books, sizeof(book_t), 6, fp);
    fclose(fp);

    fp = fopen("Book.bin", "rb");

    if (fp == NULL) {
        printf("File open error!\n");
        return 1;
    }

    book_t data[6];
    int n = fread(data, sizeof(book_t), 6, fp);

    fclose(fp);

    total_price(data, n);
    list_books(data, n);

    return 0;
}
