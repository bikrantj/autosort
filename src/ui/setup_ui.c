#include "gtk/gtk.h"
#include <headers.h>
void setup_ui(GtkApplication *app, gpointer user_data) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "File Auto Sort");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

  GtkWidget *parent_grid = gtk_grid_new();
  gtk_widget_set_halign(parent_grid, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(parent_grid, GTK_ALIGN_CENTER);
  // Create a box for file chooser:

  GtkWidget *select_file_grid = gtk_grid_new();
  gtk_widget_set_halign(select_file_grid, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(select_file_grid, GTK_ALIGN_CENTER);

  GtkWidget *file_chooser = create_file_chooser();
  // Append file chooser inside the box
  gtk_grid_attach(GTK_GRID(select_file_grid), file_chooser, 0, 0, 1, 1);

  GtkWidget *config_input_grid = configInput();
  gtk_widget_set_halign(config_input_grid, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(config_input_grid, GTK_ALIGN_CENTER);
  gtk_grid_attach(GTK_GRID(parent_grid), select_file_grid, 0, 0, 1, 1);
  // gtk_grid_attach(GTK_GRID(parent_grid), config_input_grid, 0, 1, 1, 1);
  // Append box inside window
  gtk_window_set_child(GTK_WINDOW(window), parent_grid);

  // Load css
  apply_css("../styles.css");
  gtk_widget_show(window);
}