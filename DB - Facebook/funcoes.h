#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <locale>
#include <sstream>
#include "telas.h"

using namespace std;

MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
MYSQL_ROW row1;
MYSQL_RES* res1;
MYSQL_ROW row2;
MYSQL_RES* res2;
int qstate;

string idnumeric = "0";
int idNumeric;
ostringstream convert;

string ID_usuario = "";

string ID_usuario_Vis = "";
string ID_grupo_Vis = "";

string ID_publicacao_Vis = "";
string ID_comentario_Vis = "";
string ID_reposta_Vis = "";

string ID_mural = "";
string ID_mural_Vis = "";

void executeQuery(string query){
     const char* q = query.c_str();
     qstate = mysql_query(conn,q);
}

////////////////////    BLOQUEIO - APAGAR COISAS

void DeleteReplyIfBlock(){
    executeQuery("delete from resposta where ID_mural = '"+ID_mural_Vis+"' and ID_usuario = '"+ID_usuario_Vis+"'");
}

void DeleteCommentIfBlock(){
    executeQuery("select * from comentario where ID_comentario = '"+ID_mural_Vis+"' and ID_usuario = '"+ID_usuario_Vis+"'");
    res = mysql_store_result(conn);

    vector<string> idComentarios;

    while(row = mysql_fetch_row(res)){

        idComentarios.push_back(row[0]);
    }

    vector<string> idRespostas[idComentarios.size()];

    for(int i = 0; i < idComentarios.size(); i++){
        executeQuery("select * from resposta where ID_comentario = '"+idComentarios[i]+"'");
        res = mysql_store_result(conn);

        while(row = mysql_fetch_row(res))
            idRespostas[i].push_back(row[0]);

        for(int j = 0; j < idRespostas[i].size(); j++)
            executeQuery("delete from resposta where ID_resposta = '"+idRespostas[i][j]+"'");

        executeQuery("delete from comentario where ID_comentario = '"+idComentarios[i]+"'");
    }
}

void DeletePubIfBlock(){
    executeQuery("select * from publicacao where ID_mural = '"+ID_mural_Vis+"' and ID_usuario = '"+ID_usuario_Vis+"'");
    res = mysql_store_result(conn);

    vector<string> idPublicacao;

    while(row = mysql_fetch_row(res))
        idPublicacao.push_back(row[0]);

    for(int k = 0; k < idPublicacao.size(); k++){
        executeQuery("select * from comentario where ID_publicacao = '"+idPublicacao[k]+"'");
        res = mysql_store_result(conn);

        vector<string> idComentarios;

        while(row = mysql_fetch_row(res))
            idComentarios.push_back(row[0]);

        vector<string> idRespostas[idComentarios.size()];

        for(int i = 0; i < idComentarios.size(); i++){
            executeQuery("select * from resposta where ID_comentario = '"+idComentarios[i]+"'");
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res))
                idRespostas[i].push_back(row[0]);

            for(int j = 0; j < idRespostas[i].size(); j++)
                executeQuery("delete from resposta where ID_reposta = '"+idRespostas[i][j]+"'");

            executeQuery("delete from comentario where ID_reposta = '"+idComentarios[i]+"'");
        }
        executeQuery("delete from publicacao where ID_publicacao = '"+idPublicacao[k]+"'");
    }
}

////////////////////
/////////////////// CADASTRAR (PESSOAS E GRUPOS)
int SignUp(){
    system("cls");
    string nome, nascimento, sexo, email, senha, ID_usuarioMural, visibilidade;

    if(conn){
        cout << "Type your name: "<< endl;
        cin >> nome;
        cin.ignore(80, '\n');
        cout << "Type your email: "<< endl;
        cin >> email;
        cout << "Type your password: "<< endl;
        cin >> senha;
        cin.ignore(80, '\n');
        cout << "What will your visibility be? " << endl;
        cout << "0. Just friends" << endl;
        cout << "1. Friends of friends" << endl;
        cout << "2. Public" << endl;
        cin >> visibilidade;


        if( visibilidade != "2" && visibilidade != "0" && visibilidade != "1")
            visibilidade = "0";

        executeQuery("insert into mural() values()");

        qstate = mysql_query(conn ,"SELECT LAST_INSERT_ID()");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        ID_usuarioMural = row[0];
        executeQuery("insert into usuario(ID_usuarioMural, nome, email, senha, visibilidade) values('"+ID_usuarioMural+"','"+nome+"','"+email+"','"+senha+"','"+visibilidade+"')");

        qstate = mysql_query(conn ,"SELECT LAST_INSERT_ID()");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        ID_usuario = row[0];
        ID_usuario_Vis = ID_usuario;
        ID_mural = ID_usuarioMural;
        ID_mural_Vis = ID_mural;

        if(!qstate){

            idNumeric = atoi(idnumeric.c_str());
            idNumeric++;
            convert << idNumeric;
            idnumeric = convert.str();
        }else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    else
    {
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
    }
}

int CreateGroup(){
    system("cls");
    string nome, dataDeCriacao, ID_grupoMural, visibilidade;

    if(conn){
        cout << "Type your group name: "<< endl;
        cin >> nome;
        cin.ignore(80, '\n');
        cout << "Cureent Date: "<< endl;
        getline(cin, dataDeCriacao);
        cout << "Group visibility: " << endl;
        cout << "0. Private" << endl;
        cout << "1. Public" << endl;
        cin >> visibilidade;

        if( visibilidade != "1" && visibilidade != "0")
            visibilidade = "0";

        executeQuery("insert into mural() values()");

        qstate = mysql_query(conn ,"SELECT LAST_INSERT_ID()");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        ID_grupoMural = row[1];

        executeQuery("insert into grupo(nome,dataDeCriacao,ID_grupoMural, visibilidade) values('"+nome+"','"+dataDeCriacao+"', '"+ID_grupoMural+"', '"+visibilidade+"')");

        if(!qstate)
            cout<<"Group "<< nome <<" created"<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;


        qstate = mysql_query(conn ,"SELECT LAST_INSERT_ID()");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);
        string ID_grupo = row[0];

        executeQuery("insert into grupoconf(ID_grupo, ID_usuario, Chave) values('"+ID_grupo+"','"+ID_usuario+"','"+"2"+"')");
    }
    else
    {
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
    }
}

