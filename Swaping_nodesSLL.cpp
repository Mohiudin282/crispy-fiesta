struct IntSLLNode {
    int info;
    IntSLLNode* next;
};

void swapNodes(IntSLLNode*& head, IntSLLNode*& tail, IntSLLNode* node1, IntSLLNode* node2) {
    if (node1 == node2) {
        return;
    }

    IntSLLNode* prevNode1 = nullptr;
    IntSLLNode* prevNode2 = nullptr;
    IntSLLNode* current = head;

    while (current != nullptr) {
        if (current->next == node1) {
            prevNode1 = current;
        } else if (current->next == node2) {
            prevNode2 = current;
        }

        current = current->next;
    }

    if (prevNode1 != nullptr) {
        prevNode1->next = node2;
    } else {
        head = node2;
    }

    if (prevNode2 != nullptr) {
        prevNode2->next = node1;
    } else {
        head = node1;
    }

    IntSLLNode* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    // Update tail if necessary
    if (node2->next == nullptr) {
        tail = node2;
    } else if (node1->next == nullptr) {
        tail = node1;
    }
}

void sortLinkedList(IntSLLNode*& head, IntSLLNode*& tail) {
    if (head == nullptr || head->next == nullptr) {
        return; // Already sorted or empty list
    }

    IntSLLNode* current = head;

    while (current != nullptr) {
        IntSLLNode* minNode = current;
        IntSLLNode* temp = current->next;

        while (temp != nullptr) {
            if (temp->info < minNode->info) {
                minNode = temp;
            }

            temp = temp->next;
        }

        swapNodes(head, tail, current, minNode);
        current = minNode->next;
    }
}