//linguagem C++

#include <iostream>
#include <string>
#include <stdlib.h>
#include <locale.h>

using namespace std;

//variavel global para opcao generica
string op1;
string op2;
string op3;
//-----------------------------------
void menuJogo();
void menuCripto();
void iniciarJogo();

int menuPrincipal(){
	cout << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "- Bem vindo! por favor, digite o numero de uma das opcoes para comecar. -" << endl;
	cout << "-------------------------------------------------------------------------" << endl << endl;
	
	cout << "1. Os cachorros e o gato" << endl;
	cout << "2. criptografia de mensagem" << endl << endl;
	
	cin >> op1;
	cout << endl;
	
	if(op1 == "1"){
		menuJogo();
	}
	else if(op1 == "2"){
		menuCripto();
	}
	else{
		cout << "por favor, escolha uma opcao valida." << endl << endl;
		menuPrincipal();
	}
		
}

void menuJogo(){
	
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "-                         Os cachorros e o gato                         -" << endl;
	cout << "-------------------------------------------------------------------------" << endl << endl;
	
	
	cout << "1. jogar" << endl;
	cout << "2. explicacao" << endl;
	cout << "3. voltar ao menu principal" << endl << endl;
	
	cin >> op2;
	cout << endl;
	
	if(op2 == "1"){
		iniciarJogo();
	}
	else if(op2 == "2"){
		
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "-                              explicacao                               -" << endl;
		cout << "-------------------------------------------------------------------------" << endl << endl;
	
		cout << "Dois cachorros(Bob, e Rex) e um gato(Oli) estão em uma linha." << endl <<
		"Os cachorros se movem de forma igualitária(para frente e para trás)." << endl <<
		"O gato, está se alimentando. O cachorro que chegar no ponto antes," << endl <<
		"consegue pegar o gato distraído, caso, os dois cachorros cheguem no ponto" << endl <<
		"do gato no mesmo momento, eles começam a brigar, e o gato consegue fugir." << endl << endl;
		
		cout << "Mande as posicoes dos cachorros e do gato, e descubra quem saira vitorioso!"<< endl;
		cout << "* as posicoes precisam ser numeros positivos *" << endl;
		
		cout << "precione qualquer tecla para voltar ao menu do jogo... ";
		cin >> op2;
		cout << endl;
		
		menuJogo();
	}
	else if(op2 == "3"){
		menuPrincipal();
	}
	else{
		cout << "por favor, escolha uma opcao valida." << endl << endl;
		menuJogo();
	}
}

string calcVencedor(int bob, int rex, int oli){
	string bobV = "Bob";
	string rexV = "Rex";
	string oliV = "Oli";
	
	int bobC;
	int rexC;
	
	if(bob <= oli){
		bobC = oli - bob;
	}else (bobC = bob - oli);
	
	if(rex <= oli){
		rexC = oli - rex;
	}else (rexC = rex - oli);
	
	if(bobC < rexC){
		return bobV;
	}
	else if(rexC < bobC){
		return rexV;
	}
	else{return oliV;}
}
void verificador(int nome, bool jogo){
	if (cin.fail() || nome < 0){
	    cout << endl << "insira um numero valido!" << endl << endl;
	    nome = 1;
		cin.clear(); cin.ignore(INT_MAX,'\n');
		if(jogo == true){
			iniciarJogo();
		}else(menuCripto());
	}
}
void iniciarJogo(){
	int bob;
	int rex;
	int oli;
	
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "-                  jogando - Os cachorros e o gato                      -" << endl;
	cout << "-------------------------------------------------------------------------" << endl << endl;
	
	cout << "insira numeros de 0 a 2147483647" << endl << endl;
	cout << "insira a posicao de bob: ";
	cin>> bob;
	verificador(bob, true);
	
	cout << "insira a posicao de rex: ";
	cin >> rex;
	verificador(rex, true);
		
	cout << "insira a posicao de oli: ";
	cin >> oli;
	verificador(oli, true);
		
	cout << endl << "e o resultado é... ";
	if(calcVencedor(bob, rex, oli) == "Bob" || calcVencedor(bob, rex, oli) == "Rex"){
		cout << calcVencedor(bob, rex, oli) << " pega Oli!!!" << endl << endl;
	}else(cout << calcVencedor(bob, rex, oli) << " foge!!!" << endl << endl);
	
	do{
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "1. jogar novamente." << endl;
		cout << "2. voltar ao menu do jogo." << endl;
		cout << "3. voltar ao menu principal." << endl << endl;
		
		cin >> op2;
		cout << endl;
		
		if(op2 == "1"){
			iniciarJogo();
		}
		else if(op2 == "2"){
			menuJogo();
		}
		else if(op2 == "3"){
			menuPrincipal();
		}
		else(cout << "insira uma opcao valida!" << endl << endl);
	}while(true);
}

char converter(char c, int rot)
{
    if (!isalpha(c)) return c;
    char offset = isupper(c) ? 'A' : 'a';
    return (char)((((c + rot) - offset) % 26) + offset);
}

string criptografar( string msg, int rot )
{
    string msgCript = "";
    size_t len = msg.size();
    for( size_t i = 0; i < len; i++ )
        msgCript += converter( msg[i], rot );
    return msgCript;
}

string descriptografar( string msg, int rot )
{
    return criptografar( msg, 26 - rot);
}
void voltarMenuCripto(){
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "1. voltar ao menu Criptografia." << endl;
	cout << "2. voltar ao menu principal." << endl << endl;
	
	cin >> op3;
	cout << endl;
	
	if(op3 == "1"){
		menuCripto();
	}
	else if(op3 == "2"){
		menuPrincipal();
	}
	else{
	cout << "insira uma opcao valida!" << endl << endl;
	voltarMenuCripto();
	}
}
void menuCripto(){
	int rot;
	string msg;
	
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "-                            Criptografia                               -" << endl;
	cout << "-------------------------------------------------------------------------" << endl << endl;
	
	cout << "1. criptografar" << endl;
	cout << "2. descriptografar" << endl;
	cout << "3. voltar ao menu principal" << endl << endl;
	
	cin >> op3;
	
	if(op3 == "1"){
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "-                          Criptografando                               -" << endl;
		cout << "-------------------------------------------------------------------------" << endl << endl;
		
		cout << "insira a mensagem a ser criptografada:" << endl;
		cin >> msg;
		cout << endl;
		cout << "insira a rotacao da cifra: ";
		cin >> rot;
		verificador(rot, false);
		cout << endl;
		
		cout << "texto criptografado: " << endl;
		cout << criptografar(msg, rot) << endl;
		
		voltarMenuCripto();
	}
	else if(op3 == "2"){
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "-                         Descriptografando                             -" << endl;
		cout << "-------------------------------------------------------------------------" << endl << endl;
		
		cout << "insira a mensagem a ser descriptografada" << endl;
		cin >> msg;
		cout << endl;
		cout << "insira a rotacao da cifra: ";
		cin >> rot;
		verificador(rot, false);
		cout << endl;
		
		cout << "texto descriptografado: " << endl;
		cout << descriptografar(msg, rot) << endl;
		
		voltarMenuCripto();
	}
	else if(op3 == "3"){
		menuPrincipal();
	}
	else{
		cout << "por favor, escolha uma opcao valida." << endl << endl;
		menuCripto();
	}
}


int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "portuguese");
	menuPrincipal();
	
	return 0;
}