int Login(){
    system("cls");
    while(1){
    system("cls");
    string email, senha;

    cout << "email: "<< endl;
    cin >> email;

    executeQuery("select * from usuario where email = '"+email+"'");

    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);

    if(!row){
        int choice;
        cout << "Wrong email!"<<endl;
        cout << "Type 0 to go back" << endl;
        cin >> choice;
        if(!choice)
            return 0;
        continue;
    }
    string senha_real = row[4];
    cout << "Type your password: "<<endl;
    cin >> senha;

    if(senha_real == senha){
        ID_usuario = row[0];
        ID_usuario_Vis = ID_usuario;
        ID_mural = row[1];
        ID_mural_Vis = ID_mural;
        return 1;
    }
    else
        cout <<"Acess denied"<<endl;
        return 0;
    }
}
///////////////////////
/////////////////////// VERIFICADORES DE AMIZADE OU ASSOCIACAO
int FriendshipVerif(){
    executeQuery("select * from amizade where (ID_usuario_req ='"+ID_usuario+"' and ID_usuario_rec = '"+ID_usuario_Vis+"') or (ID_usuario_req ='"+ID_usuario_Vis+"' and ID_usuario_rec = '"+ID_usuario+"')");
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);

    if(ID_usuario_Vis == ID_usuario)
        return -2;
    //if(row(2) == "")
      //  return -1;
    if(!row[2])
        return -1;

    if(row[2])
        return 1;

}

int FriendofFriendVer(){
    executeQuery("select * from amizade where (ID_usuario_rec = '"+ID_usuario_Vis+"' or ID_usuario_req = '"+ID_usuario_Vis+"') and Chave = '"+"1"+"'");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        string id;

        if(ID_usuario_Vis == row[1])
            id = row[0];
        else
            id = row[1];

        executeQuery("select * from amizade where (ID_usuario_req ='"+ID_usuario+"' and ID_usuario_rec = '"+id+"') or (ID_usuario_req ='"+id+"' and ID_usuario_rec = '"+ID_usuario+"')");

        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        if(!row1)
            continue;
        return atoi(row1[2]);
        i++;
    }
    return 0;
}

int MemberVerif(){
   executeQuery("select * from grupoconf where (ID_grupo = '"+ID_grupo_Vis+"' and ID_usuario = '"+ID_usuario+"')");
    res2 = mysql_store_result(conn);
    row2 = mysql_fetch_row(res2);

    if(!row2)
        return -1;

    return atoi(row2[2]);
}

int BlockVerif(){
    executeQuery("select * from bloqueio where (ID_usuario_req = '"+ID_usuario_Vis+"' and ID_usuario_rec = '"+ID_usuario+"') or (ID_usuario_req = '"+ID_usuario+"' and ID_usuario_rec = '"+ID_usuario_Vis+"')");
    res2 = mysql_store_result(conn);
    row2 = mysql_fetch_row(res2);

    if(!row2)
        return 0;

    return 1;
}
/////////////////////////////
////////////////////// BUSCAS
int SearchUsers(){
    system("cls");

    executeQuery("select * from usuario");

    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        ID_usuario_Vis = row[0];
        if(!BlockVerif()){
            if(!i)
                cout<< "RESULTS:" << endl;

            cout << ++i << ": " << row[2] << endl;
        }
    }

    if(!row&&i==0){
        cout << "No Results found" << endl;
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the member number to see profile " << endl;
    cin >> reg;

    if(!reg)
        return 0;

    executeQuery("select * from usuario");

    res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
        ID_usuario_Vis = row[0];
        if(!BlockVerif()){
            if(++i == reg){
                ID_usuario_Vis = row[0];
                ID_mural_Vis = row[1];
                return 1;
            }
        }
    }

    return 0;
}

