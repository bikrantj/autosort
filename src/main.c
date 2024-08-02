#include "headers.h"
#include <dirent.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // if (argc != 2) {
  //   fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
  //   return 1;
  // }
  GtkApplication *app =
      gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(setup_ui), NULL);
  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  // processDirectory(argv[1]);
  return 0;
}
