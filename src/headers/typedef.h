#ifndef TYPEDEF_H
#define TYPEDEF_H

typedef struct {
  char *extension;
  char *folder;
} FileType;

FileType *load_file_types(const char *filename);
void free_file_types(FileType *fileTypes);
#endif // TYPEDEF_H