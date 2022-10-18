#include <iostream>
#include <string>
#include <iomanip>

int main() {

  std::cout << "Please insert 2 words:" << '\n';

  std::string word1;
  std::string word2;

  std::cin >> word1;
  std::cin >> word2;
  std::cout << '\n';

  int size1 = word1.size();
  int size2 = word2.size();

  int graph[size1 + 1][size2 + 1] = {0};

  for (size_t i = 0; i < size1 + 1; i++) {
    graph[i][0] = i;
  }
  for (size_t j = 0; j < size2 + 1; j++) {
    graph[0][j] = j;
  }

//Code that does computations below//
for (size_t x = 1; x < size1+1; x++) {
  for (size_t y = 1; y < size2+1; y++) {
    if (word1[x-1] == word2[y-1]) {
      graph[x][y] = graph[x-1][y-1];
      //std::cout << x << " " << y << " " << graph[x][y] << '\n';
    } else {
      int a = std::min(std::min(graph[x-1][y-1], graph[x][y-1]), graph[x-1][y]);
      graph[x][y] = a + 1;
      //std::cout << " miss " << x << " " << y << " " << a << " "<< graph[x][y] << '\n';
    }
  }
}
//Code that does computations above//


//Display
  for (size_t x = 0; x < size1+1; x++) {
    for (size_t y = 0; y < size2+1; y++) {
      std::cout << "| " << graph[x][y] << " | ";
    }
    std::cout  << '\n';
  }

  std::cout << "Distance is: " << graph[size1][size2] << '\n' << '\n';

  std::cout << "Application is :" << '\n';

  int x = 0;
  int y = 0;
  int inc = 0;

  if (size1 >= size2) {
    std::cout << word1 << '\n';
    for (int i = 0; i <= size1 + 1; i++) {
      if (graph[x][y] == graph[x+1][y+1]) {
        x++;
        y++;
        }
      else {
        if (graph[x][y] + 1 == graph[x+1][y]) {
          x++;
          word1[inc] = '_';
        }
      }
      inc++;
    }
    std::cout << word1 << '\n';
  }
  else {
    std::cout << word2 << '\n';
    for (int i = 0; i <= size2 + 1; i++) {
      if (graph[x][y] == graph[x+1][y+1]) {
        x++;
        y++;
        }
      else {
        if (graph[x][y] + 1 == graph[x][y+1]) {
          y++;
          word2[inc] = '_';
        }
      }
      inc++;
    }
    std::cout << word2 << '\n';
  }

  return 0;
}
