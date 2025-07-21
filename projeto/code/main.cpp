// Esse é o ponto de entrada do programa. Aqui eu crio a aplicação Qt, configuro o tamanho da janela e inicio o loop do programa.

#include "mainwindow.h"   // Inclui o cabeçalho da janela principal do aplicativo
#include <QApplication>   // Inclui a classe QApplication, necessária para qualquer aplicativo Qt

int main(int argc, char *argv[]) {
    // Cria uma instância da aplicação Qt (necessária para gerenciar eventos e janelas)
    QApplication app(argc, argv);

    // Cria a janela principal do jogo
    MainWindow w;

    // Define o tamanho inicial da janela (700x800 pixels)
    w.resize(700, 800); // Janela maior

    // Exibe a janela na tela
    w.show();

    // Inicia o loop de eventos da aplicação Qt
    return app.exec();
}
