#include "bwt.hpp"

int main ()
{
  std::string line;
  std::getline(std::cin, line);
  int size = line.size() + 1;

  std::vector<char> in(size);
  std::vector<char> out(size);
  std::vector<int> array(size);

  std::copy(line.data(), line.data() + size, in.begin());

  kktkbwt::bwt(in.begin(), array.begin(), out.begin(), size);

  kktkbwt::print(out.begin(), out.end());
}
