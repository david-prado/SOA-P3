/*
 * 
 * 
 * Compile me with:
 * 			g++ image.c `pkg-config --libs --cflags cairo gtk+-3.0` -o image
 * 
 * */
#include <gtk-3.0/gtk/gtk.h>
#include <cairo.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>
/*
static void do_drawing(cairo_t *);

struct globe {
  int count;
  double coordx[100];
  double coordy[100];
} glob;

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    gpointer user_data)
{
  do_drawing(cr);

  return FALSE;
}

static void do_drawing(cairo_t *cr)
{
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_set_line_width(cr, 0.5);

  int i, j;
  for (i = 0; i <= glob.count - 1; i++ ) 
  {
      for (j = 0; j <= glob.count - 1; j++ ) 
      {
          cairo_move_to(cr, glob.coordx[i], glob.coordy[i]);
          cairo_line_to(cr, glob.coordx[j], glob.coordy[j]);
      }
  }

  glob.count = 0;
  cairo_stroke(cr);    
}

static gboolean clicked(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    if (event->button == 1) 
    {
        glob.coordx[glob.count] = event->x;
        glob.coordy[glob.count++] = event->y;
    }

    if (event->button == 3) 
    {
        gtk_widget_queue_draw(widget);
    }

    return TRUE;
}
*/

int main(int argc, char *argv[])
{
  GtkBuilder *builder;
  GtkWidget *window;
  GError *error = NULL;
  GtkWidget *darea;

  gtk_init(&argc, &argv);
  
  /* Create new GtkBuilder object */
  builder = gtk_builder_new_from_file("threadville.glade");
 
  if (!builder) {
		g_warning("%s", error->message);
		g_free(error);
		return (1);
  }

  /* Get main window pointer from UI */
  window = GTK_WIDGET(gtk_builder_get_object(builder, "Win_ville"));

  darea = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), darea);

  gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);

//  g_signal_connect(G_OBJECT(darea), "draw", 
//      G_CALLBACK(on_draw_event), NULL);
       
//  g_signal_connect(window, "destroy",
//      G_CALLBACK(gtk_main_quit), NULL); 
      
//  g_signal_connect(window, "on_salir_clicked",
//      G_CALLBACK(gtk_main_quit), NULL); 
    
//  g_signal_connect(window, "button-press-event", 
//      G_CALLBACK(clicked), NULL);

  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 1400, 500); 
  gtk_window_set_title(GTK_WINDOW(window), "Aventuras en Threadville");

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
