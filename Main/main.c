#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

static void load_url(GtkWidget *entry, gpointer user_data) {
    const gchar *url = gtk_entry_get_text(GTK_ENTRY(entry));
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(user_data), url);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *toolbar;
    GtkWidget *url_entry;
    GtkWidget *back_button;
    GtkWidget *forward_button;
    GtkWidget *reload_button;
    GtkWidget *web_view;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Sanchovi Browser");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    toolbar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(box), toolbar, FALSE, FALSE, 0);

    back_button = gtk_button_new_with_label("Back");
    gtk_box_pack_start(GTK_BOX(toolbar), back_button, FALSE, FALSE, 0);

    forward_button = gtk_button_new_with_label("Forward");
    gtk_box_pack_start(GTK_BOX(toolbar), forward_button, FALSE, FALSE, 0);

    reload_button = gtk_button_new_with_label("Reload");
    gtk_box_pack_start(GTK_BOX(toolbar), reload_button, FALSE, FALSE, 0);

    url_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(toolbar), url_entry, TRUE, TRUE, 0);

    web_view = webkit_web_view_new();
    gtk_box_pack_start(GTK_BOX(box), web_view, TRUE, TRUE, 0);

    g_signal_connect(back_button, "clicked", G_CALLBACK(webkit_web_view_go_back), web_view);
    g_signal_connect(forward_button, "clicked", G_CALLBACK(webkit_web_view_go_forward), web_view);
    g_signal_connect(reload_button, "clicked", G_CALLBACK(webkit_web_view_reload), web_view);
    g_signal_connect(url_entry, "activate", G_CALLBACK(load_url), web_view);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.SanchoviBrowser", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

