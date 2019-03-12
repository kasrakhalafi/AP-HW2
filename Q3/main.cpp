#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<set>

int main()
{
  int len{};
  std::ifstream infile{"db.txt"};
  std::string str{},input{};
  int product_count{},customer_count{};
  std::string* data{};
  std::stringstream ss{};
  std::vector<std::string> vec,cust;
  
  while (std::getline(infile, str))//getting inputs from file
{
  input += str;
  input.push_back('\n');
 }
  infile.close();

  len = input.length();
    
  data = new std::string [len/28];//defining dynamic string with size of rows by div of all inputs to elemnts of a row
  
  for(size_t i{};i<input.length()/28;i++)//filling the made string 
    {
    data[i] = input.substr(i*28,27);
    }

  for(size_t i{};i<(input.length()/28)-1;i++){
    if(data[i].substr(1,10) == data[i+1].substr(1,10)){//checking for the same dates
      vec.push_back(data[i].substr(19,3));//if had same dates save product in the vector
      cust.push_back(data[i].substr(23,4));//save customer in another vector 
      if(i == (input.length()/28)-2){//chek if its last input enter the last input
	vec.push_back(data[i+1].substr(19,3));//enter last input of customer and product
	cust.push_back(data[i+1].substr(23,4));

	product_count = std::set<std::string>( vec.begin(), vec.end() ).size();//saving different products in a int
	customer_count = std::set<std::string>( cust.begin(), cust.end() ).size();//saving different customors in a int

	std::cout << data[i].substr(0,11) << "] " << product_count << " " << customer_count << std::endl;//showing all datas!
	break;
      }
    }
    
    if(data[i].substr(1,10) != data[i+1].substr(1,10)){//check if the date changes or not
      
      vec.push_back(data[i].substr(19,3));//save the last member of the same date
      cust.push_back(data[i].substr(23,4));
      product_count = std::set<std::string>( vec.begin(), vec.end() ).size() ;//counting different members
      customer_count = std::set<std::string>( cust.begin(), cust.end() ).size() ;
      
      std::cout << data[i].substr(0,11) << "] " << product_count << " " << customer_count << std::endl;//writing datas!
      
      vec.erase(vec.begin(),vec.begin()+vec.size());//clear datas to check and import new datas for new date
      cust.erase(cust.begin(),cust.begin()+cust.size());
    }
  }
  return 0;
}

