#include<string>
  
class Map{
 public:
  Map(int n);
  ~Map();
  void showMap();
  void findRoute();
  void showRoute();
  //void ~showRoute();
  int ** arr;
  std::string ** str;

 private:
  bool cond;
  int N;
};
