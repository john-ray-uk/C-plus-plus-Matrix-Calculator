/* ==============================

       My first C++ Project:

         Matrix Calculator

       MatCalc Version 1.0

    (built with Visual Studio)
    
================================*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
    
   // Very cool title sequence
  
  string Buffer =  "=============================================================== \n";

  cout << Buffer << endl;
  cout << "                    MatCalc Version 1.0 \n" << endl;
  cout << "                   (written by John Ray)\n" << endl;
  cout << Buffer << endl;

  int rows1;
  int cols1;
  string FirstQuestion;
  string SecondQuestion;
  string Q1 = "     What are the number of rows of your first matrix? \n";
  string Q2 = "(There's a limit of 3x3 for division / inverse / determinants.)\n";
  string Q3 = "          Please type an integer number (e.g. \"2\")\n";
  FirstQuestion = Buffer + Q1 + Q2 + Q3 + Buffer;
  cout << FirstQuestion << endl;
  cin >> rows1;
  
  string ErrorMessage = "            Uh, oh. You didn't enter a valid response. \n";
  
  cout << endl << Buffer << "                   Number of rows input: " << rows1 << "\n" << Buffer;
  
  string Q4 = " What are the number of columns of your first matrix? \n";
  SecondQuestion = Buffer + Q4 + Q2 + Q3 + Buffer;
  cout << SecondQuestion << endl;
  cin >> cols1;
 
  cout << endl << Buffer << "                  Number of columns input: " << cols1 << "\n" << Buffer;
  
  cout << Buffer << "                    Your matrix is " << rows1 << " by " << cols1 << ".\n" << Buffer;
  vector<vector<float>> matrix1(rows1, vector<float>(cols1));
  for (int i = 0; i < rows1; i++) {
      for (int j = 0; j < cols1; j++) {
          cout << "\n          Please type the value for the " << i+1 << " by " << j+1 << " element.\n";
          cin >> matrix1[i][j];
          cout << endl;
  } }
  cout << Buffer << "                 Your current first matrix is: " << endl << endl;
  for (int i = 0; i < rows1; i++) {
      cout << "                            | ";
      for (int j = 0; j < cols1; j++) {
          cout << matrix1[i][j] <<" ";
      }
      cout << "| \n";
  }
  
  cout << endl << Buffer;
  float det1;
  vector<vector<float>> inverse1(rows1, vector<float>(cols1));
  if (rows1 <= 3  && rows1 == cols1) {
      // Show determinant and inverse
      if (rows1 == 1) {
          det1 = matrix1[0][0];
          inverse1[0][0] = (1/det1)*matrix1[0][0];
          
          cout << Buffer << "                 Your matrix's determinant is: " << endl << endl;
          cout << "                              " << det1 << endl << Buffer;
          cout << Buffer << "                    Your matrix's inverse is: " << endl << endl;
          cout << "                              " << inverse1[0][0] << endl << Buffer;
  
      }
      else if (rows1 == 2) {
          det1 = (matrix1[0][0]*matrix1[1][1] - matrix1[0][1]*matrix1[1][0]);
          
          if (det1 != 0) {
              float a = matrix1[0][0];
              float b = matrix1[0][1];
              float c = matrix1[1][0];
              float d = matrix1[1][1];
              inverse1[0][0] = d/det1;
              inverse1[0][1] = -b/det1;
              inverse1[1][0] = -c/det1;
              inverse1[1][1] = a/det1;
              
          
              cout << Buffer << "                 Your matrix's determinant is: " << endl << endl;
              cout << "                                " << det1 << endl << Buffer;
              cout << Buffer << "                    Your matrix's inverse is: " << endl << endl;
              cout << "                           \n";
              
                for (int i = 0; i < rows1; i++) {
                    cout << "                            | ";
                    for (int j = 0; j < cols1; j++) {
                        cout << inverse1[i][j] <<" ";
                    }
                    cout << "| \n";
                    
               }
              cout << endl << endl << Buffer;
  
          }
          
          else {
          
              cout << Buffer << "                 Your matrix's determinant is: " << endl << endl;
              cout << "                                " << det1 << endl << Buffer;
              cout << Buffer << "                    Your matrix is singular: " << endl;
              cout << "                      " << "there is no inverse!" << endl << Buffer;
              
          }
      }
      
      else {
          
          float cof1a = (matrix1[1][1]*matrix1[2][2] - matrix1[1][2]*matrix1[2][1]);
          float cof1b = (matrix1[0][1]*matrix1[2][2] - matrix1[0][2]*matrix1[2][1]);
          float cof1c = (matrix1[0][1]*matrix1[1][2] - matrix1[0][2]*matrix1[1][1]);
          det1 = matrix1[0][0]*cof1a - matrix1[1][0]*cof1b + matrix1[2][0]*cof1c;
          cout << Buffer << "                 Your matrix's determinant is: " << endl << endl;
          cout << "                                " << det1 << endl << Buffer;
          
          if (det1 != 0) {
              float cof1d = (matrix1[1][0]*matrix1[2][2] - matrix1[1][2]*matrix1[2][0]);
              float cof1e = (matrix1[0][0]*matrix1[2][2] - matrix1[0][2]*matrix1[2][0]);
              float cof1f = (matrix1[0][0]*matrix1[1][2] - matrix1[0][2]*matrix1[1][0]);
              float cof1g = (matrix1[1][0]*matrix1[2][1] - matrix1[1][1]*matrix1[2][0]);
              float cof1h = (matrix1[0][0]*matrix1[2][1] - matrix1[0][1]*matrix1[2][0]);
              float cof1i = (matrix1[0][0]*matrix1[1][1] - matrix1[0][1]*matrix1[1][0]);
              
              float a = cof1a;
              float b = -cof1d;
              float c = cof1g;
              float d = -cof1b;
              float e = cof1e;
              float f = -cof1h;
              float g = cof1c;
              float h = -cof1f;
              float i = cof1i;

              inverse1[0][0] = a/det1;
              inverse1[1][0] = b/det1;
              inverse1[2][0] = c/det1;
              inverse1[0][1] = d/det1;
              inverse1[1][1] = e/det1;
              inverse1[2][1] = f/det1;
              inverse1[0][2] = g/det1;
              inverse1[1][2] = h/det1;
              inverse1[2][2] = i/det1;
              
          
              cout << Buffer << "                    Your matrix's inverse is: " << endl << endl;
              cout << "                           \n";
              
                for (int i = 0; i < rows1; i++) {
                    cout << "                            | ";
                    for (int j = 0; j < cols1; j++) {
                        cout << inverse1[i][j] <<" ";
                    }
                    cout << "| \n";
                    
                }
              cout << endl << endl <<  Buffer;
  
          }
          
          else {
          
              cout << Buffer << "                 Your matrix's determinant is: " << endl << endl;
              cout << "                                " << det1 << endl << Buffer;
              cout << Buffer << "                    Your matrix is singular: " << endl << endl;
              cout << "                      " << "there is no inverse!" << endl << Buffer;
              
          }
              
          
      } 
      
  }
  
  int rows2;
  int cols2;
  string ThirdQuestion;
  string FourthQuestion;
  string Q11 = "    What are the number of rows of your second matrix? \n";
  ThirdQuestion = Buffer + Q11 + Q2 + Q3 + Buffer;
  cout << ThirdQuestion << endl;
  cin >> rows2;
  
  cout << endl << Buffer << "                   Number of rows input: " << rows2 << "\n" << Buffer;
  
  string Q14 = "What are the number of columns of your second matrix? \n";
  FourthQuestion = Buffer + Q14 + Q2 + Q3 + Buffer;
  cout << FourthQuestion << endl;
  cin >> cols2;
 
  cout << endl << Buffer << "                  Number of columns input: " << cols2 << "\n" << Buffer;
  
  cout << Buffer << "                    Your matrix is " << rows2 << " by " << cols2 << ".\n" << Buffer;
  vector<vector<float>> matrix2(rows2, vector<float>(cols2));
  for (int i = 0; i < rows2; i++) {
      for (int j = 0; j < cols2; j++) {
          cout << "\n          Please type the value for the " << i+1 << " by " << j+1 << " element.\n";
          cin >> matrix2[i][j];
          cout << endl;
  } }
  cout << Buffer << "                 Your current second matrix is: " << endl << endl;
  for (int i = 0; i < rows2; i++) {
      cout << "                            | ";
      for (int j = 0; j < cols2; j++) {
          cout << matrix2[i][j] <<" ";
      }
      cout << "| \n";
  }
  
  cout << endl << Buffer;
  float det2;
  vector<vector<float>> inverse2(rows2, vector<float>(cols2));
  if (rows2 <= 3  && rows2 == cols2) {
      // Show determinant and inverse
      if (rows2 == 1) {
          det2 = matrix2[0][0];
          inverse2[0][0] = (1/det2)*matrix2[0][0];
          
          cout << Buffer << "                 Your matrix's determinant is: " << endl << endl;
          cout << "                                " << det2 << endl << Buffer;
          cout << Buffer << "                    Your matrix's inverse is: " << endl << endl;
          cout << "                           " << inverse2[0][0] << endl << Buffer;
  
      }
      else if (rows2 == 2) {
          det2 = (matrix2[0][0]*matrix2[1][1] - matrix2[0][1]*matrix2[1][0]);
          
          if (det2 != 0) {
              float a2 = matrix2[0][0];
              float b2 = matrix2[0][1];
              float c2 = matrix2[1][0];
              float d2 = matrix2[1][1];
              inverse2[0][0] = d2/det2;
              inverse2[0][1] = -b2/det2;
              inverse2[1][0] = -c2/det2;
              inverse2[1][1] = a2/det2;
              
          
              cout << Buffer << "                 Your matrix's determinant is: " << endl << endl;
              cout << "                                " << det2 << endl << Buffer;
              cout << Buffer << "                    Your matrix's inverse is: " << endl << endl;
              cout << "                           \n";
              
                for (int i = 0; i < rows2; i++) {
                    cout << "                            | ";
                    for (int j = 0; j < cols2; j++) {
                        cout << inverse2[i][j] <<" ";
                    }
                    cout << "| \n";
                    
               }
              cout << endl << endl << Buffer;
  
          }
          
          else {
          
              cout << Buffer << "                 Your matrix's determinant is: " << endl << endl;
              cout << "                                " << det2 << endl << Buffer;
              cout << Buffer << "                    Your matrix is singular: " << endl << endl;
              cout << "                      " << "there is no inverse!" << endl << Buffer;
              
          }
      }
      
      else {
          
          float cof2a = (matrix2[1][1]*matrix2[2][2] - matrix2[1][2]*matrix2[2][1]);
          float cof2b = (matrix2[0][1]*matrix2[2][2] - matrix2[0][2]*matrix2[2][1]);
          float cof2c = (matrix2[0][1]*matrix2[1][2] - matrix2[0][2]*matrix2[1][1]);
          det2 = matrix2[0][0]*cof2a - matrix2[1][0]*cof2b + matrix2[2][0]*cof2c;
          cout << Buffer << "                 Your matrix's determinant is: " << endl << endl;
          cout << "                                " << det2 << endl << Buffer;
          
          if (det2 != 0) {
              float cof2d = (matrix2[1][0]*matrix2[2][2] - matrix2[1][2]*matrix2[2][0]);
              float cof2e = (matrix2[0][0]*matrix2[2][2] - matrix2[0][2]*matrix2[2][0]);
              float cof2f = (matrix2[0][0]*matrix2[1][2] - matrix2[0][2]*matrix2[1][0]);
              float cof2g = (matrix2[1][0]*matrix2[2][1] - matrix2[1][1]*matrix2[2][0]);
              float cof2h = (matrix2[0][0]*matrix2[2][1] - matrix2[0][1]*matrix2[2][0]);
              float cof2i = (matrix2[0][0]*matrix2[1][1] - matrix2[0][1]*matrix2[1][0]);
              
              float a2 = cof2a;
              float b2 = -cof2d;
              float c2 = cof2g;
              float d2 = -cof2b;
              float e2 = cof2e;
              float f2 = -cof2h;
              float g2 = cof2c;
              float h2 = -cof2f;
              float i2 = cof2i;

              inverse2[0][0] = a2/det2;
              inverse2[1][0] = b2/det2;
              inverse2[2][0] = c2/det2;
              inverse2[0][1] = d2/det2;
              inverse2[1][1] = e2/det2;
              inverse2[2][1] = f2/det2;
              inverse2[0][2] = g2/det2;
              inverse2[1][2] = h2/det2;
              inverse2[2][2] = i2/det2;
              
          
              cout << Buffer << "                    Your matrix's inverse is: " << endl << endl;
              cout << "                           \n";
              
                for (int i = 0; i < rows2; i++) {
                    cout << "                            | ";
                    for (int j = 0; j < cols2; j++) {
                        cout << inverse2[i][j] <<" ";
                    }
                    cout << "| \n";
                    
                }
              cout << endl << endl <<  Buffer;
  
          }
          
          else {
          
              cout << Buffer << "                 Your matrix's determinant is: " << endl << endl;
              cout << "                                " << det2 << endl << Buffer;
              cout << Buffer << "                    Your matrix is singular: " << endl << endl;
              cout << "                      " << "there is no inverse!" << endl << Buffer;
              
          }
              
          
      } 
      
  }
  
  string CalcQ1 = "              What operation do you wish to perform?\n";
  string CalcQ2 = "                         Your options are:\n\n";
  string CalcQ3 = "         Type \"add\" for addition, \"sub\" for subtraction,\n";
  string CalcQ4 = "       \"mul\" for multiplication, \"div\" for division, or \"end\"\n";
  string CalcQ5 = "\"mul\" for multiplication, or \"end\" if you wish to perform no operation.\n";
  string CalcQ6 = "               if you wish to perform no operation.\n";
  string Result1 = "                     Your resultant matrix is: \n\n";

  bool correctOperator = false;
  float det3;
  vector<vector<float>> matrix3(rows1, vector<float>(cols2));
  vector<vector<float>> inverse3(rows1, vector<float>(cols2));

  while (correctOperator != true) {
  
      string QnIfNotSingular = CalcQ1 + CalcQ2 + CalcQ3 + CalcQ4 + CalcQ6 + Buffer;
      string QnIfSingular    = CalcQ1 + CalcQ2 + CalcQ3 + CalcQ5 + Buffer;
      string QnIfJustMult    = CalcQ1 + CalcQ2 + CalcQ5 + Buffer;
      string QnIfJustMulDiv  = CalcQ1 + CalcQ2 + CalcQ4 + CalcQ6 + Buffer;
      string operation;
  
      if (cols1 == rows2) {
          // Required condition for any Matrix operations
          // Matrices compatible for multiplication
          if (det2 != 0 && rows2 == cols2) {
              // Matrices compatible for division
              if (cols1 == cols2 && rows1 == rows2) {
                  // Matrices compatible for ALL operations
                  cout << QnIfNotSingular;
                  cin  >> operation;
  
                  if (operation == "end" || operation == "END") {
                      // Ends program prematurely
                      correctOperator = true;
                  }
                  else if (operation == "add" || operation == "ADD" ||
                           operation == "sub" || operation == "SUB" ||
                           operation == "mul" || operation == "MUL" ||
                           operation == "div" || operation == "DIV") {
                      // Code for operations
                      if (operation == "add" || operation == "ADD") {
                          // Run addition code
                          cout << Buffer << Result1;
                          for (int i = 0; i < rows1; i++) {
                              cout << "                            | ";
                              for (int j = 0; j < cols2; j++) {
                                  matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
                                  cout << matrix3[i][j] << " ";
                              }
                              cout << "| \n";
                          }
                          cout << endl << endl << Buffer;
                      }
                      else if (operation == "sub" || operation == "SUB") {
                          // Run subtraction code
                          cout << Buffer << Result1;
                          for (int i = 0; i < rows1; i++) {
                              cout << "                            | ";
                              for (int j = 0; j < cols2; j++) {
                                  matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
                                  cout << matrix3[i][j] << " ";
                              }
                              cout << "| \n";
                          }
                          cout << endl << endl << Buffer;
                      }
                      else if (operation == "mul" || operation == "MUL") {
                          // Run multiplication code
                          cout << Buffer << Result1;
                          for (int i = 0; i < rows1; i++) {
                              cout << "                            | ";
                              for (int j = 0; j < cols2; j++) {
                                  matrix3[i][j] = 0;
                                  for (int k = 0; k < rows2; k++) {
                                      matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                                  }
                                  cout << matrix3[i][j] << " ";
                              }
                              cout << "| \n";
                          }
                          cout << endl << endl << Buffer;
                      }
                      else if (operation == "div" || operation == "DIV") {
                          // Run division code
                          cout << Buffer << Result1;
                          for (int i = 0; i < rows1; i++) {
                              cout << "                            | ";
                              for (int j = 0; j < cols2; j++) {
                                  matrix3[i][j] = 0;
                                  for (int k = 0; k < rows2; k++) {
                                      matrix3[i][j] += matrix1[i][k] * inverse2[k][j];
                                  }
                                  cout << matrix3[i][j] << " ";
                              }
                              cout << "| \n";
                          }
                          cout << endl << endl << Buffer;
                      }
                      correctOperator = true;
                  }
                  else {
                      // Code to repeat the question.
                      cout << Buffer << ErrorMessage << Buffer;
                  }
  
              }
              else {
                  // Matrices compatible for mult and div ONLY
                  cout << QnIfJustMulDiv;
                  cin  >> operation;
  
                  if (operation == "end" || operation == "END") {
                      correctOperator = true;
                  }
                  else if (operation == "mul" || operation == "MUL") {
                      // Run multiplication code
                      cout << Buffer << Result1;
                      for (int i = 0; i < rows1; i++) {
                          cout << "                            | ";
                          for (int j = 0; j < cols2; j++) {
                              matrix3[i][j] = 0;
                              for (int k = 0; k < rows2; k++) {
                                  matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                              }
                              cout << matrix3[i][j] << " ";
                          }
                          cout << "| \n";
                      }
                      cout << endl << endl << Buffer;
                      correctOperator = true;
                  }
                  else if (operation == "div" || operation == "DIV") {
                      // Run division code
                      cout << Buffer << Result1;
                      for (int i = 0; i < rows1; i++) {
                          cout << "                            | ";
                          for (int j = 0; j < cols2; j++) {
                              matrix3[i][j] = 0;
                              for (int k = 0; k < rows2; k++) {
                                  matrix3[i][j] += matrix1[i][k] * inverse2[k][j];
                              }
                              cout << matrix3[i][j] << " ";
                          }
                          cout << "| \n";
                      }
                      cout << endl << endl << Buffer;
                      correctOperator = true;
                  }
                  else {
                      // Code to repeat the question.
                      cout << Buffer << ErrorMessage << Buffer;
                  }
              }
          }
          else {
              // Matrices not compatible for division
              if (cols1 == cols2 && rows1 == rows2) {
                  // Matrices compatible for mul, add, and sub
                  cout << QnIfSingular;
                  cin  >> operation;
  
                  if (operation == "end" || operation == "END") {
                      correctOperator = true;
                  }
                  else if (operation == "add" || operation == "ADD" ||
                           operation == "sub" || operation == "SUB" ||
                           operation == "mul" || operation == "MUL") {
                      if (operation == "add" || operation == "ADD") {
                          // Run addition code
                          cout << Buffer << Result1;
                          for (int i = 0; i < rows1; i++) {
                              cout << "                            | ";
                              for (int j = 0; j < cols2; j++) {
                                  matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
                                  cout << matrix3[i][j] << " ";
                              }
                              cout << "| \n";
                          }
                          cout << endl << endl << Buffer;
                      }
                      else if (operation == "sub" || operation == "SUB") {
                          // Run subtraction code
                          cout << Buffer << Result1;
                          for (int i = 0; i < rows1; i++) {
                              cout << "                            | ";
                              for (int j = 0; j < cols2; j++) {
                                  matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
                                  cout << matrix3[i][j] << " ";
                              }
                              cout << "| \n";
                          }
                          cout << endl << endl << Buffer;
                      }
                      else if (operation == "mul" || operation == "MUL") {
                          // Run multiplication code
                          cout << Buffer << Result1;
                          for (int i = 0; i < rows1; i++) {
                              cout << "                            | ";
                              for (int j = 0; j < cols2; j++) {
                                  matrix3[i][j] = 0;
                                  for (int k = 0; k < rows2; k++) {
                                      matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                                  }
                                  cout << matrix3[i][j] << " ";
                              }
                              cout << "| \n";
                          }
                          cout << endl << endl << Buffer;
                          correctOperator = true;
                      }
                  }
                  else {
                      // Code to repeat the question.
                      cout << Buffer << ErrorMessage << Buffer;
                  }
              }
              else {
                  // Matrices compatible for multiplication ONLY
                  cout << QnIfJustMult;
                  cin  >> operation;
  
                  if (operation == "end" || operation == "END") {
                      correctOperator = true;
                  }
                  else if (operation == "mul" || operation == "MUL") {
                      // Run multiplication code
                      cout << Buffer << Result1;
                      for (int i = 0; i < rows1; i++) {
                          cout << "                            | ";
                          for (int j = 0; j < cols2; j++) {
                              matrix3[i][j] = 0;
                              for (int k = 0; k < rows2; k++) {
                                  matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                              }
                              cout << matrix3[i][j] << " ";
                          }
                          cout << "| \n";
                      }
                      cout << endl << endl << Buffer;
                      correctOperator = true;
                  }
                  else {
                      // Code to repeat the question.
                      cout << Buffer << ErrorMessage << Buffer;
                  }
              }
          }
      }
      else {
          cout << Buffer << "Matrices not compatible for operations - sorry!\n" << Buffer;
          correctOperator = true;
      }
  
  } 
  
  
  string EndMessage1 = "                          Ending Program\n";
  string EndMessage2 = "                   I hope you have a good day!\n";
  
  cout << Buffer << EndMessage1 << EndMessage2 << Buffer;
  
  
  return 0;
}