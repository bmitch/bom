#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RED "\x1B[31m"
#define RESET "\x1B[0m"

typedef struct {
    char url[256];
    char title[256];
    char tags[256];
    char datetime[20];
} Bookmark;

void SaveBookmarkToFile(Bookmark bookmark);
void addBookmark();

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "add") == 0) {
        addBookmark();
    } else {
        printf(RED "Unknown command." RESET "\n");
    }

    return 0;
}

void SaveBookmarkToFile(Bookmark bookmark) {
    FILE *file = fopen("bookmarks.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s\n", bookmark.url);
    fprintf(file, "%s\n", bookmark.title);
    fprintf(file, "%s\n", bookmark.tags);
    fprintf(file, "%s\n", bookmark.datetime);
    fprintf(file, "\n");

    fclose(file);
}

void addBookmark() {
    Bookmark newBookmark;

    printf("Enter URL: ");
    fgets(newBookmark.url, sizeof(newBookmark.url), stdin);
    strtok(newBookmark.url, "\n");

    printf("Enter title (optional): ");
    fgets(newBookmark.title, sizeof(newBookmark.title), stdin);
    strtok(newBookmark.title, "\n");

    printf("Enter tags (optional): ");
    fgets(newBookmark.tags, sizeof(newBookmark.tags), stdin);
    strtok(newBookmark.tags, "\n");

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(newBookmark.datetime, sizeof(newBookmark.datetime), "%Y-%m-%d %H:%M", tm_info);

    SaveBookmarkToFile(newBookmark);
    printf("Bookmark saved successfully.\n");
}