int SearchGroups(){
    system("cls");

    executeQuery("select * from grupo");

    res = mysql_store_result(conn);
    int i = 0;
    string aux_grp = ID_grupo_Vis;
    string aux_id = ID_usuario_Vis;
    while(row=mysql_fetch_row(res)){
         ID_grupo_Vis = row[0];
        if(MemberVerif() < 3){
            if(!i)
                cout<< "Groups:" << endl;
            cout << ++i << ": " << row[2] << endl;
        }
    }

    if(!row&&i==0){
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the group number " << endl;
    cin >> reg;

    if(!reg)
        return 0;

    executeQuery("select * from grupo");

    res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
        ID_grupo_Vis = row[0];
        if(MemberVerif() < 3){
            if(++i == reg){
                ID_grupo_Vis = row[0];
                ID_mural_Vis = row[1];
                return 1;
            }
        }
    }
    return 0;
}
int MakePub(){
    system("cls");
    string texto="", ID_mural;
    int option;



            cout << "Type your Pub: " << endl;
            cin >> texto;

            if(texto == ""){
                return 0;
            }



    executeQuery("select ID_usuarioMural from usuario where ID_usuario = '"+ID_usuario_Vis+"'");

    res = mysql_store_result(conn);
    row=mysql_fetch_row(res);
    ID_mural = row[1];

    executeQuery("insert into publicacao(ID_mural, ID_usuario, texto) values('"+ID_mural_Vis+"','"+ID_usuario+"', '"+texto+"')");

    return 1;
}

int MakeComment(){
    system("cls");
    string texto="", ID_mural;

    cout << "Type your comment: " << endl;
    cin >> texto;
    if(texto == ""){
        return 0;
    }

    executeQuery("select ID_usuarioMural from usuario where ID_usuario = '"+ID_usuario_Vis+"'");

    res = mysql_store_result(conn);
    row=mysql_fetch_row(res);
    ID_mural_Vis = row[1];



    executeQuery("insert into comentario(texto, ID_mural, ID_usuario, ID_publicacao) values('"+texto+"','"+ID_mural_Vis+"','"+ID_usuario_Vis+"','"+ID_publicacao_Vis+"')");

    cout << "comment posted" << endl;
}

int MakeReply(){
    system("cls");
    string texto="", ID_mural;

    cout << "Type your reply: " << endl;
    cin >> texto;
    if(texto == ""){
        return 0;
    }

    executeQuery("select ID_usuarioMural from usuario where ID_usuario = '"+ID_usuario_Vis+"'");

    res = mysql_store_result(conn);
    row=mysql_fetch_row(res);
    ID_mural = row[1];

    executeQuery("insert into resposta(texto, ID_mural, ID_usuario, ID_publicacao, ID_comentario) values('"+texto+"','"+ID_mural+"','"+ID_usuario_Vis+"','"+ID_publicacao_Vis+"','"+ID_comentario_Vis+"')");

    return 1;
}

int SeePubs(){
    system("cls");
    string texto = "", nome_usuario_pub = "", ID_mural, nome_usuario_Mural;

    executeQuery("select * from usuario where ID_usuario = '"+ID_usuario_Vis+"'");
    res = mysql_store_result(conn);
    row=mysql_fetch_row(res);

    ID_mural = row[1];
    nome_usuario_Mural = row[2];

    executeQuery("select * from publicacao where ID_mural = '"+ID_mural_Vis+"'");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){

        string id = row[2];
        executeQuery("select * from usuario where ID_usuario = '"+ id +"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        nome_usuario_pub = row1[2];

        ID_usuario_Vis = id;
        if(!BlockVerif()){
            cout  << ++i << "." << endl << endl;
            cout << nome_usuario_pub << " " <<  endl;
            if(row[3] != "")
                cout << row[3] << endl;

        }
    }

    if(!row&&i==0){
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the Pub number " << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

    executeQuery("select * from publicacao where ID_mural = '"+ID_mural_Vis+"'");
    res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
        ID_usuario_Vis = row[2];
        if(!BlockVerif()){
            if(++i == reg){
                ID_publicacao_Vis = row[0];
                return 1;
            }
        }
    }

    return 0;
}

int SeeComments(){
    system("cls");
    string texto = "", nome_usuario_pub = "", ID_mural, nome_usuario_comt;

    executeQuery("select * from comentario where ID_publicacao = '"+ID_publicacao_Vis+"'");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        if(!i)
            cout<< "Comentarios:" << endl << endl;
        string id = row[1];
        executeQuery("select * from usuario where ID_usuario = '"+id+"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        nome_usuario_comt = row1[2];

        ID_usuario_Vis = id;
        if(!BlockVerif()){
            cout  << ++i << "." << endl << endl;
            cout << nome_usuario_comt << " " << endl;
            cout << row[4] << endl;
        }
    }

    if(!row&&i==0){
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the comment number " << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

    executeQuery("select * from comentario where ID_publicacao = '"+ID_publicacao_Vis+"'");
    res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
        ID_usuario_Vis = row[1];
        if(!BlockVerif()){
            if(++i == reg){
                ID_comentario_Vis = row[0];
                return 1;
            }
        }
    }

    return 0;
}

