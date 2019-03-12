#include <iostream>
#include "map.h"
#include<cmath>

int main()
{
  Map map{10};
  map.showMap();
  map.findRoute();
  map.showRoute();
  return 0;
}
