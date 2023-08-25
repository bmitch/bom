#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define RED "\x1B[31m"
#define RESET "\x1B[0m"
#define WHITE "\x1B[37m"
#define BLUE "\x1B[34m"
#define CYAN "\x1B[36m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

typedef struct {
    char url[256];
    char title[256];
    char tags[256];
    char datetime[20];
} Bookmark;

char *getBookmarkFilePath();

void SaveBookmarkToFile(Bookmark bookmark, const char *filePath);
void addBookmark();
void listBookmarks();

int main(int argc, char *argv[]) {
    char *filePath = getBookmarkFilePath();

    if (argc > 1 && strcmp(argv[1], "add") == 0) {
        addBookmark(filePath);
    } else if (argc > 1 && strcmp(argv[1], "list") == 0) {
        listBookmarks(filePath);
    }

    else {
        printf(RED "Unknown command." RESET "\n");
    }

    return 0;
}

char *getBookmarkFilePath() {
    char *filePath = getenv("BOOKMARKS_FILE_PATH");
    return (filePath != NULL) ? filePath : "bookmarks.txt";
}

void SaveBookmarkToFile(Bookmark bookmark, const char *filePath) {
    FILE *file = fopen(filePath, "a");
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

void addBookmark(char *filePath) {
    Bookmark newBookmark;

    printf("Enter URL: ");
    fgets(newBookmark.url, sizeof(newBookmark.url), stdin);
    newBookmark.url[strcspn(newBookmark.url, "\n")] = 0; // Remove newline

    printf("Enter Title (optional): ");
    fgets(newBookmark.title, sizeof(newBookmark.title), stdin);
    newBookmark.title[strcspn(newBookmark.title, "\n")] = 0; // Remove newline

    printf("Enter Tags (optional, separated by commas): ");
    fgets(newBookmark.tags, sizeof(newBookmark.tags), stdin);
    newBookmark.tags[strcspn(newBookmark.tags, "\n")] = 0; // Remove newline

    // Adding date
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(newBookmark.datetime, sizeof(newBookmark.datetime), "%Y-%m-%d %H:%M", t);

    // Saving to file
    FILE *file = fopen(filePath, "a");
    if (file == NULL) {
        printf("Error opening bookmarks file.\n");
        return;
    }

    fprintf(file, "%s\n", newBookmark.url);

    if (strlen(newBookmark.title) > 0) {
        fprintf(file, "[ %s ]\n", newBookmark.title);
    }

    if (strlen(newBookmark.tags) > 0) {
        fprintf(file, "# %s\n", newBookmark.tags);
    }

    fprintf(file, "@ %s\n\n", newBookmark.datetime); // Adding an extra newline to separate bookmarks

    fclose(file);

    printf("Bookmark added successfully.\n");
}

void listBookmarks(char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Could not open bookmarks file.\n");
        return;
    }

    char line[256];
    char nextLine[256];
    int bookmarkCount = 0;
    bool firstBookmark = true;

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character if it exists
        line[strcspn(line, "\n")] = 0;

        // Skip empty lines
        if (strlen(line) == 0) continue;

        if (line[0] != '[' && line[0] != '#' && line[0] != '@') {
            if (!firstBookmark) {
                printf("\n");
            }
            bookmarkCount++;
            printf("\033[1;37m%d.\t\033[0m", bookmarkCount); // Bright white color for the number
            fgets(nextLine, sizeof(nextLine), file); // Read the title line
            nextLine[strcspn(nextLine, "\n")] = 0; // Remove newline character
            printf(BLUE "%s\n" RESET, nextLine); // Print title
            printf("\t" WHITE "%s\n" RESET, line); // Print URL
            firstBookmark = false;
        } else if (line[0] == '#') {
            printf("\t" CYAN "# ");
            // Print tags without commas, ignoring consecutive commas and spaces
            bool prevCharWasCommaOrSpace = false;
            for (int i = 1; line[i]; i++) {
                if (line[i] != ',' && line[i] != ' ') {
                    printf("%c", line[i]);
                    prevCharWasCommaOrSpace = false;
                } else if (!prevCharWasCommaOrSpace) {
                    printf(" ");
                    prevCharWasCommaOrSpace = true;
                }
            }
            printf("\n" RESET);
        } else if (line[0] == '@') {
            // Ignoring the date added, as per your example
        }
    }

    fclose(file);
}





