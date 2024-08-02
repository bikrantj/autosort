#include <headers.h>
void setup_ui(GtkApplication *app, gpointer user_data) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "File Auto Sort");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

  // Create a box for file chooser:
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  GtkWidget *file_chooser = create_file_chooser();

  // Append file chooser inside the box
  gtk_box_append(GTK_BOX(box), file_chooser);

  // Append box inside window
  gtk_window_set_child(GTK_WINDOW(window), box);

  gtk_widget_show(window);
}