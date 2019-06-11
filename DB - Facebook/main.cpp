#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <string>
#include "funcoes.h"
#include "telas.h"

int main()
{

    //conexao com a database
    conn = mysql_init(0);
    if(conn)
        cout << "";
    else
        cout << "connection object problem" << mysql_error(conn) << endl;

    conn = mysql_real_connect(conn, "localhost", "root", "", "facebook_bd", 3306, NULL, 0);


    InitialScreen();

    mysql_close(conn);
    return 0;
}
