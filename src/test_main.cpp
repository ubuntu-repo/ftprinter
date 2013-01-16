#include "ftprinter/FTPrinter.h"
#include "ftprinter/BufferedFTPrinter.h"
#include "ftprinter/PrintFormat.h"

#define _USE_MATH_DEFINES
#include <math.h>

using ftprinter::FTPrinter;
using ftprinter::BufferedFTPrinter;

int main(int argc, char** argv){
  //test of standard unformated output
  FTPrinter tp;
  tp.addColumn("Name", 25);
  tp.addColumn("Age", 5);
  tp.addColumn("Position", 30);
  tp.addColumn("Allowance", 9);

  tp.printHeader();
  tp << "Dat Chu" << 25 << "Research Assistant" << -0.00000000001337;
  tp << "John Doe" << 26 << "Too much float" << 125456789.123456789;
  tp << "John Doe" << 26 << "Typical Int" << 1254;
  tp << "John Doe" << 26 << "Typical float" << 1254.36;
  tp << "John Doe" << 26 << "Too much negative" << -125456789.123456789;
  tp << "John Doe" << 26 << "Exact size int" << 125456789;
  tp << "John Doe" << 26 << "Exact size int" << -12545678;
  tp << "John Doe" << 26 << "Exact size int" << -125456789;
  tp << "John Doe" << 26 << "Exact size float" << -1254567.8f;
  tp << "John Doe" << 26 << "Negative Int" << -1254;
  tp << "Jane Doe" << ftprinter::endl();
  tp << "Tom Doe" << 7 << "Student" << -M_PI;
  tp.printFooter();

  //test for formated output
  FTPrinter tp2;
  tp2.addColumn("red",     8, ftprinter::format::red);
  tp2.addColumn("green",   8, ftprinter::format::green);
  tp2.addColumn("yellow",  8, ftprinter::format::yellow);
  tp2.addColumn("blue",    8, ftprinter::format::blue);
  tp2.addColumn("cyan",    8, ftprinter::format::cyan);
  tp2.addColumn("magenta", 8, ftprinter::format::magenta);
  tp2.addColumn("white",   8, ftprinter::format::white);
  tp2.addColumn("black",   8, ftprinter::format::black);
  tp2.addColumn("nothing", 8, ftprinter::format::none);

  tp2.printHeader();
  
  tp2 << "asdfsdf" << ftprinter::format::red << 2 << 3 << 4 << 5 << ftprinter::endl();
  tp2 << ftprinter::format::blue << 6 << 7 << ftprinter::endl();
  tp2 << ftprinter::format::red << 1
      << ftprinter::format::blue << 2
      << ftprinter::format::red << 3
      << ftprinter::format::blue << 4
      << ftprinter::format::red << 5
      << ftprinter::format::blue << 6
      << ftprinter::format::red << 7
      << ftprinter::format::blue << 8
      << ftprinter::format::green << 9
      << "neue zeile";
  tp2.printHeader();

  //test for displacement compensation
  FTPrinter tp3;
  tp3.addColumn("too short column",  8);
  tp3.addColumn("long enough column", 20);
  tp3.addColumn("long enough column", 50);

  tp3.printHeader();

  tp3 << "asdhfjahsddfjhasdlkfjhasdklfjasdkfjhasdklfj" << "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdf" << "bbbbb";
  tp3 << 66666666666.5 << "asdf" << "asdfasdf";
  tp3 << 123456789 << "a";
  tp3.printFooter();


  //test for buffered writing
  BufferedFTPrinter btp;
  btp.addColumn("Name", 1, 25);
  btp.addColumn("Age", 1, 5);
  btp.addColumn("Position", 1, 30);
  btp.addColumn("Allowance", 1, 9);

  btp.printHeader();
  btp.printOut();

  btp << "Dat Chu" << 25 << "Research Assistant" << -0.00000000001337;
  btp << "John Doe" << 26 << "Too much float" << 125456789.123456789;
  btp << "John Doe" << 26 << "Typical Int" << 1254;
  btp << "John Doe" << 26 << "Typical float" << 1254.36;
  btp << "John Doe" << 26 << "Too much negative" << -125456789.123456789;
  btp << "John Doe" << 26 << "Exact size int" << 125456789;
  btp << "John Doe" << 26 << "Exact size int" << -12545678;
  btp << "John Doe" << 26 << "Exact size int" << -125456789;
  btp << "John Doe" << 26 << "Exact size float" << -1254567.8f;
  btp << "John Doe" << 26 << "Negative Int" << -1254;
  btp << "Jane Doe" << ftprinter::endl();
  btp << "Tom Doe" << 7 << "Student" << -M_PI;
  btp.printFooter();

  return 0;
}
