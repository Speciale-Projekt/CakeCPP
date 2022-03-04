#include <iostream>
#include <filesystem>
#include "DirMonitor.h"
namespace fs = std::filesystem;


int main() {
     // Create a FileWatcher instance that will check the current folder for changes every  seconds
     // Get current location
     // Create folder "test" in current location
     std::string pathToTest = "/home/agw/CLionProjects/Cake/test";
     fs::create_directory(pathToTest);


     FileWatcher fw{pathToTest, std::chrono::milliseconds(1000)};

     // Start monitoring a folder for changes and (in case of changes)
     // run a user provided lambda function
     fw.start([] (const std::string& path_to_watch, FileStatus status) -> void {
         // Process only regular files, all other file types are ignored
         if(!std::filesystem::is_regular_file(std::filesystem::path(path_to_watch)) && status != FileStatus::erased) {
             return;
         }

         switch(status) {
             case FileStatus::created:
                 std::cout << "File created: " << path_to_watch << '\n';
                 break;
             case FileStatus::modified:
                 std::cout << "File modified: " << path_to_watch << '\n';
                 break;
             case FileStatus::erased:
                 std::cout << "File erased: " << path_to_watch << '\n';
                 break;
             default:
                 std::cout << "Error! Unknown file status.\n";
         }
     });
 }