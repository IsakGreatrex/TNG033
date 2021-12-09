#include "set.hpp"


// std::size_t is defined in the C++ standard library
// std::size_t is an unsigned integer type that can store the maximum size of any possible object
// sizes are non-negative integers -- i.e. unsigned integer type

// Initialize the counter of the total number of existing nodes
std::size_t Set::Node::count_nodes = 0;

// Used only for debug purposes
// Return number of existing nodes
std::size_t Set::get_count_nodes() {
    return Set::Node::count_nodes;
}


/* ******************************************************** */

// Default constructor
Set::Set() {
    head = new Node();
}

// Constructor for creating a set from an int
Set::Set(int v) : Set(){
    insert(head, v);
}

// Constructor: create a set with the elements in V
// V is not sorted and may contain repeated elements
Set::Set(const std::vector<int>& V) : Set(){
    
    for(auto i : V){
        //Node* tempNode = new Node(i,nullptr);
        Node* iterNode = head;
        while (iterNode != nullptr) {
            if (iterNode->next == nullptr) {
                /*Node* lastNode = new Node(i,iterNode->next);
                iterNode->next = lastNode;*/
                insert(iterNode, i);
                break;
            }
            if (iterNode->next->value > i) {
                /*Node* loopNode = new Node(i, iterNode->next);
                iterNode->next = loopNode;*/
                insert(iterNode, i);
                break;
            }
            if (iterNode->next->value == i ){
                break;
            }
            else{
                iterNode = iterNode->next;
            }
        }
    }
}

// copy constructor
Set::Set(const Set& source) : head(new Node) {
    Node* ptr1 = source.head->next;
    Node* ptr2 = head;
    
    while (ptr1 != nullptr) {
        ptr2->next = new Node(ptr1->value, nullptr);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    counter = source.counter;
}

// Assignment operator: copy-and-swap idiom
// Uses the copy constructor and the destructor
Set& Set::operator=(Set s) {
    std::swap(head, s.head);
    std::swap(counter, s.counter);
    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() {
    // ADD CODE
    Node* ptr = head;
    while (head != nullptr) {
        head = head->next;
        delete ptr;
        ptr = head;
    }
    /*
    Node* temp = head->next;
    while(temp != nullptr)
    {
        head->next = temp->next;
        delete temp;
        temp = head->next;
    }
    delete head;
     */
}


// Return number of elements in the set
std::size_t Set::cardinality() const {
    Node* temp = head->next;
    int counter = 0;
    while (temp != nullptr) {
        temp = temp->next;
        ++counter;
    }
 
    return counter;  // delete if needed
}

// Test if set is empty
bool Set::empty() const {
    if (head->next == nullptr) {
        return true;
    }else
    return false;  // delete if needed
}

// Test if x is an element of the set
bool Set::member(int x) const {
    Node* ptr = this-> head;
    while (ptr != nullptr) {
        if (ptr->value == x) {
            return true;
        }
        ptr = ptr->next;
    }

    return false;  // delete if needed
}

bool Set::operator<=(const Set& b) const {
   /* Node* ptr1 = this->head->next;
    Node* ptr2 = b.head->next;
    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1->value == ptr2->value) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }else if(ptr2->value < ptr1->value)
        {
            ptr2 = ptr2->next;
        }
        else{
            return false;
        }
    }
    return true;*/
    Node* ptr = head->next;
    while (ptr!=nullptr) {
        if(b.member(ptr->value) == false){
            return false;
        }
        ptr = ptr -> next;
    }
    
    return true;
}

bool Set::operator==(const Set& b) const {
  /*  Node* ptr = head->next;
    
    while (ptr!=nullptr) {
        if (b.member(ptr->value) == true) {
            //return true;
            ptr = ptr->next;
        } else {
            return false;
        }
    }
    return true;*/
    
    return *this <= b && b <= *this;
    
}

bool Set::operator!=(const Set& b) const {
   /* Node* ptr1 = this->head->next;
    Node* ptr2 = b.head->next;
    
    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1->value != ptr2->value) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
            return true;
        }else{
            return false;
        }
    }
    */
    return !(*this == b);
}

bool Set::operator<(const Set& b) const {
   /* Node* ptr1 = head->next;
    Node* ptr2 = b.head->next;
    
    while (ptr1 !=nullptr) {
        if (b.member(ptr2->value == false)) {
            return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    return true;  // delete if needed
    */
    return (*this <= b && *this != b);
    
}

// Set union
// Repeated values are not allowed
Set Set::operator+(const Set& b) const {
    
    Set result{};
    // skulle kunna göra result av b för att slippa while av b
   /*
    Node* ptr1 = head->next;
    Node* ptr2 = b.head->next;
    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (result.member(ptr1 -> value) == false) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
            else{
                result.insert(ptr1, ptr1->value);
                result.insert(ptr2, ptr2->value);
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
        }
    return result;  */
    
    
    Node* ptr1 = head->next;
    Node* ptr2 = b.head->next;
    
    while(ptr1 != nullptr) {
        if(result.member(ptr1 -> value) == false) {
            result.insert(result.head, ptr1 ->value);
        }
        ptr1 = ptr1 -> next;
    }
    while(ptr2 !=nullptr) {
        if(result.member(ptr2 -> value) == false) {
            result.insert(result.head, ptr2 -> value);
        }
        ptr2 = ptr2 -> next;
    }
    
    return result;
    
}

// Set intersection
Set Set::operator*(const Set& b) const {
    Set result{};
    Node* ptr = head->next;
    while (ptr != nullptr) {
        if (b.member(ptr->value) == true) {
            result.insert(result.head, ptr->value);
        }
        ptr = ptr->next;
    }
    return result;  // delete if needed
}

// Set difference
Set Set::operator-(const Set& b) const {
    Set result{};
    Node* ptr = head->next;
    while (ptr!=nullptr) {
        if (b.member(ptr->value) == false) {
            result.insert(result.head, ptr->value);
            ptr = ptr->next;
        }
        else{
            ptr = ptr->next;
        }
    }
    
    return result;  // delete if needed
}

// set difference with set {x}
Set Set::operator-(int x) const {
  //  Set result{};
 //   Node* ptr = head-> next;
    Set test = Set{x};
   /*
    while (ptr != nullptr) {
        if (test.member(ptr->value) == false) {
            result.insert(result.head, ptr->value);
            ptr = ptr->next;
        }
        else{
            ptr = ptr->next;
        }
    }
    
    return result;  // delete if needed*/
    
    return *this-test;
}

// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const Set& theSet) {
    if (theSet.empty()) {
        os << "Set is empty!";
    } else {
        Set::Node* temp = theSet.head->next;
        os << "{ ";

        while (temp != nullptr) {
            os << temp->value << " ";
            temp = temp->next;
        }
        os << "}";
    }
    return os;
}

/********** Private member functions ************/

void Set::insert(Node* p , int value){
    /*Node* newNode = new Node(value, p->next);
    p->next = newNode;*/
    
    p->next = new Node(value,p->next);
    
}
