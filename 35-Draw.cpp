#include <cstdlib>
#include <iostream>

void draw(int, int);

int main(int argc, char **argv) {

  int max_i = 10, max_kj = 20, x = {0};
  std::string s = {};

  if (argc > 1) {
    s = argv[1];
    if (s == "-a" || s == "--animation") {
      while (x < 40) {
        x++;
        draw(x + 2, x + 2);
        system("sleep 0.02");
        system("clear");
      }
    }
  }

  if (argc > 2) {
    max_i = std::stoi(argv[1]);
    max_kj = std::stoi(argv[2]);
    draw(max_i, max_kj);
  }

  return 0;
}

void draw(int max_i, int max_kj) {
  for (int i = 0; i <= max_i; i++) {
    if (i == 0) {
      std::cout << "\u250C"; // 1º +
      for (int k = 0; k <= max_kj; k++) {
        if (k == max_kj) {
          std::cout << "\u2510"; // 2º +
        } else {
          std::cout << "\u2500"; // -
        }
      }
      std::cout << '\n';
    } else {
      if (i == max_i) {
        std::cout << "\u2514";
      } else {
        std::cout << "\u2502"; // 3º +
      }

      for (int j = 0; j <= max_kj; j++) {
        if (j == max_kj) {
          if (i == max_i) {
            std::cout << "\u2518"; // 4º +
          } else {
            std::cout << "\u2502"; // |
          }
        } else {
          if (i == max_i) {
            std::cout << "\u2500";
          } else {
            std::cout << " ";
          }
        }
      }
      std::cout << '\n';
    }
  }
}
