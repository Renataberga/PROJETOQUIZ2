// Aqui é a lógica que realmente executa as ações do jogador — como iniciar a pontuação em zero e aumentar a pontuação a cada acerto.

#include "jogador.h"  // Inclui a definição da classe Jogador

// Construtor da classe Jogador
// Inicializa o nome com o valor passado (ou vazio, se não for fornecido) e zera a pontuação

Jogador::Jogador(const QString &nome)
    : nome(nome), pontuacao(0) {}

// Método que incrementa a pontuação do jogador em 1 ponto
void Jogador::adicionarPonto() {
    pontuacao++;
}
