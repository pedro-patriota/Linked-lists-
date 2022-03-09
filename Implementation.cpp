#include <iostream>
#include <string>
using namespace std;


class Node{ // creates a node
    public:
    string data; // data type
    Node* next;
};

Node* Pos(int pos, Node* head){ // discovers the node in "pos" position
    int i = 0;
    Node* current = head; // starts with the head

    while (i < pos && (current->next != NULL)){ // goes thourgh the entire stack/queue
        current = current -> next;
        i ++;
    }
    return current;
}

Node* Pop(Node* past_node ){ // removes a node
    Node* p = past_node -> next; // gets the previous one
    past_node -> next = p -> next; // constructs a new "next"
    free(p); // delete the node

    return past_node;
}


Node* Insert(Node* current_node, string new_data){ // Inserts a node
    Node* new_node = new Node();
    new_node ->data = new_data; 
    new_node -> next = current_node -> next; // subsitutes the "next's"
    current_node -> next = new_node;

    return current_node;
}

Node* Push_last(Node* head, Node* tail, string d){ // Adds the node in the end
    Node* old_tail = Insert(tail, d);
    return (head, old_tail -> next); // returns the "head" and the new "tail"
}

Node* Push_beginning(Node* head, string new_data){ // Adds the node in the beginning
    Node* new_node = new Node();
    new_node -> data = new_data;
    new_node -> next = head-> next; // substitute the node which the head is pointing for
    // by the new node
    head->next = new_node; "Uses the next"" of the initializer node" ;

    return head;
}


void Print_Actual_Node(Node* tail){
    cout << tail->data << endl;            "Printing functions";
}
void Print_Num_Node(int value){
    cout << value << endl;
}


int main (){

    Node *n, *t, *h, *past_node; // Atributes for the stack
    Node *n2, *t2, *h2, *past_node2; // Atributes for the queue
    string command, my_word, my_website;
    int num_historic = 0, non_seen_pages = 0; // const
    
    n = new Node;
    n -> data = "Stack Head"; // initializer node
    n -> next = NULL; // points to null
    t = n; "Makes the head and the tail initially pointed for the initializer node";
    h = n;
    
    n2 = new Node;
    n2 -> data = "Queue Head";
    n2 -> next = NULL;
    t2 = n2; "Makes the head and the tail initially pointed for the initializer node";
    h2 = n2;



    while (true){
        getline(cin, command);
        my_word = command.substr(0,3); // gets the word
        if (my_word == "END"){ // EOF case
            break;
        }
        
        //split(command)
        if (my_word == "OPN"){
            my_website = command.substr(4, sizeof(command)); // gets the website part from the
            // command
            h, t = Push_last(h, t, my_website); // adds it to the end of the stack
            num_historic++;
            Print_Num_Node(num_historic); // prints the num of pages  in the historic
        }

        else if (my_word == "CUR"){
            if (num_historic == 0){ // NULL case
                cout << "NULL" << endl;
            }
            else{
            Print_Actual_Node(t); // Prints the data from the tail 
            }
        }   

        else if (my_word == "BCK"){
            if (num_historic > 0){                  "We are able to remove something";
            
            past_node = Pos(num_historic -1, h); // gets the past node from the tail
            t = Pop(past_node); // removes the last node and rearranges the tail
            num_historic--; // removes one page from the const historic
            
            if (num_historic == 0){ // In case there is no previous node
                cout << "NULL" << endl;
            }
            else{ 
                Print_Actual_Node(t);
            }

            }
            
            else if (num_historic == 0){ // In case the node is already empty
                cout << "NULL" << endl;
            }
        }

        else if (my_word == "PAN"){ // Removes everything
            for(int i = num_historic; i > 0; i--){ // Goes since the head to the tail elimating
            // everything, execept the initalizer node
                past_node = Pos(i -1,h);
                t = Pop(past_node);
            }
            Print_Num_Node(num_historic); // Prints the total of deleted pages
            num_historic = 0;
        }

        else if (my_word == "SAV"){ // Saves the actual tail's node
            if (num_historic > 0){
                h2 = Push_beginning(h2, t-> data); // Puts the new value to the "next" of the 
                // initializer node (beginning)
                non_seen_pages ++;
                Print_Num_Node(non_seen_pages);
            }
            else{ // In case there is nothing to save
                cout << "NULL" << endl;
            }
        }
        else if (my_word == "REA"){

            if (non_seen_pages == 0){ // In caseThere is no saved pages
                cout << "NULL" << endl;
            }
            else{
                t2 = Pos(non_seen_pages, h2); // Gets the last node, the first one inserted
                Print_Actual_Node(t2);
                past_node2 = Pos(non_seen_pages -1, h2);
                Pop(past_node2);// removes the last node
                non_seen_pages --;
            }
            
        }
           
    }

    free (n), (t), (h), (n2), (t2), (h2), (past_node), (past_node2); // Bye bye 
    return 0;
}
