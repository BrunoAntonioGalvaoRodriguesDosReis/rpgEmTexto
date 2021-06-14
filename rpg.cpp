#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>

/**
 * Um sistema de RPG em modo text que, dependendo das 
 * escolhas da/do jogadora/or pode mudar o final
 */

// TODO Fazer uma forma do jogador ou jogadora escolher sua raça
// TODO Sendo que cada raça tem a possibilidade de  ter mais ou menos atributos que as outras

struct Personagem{
    std::string nome;

   unsigned int energia;
    unsigned int altura;
    unsigned int forcaFisica;
    unsigned int forcaMagica;
    unsigned int creditos;
    unsigned int maestria;
    unsigned int feitico;
    unsigned int socializacao;
};

float geraAleatorio(){
    return rand() / (float) RAND_MAX;
}

struct Personagem boasVindasDoJogo(){
    std::cout << "Boas vindas ao nosso mundo!\n";
    std::cout << "Um sentimento de obscuridade tomou conta de nossa terra, \n";
    std::cout << "o rei Demônio dominou as principais forças de defesa do nosso povo\n";
    std::cout << "e a cada dia que passa as esperanças decaem mais e mais...\n";

    std::cout << "Como somos um bando de incompetentes e não conseguimos nos defender\n";
    std::cout << "precisamos de alguém que nos lidere para a derrocada deste maldito!\n";
    std::cout << "Você é nossa escolha!! E... a propósito... qual é mesmo o seu nome?\n";

    std::string nome;
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "De agora em diante lhe chamaremos de Sir " << nome << "!\n";

    struct Personagem eu;

    eu.nome = nome;
    eu.energia = (geraAleatorio() * 90) + 10;
    eu.altura = geraAleatorio() * 300;
    eu.forcaFisica = geraAleatorio() * 100;
    eu.forcaMagica = geraAleatorio() * 50;
    eu.creditos = 26;
    eu.maestria =geraAleatorio() *1000;
    eu.feitico =0;
    eu.socializacao =geraAleatorio() *300;

    return eu;
}

void mostraStatusDoJogador(struct Personagem &p){

    if(p.energia == 0){
        std::cout << "Você morreu!!!" << std::endl;
        return;
    }

    std::cout << "Você agora tem " <<p.feitico  << "\n" "pontos de feitico" "\n" << p.altura/100.0 <<
                " metros de altura, " "\n"  << p.energia << " de energia com uma força de intensidade "  <<
                p.forcaFisica << "\n" " e um poder mágico de " <<
                p.forcaMagica  <<"seu nivel de maestria é"  <<p.maestria<<" e voce possui" << std::endl;
}

void faseDaCidade(struct Personagem &p){
    
    unsigned int opcao = 0;

    while(opcao < 1 || opcao > 2){
        std::cout << "Você está na rua principal da cidade, nesta rua você vê dois estabelecimentos: Uma quitanda de um lado uma loja de armas do outro.\n Para onde você deseja ir?" << std::endl;
        std::cout << "1-Quitanda\n2-Loja de armas" << std::endl;

        std::cin >> opcao;
    }

    if(opcao == 1){
        std::cout << "O vendedor te olha e pergunta: O que deseja meu caro?" << std::endl;
        
        std::cout << "1-Nada\n2-Comida\n3-Que vá para a p*" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            opcao = 0;

            while(opcao < 1 || opcao > 2){
                std::cout << "1-Macarrão (Dá muita energia)\n2-Balinha (Dá pouca energia)" << std::endl;
                std::cin >> opcao;
            }

            switch(opcao){
                case 1:
                    if(p.creditos >= 50){
                        p.energia += 50;
                        p.creditos -= 50;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
                case 2:
                    if(p.creditos >= 10){
                        p.energia += 10;
                        p.creditos -= 10;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
            }
            return;

        }else if(opcao == 3){
            std::cout << "Prepare-se para morrer indolente!!!" << std::endl;
            p.energia = p.energia - p.energia;
            return;
        }else{
            std::cout << "Que cara estranho....";
        }

    }

    if(opcao == 2){
        std::cout << "O vendedor te olha e pergunta: Pronto pra batalha?" << std::endl;
        
        std::cout << "1-Não\n2-Espada\n3-Adaga" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            std::cout << "Bela escolha!" << std::endl;

            if(p.creditos >= 200){
                std::cout << "Muitos cairão por essa lâmina!!" << std::endl;
                p.creditos = p.creditos - 200;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Você não merece este tesouro plebeu!!" << std::endl;
            }

        }else if(opcao == 3){
            std::cout << "Pelo menos dá para apontar um lápis" << std::endl;

            if(p.creditos >= 25){
                std::cout << "ok..." << std::endl;
                p.creditos = p.creditos - 25;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Saia daqui farrapo!!!" << std::endl;
            }
        }else{
            std::cout << "Vá embora!." << std::endl;
        }
    }
}

