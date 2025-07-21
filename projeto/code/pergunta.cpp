// Essa implementação verifica se a resposta escolhida bate com o índice correto. Isso deixa a validação encapsulada dentro da própria pergunta.

#include "pergunta.h"  // Inclui o cabeçalho da classe Pergunta

// Construtor da classe Pergunta
// Inicializa o texto da pergunta, a lista de opções e o índice da resposta correta
Pergunta::Pergunta(const QString &texto, const QStringList &opcoes, int respostaCorreta)
    : texto(texto), opcoes(opcoes), respostaCorreta(respostaCorreta) {}

// Método que verifica se a resposta escolhida (índice passado) está correta
bool Pergunta::verificarResposta(int resposta) const {
    return resposta == respostaCorreta;  // Retorna true se for igual à correta
}
