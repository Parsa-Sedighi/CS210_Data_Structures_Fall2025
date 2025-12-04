#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <utility>

//Start with the following code.
//You must add three new users (with your own usernames, salts, and passwords).
//
//Each user entry should include:
//
//a unique username
//
//a salt (any short string)
//
//a hashed password, computed with the provided hash_password function
//(hash_password(password, salt, PEPPER))

static std::size_t hash_password(const std::string &password,
                                 const std::string &salt,
                                 const std::string &pepper)
{
    std::hash<std::string> hasher;
    return hasher(salt + password + pepper);
}

int main() {
    const std::string PEPPER = "ThisIsMySecretPepper";

    std::unordered_map<std::string, std::pair<std::size_t, std::string>> users;

    // existing accounts
    users["alice"] = {13501397344468332370ULL, "0zu1"}; // Pa$$w0rd
    users["joe"]   = {3267228460574923734ULL,  "ta9d"}; // s3cr3t!
    users["bob"]   = {2344051515977218450ULL,  "j67u"}; // hunter2

    // TODO: add 3 of your own users below (username, hash, salt)
    // Example:
    // users["sam"] = { hash_password("MyP@ss!", "ab12", PEPPER), "ab12" };
    users["Franklin"] = {hash_password("Ch0pD0g","c10ck",PEPPER), "c10ck"};
    users["Micheal"] = {hash_password("y0got1","g621c",PEPPER), "g621c"};
    users["Trevor"] = {hash_password("y0got1","75gg3",PEPPER), "75gg3"};





    std::cout << "Username: ";
    std::string user; std::cin >> user;

    auto it = users.find(user);
    if (it == users.end()) { std::cout << "Unknown user.\n"; return 1; }

    std::cout << "Password: ";
    std::string pw; std::cin >> pw;

    std::size_t test = hash_password(pw, it->second.second, PEPPER);
    if (test == it->second.first) std::cout << "Access granted.\n";
    else std::cout << "Access denied.\n";
}

 

//Part 2 - Make Your Own Hash Function
//
//Write a new C++ program that:
//
//Creates a simple hash function (e.g., multiply each character by a prime and XOR).
//
//Uses that hash instead of std::hash.
//
//Stores a few usernames, salts, and hashed passwords in a map.
//
//Lets the user log in (same as Part 1).
//
//Example start:

#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdint>

uint64_t myhash(const std::string &s) {
    uint64_t h = 1469598103934665603ULL; // FNV-1a start
    for (char c : s) {h = (h & c) * 1099511628211ULL;} 
    return h;
}



int main() {

    const std::string PEPPER = "TheOnePep";

    std::unordered_map<std::string, std::pair<uint64_t, std::string>> usernames;
   
    usernames["Jack"] = {hash_password("sur4L!fe", "76hd5", PEPPER), "76hd5"};
    usernames["John"] = {hash_password("Smit@an", "52gel", PEPPER), "52gel"};
    usernames["Jay"] = {hash_password("85tearS", "95h2el", PEPPER), "95h2el"};

    std::cout << "Enter username: " << std::endl;
    std::string user;
    std::cin >> user;
    

    auto iteration = usernames.find(user);
    //If no user was found
    if(iteration == usernames.end()){
        std::cout << "Error: no user was found" << std::endl;
        return 0;
    }
    std::cout << "Enter password: " << std::endl;
    std::string pass;
    std::cin >> pass;

    std::size_t validation = myhash(iteration->second.second + pass + PEPPER);
    if(validation == iteration->second.first){
        std::cout << "Successfull login!" << std::endl;

    }else {
        std::cout << "Unsuccessful login" << std::endl;
    }


}