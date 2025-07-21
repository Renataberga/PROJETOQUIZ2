// Aqui é construído e configurado todos os elementos da interface e implemento a reação a cada botão — iniciar, responder, avançar ou reiniciar.
// Tudo interage com as outras classes aqui.

#include "mainwindow.h"
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QSpacerItem>

// Construtor da MainWindow, inicializa a janela principal e componentes
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), jogador("Jogador") {          // inicializa QMainWindow e o jogador com nome "Jogador"

    QWidget *central = new QWidget(this);                // Cria widget central que conterá o layout
    QVBoxLayout *layout = new QVBoxLayout(central);      // Layout vertical para organizar os widgets no centro

    // ---------- TÍTULO DO JOGO ----------
    layout->addStretch();                                // Adiciona espaço flexível acima para centralizar verticalmente os widgets
    titulo = new QLabel("DESAFIO DAS PERGUNTAS", this);  // Cria um label com o título do jogo
    titulo->setAlignment(Qt::AlignCenter);               // Centraliza o texto no label
    QFont fontTitulo = titulo->font();                   // Pega a fonte atual do label para modificar
    fontTitulo.setFamily("Comic Sans MS");               // Define a família da fonte
    fontTitulo.setPointSize(28);                         // Define o tamanho da fonte
    fontTitulo.setBold(true);                            // Define o texto em negrito
    titulo->setFont(fontTitulo);                         // Aplica a fonte personalizada ao label
    layout->addWidget(titulo);                           // Adiciona o título ao layout
    layout->addSpacing(40);                              // Adiciona espaço fixo de 10px após o título

    // ---------- BOTÃO INICIAR ----------
    botaoIniciar = new QPushButton("Iniciar Jogo", this); // Cria botão para iniciar o jogo
    QFont fontBotao = botaoIniciar->font();               // Pega a fonte atual do botão
    fontBotao.setPointSize(30);                           // Ajusta o tamanho da fonte para 30 pontos
    botaoIniciar->setFont(fontBotao);                     // Aplica a fonte ao botão
    botaoIniciar->setFixedSize(500, 80);                  // Define tamanho fixo do botão
    botaoIniciar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);  // Política de tamanho fixa
    botaoIniciar->setCursor(Qt::PointingHandCursor);       // Altera o cursor ao passar sobre o botão
    layout->addWidget(botaoIniciar, 0, Qt::AlignCenter);   // Adiciona o botão ao layout, centralizado

    // ---------- CONEXÃO BOTÃO INICIAR ----------
    connect(botaoIniciar, &QPushButton::clicked, this, [=]() {
        botaoIniciar->hide();                             // Esconde o botão iniciar ao clicar
        titulo->hide();                                   // Esconde o título do jogo
        labelPergunta->setText("Escolha um tema:");       // Atualiza o texto do label pergunta
        labelPergunta->show();                            // Exibe o label pergunta
        for (auto &b : botoesTema) b->show();             // Mostra os botões de tema
    });

    // ---------- LABEL PERGUNTA/TEMA ----------
    labelPergunta = new QLabel("Escolha um tema:", this);   // Cria label para mostrar perguntas ou temas
    labelPergunta->setWordWrap(true);                       // Permite quebra de linha no texto do label
    labelPergunta->setAlignment(Qt::AlignCenter);           // Centraliza o texto
    labelPergunta->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);  // Política de tamanho expansível na horizontal
    labelPergunta->setMaximumHeight(100);                   // Limita altura máxima do label
    labelPergunta->setVisible(false);                       // Inicialmente escondido
    layout->addWidget(labelPergunta);                       // Adiciona o label ao layout

    // ---------- BOTÕES DOS TEMAS ----------
    QStringList temas = {"Entretenimento", "História", "Ciência", "Aleatório"}; // Lista de temas
    for (int i = 0; i < 4; ++i) {
        botoesTema[i] = new QPushButton(temas[i], this);      // Cria botão para cada tema
        botoesTema[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);  // Expansível horizontalmente
        botoesTema[i]->setMinimumHeight(100);                 // Altura mínima do botão
        botoesTema[i]->hide();                                // Escondido inicialmente
        layout->addWidget(botoesTema[i]);                     // Adiciona botão ao layout
        connect(botoesTema[i], &QPushButton::clicked, this, &MainWindow::escolherTema);  // Conecta clique ao método escolherTema
    }

    // ---------- BOTÕES DAS RESPOSTAS ----------
    for (int i = 0; i < 3; ++i) {
        botoesResposta[i] = new QPushButton(this);            // Cria botão para respostas
        botoesResposta[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  // Expansível horizontal e verticalmente
        botoesResposta[i]->setMinimumHeight(40);             // Altura mínima
        layout->addWidget(botoesResposta[i]);                // Adiciona botão ao layout
        botoesResposta[i]->hide();                           // Inicialmente escondido
        connect(botoesResposta[i], &QPushButton::clicked, this, &MainWindow::responder);  // Conecta clique ao método responder
    }

    // ---------- LABEL RESULTADO ----------
    labelResultado = new QLabel("", this);                   // Label para mostrar resultado das respostas
    labelResultado->setAlignment(Qt::AlignCenter);           // Centraliza o texto
    labelResultado->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  // Expansível
    layout->addWidget(labelResultado);                      // Adiciona ao layout

    // ---------- BOTÃO PRÓXIMA PERGUNTA ----------
    botaoProxima = new QPushButton("Próxima", this);        // Botão para ir para próxima pergunta
    botaoProxima->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    botaoProxima->setMinimumHeight(40);
    botaoProxima->hide();                                  // Inicialmente escondido
    layout->addWidget(botaoProxima);
    connect(botaoProxima, &QPushButton::clicked, this, &MainWindow::proximaPergunta); // Conecta ao método proximaPergunta

    // ---------- BOTÃO REINICIAR ----------
    botaoReiniciar = new QPushButton("Reiniciar", this);   // Botão para reiniciar o jogo
    botaoReiniciar->setMinimumHeight(50);
    QFont fontReiniciar = botaoReiniciar->font();
    fontReiniciar.setPointSize(16);                        // Define tamanho da fonte
    botaoReiniciar->setFont(fontReiniciar);
    botaoReiniciar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    botaoReiniciar->setFixedSize(300, 50);
    layout->addWidget(botaoReiniciar, 0, Qt::AlignCenter); // Centraliza no layout
    botaoReiniciar->hide();                                // Inicialmente escondido
    connect(botaoReiniciar, &QPushButton::clicked, this, &MainWindow::reiniciarQuiz); // Conecta ao método reiniciarQuiz

    setCentralWidget(central);                            // Define widget central da janela
}

