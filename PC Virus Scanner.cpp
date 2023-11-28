#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>

struct FileInfo {
    std::string name;
    std::string type;
    long long size;
};

void scanFileSystem() {
    std::cout << "Scanning file system...\n";
    std::filesystem::path currentDir = std::filesystem::current_path();
    std::vector<FileInfo> filesInfo;

    for (const auto& entry : std::filesystem::recursive_directory_iterator(currentDir)) {
        if (std::filesystem::is_regular_file(entry.path())) {
            FileInfo file;
            file.name = entry.path().filename().string();
            file.type = entry.path().extension().string();
            file.size = std::filesystem::file_size(entry);
            filesInfo.push_back(file);

            // Simulate delay
            for (volatile long long j = 0; j < 10000000; ++j);
        }
    }

    std::cout << "Total files scanned: " << filesInfo.size() << "\n";
    std::cout << "----------------------------------\n";
    std::cout << "Scanned files:\n";
    for (const auto& fileInfo : filesInfo) {
        std::cout << "Name: " << fileInfo.name << " | Type: " << fileInfo.type << " | Size: " << fileInfo.size << " bytes\n";
    }
    std::cout << "----------------------------------\n";
}

void quarantineInfectedFiles() {
    std::cout << "Quarantining infected files...\n";
    // Simulated quarantine process
    // Simulate delay
    for (volatile long long j = 0; j < 30000000; ++j);
    std::cout << "Infected files quarantined.\n";
}

void generateReport() {
    std::ofstream reportFile("scan_report.txt");

    if (reportFile.is_open()) {
        std::time_t currentTime = std::time(nullptr);
        std::string timeString = std::ctime(&currentTime);

        reportFile << "Scan Report\n";
        reportFile << "Generated at: " << timeString << "\n";
        reportFile << "Details:\n";
        reportFile << " - File system scanned.\n";
        reportFile << " - Infected files quarantined.\n";

        reportFile.close();
        std::cout << "Report generated.\n";
    } else {
        std::cout << "Unable to generate report. Error opening the file.\n";
    }
}

void displayMenu() {
    std::cout << "PC Virus Scanner\n";
    std::cout << "1. Scan File System\n";
    std::cout << "2. Quarantine Infected Files\n";
    std::cout << "3. Generate Report\n";
    std::cout << "4. List Process IDs\n";
    std::cout << "5. View System Time\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void listProcessIDs() {
    std::cout << "Listing process IDs...\n";
    // Simulated process IDs retrieval
    std::cout << "Process IDs:\n";
    for (int i = 1000; i < 1005; ++i) {
        std::cout << i << "\n";
    }
}

void viewSystemTime() {
    std::time_t now = std::time(nullptr);
    std::string timeString = std::ctime(&now);
    std::cout << "System Time: " << timeString;
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                scanFileSystem();
                break;
            case 2:
                quarantineInfectedFiles();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                listProcessIDs();
                break;
            case 5:
                viewSystemTime();
                break;
            case 6:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice!\n";
        }
    }
    return 0;
}
