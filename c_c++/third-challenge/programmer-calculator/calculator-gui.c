#include <gtk/gtk.h>
#include <stdlib.h>

// Funções para operações básicas e conversões
float adicionar(float a, float b) { return a + b; }
float subtrair(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }
float dividir(float a, float b) { return (b != 0) ? a / b : 0; }

int binario_para_decimal(const char *bin) {
    return strtol(bin, NULL, 2);
}

void decimal_para_binario(int dec, char *bin) {
    itoa(dec, bin, 2);
}

// Callback para o botão de calcular
void calcular(GtkWidget *widget, gpointer data) {
    GtkEntry **entries = (GtkEntry **)data;
    const char *num1_str = gtk_entry_get_text(entries[0]);
    const char *num2_str = gtk_entry_get_text(entries[1]);
    const char *operador = gtk_entry_get_text(entries[2]);

    float num1 = atof(num1_str);
    float num2 = atof(num2_str);
    float resultado;
    char resultado_str[32];

    switch (operador[0]) {
        case '+':
            resultado = adicionar(num1, num2);
            break;
        case '-':
            resultado = subtrair(num1, num2);
            break;
        case '*':
            resultado = multiplicar(num1, num2);
            break;
        case '/':
            resultado = dividir(num1, num2);
            break;
        default:
            strcpy(resultado_str, "Operador inválido");
            gtk_entry_set_text(entries[3], resultado_str);
            return;
    }
    snprintf(resultado_str, sizeof(resultado_str), "%.2f", resultado);
    gtk_entry_set_text(entries[3], resultado_str);
}

int main(int argc, char *argv[]) {
    GtkWidget *window, *grid, *button;
    GtkEntry *entries[4];
    gtk_init(&argc, &argv);

    // Criação da janela
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculadora Programador");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Criação do grid para organizar os widgets
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Criação das entradas de texto
    for (int i = 0; i < 4; i++) {
        entries[i] = GTK_ENTRY(gtk_entry_new());
        gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(entries[i]), 0, i, 1, 1);
    }
    gtk_entry_set_placeholder_text(entries[0], "Número 1");
    gtk_entry_set_placeholder_text(entries[1], "Número 2");
    gtk_entry_set_placeholder_text(entries[2], "Operador (+, -, *, /)");
    gtk_entry_set_placeholder_text(entries[3], "Resultado");

    // Criação do botão de calcular
    button = gtk_button_new_with_label("Calcular");
    g_signal_connect(button, "clicked", G_CALLBACK(calcular), entries);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 4);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
