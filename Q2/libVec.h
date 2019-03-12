#include<vector>

class libVec{
 public:
  libVec();
  ~libVec();
  void disp();
  void counter(int);
  
 private:
  int N,cnt{};
  std::vector<int> vec;
  
};
