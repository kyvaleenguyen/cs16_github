// file: ll_functions.cpp

// Used in the function createLL()
// This function is started for you correctly - you have to complete it.
//   Use the comments to help you figure out what to do.
void h_insert(LinkNodePtr& head, string nom, int num) {
    LinkNodePtr tmp_ptr;
    tmp_ptr = new LinkNode;

    tmp_ptr->name = nom;
    tmp_ptr->number = num;
    tmp_ptr->link = nullptr; 

    // If the list is empty, the new node becomes the head
    // Check if the list is empty by checking if head = NULL or head = nullptr
    if (head == nullptr) {
        // The new node is now the first node that has been created
        head = tmp_ptr;
    } else {
        // The node is not the first node & the list already has at least one element (its not empty)
        // Create new temporary pointer to check through list for last node
        LinkNodePtr currentPtr = head;

        // If the list is not empty, traverse to the last node
        // Iterate through list checking if head != nullptr to find end of list (last node)
        while (currentPtr->link != nullptr) {
            currentPtr = currentPtr->link;
        }

        // Change the pointer of the last node to the new node
        // Link last node to new node & move to next node
        currentPtr->link = tmp_ptr;
    }
}

void createLL(LinkNodePtr& h) {
    // Name & number variables to add to node/struct
    string nom = "";
    int num;

    while (true) {
        // Prompt to get user input
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";

        // Get user input for name & number
        // Check if user input is not invalid
        //      Note: if user enters letter instead of number, the program will fail in current version
        cin >> nom >> num;

        // Check for exit input from user to exit program
        if ((nom == "0") && (num == 0)) {
            break;
        }

        // Call h_insert if exit condition not met
        h_insert(h, nom, num);
    }
}

void printLL(LinkNodePtr h) {
    // Check if no nodes present
    // If no nodes, exit
    if (h == nullptr) {
        cout << "This list is empty." << endl;
        return;
    }

    // Print list string if list not empty
    cout << "Printing the list:" << endl;

    // Print each value in each Node
    LinkNodePtr temp = h;
    int count = 0;
    while (temp != nullptr) {
        cout << "Node #" << count << ": ";
        cout << temp->name << ", " << temp->number << endl;
        temp = temp->link;
        count++;
    }
    cout << "--------" << endl;
}

void insertNodeAfter(LinkNodePtr& h) {
    // Check if list is empty
    if (h == nullptr) {
        cout << "Cannot insert in a non-existing link." << endl;
        return;
    }

    // Insert node string
    cout << "Enter node position to insert new node after (enter negative number to exit): ";

    // Count how many nodes there are in the list
    // Create pointer to check list
    LinkNodePtr current = h;

    // Create count to count how many nodes there are in the list
    int count = 0;

    while (current != nullptr) {
        current = current->link;
        count++;
    }

    // User input integer index to insert new node
    int userInput;

    // Get user input
    cin >> userInput;

    // If user enters negative int, do not insert new node into list
    if (userInput < 0) {
        return;
    } else {
        // If user does enter negative int, enter new node at index entered by user
        //      Note: check if this index is out of bounds first
        // Check if index is "illegal" (out of bounds)
        if (userInput >= count) {
            cout << "Position entered is illegal. Nothing inserted." << endl;
            return;
        }
    }

    // Create pointer to iterate through list
    current = h;
    
    // For loop to iterate through list
    for (int i = 0; i < userInput; i++) {
        current = current->link;
    }

    // Insert new node
    LinkNodePtr new_node = new LinkNode;

    // Get name string input from user & number input
    cout << "Enter data (name, then number): ";
    cin >> new_node->name >> new_node->number;

    // Link new node & insert in list at index user inputted earlier
    new_node->link = current->link;
    current->link = new_node;
}

void findMax(LinkNodePtr h) {
    // Check if list is empty first
    if (h == nullptr) {
        cout << "This list is empty." << endl;
        return;
    }

    // Max is number in the first node
    int max = h->number;

    // Search through list
    // Create new pointer to search
    LinkNodePtr current = h;

    while (current != nullptr) {
        if (current->number > max) {
            max = current->number;
        }
        // Move to next node
        current = current->link;
    }

    // Print max value found
    cout << "Largest number in the list is: " << max << endl;
}

void findMin(LinkNodePtr h) {
    // Check if list is empty first
    if (h == nullptr) {
        cout << "This list is empty." << endl;
        return;
    }

    // Min is number in the first node
    int min = h->number;

    // Search through list
    // Create new pointer to search
    LinkNodePtr current = h;

    while (current != nullptr) {
        if (current->number < min) {
            min = current->number;
        }
        // Move to next node
        current = current->link;
    }

    // Print smallest value found
    cout << "Smallest number in the list is: " << min << endl;
}