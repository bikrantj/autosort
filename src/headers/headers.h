#ifndef HEADERS_H
#define HEADERS_H
#include "gtk/gtk.h"
#include "typedef.h"

// ========== UI_HEADERS ==========
void setup_ui(GtkApplication *app, gpointer user_data);
GtkWidget *create_file_chooser(Global *config);
void apply_css(const char *css_file_path);
GtkWidget *configInput();
void complete_dialog(Global *config);
// ========== UTILS_HEADERS ==========
// Function to create a directory if it doesn't exist
void createDirectory(const char *path);

// Function to get the file extension
const char *getFileExtension(const char *filename);

// Function to move files to their respective folders
void moveFile(const char *filePath, const char *destFolder);

FileType *load_file_types(const char *filename);
void free_file_types(FileType *fileTypes);
void print_file_types(const FileType *fileTypes);
// Recursive function to process directories
void processDirectory(const char *dirPath, const char *rootPath);

// ========== CALLBACKS_HEADERS ==========
void onDirectorySelect(const char *dirPath);
#endif // HEADERS_H