int SeeReplies(){
    system("cls");
    string texto = "", nome_usuario_pub = "", ID_mural, nome_usuario_resp;

    executeQuery("select * from resposta where ID_comentario = '"+ID_comentario_Vis+"'");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        if(!i)
            cout<< "Replies:" << endl << endl;
        string id = row[3];
        executeQuery("select * from usuario where ID_usuario = '"+id+"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        nome_usuario_resp = row1[2];

        ID_usuario_Vis = id;
        if(!BlockVerif()){
            cout << ++i << "."<< endl << endl;
            cout << nome_usuario_resp << " " <<  endl;
            cout << row[5] << endl;
        }
    }

    if(!row&&i==0){
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the reply number" << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

    executeQuery("select * from resposta where ID_comentario = '"+ID_comentario_Vis+"'");
    res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
         ID_usuario_Vis = row[3];
        if(!BlockVerif()){
            if(++i == reg){
                ID_reposta_Vis = row[0];
                return 1;
            }
        }
    }

    return 0;
}

int SeeProfile(){
    executeQuery("select * from usuario where ID_usuario = '"+ID_usuario_Vis+"'");
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);

    cout << "Nome: " << row[2] << " " <<  endl;
    cout << "Email:" << row[3] << " " << endl;
    cout << "Default Visibility :" << row[5] << " " << endl;

    int i;

    cin >> i;
    return 0;
}

int SeeRequests(){
    executeQuery("select * from amizade where ID_usuario_rec = '"+ID_usuario+"' and Chave = '"+"0"+"'");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        if(!i)
            cout<< "Solicitacoes:" << endl << endl;

        string id = row[0];
        executeQuery("select * from usuario where ID_usuario = '"+id+"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        cout << ++i <<". "<< row1[2]  <<  endl;
    }

    if(!row&&i==0){
        cout << "No requests" << endl;
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the request number " << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

    executeQuery("select * from amizade where ID_usuario_rec = '"+ID_usuario+"' and Chave = '"+"0"+"'");
    res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
        if(++i == reg){
            system("cls");

            string solicitador = row[0], solicitado = row[1];
            int opt;
            cout << "1. aceitar \n 2.recusar"<< endl;
            cin >> opt;

            if(opt == 1)
                executeQuery("update amizade set Chave = 1 where ID_usuario_req = '"+solicitador+"' and ID_usuario_rec = '"+solicitado+"'");
            else
                executeQuery("delete from amizade where ID_usuario_req = '"+solicitador+"' and ID_usuario_rec = '"+solicitado+"'");
        }
    }

    return 1;
}

int SeeRequestsGrp(){
    executeQuery("select * from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and Chave = '"+"0"+"'");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        if(!i)
            cout<< "REQUESTS" << endl << endl;

        string id = row[1];

        executeQuery("select * from usuario where ID_usuario = '"+id+"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        cout << ++i <<". "<< row1[2] <<  endl;
    }

    if(!row&&i==0){
        cout << "No Requests" << endl;
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the request number " << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

    executeQuery("select * from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and Chave = '"+"0"+"'");
    res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
        if(++i == reg){
            system("cls");

            string solicitador = row[1];
            int opt;
            cout << "1. aceitar \n 2.recusar"<< endl;
            cin >> opt;

            if(opt == 1)
                executeQuery("update grupoconf set Chave = 1 where ID_grupo = '"+ID_grupo_Vis+"' and ID_usuario = '"+solicitador+"'");
            else
                executeQuery("delete from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and ID_usuario = '"+solicitador+"'");
        }
    }

    return 1;
}
/////////////////////////////
//////////////////////////// FAZER SOLICITAÇÕES

void RequestFriendship(){
    executeQuery("insert into amizade(ID_usuario_req,ID_usuario_rec,Chave) values('"+ID_usuario+"','"+ID_usuario_Vis+"','"+"0"+"')");
}