// Método chamado ao clicar em um botão de tema
void MainWindow::escolherTema() {
    QPushButton *botao = qobject_cast<QPushButton *>(sender()); // Obtém o botão que enviou o sinal
    temaEscolhido = botao->text();                              // Guarda o tema escolhido pelo texto do botão
    quiz.carregarPerguntas(temaEscolhido);                      // Carrega as perguntas do tema no quiz
    for (auto &b : botoesTema) b->hide();                       // Esconde todos os botões de tema
    mostrarPergunta();                                          // Exibe a primeira pergunta
}

// Exibe a pergunta atual e as opções de resposta
void MainWindow::mostrarPergunta() {
    Pergunta p = quiz.getPerguntaAtual();                       // Obtém pergunta atual do quiz
    labelPergunta->setText(p.texto);                            // Atualiza label com o texto da pergunta
    for (int i = 0; i < 3; ++i) {
        botoesResposta[i]->setText(p.opcoes[i]);                // Define texto das opções nos botões
        botoesResposta[i]->setEnabled(true);                    // Habilita os botões para clique
        botoesResposta[i]->show();                              // Mostra os botões de resposta
    }
    botaoProxima->hide();                                       // Esconde o botão "Próxima"
    labelResultado->clear();                                    // Limpa mensagem de resultado
}

