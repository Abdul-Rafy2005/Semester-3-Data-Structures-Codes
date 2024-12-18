
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:

    string title;
    string genre;
    int MovieID;
    float Rating;
    node* left;
    node* right;
    node(string Title,string Genre,int movieID, float rating) : title(Title), genre(Genre), MovieID(movieID), Rating(rating), left(nullptr), right(nullptr) {}

};

class tree
{
    node* root;
    void delete_tree(node *&root);
    int min_ID(node * root);
    void Insertion(node* current,node* prev,string Title,string Genre,int movieID, float rating);
    void deletion(node* current, node* prev, int MOvieID);

    public:
    void insert(string Title,string genre,int MovieID, float rating) { Insertion(root,nullptr,Title,genre,MovieID,rating); }
    void deletenode(int MovieID) { deletion(root,nullptr,MovieID); }
    tree() : root(nullptr) {}
    ~tree();
    void Inorder(node * root);
    node* getroot() { return root; }
    void recommand_algo(string Genre,float rating);
};

tree::~tree()
{
   delete_tree(root); 
}

void tree::delete_tree(node *&root)
{
    if(root)
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}


int tree::min_ID(node *root)
{
    while (root && root->left) root = root->left;
    return root->MovieID;
}

void tree::Insertion(node* current,node* prev, string Title,string Genre,int movieID, float rating)
{
    
    if(!current)
    {
        node* newnode = new node(Title,Genre,movieID,rating);

        if(!root)   root = newnode;
        else if(movieID < prev->MovieID) prev->left = newnode;
        else prev->right = newnode;
        
        return;
    }
    
    if(current->MovieID > movieID) Insertion(current->left,current,Title,Genre,movieID,rating);
    else Insertion(current->right,current,Title,Genre,movieID,rating);
       
}



void tree::deletion(node* current, node* prev, int movieID)
{

    if (current == nullptr)
    {
        cout << "No Such element Found!" << endl;
        return;
    }
    
    if(current->MovieID > movieID) deletion(current->left,current,movieID);
    else if (current->MovieID < movieID)  deletion(current->right,current,movieID);
    else 
    {
       if(!current->left && !current->right)
       {
        
           if(current != root)
           {
               if(prev->left == current) prev->left = nullptr;
               else prev->right = nullptr;
           }  

           else { root = nullptr; }
           delete current; 

       }

        else if(!current->left || !current->right) 
        {

            node* child = (current->left) ? current->left : current->right;

            if(current != root)
            {  
                if(prev->left == current) prev->left = child;
                else prev->right = child;
            }

            else { root = child; }

            delete current; 

        }

        else
        {
            int successor = min_ID(current->right);
            deletion(current->right,current,successor);
            current->MovieID = successor;
        }
    }
}

void tree::Inorder(node* root) 
{
    if (root) 
    {
        Inorder(root->left);
        cout << "ID: " << root->MovieID << ", Title: " << root->title << ", Genre: " << root->genre << ", Rating: " << root->Rating << endl;
        Inorder(root->right);
    }
}


void tree::recommand_algo(string Genre, float rating) {
    
    int MAX = 100; 
    node* recommendations[MAX]; 
    int count = 0;

    stack<node*> s; 
    node* current = root;

   
    while (current || !s.empty()) 
    {
        if (current) 
        {
            s.push(current); 
            current = current->left;
        } else 
        {
            current = s.top();
            s.pop();


            if (current->genre == Genre && current->Rating >= rating) 
            {
                if (count < MAX)  recommendations[count++] = current; 
                else 
                {
                    cout << "Recommendation limit reached!\n";
                    break;
                }
            }
            current = current->right;
        }
    }

   
    for (int i = 0; i < count - 1; ++i) 
        for (int j = 0; j < count - i - 1; ++j) 
        {
            if (recommendations[j]->Rating < recommendations[j + 1]->Rating) 
            {
                node* temp = recommendations[j];
                recommendations[j] = recommendations[j + 1];
                recommendations[j + 1] = temp;
            }
        }
    


    if (count == 0) cout << "No recommendations found for the given criteria!" << endl; 
    else 
    {
        cout << "Recommended Movies:\n";
        for (int i = 0; i < count; ++i) 
        {
            cout << "ID: " << recommendations[i]->MovieID << ", Title: " << recommendations[i]->title;
            cout << ", Genre: " << recommendations[i]->genre << ", Rating: " << recommendations[i]->Rating << endl;
        }
    }
}


int main() {

    tree BST;
    int choice;
    string title;
    string genre;
    int movieID;
    float rating;

    do
    { 
        
        cout << "--Main-Menu--" << endl;
        cout << "1.ADD MOVIE"<< endl;
        cout << "2.REMOVE MOVIE"<< endl;
        cout << "3.RECOMMAND MOVIE"<< endl;
        cout << "4.DISPLAY MOVIE"<< endl;
        cout << "5.EXIT : ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                cout << "ENTER MOVIE TITLE : ";
                cin >> title;

                cin.ignore(); 
                getline(cin, title);

                cout << "ENTER MOVIE GENRE: ";
                getline(cin, genre);

                cout << "ENTER MOVIE-ID : ";
                cin >> movieID;

                cout << "ENTER MOVIE RATING : ";
                cin >> rating;

                BST.insert(title,genre,movieID,rating);
                break; 

            case 2:

                cout << "ENTER MOVIE-ID : ";
                cin >> movieID;

                BST.deletenode(movieID);

            case 3:
                 
                cout << "ENTER GENRE FOR MOVIE : ";
                cin >> genre;
                cout << "ENTER MINIMUM RATING : ";
                cin >> rating;
                
                BST.recommand_algo(genre,rating);
                break;

            case 4:
                BST.Inorder(BST.getroot());
                break;
            case 5:
                choice = 0;
                break;
        }
            cout << "\n\n";
    } while (choice != 0);

    return 0;
}