void EnterRequest(){
    executeQuery("insert into grupoconf(ID_grupo, ID_usuario, Chave) values('"+ID_grupo_Vis+"','"+ID_usuario+"','"+"0"+"')");
}
///////////////////////////
/////////////////////////// VISUALIZAR AMIGOS OU MEMBROS OU BLOQUEADOS
int SeeFriends(){
    executeQuery("select * from amizade where (ID_usuario_rec = '"+ID_usuario_Vis+"' or ID_usuario_req = '"+ID_usuario_Vis+"') and Chave = '"+"1"+"'");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        if(!i)
            cout<< "FRIENDS" << endl << endl;

        string id;

        if(ID_usuario_Vis == row[1])
            id = row[0];
        else
            id = row[1];

        executeQuery("select * from usuario where ID_usuario = '"+id+"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        cout << ++i <<". "<< row1[2] <<  endl;
    }

    if(!row&&i==0){
        cout << "No friends" << endl;
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the user number  " << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

    executeQuery("select * from amizade where (ID_usuario_rec = '"+ID_usuario_Vis+"' or ID_usuario_req = '"+ID_usuario_Vis+"') and Chave = '"+"1"+"'");
    res = mysql_store_result(conn);

    i = 0;

    while(row=mysql_fetch_row(res)){
        if(++i == reg){
            if(ID_usuario_Vis == row[1]){
                ID_usuario_Vis = row[0];
                executeQuery("select * from usuario where ID_usuario = '"+ID_usuario_Vis+"'");
                res1 = mysql_store_result(conn);
                row1=mysql_fetch_row(res1);

                ID_mural_Vis = row1[1];

            }
            else{
                ID_usuario_Vis = row[1];
                executeQuery("select * from usuario where ID_usuario = '"+ID_usuario_Vis+"'");
                res1 = mysql_store_result(conn);
                row1=mysql_fetch_row(res1);

                ID_mural_Vis = row1[1];
            }
        }
    }

    return 1;
}


int SeeADM(){
    executeQuery("select * from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and (Chave = '"+"1"+"' or Chave = '"+"2"+"')");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        if(!i)
            cout<< "MEMBERS" << endl << endl;

        string id = row[1];

        executeQuery("select * from usuario where ID_usuario = '"+id+"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        cout << ++i <<". "<< row1[2] <<  endl;
    }

    if(!row&&i==0){
        cout << "No Adm" << endl;
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the member number  " << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

   executeQuery("select * from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and (Chave = '"+"1"+"' or Chave = '"+"2"+"')");
   res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
        if(++i == reg){
            string id = row[1];
            string condicao = row[2];
            int opt;
            system("cls");

            cout << "Select one option :" << endl;

            cout << "1. See profile" << endl;
            if( id != ID_usuario){
                cout << "2. Remove from group" << endl;
                if(condicao == "1"){
                    cout << "3. turn into Adm" << endl;
                }else{
                    cout << "3. Remove Adm" << endl;
                }
                cout << "4. Block from group" << endl;
            }

            cin >> opt;

            if(opt < 1 || opt > 4)
                opt = 1;
            switch(opt){
            case 1:
                if(id == ID_usuario)
                    return -1;
                ID_usuario_Vis = id;
                executeQuery("select * from usuario where ID_usuario = '"+ID_usuario_Vis+"'");
                res1 = mysql_store_result(conn);
                row1=mysql_fetch_row(res1);

                ID_mural_Vis = row1[1];

                return 1;
                break;
            case 2:
                if( id != ID_usuario)
                    executeQuery("delete from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and ID_usuario = '"+id+"'");
                break;
            case 3:
                if( id != ID_usuario){
                    if(condicao == "1"){
                        executeQuery("update grupoconf set Chave = 2 where ID_grupo = '"+ID_grupo_Vis+"' and ID_usuario = '"+id+"'");
                    }else{
                        executeQuery("update grupoconf set Chave = 1 where ID_grupo = '"+ID_grupo_Vis+"' and ID_usuario = '"+id+"'");
                    }
                }
                break;
            case 4:
                string aux = ID_usuario_Vis;
                ID_usuario_Vis = id;

                executeQuery("update grupoconf set Chave = 3 where ID_grupo = '"+ID_grupo_Vis+"' and ID_usuario = '"+id+"'");

                DeleteReplyIfBlock();
                DeleteCommentIfBlock();
                DeletePubIfBlock();

                ID_usuario_Vis = aux;
            }
            return 0;
        }
    }
    return 0;
}

int SeeMembers(){
    executeQuery("select * from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and (Chave = '"+"1"+"' or Chave = '"+"2"+"')");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        if(!i)
            cout<< "MEMBERS" << endl << endl;

        string id = row[1];

        executeQuery("select * from usuario where ID_usuario = '"+id+"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        cout << ++i <<". "<< row1[2] <<  endl;
    }

    if(!row&&i==0){
        cout << "No members" << endl;
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the user number  " << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

   executeQuery("select * from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and (Chave = '"+"1"+"' or Chave = '"+"2"+"')");
   res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
        if(++i == reg){
            ID_usuario_Vis = row[1];

            executeQuery("select * from usuario where ID_usuario = '"+ID_usuario_Vis+"'");
            res1 = mysql_store_result(conn);
            row1=mysql_fetch_row(res1);

           ID_mural_Vis = row[1];
        }
    }

    return 1;
}

int SeeFriendsEmComum(){
    executeQuery("select * from amizade where (ID_usuario_rec = '"+ID_usuario+"' or ID_usuario_req = '"+ID_usuario+"') and Chave = '"+"1"+"'");
    res = mysql_store_result(conn);
    vector <string> amigos0;

    while(row=mysql_fetch_row(res)){
        string id;

        if(ID_usuario == row[1])
            id = row[0];
        else
            id = row[1];

        amigos0.push_back(id);
    }

    executeQuery("select * from amizade where (ID_usuario_rec = '"+ID_usuario_Vis+"' or ID_usuario_req = '"+ID_usuario_Vis+"') and Chave = '"+"1"+"'");
    res = mysql_store_result(conn);
    vector <string> amigos1;

    while(row=mysql_fetch_row(res)){
        string id;

        if(ID_usuario_Vis == row[1])
            id = row[0];
        else
            id = row[1];

        amigos1.push_back(id);
    }
    if(!row){
        int i;
        cout << "No common friends" << endl;
        cin >> i;
        return 0;
    }



    vector <string> amigoscomum;

    for(int k = 0; k < amigos0.size(); k++){
        for(int j = 0; j < amigos0.size(); j++){
            if(amigos0[k] == amigos1[j])
                amigoscomum.push_back(amigos0[k]);
    }
    }

    int i;
    int z = 0;
    for(i = 0; i < amigoscomum.size(); i++){
        executeQuery("select * from usuario where ID_usuario = '"+amigoscomum[i]+"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        cout << ++z <<". "<< row1[2] <<  endl;
    }

    int reg = 0;
    cout << "Type 0 to go back or the user number " << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

    ID_usuario_Vis = amigoscomum[reg - 1];

    executeQuery("select * from usuario where ID_usuario = '"+ID_usuario_Vis+"'");
    res1 = mysql_store_result(conn);
    row1=mysql_fetch_row(res1);

    ID_mural_Vis = row[1];

    return 1;
}

int GroupBlocked(){
    executeQuery("select * from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and Chave = '"+"3"+"'");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        if(!i)
            cout<< "USUARIOS BLOQUEADOS" << endl << endl;

        string id = row[1];

        executeQuery("select * from usuario where ID_usuario = '"+id+"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        cout << ++i <<". "<< row1[2] <<  endl;

    }

    if(!row&&i==0){
        cout << "No Blocked users" << endl;
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the user number " << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

    executeQuery("select * from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and Chave = '"+"3"+"'");
    res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
        if(++i == reg){
            system("cls");

            string bloqueado = row[1];
            int opt;
            cout << "1. Remove block"<< endl;
            cin >> opt;

            if(opt == 1)
                executeQuery("delete from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and ID_usuario = '"+bloqueado+"'");
            else
                return 1;
        }
    }

    return 1;
}

int SeeBlocks(){
    string muralvisitado = ID_mural_Vis;
    ID_mural_Vis = ID_mural;

    string idusuario = ID_usuario;
    string idvisitado = ID_reposta_Vis;

    executeQuery("select * from bloqueio where ID_usuario_req = '"+ID_usuario+"'");
    res = mysql_store_result(conn);
    int i = 0;

    while(row=mysql_fetch_row(res)){
        if(!i)
            cout<< "BLOCKED USERS" << endl << endl;

        string id = row[1];
        executeQuery("select * from usuario where ID_usuario = '"+id+"'");
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);

        cout << ++i <<". "<< row1[2] << endl;
    }

    if(!row&&i==0){
        cout << "No Blocked Users" << endl;
        return 0;
    }

    int reg = 0;
    cout << "Type 0 to go back or the block user number " << endl;
    cin >> reg;

    if(!reg || reg > i)
        return 0;

    executeQuery("select * from bloqueio where ID_usuario_req = '"+ID_usuario+"'");
    res = mysql_store_result(conn);
    i = 0;

    while(row=mysql_fetch_row(res)){
        if(++i == reg){
            system("cls");

            string bloqueador = row[0], bloqueado = row[1];
            int opt;
            cout << "1. Remove Block   \n   0. Back"<< endl;
            cin >> opt;

            if(opt == 1){
                executeQuery("delete from bloqueio where ID_usuario_req = '"+bloqueador+"' and ID_usuario_rec = '"+bloqueado+"'");

                executeQuery("select * from grupoconf where ID_usuario = '"+ID_usuario+"' and Chave = '"+"2"+"'");
                res = mysql_store_result(conn);

                vector<string> idGrupo;

                while(row = mysql_fetch_row(res))
                    idGrupo.push_back(row[0]);

                for(int i = 0; i < idGrupo.size(); i++){
                    executeQuery("delete from grupoconf where ID_grupo = '"+idGrupo[i]+"' and ID_usuario = '"+ID_usuario_Vis+"'");
                }

                ID_mural_Vis = muralvisitado;
                ID_usuario = idvisitado;
                ID_usuario_Vis = idusuario;

                executeQuery("select * from grupoconf where ID_usuario = '"+ID_usuario+"' and Chave = '"+"2"+"'");
                res = mysql_store_result(conn);

                vector<string> idGrupo2;

                while(row = mysql_fetch_row(res))
                    idGrupo2.push_back(row[0]);

                for(int i = 0; i < idGrupo2.size(); i++){
                    executeQuery("delete from grupoconf where ID_grupo = '"+idGrupo2[i]+"' and ID_usuario = '"+ID_usuario_Vis+"'");
                }

                ID_usuario = idusuario;
                ID_usuario_Vis = idvisitado;

            }
            else
                return 0;
        }
    }

    return 1;
}

////////////////////////////
//////////////////////////// VER INFORMAÇÕES GRUPO OU PESSOA
void UserName(){
    executeQuery("select * from usuario where ID_usuario = '"+ID_usuario_Vis+"'");
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);

    cout << row[2] <<  endl;
}

