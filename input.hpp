#ifndef INPUT_HPP
#define INPUT_HPP
#include <fstream>
#include <cstring>

static std::string temp = "./tmp";
static std::string AST_GEN_PATH = "./exp_result";
static std::string COMPILE_OUT_PATH = "./run_ouput";
static void A_yly_genInput(){
  std::fstream f;
  f.open(temp, std::ios::out);
  f << "M1, a, b, c := 10;\n";
  f << "M2, e, f, d := 5;\n";
  f << "print(1 + b * b);\n";
  f << "print(a);\n";
  f << "print(1 + b * c);\n";
  f << "print(2 * b * e - 1);\n";
  f.close();
}

static void A_yly_getInput(char *res){
  std::ifstream f(temp);
  std::string res_;
  std::string line;
  while (std::getline(f, line)) 
    res_ += line + '\n';
  strcpy(res, res_.c_str());
}

static void A_yly_setInput(char *res){
  std::fstream f;
  f.open(temp, std::ios::out);
  f << res;
}

static void A_yly_getCompileOutput(char *res){
  std::ifstream f(COMPILE_OUT_PATH);
  std::string res_;
  std::string line;
  while (std::getline(f, line)) 
    res_ += line + '\n';
  strcpy(res, res_.c_str());
}



static void A_yly_get_AST_output(char *res){
  std::ifstream f(AST_GEN_PATH);
  std::string res_;
  std::string line;
  while (std::getline(f, line)) 
    res_ += line + '\n';
  strcpy(res, res_.c_str());
}


#endif // !INPUT_HPP