void faseDeHogwarts (struct Personagem &p){
    
    unsigned int opcao = 0;

      while(opcao < 1 || opcao > 2){
        std::cout << "Você foi enviado a Hogwarts pela Academia Braisileira de Bruxos(as) para aperfeiçoar seus pontos mágicos , ao chegar lá você se depara com o Diretor Que lhe pergunta para qual Casa de Bruxos quer entrar....\n Para qual casa você deseja ir?" << std::endl;
        std::cout << "1-Grifinoria\n2-Sonserina" << std::endl;
      
        std::cin >> opcao;
      }

      if(opcao == 1){
        std::cout << "Parabéns você agora faz parte da familia Grifinoria, O que deseja fazer agora?" << std::endl;
        
        std::cout << "1-Nada\n2-Comprar Várinha \n3-Treinar Feitiços" << std::endl;
        std::cin >> opcao;

      if(opcao == 2){

            opcao = 0;

      while(opcao < 1 || opcao > 2){
                std::cout << "1-Alder Amieiro (Leve e boa para manuzeio)\n2-Cedar Cedro (Muito Poderosa e dificil pra manuzear)" << std::endl;
                std::cin >> opcao;
    }

      switch(opcao){
            case 1:
                    if(p.creditos >= 10){
                        p.maestria += 20;
                        p.feitico += 10;
                        p.creditos -= 10;
                    }else{
                        std::cout << "Desculpe mas você não possui créditos suficientes para comprar isso..."  << std::endl;
                    }
                    break;
            case 2:
                    if(p.creditos >= 50){
                        p.maestria += 75;
                        p.feitico += 33;
                        p.creditos -= 50;
                    }else{
                        std::cout << "Desculpe mas você não possui créditos suficientes para comprar isso..." << std::endl;
                    }
                    break;
            }
            return;

        }else if(opcao == 3){
            std::cout << "Ora ora parece que você ainda não tem varinha para treinar seus  feitiços compre uma e volte aqui " << std::endl;
           


            return;
        }else{
            std::cout << "Novatos sempre dando trabalho!!!....";
        }

     if(opcao == 2){
        std::cout << "Parabéns você agora faz parte da familia Sonserina, Você está pronto para aprender sobre como voar em uma vassoura? Para onde desejas ir?" << std::endl;
        
        std::cout << "1-Ficar Aqui \n2-Ir ao Biblioteca  \n3-Ir ao Refeitorio Comer algo" << std::endl;
        std::cin >> opcao;

      if(opcao == 2){

            opcao = 0;
      } 
      while(opcao < 1 || opcao > 2){
                std::cout << "1-Ler um Livro Referente a Magia \n 2-Sair ir para outro lugar" << std::endl;
                std::cin >> opcao;

                switch(opcao){
            case 1:
                    if(p.feitico +=25)
                       p.maestria +=10;
                    
                   
                    break;
                
            case 2:
                 std::cout << "Ok vamos a outro lugar" << std::endl;
                 
                    break;
                }    
            return;
                
            
            
             if (opcao == 3){
               while(opcao < 1 || opcao > 2)
                std::cout << "1-Maça \n 2-Sopa de Batatas " << std::endl;
                std::cin >> opcao;
               
               switch(opcao){
            case 1:
                   (p.forcaFisica= p.forcaFisica + p.forcaFisica);
                    break;
            case 2:
                   (p.forcaFisica= p.forcaFisica + p.forcaFisica);
                    break;
               
            return;
        }

int main(int argc, char** argv)
{
    // s = seed rand = aleatório                                                
    // std::time vem da biblioteca ctime  
    std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

    struct Personagem j = boasVindasDoJogo();

    std::cout << "Você recebeu um presente das divindades da terra!\n";
    std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

    mostraStatusDoJogador(j);

    faseDaCidade(j);

    faseDeHogwarts(j);

    mostraStatusDoJogador(j);
}
