#include "typedef.h"
#include <gtk/gtk.h>
static void button_clicked(GtkButton *button, gpointer user_data) {
  Global *params = (Global *)user_data;
  // Print the label of the clicked button
  g_print("%s clicked\n", gtk_button_get_label(button));
  gtk_window_destroy(GTK_WINDOW(params->window));
}
static void on_response(GtkDialog *dialog, gint response_id,
                        gpointer user_data) {
  Global *params = (Global *)user_data;

  gtk_window_destroy(GTK_WINDOW(dialog));
}
void complete_dialog(Global *config) {
  GtkWidget *dialog, *label, *content_area;
  GtkDialogFlags flags;

  // Create the widgets
  dialog = gtk_dialog_new_with_buttons(
      "Complete", GTK_WINDOW(config->window),
      GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, "OK", GTK_RESPONSE_OK,
      "Cancel", GTK_RESPONSE_CANCEL, NULL);

  content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

  label = gtk_label_new("Files Sorted Successfully!");

  gtk_widget_add_css_class(label, "label");

  GtkWidget *play_again_btn =
      gtk_dialog_get_widget_for_response(GTK_DIALOG(dialog), GTK_RESPONSE_OK);
  gtk_widget_add_css_class(play_again_btn, "Ok");

  // Connect response signal
  g_signal_connect(dialog, "response", G_CALLBACK(on_response), config);

  gtk_box_append(GTK_BOX(content_area), label);
  gtk_widget_show(dialog);
}