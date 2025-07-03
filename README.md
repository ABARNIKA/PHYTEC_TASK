WEEK_1
Topics Covered

 Networking & OSI Model
- Detailed explanation of all OSI Layers
- Real-world protocol mapping (e.g., UDP at Transport Layer)
- Packet transmission using sockets in C
 C Programming Brush-up
- Pointers, arrays, structures
- Function pointers and callback functions
- Bitwise operations and byte packing
- State machine implementation
- Event-driven programming
Data Structures
- Queue
- Linked List
- Circular Buffer
 Embedded Concepts
- RTOS , Superloop
- Thread
- Multithreading concepts

OSI Model(Open Systems Interconnection)
7 - Application	Interface for end-user applications	.  Real-Time Protocol:HTTP, FTP, SMTP, DNS, MQTT, chat apps, browsers
6 - Presentation	Data formatting, encryption, compression.  Real-Time Protocol:	SSL/TLS, ASCII, JPEG, MPEG, UTF-8
5 - Session	Session control, connection setup/teardown.	 Real-Time Protocol:NetBIOS, RPC, SIP, SMB
4 - Transport	End-to-end delivery, reliability, flow control	. Real-Time Protocol:TCP(Connection-Oriented), UDP(Connectionless), SCTP
3 - Network	Logical addressing, routing	.  Real-Time Protocol:IP (IPv4/IPv6), ICMP, ARP, BGP, OSPF, RIP, IPSec
2 - Data Link	Node-to-node data transfer, error detection	. Real-Time Protocol:Ethernet, Wi-Fi (802.11), PPP, MAC, VLAN
1 - Physical	Transmission of raw bits over medium.  Real-Time Protocol:	USB, Bluetooth, RS-232, Ethernet cables, Fiber optics, Wi-Fi signal
Programs Implemented:
1) Queue:
   A queue is a linear data structure that follows the FIFO (First In, First Out) principle.
Queue Operations:
 enqueue() - Adds (inserts) an element to the rear of the queue
 dequeue() - Removes an element from the front of the queue
 peek() - Returns the element at the front without removing it
 isFull() - Checks if the queue is full (only for arrays with fixed size)
 isEmpty() -Checks if the queue is empty
2) Linked List:
     A Linked List is a linear data structure in which each element (called a node) contains:

         * Data (value to store)
         * Pointer (reference to the next node)
     linked lists do not store data in contiguous memory locations. Each node points to the next, forming a chain.
Node Creation:
   struct Node {
       int data;
   struct Node* next;
   };
Insertion(beginning,mid,end):
  newNode = (struct Node*)malloc(sizeof(struct Node));  // allocate memory for new node
  newNode->data = value;                                // assign data to the new node
  newNode->next = head;                                 // link new node to current head
  head = newNode;                                       // update head to point to new node  
Deletion(beginning,mid,end):
  temp = head;           // store the current head node
  head = head->next;     // move head to the next node
  free(temp);            // free memory of the old head node
4) Circuler Buffer:
    A Circular Buffer (or Ring Buffer) is a fixed-size buffer that works like a queue but wraps around when it reaches the end.
    It perform some operations like a enqueue(),dequeue(),display(),peek().
5) State Machine:

     This code implements a Finite State Machine (FSM) in C that simulates receiving and processing messages byte-by-byte.
   STATE_WAIT_START - Idle state, waits for the first byte of a message
   STATE_RECEIVING - Collects the rest of the message bytes until \n is received
   STATE_PROCESSING - Message is fully received → triggers processing logic
   STATE_SENDING_RESPONSE - Sends a fixed response (e.g., "Fine") → then resets for the next message
Events:
   EVENT_BYTE_RECEIVED	Triggered when a byte is received in simulate_input()
   EVENT_NONE	Used manually to step from PROCESSING → SENDING_RESPONSE → WAIT_START


   
  

