#include </usr/include/mysql/mysql.h>
#include <iostream>

int main(int argc, char *argv[]) {

  MYSQL *connect;
  connect = mysql_init(NULL);
  if (!connect) {
    std::cout << "deu erro na inicialização do mariadb" << '\n';
    return 1;
  }

  connect = mysql_real_connect(connect, "localhost", "root", "Ravima01", "cpp",
                               0, NULL, 0);

  if (connect) {
    std::cout << "conectou";
  } else {
    std::cout << "não conectou";
  }

  mysql_close(connect);
  return 0;
}
// comando para compilar
// g++ connect.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql -o
// connect
