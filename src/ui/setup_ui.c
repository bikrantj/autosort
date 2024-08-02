#include <headers.h>
void setup_ui(GtkApplication *app, gpointer user_data) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "File Auto Sort");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

  // Create a box for file chooser:
  GtkWidget *grid = gtk_grid_new();
  gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
  // gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  // gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
  GtkWidget *file_chooser = create_file_chooser();
  gtk_grid_attach(GTK_GRID(grid), file_chooser, 0, 0, 1, 1);

  // Append file chooser inside the box

  // Append box inside window
  gtk_window_set_child(GTK_WINDOW(window), grid);

  // Load css
  apply_css("../styles.css");
  gtk_widget_show(window);
}