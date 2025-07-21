// Aqui é definida a estrutura da classe Jogador, com seus dados e o método público que permite somar pontos.

#ifndef JOGADOR_H
#define JOGADOR_H

#include <QString>  // Inclui a classe QString para manipulação de strings no Qt

// Classe que representa o jogador do quiz
class Jogador {
public:
    QString nome;      // Nome do jogador
    int pontuacao;     // Pontuação acumulada do jogador

    // Construtor que inicializa o nome do jogador (padrão vazio)
    Jogador(const QString &nome = "");

    // Método que adiciona um ponto à pontuação do jogador
    void adicionarPonto();
};

#endif // JOGADOR_H
