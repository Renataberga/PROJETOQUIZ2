// Aqui foi definido a estrutura do quiz como um todo. Ele armazena todas as perguntas e gerencia qual está sendo exibida.
#ifndef QUIZ_H
#define QUIZ_H

#include "pergunta.h"              // Inclui a classe Pergunta, usada para representar cada pergunta do quiz
#include <QVector>                 // Inclui QVector, um vetor dinâmico usado para armazenar as perguntas

// Classe responsável por gerenciar as perguntas e a lógica do quiz
class Quiz {
public:
    QVector<Pergunta> perguntas;   // Vetor que armazena todas as perguntas carregadas
    int perguntaAtual;             // Índice da pergunta atual que está sendo exibida

    Quiz();                        // Construtor do quiz

    // Carrega perguntas de acordo com o tema escolhido
    void carregarPerguntas(const QString &tema);

    // Retorna a pergunta atual com base no índice 'perguntaAtual'
    Pergunta getPerguntaAtual() const;

    // Verifica se a resposta escolhida está correta
    bool verificarResposta(int resposta);
};

#endif // QUIZ_H
