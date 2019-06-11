#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

#include "funcoes.h"
#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <string>
#include <stdlib.h>


using namespace std;

void ReplyScreen(){
     system("cls");
    cout << "Select one Option" << endl << endl;
    if(PubOwner(1) || PageOwner(1) || GroupOwner(1))
        cout << "1. Delete Reply" << endl;
    cout << "0. Voltar" << endl;

    int option;
    cin >> option;
    system("cls");

    switch(option){
        case 1:
            DeleteReply();
            ReplyScreen();
            break;
    }
}


void CommentScreen(){
    system("cls");
    cout << "Select one option" << endl << endl;
    cout << "1. See Replies" << endl;
    cout << "2. Reply" << endl;
    if(PubOwner(1) || PageOwner(1) || GroupOwner(1))
        cout << "3. Delete Comment" << endl;
    cout << "0. Back" << endl;

    int option;
    cin >> option;
    system("cls");
    switch(option){
        case 1:
            if(SeeReplies()){
                ReplyScreen();
            }
            CommentScreen();
            break;
        case 2:
            MakeReply();
            CommentScreen();
            break;
        case 3:
            if(PubOwner(1) || PageOwner(1) || GroupOwner(1))
                DeleteComment();
        default:
            break;
    }
}


void PubScreen(){
    system("cls");
    cout << "Select one option" << endl << endl;
    cout << "1. See Comments" << endl;
    cout << "2. Comment" << endl;
    if(PubOwner(0) || PageOwner(0) || GroupOwner(0))
        cout << "3. Delete Pub" << endl;
    cout << "0. Back" << endl;

    int option;
    cin >> option;
    system("cls");
    switch(option){
        case 1:
            if(SeeComments()){
                CommentScreen();
            }
            PubScreen();
            break;
        case 2:
            MakeComment();
            PubScreen();
            break;
        case 3:
            if(PubOwner(0) || PageOwner(0) || GroupOwner(0))
                DeletePub();
        default:
            if(SeePubs()){
                PubScreen();
            }
            break;
    }
}

void VisitedUserScreen(){
    system("cls");

    UserName();

    int Visible;

    cout << "Select one option" << endl << endl;

    switch(CheckVisib()){
    case 0:
        if(FriendshipVerif() == 1){
            Visible = 1;
        }else{
            Visible = 0;
        }
        break;
    case 1:
        if(FriendofFriendVer() || FriendshipVerif() == 1){
            Visible = 1;
        }else{
            Visible = 0;
        }
        break;
    case 2:
        Visible = 1;
        break;
    }
    if(Visible){
        cout << "1. See Perfl" << endl;
        cout << "2. Publish" << endl;
        cout << "3. See publication" << endl;
        cout << "4. See Friends" << endl;
        cout << "5. See common friends" << endl;
        cout << "7. Send Friendship request" << endl;
        cout << "6. Undo Friendship" << endl;

    }else{
        if(FriendshipVerif() == -2){
        return;
        }
        if(FriendshipVerif() == -1){
            cout << "1. Request Friendship" << endl;
        }
        if(FriendshipVerif() == 0){
            cout << "Friendship request sent" << endl;
        }
    }
    cout << "8. Block User" << endl;
    cout << "0. Back" << endl;
    int option;
    cin >> option;
    system("cls");
    switch(option){
        case 1:
            if(Visible)
                SeeProfile();
            else{
            if(FriendshipVerif() == -1)
                RequestFriendship();
            }
            VisitedUserScreen();
            break;
        case 2:
            if(Visible)
                MakePub();
            VisitedUserScreen();
            break;
        case 3:
            if(Visible && SeePubs()){
                PubScreen();
            }
            VisitedUserScreen();
            break;
        case 4:
            if(Visible){
                if(SeeFriends())
                    VisitedUserScreen();
            }
            VisitedUserScreen();
            break;
        case 5:
            if(Visible)
                SeeCommonFriends();
            VisitedUserScreen();
            break;
        case 6:
            UndoFriendship();
            VisitedUserScreen();
            break;
        case 7:
            RequestFriendship();
            VisitedUserScreen();
            break;
        case 8:
            BlockUser();
            break;
        default:
            break;
    }
}



