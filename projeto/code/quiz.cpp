// A lógica pesada do quiz fica aqui: carrega perguntas por tema, sortea perguntas se for no modo aleatório e valida se o jogador respondeu certo.

#include "quiz.h"
#include <QRandomGenerator>
#include <algorithm>

Quiz::Quiz() : perguntaAtual(0) {}

void Quiz::carregarPerguntas(const QString &tema) {
    perguntas.clear();
    perguntaAtual = 0;
    QVector<Pergunta> perguntasTemp;

    // --- ENTRE EM CADA TEMA ABAIXO ---
    if (tema == "Entretenimento" || tema == "Aleatório") {
        perguntasTemp += {
            Pergunta("Quem venceu o Oscar 2020 de Melhor Filme?", {"1917", "Parasita", "Coringa"}, 1),
            Pergunta("Quem interpreta o personagem Tony Stark (Homem de Ferro) no universo Marvel?", {"Chris Evans", "Chris Hemsworth", "Robert Downey Jr."}, 2),
            Pergunta("Qual é o nome da série da Netflix protagonizada por um grupo que assalta a Casa da Moeda da Espanha?", {"Narcos", "La Casa de Papel", "Elite"}, 1),
            Pergunta("Qual dessas cantoras lançou o álbum Lemonade em 2016?", {"Adele", "Beyoncé", "Rihanna"}, 1),
            Pergunta("Qual banda é famosa por músicas como 'Bohemian Rhapsody' e 'We Will Rock You'?", {"The Beatles", "Queen", "U2"}, 1),
            Pergunta("Quem é o cantor brasileiro conhecido como 'O Rei'?", {"Chico Buarque", "Roberto Carlos", "Caetano Veloso"}, 1),
            Pergunta("Qual é o nome do bruxo protagonista da série de livros de J.K. Rowling?", {"Frodo", "Harry Potter", "Percy Jackson"}, 1),
            Pergunta("Qual rede de TV americana exibe a série 'Os Simpsons' desde 1989?", {"NBC", "FOX", "CBS"}, 1),
            Pergunta("Em que país nasceu o famoso diretor Alfred Hitchcock?", {"Estados Unidos", "Reino Unido", "França"}, 1),
            Pergunta("Qual série tem um grupo de amigos que se reúne no Central Perk, um café em Nova York?", {"How I Met Your Mother", "The Big Bang Theory", "Friends"}, 2)
        };
    }

    if (tema == "História" || tema == "Aleatório") {
        perguntasTemp += {
            Pergunta("Quem descobriu o Brasil?", {"Pedro Álvares Cabral", "Cristóvão Colombo", "Vasco da Gama"}, 0),
            Pergunta("Em que ano ocorreu a Revolução Francesa?", {"1789", "1815", "1776"}, 0),
            Pergunta("Quem foi o líder da Alemanha durante a Segunda Guerra Mundial?", {"Adolf Hitler", "Joseph Stalin", "Benito Mussolini"}, 0),
            Pergunta("Qual império foi governado por Alexandre, o Grande?", {"Império Romano", "Império Persa", "Império Macedônio"}, 2),
            Pergunta("Qual civilização antiga construiu as pirâmides de Gizé?", {"Egípcia", "Mesopotâmica", "Inca"}, 0),
            Pergunta("Qual era o nome do navio em que Charles Darwin viajou?", {"HMS Beagle", "HMS Victory", "Santa Maria"}, 0),
            Pergunta("Quem foi o primeiro imperador de Roma?", {"César Augusto", "Júlio César", "Nero"}, 0),
            Pergunta("Qual evento marcou o início da Primeira Guerra Mundial?", {"Invasão da Polônia", "Assassinato do arquiduque Francisco Ferdinando", "Ataque a Pearl Harbor"}, 1),
            Pergunta("Qual país foi o primeiro a abolir a escravidão?", {"Estados Unidos", "França", "Haiti"}, 2),
            Pergunta("Qual muro dividia a Alemanha durante a Guerra Fria?", {"Muro de Berlim", "Muro de Viena", "Muro de Moscou"}, 0)
        };
    }

    if (tema == "Ciência" || tema == "Aleatório") {
        perguntasTemp += {
            Pergunta("Qual planeta é conhecido como Planeta Vermelho?", {"Terra", "Marte", "Júpiter"}, 1),
            Pergunta("Qual é o planeta mais próximo do Sol?", {"Mercúrio", "Vênus", "Terra"}, 0),
            Pergunta("O que é H2O?", {"Gás carbônico", "Água", "Ácido sulfúrico"}, 1),
            Pergunta("Qual é a unidade de medida da força?", {"Joule", "Newton", "Watt"}, 1),
            Pergunta("Qual cientista formulou a teoria da relatividade?", {"Isaac Newton", "Albert Einstein", "Galileu Galilei"}, 1),
            Pergunta("Qual parte da célula é responsável pela produção de energia?", {"Mitocôndria", "Ribossomo", "Lisossomo"}, 0),
            Pergunta("Qual elemento químico tem o símbolo 'O'?", {"Ouro", "Oxigênio", "Ósmio"}, 1),
            Pergunta("Quantos planetas compõem o sistema solar?", {"8", "9", "7"}, 0),
            Pergunta("Qual gás é essencial para a respiração humana?", {"Dióxido de carbono", "Hidrogênio", "Oxigênio"}, 2),
            Pergunta("O que é DNA?", {"Tipo de proteína", "Molécula de hereditariedade", "Hormônio"}, 1)
        };
    }

    if (tema == "Aleatório") {
        std::shuffle(perguntasTemp.begin(), perguntasTemp.end(), *QRandomGenerator::global());
        perguntas = perguntasTemp.mid(0, 10); // Pega as 10 primeiras
    } else {
        perguntas = perguntasTemp;
    }
}

Pergunta Quiz::getPerguntaAtual() const {
    return perguntas[perguntaAtual];
}

bool Quiz::verificarResposta(int resposta) {
    return perguntas[perguntaAtual].verificarResposta(resposta);
}