void GroupName(){
    executeQuery("select * from grupo where ID_grupo = '"+ID_grupo_Vis+"'");
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);

    cout << row[2] << endl;

}
/////////////////////////
//////////////////////// VERIFICADOR DE VISIBILIDADE
int CheckVisib(){
    executeQuery("select * from usuario where ID_usuario = '"+ID_usuario_Vis+"'");
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);

    return atoi(row[5]);
}

int CheckVisibGrp(){
    executeQuery("select * from grupo where ID_grupo = '"+ID_grupo_Vis+"'");
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);

    return atoi(row[4]);
}
////////////////////////
/////////////////////// DESFAZER ASSOCIACAO OU AMIZADE
void UndoFriendship(){
    executeQuery("delete from amizade where (ID_usuario_req = '"+ID_usuario+"' and ID_usuario_rec = '"+ID_usuario_Vis+"') or (ID_usuario_req = '"+ID_usuario_Vis+"' and ID_usuario_rec = '"+ID_usuario+"')");
}

void UndoRequest(){
    executeQuery("delete from grupoconf where ID_grupo = '"+ID_grupo_Vis+"' and ID_usuario = '"+ID_usuario+"'");
}

//////////////////////////
////////////////////////// CHECAGEM SE EH DONO DO MURAL, DONO DO CONTEUDO OU ADMINISTRADOR DO GRUPO
int PageOwner(int tipo){
    if(tipo == 0){
        executeQuery("select * from publicacao where ID_publicacao = '"+ID_publicacao_Vis+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        string mural = row[1];

        executeQuery("select * from usuario where ID_usuario = '"+ID_usuario+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        string mural1 = row[1];

        if(mural == mural1){
            return 1;
        }
        return 0;
    }
    if(tipo == 1){
        executeQuery("select * from comentario where ID_comentario = '"+ID_comentario_Vis+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        string mural = row[2];

        executeQuery("select * from usuario where ID_usuario = '"+ID_usuario+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        string mural1 = row[1];

        if(mural == mural1)
            return 1;
        return 0;
    }
    if(tipo == 2){
        executeQuery("select * from resposta where ID_resposta = '"+ID_reposta_Vis+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        string mural = row[2];

        executeQuery("select * from usuario where ID_usuario = '"+ID_usuario+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        string mural1 = row[1];

        if(mural == mural1)
            return 1;
        return 0;
    }
}

int PubOwner(int tipo){
    if(tipo == 0){
        executeQuery("select * from publicacao where ID_publicacao = '"+ID_publicacao_Vis+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        string id = row[2];

        if(id == ID_usuario){
            return 1;
        }
        return 0;
    }
    if(tipo == 1){
        executeQuery("select * from comentario where ID_comentario = '"+ID_comentario_Vis+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        string id = row[2];

        if(id == ID_usuario)
            return 1;
        return 0;
    }
    if(tipo == 2){
        executeQuery("select * from resposta where ID_reposta = '"+ID_reposta_Vis+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        string id = row[2];

        if(id == ID_usuario)
            return 1;
        return 0;
    }
}

int GroupOwner(int tipo){
    if(tipo == 0){
        string muralpost = ID_mural_Vis;

        executeQuery("select * from grupo where ID_grupoMural = '"+muralpost+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);
        if(!row)
            return 0;

        string grupo = row[0];
        executeQuery("select * from grupoconf where ID_grupo = '"+grupo+"' and ID_usuario = '"+ID_usuario+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        if(!row)
            return 0;

        string condicao = row[2];

        if(condicao == "2")
            return 1;

        return 0;
    }
    if(tipo == 1){
        string muralpost = ID_mural_Vis;

        executeQuery("select * from grupo where ID_grupo = '"+muralpost+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        if(!row)
            return 0;

        string grupo = row[0];

        executeQuery("select * from grupoconf where ID_grupo = '"+grupo+"' ID_usuario = '"+ID_usuario+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        if(!row)
            return 0;

        string condicao = row[2];

        if(condicao == "2")
            return 1;
        return 0;
    }
    if(tipo == 2){
        string muralpost = ID_grupo_Vis;

        executeQuery("select * from grupo where ID_grupoMural = '"+muralpost+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        if(!row)
            return 0;

        string grupo = row[0];

        executeQuery("select * from grupoconf where ID_grupo = '"+grupo+"' ID_usuario = '"+ID_usuario+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        if(!row)
            return 0;

        string condicao = row[2];

        if(condicao == "2")
            return 1;
        return 0;
    }
}
/////////////////////////////
///////////////////////////// APAGAR PUBLICAÇÕES, COMENTARIOS, RESPOSTAS
void DeleteReply(){
    executeQuery("delete from resposta where ID_resposta = '"+ID_reposta_Vis+"'");
}

void DeleteComment(){
    executeQuery("select * from resposta where ID_comentario = '"+ID_comentario_Vis+"'");
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);


    vector<string> id;

    while(row = mysql_fetch_row(res))
        id.push_back(row[0]);

        executeQuery("delete from resposta where ID_comentario = '"+ID_comentario_Vis+"'");

    executeQuery("delete from comentario where ID_comentario = '"+ID_comentario_Vis+"'");
}

void DeletePub(){
    executeQuery("select * from resposta where ID_publicacao = '"+ID_publicacao_Vis+"'");
    res = mysql_store_result(conn);


    vector<string> id;

    while(row = mysql_fetch_row(res))
        id.push_back(row[0]);

        executeQuery("delete from resposta where ID_publicacao = '"+ID_publicacao_Vis+"'");


    executeQuery("select * from comentario where ID_publicacao = '"+ID_publicacao_Vis+"'");
    res = mysql_store_result(conn);

    vector<string> id1;

    while(row = mysql_fetch_row(res))
        id1.push_back(row[0]);

        executeQuery("delete from comentario where ID_publicacao = '"+ID_publicacao_Vis+"'");

    executeQuery("delete from publicacao where ID_publicacao = '"+ID_publicacao_Vis+"'");
}

void BlockUser(){
    string muralvisitado = ID_mural_Vis;
    ID_mural_Vis = ID_mural;

    string idusuario = ID_usuario;
    string idvisitado = ID_usuario_Vis;

    DeleteReplyIfBlock();
    DeleteCommentIfBlock();
    DeletePubIfBlock();

    executeQuery("delete from amizade where (ID_usuario_req = '"+ID_usuario_Vis+"' and ID_usuario_rec = '"+ID_usuario+"') or (ID_usuario_req = '"+ID_usuario+"' and ID_usuario_rec = '"+ID_usuario_Vis+"')");

    executeQuery("select * from grupoconf where ID_usuario = '"+ID_usuario+"' and Chave = '"+"2"+"'");
    res = mysql_store_result(conn);

    vector<string> idGrupo;

    while(row = mysql_fetch_row(res))
        idGrupo.push_back(row[0]);

    for(int i = 0; i < idGrupo.size(); i++){
        executeQuery("select * from grupo where ID_grupo = '"+idGrupo[i]+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        ID_grupo_Vis = row[0];

        DeleteReplyIfBlock();
        DeleteCommentIfBlock();
        DeletePubIfBlock();

        executeQuery("delete from grupoconf where ID_grupo = '"+idGrupo[i]+"' and ID_usuario = '"+ID_usuario_Vis+"'");
        executeQuery("insert into grupoconf(ID_grupo, ID_usuario, Chave) values('"+idGrupo[i]+"', '"+ID_usuario_Vis+"', '"+"4"+"')");
    }

    ID_mural_Vis = muralvisitado;
    ID_usuario = idvisitado;
    ID_usuario_Vis = idusuario;

    DeleteReplyIfBlock();
    DeleteCommentIfBlock();
    DeletePubIfBlock();

    executeQuery("delete from amizade where (ID_usuario_req = '"+ID_usuario_Vis+"' and ID_usuario_rec = '"+ID_usuario+"') or (ID_usuario_req = '"+ID_usuario+"' and ID_usuario_rec = '"+ID_reposta_Vis+"')");

    executeQuery("select * from grupoconf where ID_usuario = '"+ID_usuario+"' and Chave = '"+"2"+"'");
    res = mysql_store_result(conn);

    vector<string> idGrupo2;

    while(row = mysql_fetch_row(res))
        idGrupo2.push_back(row[0]);

    for(int i = 0; i < idGrupo2.size(); i++){
        executeQuery("select * from grupo where ID_grupo = '"+idGrupo2[i]+"'");
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        ID_mural_Vis = row[0];

        DeleteReplyIfBlock();
        DeleteCommentIfBlock();
        DeletePubIfBlock();

        executeQuery("delete from grupoconf where ID_grupo = '"+idGrupo2[i]+"' and ID_usuario = '"+ID_usuario_Vis+"'");
        executeQuery("insert into grupoconf(ID_grupo, ID_usuario, Chave) values('"+idGrupo2[i]+"', '"+ID_usuario_Vis+"', '"+"4"+"')");
    }

    ID_usuario = idusuario;
    ID_usuario_Vis = idvisitado;

    executeQuery("insert into bloqueio(ID_usuario_req, ID_usuario_rec) values('"+ID_usuario+"', '"+ID_usuario_Vis+"')");
}



#endif // FUNCOES_H_INCLUDED
