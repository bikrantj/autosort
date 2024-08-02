#ifndef TYPEDEF_H
#define TYPEDEF_H
#include "gtk/gtk.h"

typedef struct {
  char *extension;
  char *folder;
} FileType;

FileType *load_file_types(const char *filename);
void free_file_types(FileType *fileTypes);
typedef struct {
  GtkWidget *window;
} Global;
#endif // TYPEDEF_H