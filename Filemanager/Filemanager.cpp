
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void remove_file(const string& filename) {
   if (remove(filename.c_str()) != 0) {
      cout << "Error deleting file: " << filename << endl;  
   }
   else {
      cout << "File " << filename << " deleted successfully." << endl;
   }
}

void create_file(const string& filename) {
   ofstream file(filename);
   file.close();
      cout << "File " << filename << " created successfully." << endl;   
}

void exists_file(const string& filename) {
   ifstream file(filename);
   if (file.good()) {
      cout << "File " << filename << " exsists." << endl;
      file.close();
   }
   else {
      cout << "File " << filename << " does not exists." << endl;
   }
}

void info_file(const string& filename) {
   ifstream file(filename);
   if (file.good()) {
      file.seekg(0, ios::end);
      streampos size = file.tellg();            
      cout << "File " << filename << " size: " << size << " bytes." << endl;
      file.close();
   }
   else {
      cout << "File " << filename << " does not exist." << endl;
   }
}

void copy_file(const string& sourse, const string& destination) {
   ifstream src_file(sourse, ios::binary);
   ofstream dst_file(destination, ios::binary);
   dst_file << src_file.rdbuf();
   src_file.close();
   dst_file.close();
   cout << "File " << sourse << " copied to " << destination << " successfully." << endl;
}

void move_file(const string& sourse, const string& destination) {
   if (rename(sourse.c_str(), destination.c_str()) != 0) {
      cout << "Error moving file: " << sourse << " to " << destination << endl;
   }
   else {
      cout << "File " << sourse << " moved to " << destination << " successfully." << endl;
   }
}

void rename_file(const string& filename, const string& new_filename) {
   if (rename(filename.c_str(), new_filename.c_str()) != 0) {
      cout << "Error renaming file: " << filename << " to " << new_filename << endl;
   }
   else {
      cout << "File " << filename << " renamed to " << new_filename << " successfully." << endl;
   }
}

int main() {
   
   cout << endl;
   cout << "Enter \"remove ./your file\" to delete the file;" << endl;
   cout << "Enter \"create ./your file\" to create the file;" << endl;
   cout << "Enter \"exists ./your file\" to check if the file exists;" << endl;
   cout << "Enter \"info ./your file\" to get information about the file;" << endl;
   cout << "Enter \"copy ./your file /tmp/your file \" to copy a file;" << endl;
   cout << "Enter \"move ./your file /tmp/your file \" to move a file;" << endl;
   cout << "Enter \"rename ./your file ./your new_file \" to rename a file;" << endl;
   cout << endl;
   
   while (true) {
      string command;
      getline(cin, command);
      istringstream iss(command);
      string action;
      iss >> action;
      if (action == "remove") {
         string file;
         iss >> file;
         remove_file(file);
      }
      else if (action == "create") {
         string file;
         iss >> file;
         create_file(file);
      }
      else if (action == "exists") {
         string file;
         iss >> file;
         exists_file(file);
      }
      else if (action == "info") {
         string file;
         iss >> file;
         info_file(file);
      }
      else if (action == "copy") {
         string file1, file2;
         iss >> file1 >> file2;
         copy_file(file1, file2);
      }
      else if (action == "move") {
         string file1, file2;
         iss >> file1 >> file2;
         move_file(file1, file2);
      }
      else if (action == "rename") {
         string file, new_file;
         iss >> file >> new_file;
         rename_file(file, new_file);
      }
      else {
         cout << "Invalid command. Please try again." << endl;
      }
   }
}
