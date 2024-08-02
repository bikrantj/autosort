#include "gtk/gtk.h"
#include "gtk/gtkshortcut.h"

static void activate_directory_input() {}
GtkWidget *configInput() {
  GtkWidget *config_input_grid = gtk_grid_new();

  // Directory Name Grids and Inputs
  GtkWidget *directory_name_grid = gtk_grid_new();
  GtkEntryBuffer *directory_name = gtk_entry_buffer_new(NULL, -1);
  GtkWidget *directory_label = gtk_label_new("Folder Name");
  GtkWidget *directory_name_input = gtk_entry_new_with_buffer(directory_name);
  gtk_grid_attach(GTK_GRID(directory_name_grid), directory_label, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(directory_name_grid), directory_name_input, 0, 1, 1,
                  1);

  // Extension Name Grids and Inputs
  GtkWidget *file_ext_grid = gtk_grid_new();
  GtkEntryBuffer *file_ext = gtk_entry_buffer_new(NULL, -1);
  GtkWidget *file_ext_label =
      gtk_label_new("Enter file extensions, separated by a whitespace.");
  GtkWidget *file_ext_input = gtk_entry_new_with_buffer(file_ext);
  gtk_grid_attach(GTK_GRID(file_ext_grid), file_ext_label, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(file_ext_grid), file_ext_input, 0, 1, 1, 1);

  //   g_signal_connect(new_word_input, "activate", G_CALLBACK(button_press),
  //                    app_config);
  gtk_grid_attach(GTK_GRID(config_input_grid), directory_name_grid, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(config_input_grid), file_ext_grid, 1, 0, 1, 1);

  // Add classes:
  gtk_widget_add_css_class(directory_name_grid, "input-grid");
  gtk_widget_add_css_class(directory_label, "label");
  gtk_widget_add_css_class(file_ext_grid, "input-grid");
  gtk_widget_add_css_class(file_ext_label, "label");
  gtk_widget_add_css_class(directory_name_input, "input");
  gtk_widget_add_css_class(file_ext_input, "input");

  return config_input_grid;
}