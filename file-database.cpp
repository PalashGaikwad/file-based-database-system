// CREATED BY PALASH GAIKWAD.
// PROGRAM NAME: FILE BASED DATABASE SYSTEM

#include <iostream> // For cout and cin.
#include <fstream>  // Fstream allows for ifstream and ofstream
#include <sstream>  // For stringstream usage.

int main()
{
  std::ifstream in_file;
  std::string file_name;
  std::string selection;

  do
  {
    // MENU
    std::cout << "MENU*************************************";
    std::cout << "\nDB: Create file database\n";
    std::cout << "RDB: Read database \n";
    std::cout << "UDB: Update Database \n";
    std::cout << "DDB: Delete Database \n";
    std::cout << "Q: Quit management system \n";
    std::cout << "*****************************************\n";
    std::cout << "\nInput DB to create a database, RDB to read a database, etc: ";
    std::cin >> selection;

    // Create Database
    if (selection == "DB" || selection == "db")
    {
      std::cout << "Input database name: ";
      std::cin >> file_name;
      std::ifstream in_file_checker(file_name);
      std::ofstream out_file;
      std::string file_name_copy{file_name};
      if (in_file_checker) // CREATED BY PALASH GAIKWAD.
      { // Checking if file exist's to create duplicate
        while (in_file_checker)
        {
          static int i{};
          std::stringstream ss;
          ss << i;
          std::string concat;
          ss >> concat;
          if (file_name != file_name_copy)
          {
            file_name.pop_back();
          }
          file_name += concat;
          in_file_checker.open(file_name);
          if (in_file_checker)
          {
            i++;
          }
          else if (!in_file_checker)
          {
            break;
          }
        }
      }
      out_file.open(file_name); // Opening connection.
      if (!out_file)            // Checking if file connected to program.
      {
        std::cerr << "Issue opening/creating file. \n";
        continue;
      }
      out_file.close(); // Closing connection.
      std::cout << "\nFile created\n\n";
    }
    // Read database
    else if (selection == "RDB" || selection == "rdb")
    {
      std::cout<<"\n List of Databases \n"; system("ls"); // Executes ls command in this directory using terminal.
      std::cout << "\n\nGive name for the database you want to open: ";
      std::cin >> file_name;
      std::cout << "\n";
      in_file.open(file_name);
      if (!in_file.is_open()) // Checking if file connected to program.
      {
        std::cerr << "ERROR CONNECTING TO FILE: Invalid filename, re-enter the correct database name.\n\n";
        continue;
      }
      std::string line;
      int counter{};
      // CREATED BY PALASH GAIKWAD.

      while (std::getline(in_file, line)) // Outputs whole database.
      {
        std::cout << line << "\n";
        counter++;
      }
      std::cout<<"\n";

      if (counter == 0) // Checking if file is empty or not.
      {
        std::cout << "Couldn't output, File is empty. \n\n\n";
      }
    }
    // Update Database
    else if (selection == "UDB" || selection == "udb")
    {
      std::cout<<"\n List of Databases \n"; system("ls"); // Executes ls command in this directory using terminal.
      std::cout << "\n\nGive name for the database you want to open: ";
      std::cin >> file_name;
      in_file.open(file_name);
      if (!in_file) // Checking if file connected to program.
      {
        std::cerr << "ERROR CONNECTING TO FILE: Invalid filename, re-enter the correct database name.\n\n";
        continue;
      }
      std::cout << "File successfully opened. \n\n";
      std::cout << "Press CTRL+X to Save Changes, Press Y and then Enter to confirm changes\n";
      std::string buffer{};
      std::cout << "Input any alphabet to continue: \n";
      std::cin >> buffer;
      std::string nano{"nano "};
      std::string parameter{nano + file_name};
      // Activating Nano
      system(parameter.c_str());
    }
    // Delete Database
    else if (selection == "DDB" || selection == "ddb")
    {
      char a{};
      std::cout << "Are you sure you want to delete a database(y/n): ";
      std::cin >> a;
      if (a == 'y' || a == 'Y')
      {
        std::string of_type{};
        std::cout<<"\n List of Databases \n"; system("ls");
        std::cout << "Input the file name dbyou want to delete: ";
        std::cin >> of_type;
        std::cout << "\n";
        std::string parameter{"rm " + of_type};
        int check = system(parameter.c_str()); // Activates rm command on terminal with file name
        std::cout << "\n";
        if (check == 1) {
        std::cout << "Deleted File\n";
      }
      }
      continue;
    }
    // CREATED BY PALASH GAIKWAD.
    // Closing connection before program terminates.
    else if (selection == "q" || selection == "Q")
    {
      if (in_file.is_open()) // Checking if file is still open.
      {
        std::cout << "Closing file connection..\n";
        in_file.close();
        std::cout << "Connection closed!\n";
      }
    }
  } while (selection != "q" && selection != "Q");
  std::cout << "Bye!\n";

  return 0;
}
// CREATED BY PALASH GAIKWAD.