// Método chamado ao clicar em uma resposta
void MainWindow::responder() {
    QPushButton *botao = qobject_cast<QPushButton *>(sender()); // Botão clicado
    int resposta = -1;                                          // Índice da resposta selecionada, inicializa inválido

    for (int i = 0; i < 3; ++i) {
        if (botoesResposta[i] == botao)
            resposta = i;                                       // Identifica qual botão foi clicado
        botoesResposta[i]->setEnabled(false);                   // Desabilita todos botões para impedir múltiplos cliques
    }

    bool correta = quiz.verificarResposta(resposta);           // Verifica se resposta está correta
    if (correta) {
        jogador.adicionarPonto();                              // Incrementa pontuação do jogador
        labelResultado->setText("Correto!");                   // Mostra mensagem de acerto
    } else {
        // Mostra mensagem de erro e resposta correta
        labelResultado->setText("Errado!\nResposta correta: " +
        quiz.getPerguntaAtual().opcoes[quiz.getPerguntaAtual().respostaCorreta]);
    }
    botaoProxima->show();                                      // Mostra botão para próxima pergunta
}

// Vai para a próxima pergunta ou finaliza o quiz
void MainWindow::proximaPergunta() {
    quiz.perguntaAtual++;                                     // Avança índice da pergunta

    if (quiz.perguntaAtual < quiz.perguntas.size()) {
        mostrarPergunta();                                    // Exibe próxima pergunta se houver
    } else {
        labelResultado->clear();                              // Limpa mensagem de resultado
        // Mostra mensagem final com a pontuação do jogador
        labelPergunta->setText("Parabéns!\nSua Pontuação foi: " + QString::number(jogador.pontuacao));
        labelPergunta->setAlignment(Qt::AlignCenter);         // Centraliza o texto final
        for (auto &b : botoesResposta) b->hide();             // Esconde botões de resposta
        botaoProxima->hide();                                 // Esconde botão próxima
        botaoReiniciar->show();                               // Mostra botão para reiniciar
    }
}

// Reinicia o jogo, voltando para a tela de seleção de tema
void MainWindow::reiniciarQuiz() {
    jogador = Jogador("Jogador");                             // Reseta jogador e pontuação
    labelResultado->clear();                                  // Limpa resultado
    labelPergunta->setText("Escolha um tema:");               // Texto inicial da pergunta
    labelPergunta->setAlignment(Qt::AlignCenter);             // Centraliza texto
    for (auto &b : botoesTema) b->show();                     // Mostra botões de tema
    for (auto &b : botoesResposta) b->hide();                 // Esconde botões de resposta
    botaoProxima->hide();                                     // Esconde botão próxima
    botaoReiniciar->hide();                                   // Esconde botão reiniciar
}

// Evento chamado ao redimensionar a janela
void MainWindow::resizeEvent(QResizeEvent *event) {
    QFont font;
    // Calcula tamanho base da fonte proporcional ao menor lado da janela
    int baseSize = std::min(event->size().width(), event->size().height()) / 40;
    font.setPointSize(baseSize);

    // Aplica fonte proporcional ao label pergunta e resultado
    labelPergunta->setFont(font);
    labelResultado->setFont(font);

    // Aplica fonte proporcional aos botões de tema
    for (int i = 0; i < 4; ++i)
        botoesTema[i]->setFont(font);
    // Aplica fonte proporcional aos botões de resposta
    for (int i = 0; i < 3; ++i)
        botoesResposta[i]->setFont(font);

    // Aplica fonte proporcional ao botão próxima
    botaoProxima->setFont(font);

    // Chama o evento base da classe QMainWindow para completar o redimensionamento
    QMainWindow::resizeEvent(event);
}
