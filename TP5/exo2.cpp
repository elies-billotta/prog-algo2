#include <time.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>


using std::size_t;
using std::string;


std::vector<string> names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

unsigned long int hash(string key)
{
    int i = 0;
    int hash_value = 0;
    while (key[i] != '\0'){
        hash_value += key[i]*pow(256, i);
    }
    return hash_value;
}

struct MapNode
{

    string key;
    unsigned long int key_hash;

    int value;

    MapNode* left;
    MapNode* right;

    MapNode(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->key_hash = hash(key);

        this->left = this->right = nullptr;
    }

    /**
     * @brief insertNode insert a new node according to the key hash
     * @param node
     */
    void insertNode(MapNode* node)
    {/*
        if (value < this->value && this->left == nullptr){
            this->left = new    (node);
        }
        else if (value > this->value && this->right == nullptr){
            this->right = new SearchTreeNode(node);
        }
        else if (value > this->left->value){
            this->right->insertNode(node);
        }
        else this->left->insertNode(node);*/
    }

    void insertNode(string key, int value)
    {
        this->insertNode(new MapNode(key, value));
    }

};

struct Map
{
    Map() {
        this->root = nullptr;
    }

    /**
     * @brief insert create a node and insert it to the map
     * @param key
     * @param value
     */
    void insert(string key, int value)
    {
        if (this->root == nullptr){
            this->root = new MapNode(key, value);
        }
        else {
            this->root->insertNode(key, value);
        }

    }

    /**
     * @brief get return the value of the node corresponding to key
     * @param key
     * @return
     */
    int get(string key)
    {
        MapNode* node = this->root;
        while (node != nullptr){
            if (node->key == key){
                return node->value;
            }
            else if (node->key_hash < hash(key)){
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
        return -1;
    }

    MapNode* root;
};


int main(int argc, char *argv[])
{
    srand(time(NULL));
	Map map;

    map.insert("Yolo", 20);
    for (std::string& name : names)
    {
        if (rand() % 3 == 0)
        {
            map.insert(name, rand() % 21);
        }
    }

    printf("map[\"Margot\"]=%d\n", map.get("Margot"));
    printf("map[\"Jolan\"]=%d\n", map.get("Jolan"));
    printf("map[\"Lucas\"]=%d\n", map.get("Lucas"));
    printf("map[\"Clemence\"]=%d\n", map.get("Clemence"));
    printf("map[\"Yolo\"]=%d\n", map.get("Yolo"));
    printf("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));
}
