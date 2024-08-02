#include "headers.h"
#include "typedef.h"
#include <dirent.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

FileType fileTypes[] = {
    {"jpg", "images"},     {"png", "images"},    {"jpeg", "images"},
    {"docx", "documents"}, {"pdf", "documents"}, {"txt", "documents"},
    {NULL, NULL} // Sentinel to mark end of array
};
// Function to create a directory if it doesn't exist
void createDirectory(const char *path) {
  struct stat st = {0};
  if (stat(path, &st) == -1) {
    mkdir(path, 0700);
  }
}

// Function to get the file extension
const char *getFileExtension(const char *filename) {
  const char *dot = strrchr(filename, '.');
  if (!dot || dot == filename)
    return "";
  return dot + 1;
}

// Function to move files to their respective folders
void moveFile(const char *filePath, const char *destFolder) {
  char newFilePath[1024];
  snprintf(newFilePath, sizeof(newFilePath), "%s/%s", destFolder,
           strrchr(filePath, '/') + 1);
  rename(filePath, newFilePath);
}

// Recursive function to process directories
void processDirectory(const char *dirPath) {
  DIR *dir;
  struct dirent *entry;

  if (!(dir = opendir(dirPath)))
    return;

  while ((entry = readdir(dir)) != NULL) {
    char path[1024];
    if (entry->d_type == DT_DIR) {
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        continue;

      snprintf(path, sizeof(path), "%s/%s", dirPath, entry->d_name);
      processDirectory(path);
    } else {
      snprintf(path, sizeof(path), "%s/%s", dirPath, entry->d_name);
      const char *ext = getFileExtension(entry->d_name);

      // Find the matching folder for the file extension
      int found = 0;
      for (int i = 0; fileTypes[i].extension != NULL; i++) {
        if (strcmp(ext, fileTypes[i].extension) == 0) {
          char destFolder[1024];
          snprintf(destFolder, sizeof(destFolder), "%s/%s", dirPath,
                   fileTypes[i].folder);
          createDirectory(destFolder);
          moveFile(path, destFolder);
          found = 1;
          break;
        }
      }

      // If no matching folder is found, create a folder with the extension name
      if (!found) {
        char destFolder[1024];
        snprintf(destFolder, sizeof(destFolder), "%s/%s", dirPath, ext);
        createDirectory(destFolder);
        moveFile(path, destFolder);
      }
    }
  }
  closedir(dir);
}
