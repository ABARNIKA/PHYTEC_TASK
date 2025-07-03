# WEEK_1

## Topics Covered

###  Networking & OSI Model
- Detailed explanation of all OSI Layers  
- Real-world protocol mapping (e.g., UDP at Transport Layer)  
- Packet transmission using sockets in C  

###  C Programming Brush-up
- Pointers, arrays, structures  
- Function pointers and callback functions  
- Bitwise operations and byte packing  
- State machine implementation  
- Event-driven programming  

###  Data Structures
- Queue  
- Linked List  
- Circular Buffer  

###  Embedded Concepts
- RTOS, Superloop  
- Thread  
- Multithreading concepts  

---

##  OSI Model (Open Systems Interconnection)

| Layer | Name         | Description                                   | Real-Time Protocols                                                  |
|-------|--------------|-----------------------------------------------|----------------------------------------------------------------------|
| 7     | Application  | Interface for end-user applications           | HTTP, FTP, SMTP, DNS, MQTT, chat apps, browsers                      |
| 6     | Presentation | Data formatting, encryption, compression      | SSL/TLS, ASCII, JPEG, MPEG, UTF-8                                    |
| 5     | Session      | Session control, connection setup/teardown    | NetBIOS, RPC, SIP, SMB                                               |
| 4     | Transport    | End-to-end delivery, reliability, flow control| TCP (Connection-Oriented), UDP (Connectionless), SCTP               |
| 3     | Network      | Logical addressing, routing                   | IP (IPv4/IPv6), ICMP, ARP, BGP, OSPF, RIP, IPSec                     |
| 2     | Data Link    | Node-to-node data transfer, error detection   | Ethernet, Wi-Fi (802.11), PPP, MAC, VLAN                             |
| 1     | Physical     | Transmission of raw bits over medium          | USB, Bluetooth, RS-232, Ethernet cables, Fiber optics, Wi-Fi signal |

---

##  Programs Implemented

###  Queue
A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle.

#### Queue Operations:
- `enqueue()` – Add element to the rear of the queue  
- `dequeue()` – Remove element from the front  
- `peek()` – View the front element without removing  
- `isFull()` – Check if the queue is full (only for fixed-size array)  
- `isEmpty()` – Check if the queue is empty  

---

### 2 Linked List
A **Linked List** is a linear data structure in which each element (called a node) contains:

- Data (value to store)  
- Pointer (reference to the next node)  

Unlike arrays, linked lists do not store data in contiguous memory. Each node points to the next, forming a chain.

#### Node Creation:
```c
struct Node {
    int data;
    struct Node* next;
};

####  Insertion at Beginning:

newNode = (struct Node*)malloc(sizeof(struct Node));  // allocate memory for new node  
newNode->data = value;                                // assign data to the new node  
newNode->next = head;                                 // link new node to current head  
head = newNode;                                       // update head to point to new node
### 3)Circular Buffer (using Queue)

A **Circular Buffer (Ring Buffer)** is a fixed-size buffer that wraps around when it reaches the end, working like a queue.

####  Operations:
- enqueue() – Add element to the buffer  
- dequeue() – Remove element from the buffer  
- display() – Show current buffer content  
- peek() – View the front element without removing  
### 4️) State Machine

This code implements a **Finite State Machine (FSM)** in C that simulates receiving and processing messages byte-by-byte.

####  States:
- STATE_WAIT_START – Idle state, waits for the first byte of a message  
- `STATE_RECEIVING` – Collects message bytes until `\n` is received  
- `STATE_PROCESSING` – Triggers logic to process the complete message  
- `STATE_SENDING_RESPONSE` – Sends a response (e.g., `"Fine"`) and resets  

####  Events:
- `EVENT_BYTE_RECEIVED` – Triggered when a byte is received  
- `EVENT_NONE` – Used internally to step through states  
