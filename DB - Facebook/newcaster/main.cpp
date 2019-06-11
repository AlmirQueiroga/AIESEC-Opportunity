#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include <windows.h>

using namespace std;

int Comeco(){

	int c;

    cout << "Selecione uma das opcoes" << endl << endl;
    cout << "1 - Login" << endl;
    cout << "2 - Cadastrar-se" << endl;

    if(c < 1 || c > 2){
    	cout << "erro! opcao nao existente" << endl;

    	return 0;

    }else{
    cin >> c
    switch(option){
        case 1:
        Login();
        break;
        case 2:
            cadastrarUsuario();
            break;
                }
    return c;
	}
};

void MenuPrincipal(){

	int c;

	cout << "escolha uma opçao abaixo:" << endl;
	cout << "1 - ver solicitacoes de amizade" << endl;
	cout << "2 - ver amigos" << endl;
	cout << "3 - ver mensagens" << endl;
	cout << "4 - ver seu mural" << endl;
	cout << "5 - buscar usuarios" << endl;
	cout << "6 - buscar grupo" << endl;
	cout << "7 - criar grupo" << endl;
	cout << "8 - ver perfil" << endl;

	cin << c;

	if(c < 1 || c > 8){
		cout << "erro! opcao nao existente" << endl;
	}else{

	switch(option){
        case 1:
        	solicitacoes();
            break;
        case 2:
           	listaamigos();
           break;
        case 3:
          	mensagens();
          break;
        case 4:
        	mural();
        	break;
        case 5:
           	buscaruser();
           	break;
        case 6:
           	buscargrupo();
           	break;
        case 7:
          	criargrupo();
          	break;
        case 8:
        	verPerfil();
        	break;
}
}
}

void mural(){

	int c;

	cout << "1 - publicar" << endl;
	cout << "2 - ver publicações" << endl;
	cout << "3 - retornar" << endl;
	cin << c;

	if(c < 1 || c > 3){
		cout << "erro! opcao nao existente" << endl;
	}else{

		switch(){
			case 1:
			CriarPublicacao();
			case 2:
			VerPublicacao(); //////// ---> banco de dados -----> escolher publicação ----> publicacao()
			case 3:
			//////////////////////// conflito, retornar pra onde? perfil de quem?
		}
	}
};


void publicacao(){

	cout << "1 - ver comentarios" << endl;
	cout << "2 - comentar" << endl;
	cout << "3 - retornar" << endl;

	if(c < 1 || c > 3){
		cout << "erro! opcao nao existente" << endl;
	}else{

		switch(){
			case 1:
			vercomentarios(); //////// ---> banco de dados -----> escolher comentario ----> comentario()
			case 2:
			criarcomentario();
			case 3:
			mural();
		}
	}
};


void comentario(){

	cout << "1 - ver respostas" << endl;
	cout << "2 - responder" << endl;
	cout << "3 - retornar" << endl;

	if(c < 1 || c > 3){
		cout << "erro! opcao nao existente" << endl;
	}else{

		switch{
			case 1:
			verresposta(); //////// ---> banco de dados -----> ver respostas
			case 2:
			criarreposta();
			case 3:
			publicacao();
		}
	}

};

void UserVisitado(){ ///////////// PUXADA PELO PROCURAR USUARIO
    cout << "Selecione uma das opções" << endl << endl;
    if(amizadeVerificador() == 1){
        cout << "1. Ver Perfil" << endl;
        cout << "2. Publicar" << endl;
        cout << "3. Ver Publicacoes do Mural" << endl;
        cout << "4. Ver Amigos" << endl;
        cout << "5. Ver Amigos em Comum" << endl;
        cout << "6. Desfazer Amizade" << endl;
    }
    if(amizadeVerificador() == 5){
        return;
    }
    if(amizadeVerificador() == -1){
        cout << "1. Ver Perfil" << endl;
        cout << "2. Solicitar Amizade" << endl;
    }
    else{
        cout << "1. Ver Perfil" << endl;
    }
    int option;
    cin >> option;
    switch(option){
        case 1:
            verPerfil();
            UserVisitado();
            break;
        case 2:
            if(amizadeVerificador() == 1)
                CriarPublicacao();
            if(amizadeVerificador() == -1)
                solicitarAmizade();
            UserVisitado();
            break;
        case 3:

            if(amizadeVerificador() == 1 && VerPublicacao()){
                Publicacao();
            }
            UserVisitado();
            break;
        case 4:
            //?????????????
            break;
        case 5:
            //?????????????w
            break;
        case 6:
            //??????????ww
            break;
        default:

            break;
    }
}


int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    conn = mysql_init(0);
    if(conn) {
        cout << "connection object ok" << endl;
    }else {
    cout << "connection object problem" << mysql_error(conn) << endl;
    }

    conn = mysql_real_connect(conn, "localhost", "root", "", "facebook", 0, NULL, 0);

       if(conn) {
        cout << "connection to database ok" << endl;
    }else {
    cout << "connection object problem" << mysql_error(conn) << endl;
    }

    return 0;
}
