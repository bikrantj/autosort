#include "headers.h"
#include <dirent.h>
#include <gtk/gtk.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  FileType *fileTypes = load_file_types("../config.txt");
  GtkApplication *app =
      gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(setup_ui), fileTypes);
  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return 0;
}
