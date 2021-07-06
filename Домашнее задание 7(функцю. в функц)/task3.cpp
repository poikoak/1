#include <iostream>
#include <io.h>
#include <algorithm>

/**
 * Разработать командный интерпретатор (по типу cmd), который понимает следующие команды:
 * - cls - очистка экрана
 * - exit - выход из программы
 * - dir - показать содержимое текущей папки
 * - type - показать содержимое файла (пример: type c:\temp\text.txt)
 * */


/**
 * Методы dir и type могут принимать как полные, так и относительные пути.
 * */
struct Cmd {
private:
    const unsigned DIR_PATH_LENGTH = 256;

    char *path = nullptr;

    void showPath() {
        std::cout << this->path << ">";
    }

    bool isEqlCommands(const char *command1, const char *command2, bool checkParams = false) {
        if (checkParams) {

            unsigned commandLength = strlen(command2);

            while (commandLength) {
                while (isspace(*command1)) { ++command1; }
                if (*command1 != *command2) return false;
                ++command1;
                ++command2;
                --commandLength;
            }

        } else {

            while (true) {
                while (isspace(*command1)) { ++command1; }
                if (*command1 != *command2) return false;
                if (*command1 == '\0') { break; }
                ++command1;
                ++command2;
            }
        }

        return true;
    }

    const char *getParams(const char *command) {

        while (isspace(*command)) { ++command; }
        while (*command != ' ' && *command != 0) { ++command; }
        while (isspace(*command)) { ++command; }

        return command;
    }

    bool isOnThePath(const char *str) {
        for (int i = 0, j = 0; str[i] != 0; ++i) {
            if (str[j] == '\\') continue;
            if (tolower(this->path[i]) != tolower(str[j])) return false;
            ++j;
        }

        return true;
    }

    // В этом методе нужно ввести путь к директории. Например: c:\Temp
    void setPath() {
        while (true) {
            this->path = new char[this->DIR_PATH_LENGTH];

            std::cout << "Type the path to the directory!" << std::endl;
            std::cin.getline(this->path, this->DIR_PATH_LENGTH);

            if (isDir()) break;
            else {
                std::cout << "The specified directory could not be found!" << std::endl;
                delete[] this->path;
            }
        }
    }

    // Тут я проверяю существует ли указанная директория
    bool isDir() {
        _finddata_t cFile;

        long hFile = _findfirst(this->path, &cFile);

        if (cFile.attrib & _A_SUBDIR) {
            _findclose(hFile);
            return true;
        } else {
            _findclose(hFile);
            return false;
        }
    }

    void type(const char *path) {
        if (strlen(path) != 0) {
            FILE *file;

            char *newPath = new char[this->DIR_PATH_LENGTH];

            if (isOnThePath(path)) {
                strcpy(newPath, path);
            } else {
                strcpy(newPath, this->path);
                strcat(newPath, "\\");
                strcat(newPath, path);
            }

            if (fopen_s(&file, newPath, "r") == 0) {
                const unsigned CHAR_SIZE = sizeof(char);

                fseek(file, 0, SEEK_END);

                unsigned fileSize = ftell(file);

                fseek(file, 0, SEEK_SET);

                char *buffer = new char[fileSize + 1];
                fread(buffer, CHAR_SIZE, fileSize, file);

                buffer[fileSize] = 0;

                std::cout << buffer << std::endl;

                delete[] buffer;
                delete[] newPath;

                fclose(file);

            } else {
                std::cout << "Couldn't read the file!" << std::endl;
            }
        } else {
            std::cout << "Error in the command syntax!" << std::endl;
        }
    }

    void dir(const char *path) {
        char *newPath = new char[2000];

        unsigned lengthPath = strlen(path);

        if (isOnThePath(path) && lengthPath != 0) {
            strcpy(newPath, path);
            strcat(newPath, "\\");
            strcat(newPath, "*.*");

        } else if (lengthPath != 0) {
            std::cout << "File not found!" << std::endl;

            delete[] newPath;

            return;

        } else {
            strcpy(newPath, this->path);
            strcat(newPath, "\\");
            strcat(newPath, "*.*");
        }

        _finddata_t cFile;

        long hFile;

        hFile = _findfirst(newPath, &cFile);

        if (hFile == -1) {
            std::cout << "File not found" << std::endl;
            delete[] newPath;
            return;
        }

        if (strcmp(cFile.name, ".") != 0 && strcmp(cFile.name, "..") != 0) {
            if (cFile.attrib & _A_SUBDIR)
                std::cout << cFile.name << "   " << "<DIR>" << std::endl;
            else
                std::cout << cFile.name << "   " << cFile.size << std::endl;
        }

        while (_findnext(hFile, &cFile) == 0) {
            if (strcmp(cFile.name, ".") != 0 && strcmp(cFile.name, "..") != 0) {
                if (cFile.attrib & _A_SUBDIR)
                    std::cout << cFile.name << "   " << "<DIR>" << std::endl;
                else
                    std::cout << cFile.name << "   " << cFile.size << std::endl;
            }
        }


        delete[] newPath;

        _findclose(hFile);
    }

public:
    Cmd() {
        this->setPath();
    }

    ~Cmd() {
        delete[] this->path;
    }

    void openCmd() {
        const unsigned COMMAND_LENGTH = 256;

        this->showPath();

        char *command = new char[COMMAND_LENGTH];
        std::cin.getline(command, COMMAND_LENGTH);

        while (!isEqlCommands(command, "exit")) {

            if (isEqlCommands(command, "dir", true))
                this->dir(this->getParams(command));

            else if (isEqlCommands(command, "type", true))
                this->type(this->getParams(command));

            else if (isEqlCommands(command, "cls"))
                system("cls");

            else std::cout << "Invalid command!" << std::endl;

            this->showPath();

            std::cin.getline(command, COMMAND_LENGTH);
        }

        delete[] command;
        exit(0);
    }
};

int main() {
    Cmd cmd;
    cmd.openCmd();

    return 0;
}
