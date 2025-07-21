//Aqui é organizado todos os widgets da interface e os métodos que vão responder aos cliques do usuário.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Includes das classes do Qt usadas na MainWindow
#include <QMainWindow>            // Classe base para janelas principais
#include <QPushButton>            // Botões da interface
#include <QLabel>                 // Labels para mostrar textos
#include <QVBoxLayout>            // Layout vertical para organizar widgets

// Includes dos arquivos do projeto
#include "quiz.h"                // Classe que gerencia as perguntas e respostas do quiz
#include "jogador.h"             // Classe que representa o jogador e sua pontuação

// Declaração da classe MainWindow, que herda de QMainWindow
class MainWindow : public QMainWindow {
    Q_OBJECT                    // Macro que habilita o sistema de sinais e slots do Qt

public:
    // Construtor da MainWindow, com parâmetro opcional para o widget pai
    MainWindow(QWidget *parent = nullptr);

protected:
    // Evento chamado quando a janela é redimensionada (override indica que está sobrescrevendo o método da classe base)
    void resizeEvent(QResizeEvent *event) override;

public slots:
    void escolherTema();        // Guarda o tema e mostra a 1ª pergunta
    void responder();           // Verifica se está certa, mostra resultado
    void proximaPergunta();     // Vai para a próxima pergunta
    void reiniciarQuiz();       // Reinicia o quiz do zero

private:
    Quiz quiz;                  // Guarda as perguntas e respostas disponíveis.
    Jogador jogador;            // Guarda o nome do jogador e a pontuação atual.

    // Ponteiros para widgets da interface
    QLabel *titulo;             // Label do título do jogo
    QLabel *labelPergunta;      // Mostra a pergunta atual ou os temas.
    QLabel *labelResultado;     // Mostra se você acertou ou errou.

    QPushButton *botoesTema[4];     // 4 botões para escolha dos temas
    QPushButton *botoesResposta[3]; // 3 botões para as opções de resposta
    QPushButton *botaoProxima;      // Botão para passar para a próxima pergunta
    QPushButton *botaoReiniciar;    // Botão para reiniciar o quiz
    QPushButton *botaoIniciar;      // Botão para iniciar o jogo

    QString temaEscolhido;          // Armazena o tema escolhido pelo jogador

    // Essa função mostra a pergunta atual na tela com as 3 alternativas.
    void mostrarPergunta();
};

#endif // MAINWINDOW_H
