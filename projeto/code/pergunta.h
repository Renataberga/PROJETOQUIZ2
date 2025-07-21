// Aqui é a como cada pergunta funciona: ela guarda o enunciado, as opções e qual é a correta
#ifndef PERGUNTA_H
#define PERGUNTA_H

#include <QString>      // Inclui a classe QString para manipulação de texto
#include <QStringList>  // Inclui a classe QStringList para listas de strings

// Classe que representa uma pergunta do quiz
class Pergunta {
public:
    QString texto;           // Texto da pergunta
    QStringList opcoes;      // Lista com as opções de resposta
    int respostaCorreta;     // Índice da opção correta na lista 'opcoes'

    // Construtor que inicializa texto, opções e índice da resposta correta
    Pergunta(const QString &texto = "", const QStringList &opcoes = {}, int respostaCorreta = 0);

    // Método que verifica se a resposta escolhida (índice) está correta
    bool verificarResposta(int resposta) const;
};

#endif // PERGUNTA_H