void VisitedGroupScreen(){
    system("cls");

    nomeGrupo();
    int aux;
    cout << "Select one option" << endl << endl;

    if(CheckVisibGrp() == 0){
        if(MemberVerif() == -1){
            cout << "1. Request to enter in the group" << endl;
            aux=0;
        }
        if(MemberVerif() == 0){
            aux=1;
        }
        if(MemberVerif() == 1){
            cout << "1. See Pubs" << endl;
            cout << "2. See members" << endl;
            cout << "3. Publish" << endl;
            cout << "4. Exit group" << endl;
            aux=2;
        }
        if(MemberVerif() == 2){
            cout << "1. See Pubs" << endl;
            cout << "2. See Members" << endl;
            cout << "3. Publish" << endl;
            cout << "4. Exit group" << endl;
            cout << "5. See group requests" << endl;
            cout << "6. Blocked users" << endl;
            aux=3;
        }
    }else{
            cout << "1. See Pubs" << endl;
            cout << "2. See Members" << endl;
        if(MemberVerif() == -1){
            cout << "3. Enter group request" << endl;
            aux=4;
        }
        if(MemberVerif() == 0){
            //nada
            aux=5;
        }
        if(MemberVerif() == 1){
            cout << "3. Publish" << endl;
            cout << "4. Exit group" << endl;
            aux=2;
        }
        if(MemberVerif() == 2){
            cout << "3. Publish" << endl;
            cout << "4. Exit group" << endl;
            cout << "5. See group requests" << endl;
            cout << "6. Blocked users" << endl;
            aux=3;
        }
    }
    cout << "0. Back" << endl;
    int option;
    cin >> option;
    system("cls");
    switch(option){
        case 1:
            if(aux == 1){
                //nada
            }else{
                if(aux == 0){
                    EnterRequest();
                }
                else{
                    if(SeePubs())
                        PubScreen();
                }
            }
            VisitedGroupScreen();
            break;
        case 2:
           if(aux == 0 || aux == 1){

           }else{
                if(aux == 3){
                    int x = SeeADM();
                    if(x == -1)
                        break;
                    if(x == 1)
                        VisitedUserScreen();
               }else{
                SeeMembers();
               }
           }
            break;
        case 3:
           if(aux == 0 || aux == 1 || aux == 5){

           }else{
                if(aux == 4){
                    EnterRequest();
                }else{
                    MakePub();
                }
            }
            VisitedGroupScreen();
            break;
        case 4:
            if(aux == 0 || aux == 1 || aux == 4 || aux == 5){
            }else{
                UndoRequest();
            }
            VisitedGroupScreen();
            break;
        case 5:
            if(aux == 3){
                SeeGroupRequests();
            }
            VisitedGroupScreen();
            break;
        case 6:
            if(aux == 3){
                GroupBlocked();
            }
            VisitedGroupScreen();
        default:
            break;
    }
}

void MainScreen(){
    ID_mural_Vis = ID_mural;
    ID_usuario_Vis = ID_usuario;

    system("cls");

    UserName();

    cout << "Select one option:" << endl << endl;
    cout << "1. Publish" << endl;
    cout << "2. See Pubs" << endl;
    cout << "3. Search users" << endl;
    cout << "4. Search groups" << endl;
    cout << "5. Create group" << endl;
    cout << "6.See friends" << endl;
    cout << "7. Friendship requests" << endl;
    cout << "8. See perfil" << endl;
    cout << "9.See Blocked users" << endl;
    cout << "0. Logoff" << endl;

    int option;
    cin >> option;
    system("cls");
    switch(option){
        case 1:
            MakePub();
            MainScreen();
            break;
        case 2:
            if(SeePubs()){
                PubScreen();
            }
            MainScreen();
            break;
        case 3:
            if(SearchUsers())
                VisitedUserScreen();
            MainScreen();
            break;
        case 4:
            if(SearchGroups())
                VisitedGroupScreen();
            MainScreen();
            break;
        case 5:
            CreateGroup();
            MainScreen();
            break;
        case 6:
            if(SeeFriends())
                VisitedUserScreen();
            MainScreen();
            break;
        case 7:
            SeeRequests();
            MainScreen();
            break;
        case 8:
            SeeProfile();
            MainScreen();
        case 9:
            SeeBlocks();
            MainScreen();
        default:
            break;
    }
}

int InitialScreen(){
    cout << "Welcome to Facebook" << endl;
    cout << "Select one option" << endl << endl;
    cout << "1. Login" << endl;
    cout << "2. Sign up" << endl;
    cout << "0. Finish" << endl;

    int option;
    cin >> option;
    system("cls");
    switch(option){
        case 1:
            if(Login())
                MainScreen();
            else{
                system("cls");
                InitialScreen();
            }
            InitialScreen();
            break;
        case 2:
            SignUp();
            MainScreen();
            InitialScreen();
            break;
        default:
            break;
    }
    return 0;
}


#endif // TELAS_H_INCLUDED
