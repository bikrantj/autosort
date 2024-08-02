#include <headers.h>
void setup_ui(GtkApplication *app, gpointer user_data) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "File Auto Sort");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
  gtk_widget_show(window);
}