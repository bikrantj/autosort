#ifndef HEADERS_H
#define HEADERS_H
#include "gtk/gtk.h"

// ========== UI_HEADERS ==========
void setup_ui(GtkApplication *app, gpointer user_data);
GtkWidget *create_file_chooser();
void apply_css(const char *css_file_path);
// ========== UTILS_HEADERS ==========
// Function to create a directory if it doesn't exist
void createDirectory(const char *path);

// Function to get the file extension
const char *getFileExtension(const char *filename);

// Function to move files to their respective folders
void moveFile(const char *filePath, const char *destFolder);

// Recursive function to process directories
void processDirectory(const char *dirPath);

// ========== CALLBACKS_HEADERS ==========
void onDirectorySelect(const char *dirPath);
#endif // HEADERS_H