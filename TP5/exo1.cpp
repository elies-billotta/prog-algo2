#include <time.h>
#include <vector>
#include <string>

std::vector<std::string> names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});


int hash(std::vector<std::string> hash_table, std::string element)
{
    return (int) element[0] % hash_table.size();
}

void insert(std::vector<std::string> hash_table, std::string element)
{
    // use (*this)[i] or this->get(i) to get a value at index i
    hash_table[hash(hash_table, element)] = element;
}

/**
 * @brief buildHashTable: fill the HashTable with given names
 * @param table table to fiil
 * @param names array of names to insert
 * @param namesCount size of names array
 */
void buildHashTable(std::vector<std::string> hash_table, std::string* names, int namesCount)
{
    for (int i = 0 ; i < namesCount ; i++){
        insert(hash_table, names[i]);
    }
}

bool contains(std::vector<std::string> hash_table, std::string element)
{
    return hash_table[hash(hash_table, element)] == element;
}


int main(int argc, char *argv[])
{
    //table.resize(10);
}
