#ifndef HEADERS_H
#define HEADERS_H
#include "gtk/gtk.h"
void setup_ui(GtkApplication *app, gpointer user_data);
GtkWidget *create_file_chooser();
#endif // HEADERS_H