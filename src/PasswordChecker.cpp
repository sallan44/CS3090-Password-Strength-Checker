#include <iostream>
#include <regex>

class PasswordChecker{
    protected:
        //name of user
        std::string name;
        //password inputted
        std::string password;
        //message to be displayed to user upon entering password
        std::string message;
        //regex expression for special characters
        std::regex specialCharacters{"[^a-zA-Z0-9]"};
        //regex expression for a space
        std::regex spaces{"\\s"};

    public:
        /**
         * Constructor. Instantiayes name and password typed by user.
         */
        PasswordChecker(std::string name, std::string password) : name(name), password(password) {};

        void checkPasswordRequirements(){
            if (password.length() < 10){
                 message = "Password must be at least 10 characters.";
            } else if (std::regex_search(password, spaces)){
                message = "Password can not contain spaces.";
            } else if (!std::regex_search(password, specialCharacters)){
                 message = "Password must have at least one special character.";
            } else if (password.find(name) != std::string::npos){
                message = "Password must not contain name.";
            } else {
                message = "Password is strong.";
            }
        }

        /**
         * Prints status of password to console.
         */
        void displayMessage(){
            std::cout << message << std::endl;
        }
};

int main(){
    std::string name; 
    std::string password; 
    std::cout << "Enter your name: " << std::endl;
    std::cin >> name;
    std::cout << "Enter a password: " << std::endl;
    std::cin >> password;

    PasswordChecker pc(name, password);
    pc.checkPasswordRequirements();
    pc.displayMessage();

    return 0;
}