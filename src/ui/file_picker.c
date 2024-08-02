#include "headers.h"
#include "typedef.h"
#include <gtk/gtk.h>
#include <time.h>

static void file_dialog_response(GtkNativeDialog *dialog, int response,
                                 gpointer user_data) {
  Global *params = (Global *)(user_data);
  if (response == GTK_RESPONSE_ACCEPT) {
    g_autoptr(GFile) file = gtk_file_chooser_get_file(GTK_FILE_CHOOSER(dialog));
    gchar *selected_file_path = g_file_get_path(file);
    g_print("File selected: %s\n", g_file_get_path(file));
    onDirectorySelect(selected_file_path);
    complete_dialog(params);
  }
  gtk_native_dialog_destroy(dialog);
}

static void open_file_dialog(GtkWidget *widget, gpointer data) {
  Global *params = (Global *)(data);
  if (params->window) {
    printf("Window");
  } else {
    printf("Not windwo");
  }
  GtkFileChooserNative *dialog = gtk_file_chooser_native_new(
      "Select a File", GTK_WINDOW(params->window),
      GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER, "_Open", "_Cancel");

  g_signal_connect(dialog, "response", G_CALLBACK(file_dialog_response),
                   params);
  gtk_native_dialog_show(GTK_NATIVE_DIALOG(dialog));
}

GtkWidget *create_file_chooser(Global *config) {

  GtkWidget *button = gtk_button_new_with_label("Select Folder");

  g_signal_connect(button, "clicked", G_CALLBACK(open_file_dialog), config);

  return button;
}