# WEEK_1

## Topics Covered

### Networking & OSI Model
- Detailed explanation of all OSI Layers  
- Real-world protocol mapping (e.g., UDP at Transport Layer)  
- Packet transmission using sockets in C  

### C Programming Brush-up
- Pointers, arrays, structures  
- Function pointers and callback functions  
- Bitwise operations and byte packing  
- State machine implementation  
- Event-driven programming  

### Data Structures
- Queue  
- Linked List  
- Circular Buffer  

### Embedded Concepts
- RTOS, Superloop  
- Thread  
- Multithreading concepts  

---

## OSI Model (Open Systems Interconnection)

| Layer | Name         | Description                                   | Real-Time Protocols                                                  |
|-------|--------------|-----------------------------------------------|----------------------------------------------------------------------|
| 7     | Application  | Interface for end-user applications           | HTTP, FTP, SMTP, DNS, MQTT, chat apps, browsers                      |
| 6     | Presentation | Data formatting, encryption, compression      | SSL/TLS, ASCII, JPEG, MPEG, UTF-8                                    |
| 5     | Session      | Session control, connection setup/teardown    | NetBIOS, RPC, SIP, SMB                                               |
| 4     | Transport    | End-to-end delivery, reliability, flow control| TCP (Connection-Oriented), UDP (Connectionless), SCTP               |
| 3     | Network      | Logical addressing, routing                   | IP (IPv4/IPv6), ICMP, ARP, BGP, OSPF, RIP, IPSec                     |
| 2     | Data Link    | Node-to-node data transfer, error detection   | Ethernet, Wi-Fi (802.11), PPP, MAC, VLAN                             |
| 1     | Physical     | Transmission of raw bits over medium          | USB, Bluetooth, RS-232, Ethernet cables, Fiber optics, Wi-Fi signal  |

---

## Programs Implemented

### 1) Queue

A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle.

#### Queue Operations:
- `enqueue()` – Add element to the rear of the queue  
- `dequeue()` – Remove element from the front  
- `peek()` – View the front element without removing  
- `isFull()` – Check if the queue is full (for fixed-size array)  
- `isEmpty()` – Check if the queue is empty  

---

### 2) Linked List

A **Linked List** is a linear data structure where each node contains:

- Data (value)  
- Pointer to the next node  

Nodes are stored non-contiguously in memory, forming a chain.

#### Node Structure:
```c
struct Node {
    int data;
    struct Node* next;
};
##  Insertion at Beginning (Linked List)

This operation inserts a new node at the **beginning** of a singly linked list.

### ✅ Code:
```c
newNode = (struct Node*)malloc(sizeof(struct Node));  // allocate memory for new node  
newNode->data = value;                                // assign data to the new node  
newNode->next = head;                                 // link new node to current head  
head = newNode;                                       // update head to point to new node
## 4️⃣ Deletion from Beginning (Linked List)

This operation removes the **first node** of a singly linked list.

### 📌 Description:
To delete the first node:
1. Store the current head node in a temporary variable
2. Move the `head` pointer to the next node
3. Free the memory occupied by the old head

### ✅ Code:
```c
temp = head;           // store the current head node  
head = head->next;     // move head to the next node  
free(temp);            // free memory of the old head node  
## 5️⃣ Circular Buffer (using Queue)

A **Circular Buffer** (also called a **Ring Buffer**) is a fixed-size buffer that works like a queue, but **wraps around** when it reaches the end. It efficiently utilizes memory and is commonly used in embedded systems, real-time applications, and buffering data streams.

### 🔁 Operations:
- `enqueue()` – Add an element to the buffer  
- `dequeue()` – Remove an element from the buffer  
- `display()` – Show the current contents of the buffer  
- `peek()` – View the front element without removing it
## 6️⃣ State Machine (FSM)

This code implements a **Finite State Machine (FSM)** in C that simulates receiving and processing messages byte-by-byte.

It is commonly used in embedded systems and event-driven applications to model logical flows between different system states.

---

### 🔄 States:
- `STATE_WAIT_START` – Idle state; waits for the first byte of a message  
- `STATE_RECEIVING` – Collects remaining message bytes until `\n` is received  
- `STATE_PROCESSING` – Full message is received; triggers logic to process it  
- `STATE_SENDING_RESPONSE` – Sends a fixed response (e.g., `"Fine"`) and resets  

---

### ⚡ Events:
- `EVENT_BYTE_RECEIVED` – Triggered when a byte is received in `simulate_input()`  
- `EVENT_NONE` – Used internally to move from `PROCESSING → SENDING_RESPONSE → WAIT_START`  

