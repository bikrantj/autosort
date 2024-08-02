#include "typedef.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_EXTENSIONS 10
void print_file_types(const FileType *fileTypes) {
  for (int i = 0; fileTypes[i].extension != NULL; i++) {
    printf("{\"%s\", \"%s\"},\n", fileTypes[i].extension, fileTypes[i].folder);
  }
}
// Function to read the config file and populate ConfigData struct
FileType *load_file_types(const char *filename) {
  FileType *fileTypes = NULL;
  int num_types = 0;
  FILE *file = fopen(filename, "r");

  if (!file) {
    perror("Failed to open file");
    return NULL;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, sizeof(line), file)) {
    // Remove newline character if present
    line[strcspn(line, "\n")] = '\0';

    char *category = strtok(line, " =");
    if (!category)
      continue;

    char *ext = strtok(NULL, " ");
    while (ext) {
      if (strcmp(ext, "=") == 0) {
        ext = strtok(NULL, " ");
        continue;
      }

      fileTypes = realloc(fileTypes, (num_types + 1) * sizeof(FileType));
      fileTypes[num_types].extension = strdup(ext);
      fileTypes[num_types].folder = strdup(category);
      num_types++;

      ext = strtok(NULL, " ");
    }
  }

  fclose(file);

  // Add sentinel value
  fileTypes = realloc(fileTypes, (num_types + 1) * sizeof(FileType));
  fileTypes[num_types].extension = NULL;
  fileTypes[num_types].folder = NULL;

  return fileTypes;
}

void free_file_types(FileType *fileTypes) {
  for (int i = 0; fileTypes[i].extension; i++) {
    free(fileTypes[i].extension);
    free(fileTypes[i].folder);
  }
  free(fileTypes);
}