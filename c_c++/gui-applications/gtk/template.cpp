#include <gtk/gtk.h>
#include <stdlib.h>

// Estrutura para agrupar os widgets de entrada
typedef struct {
    GtkWidget *entry1;
    GtkWidget *entry2;
    GtkWidget *entry_operator;
    GtkWidget *entry_result;
} CalculatorWidgets;

// Função de callback para quando o botão é clicado
static void on_calculate_clicked(GtkWidget *widget, gpointer data) {
    CalculatorWidgets *widgets = (CalculatorWidgets *)data;
    const char *num1_str = gtk_entry_get_text(GTK_ENTRY(widgets->entry1));
    const char *num2_str = gtk_entry_get_text(GTK_ENTRY(widgets->entry2));
    const char *operator_str = gtk_entry_get_text(GTK_ENTRY(widgets->entry_operator));

    double num1 = atof(num1_str);
    double num2 = atof(num2_str);
    double result;

    switch (operator_str[0]) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                gtk_entry_set_text(GTK_ENTRY(widgets->entry_result), "Erro: Divisão por zero");
                return;
            }
            break;
        default:
            gtk_entry_set_text(GTK_ENTRY(widgets->entry_result), "Operador inválido");
            return;
    }

    char result_str[32];
    snprintf(result_str, sizeof(result_str), "%.2f", result);
    gtk_entry_set_text(GTK_ENTRY(widgets->entry_result), result_str);
}

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculadora");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    CalculatorWidgets *widgets = g_new0(CalculatorWidgets, 1);

    widgets->entry1 = gtk_entry_new();
    widgets->entry2 = gtk_entry_new();
    widgets->entry_operator = gtk_entry_new();
    widgets->entry_result = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Número 1"), 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), widgets->entry1, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Número 2"), 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), widgets->entry2, 1, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Operador (+, -, *, /)"), 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), widgets->entry_operator, 1, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Resultado"), 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), widgets->entry_result, 1, 3, 1, 1);

    GtkWidget *button = gtk_button_new_with_label("Calcular");
    g_signal_connect(button, "clicked", G_CALLBACK(on_calculate_clicked), widgets);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 2, 1);

    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("com.example.GtkApplication", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
