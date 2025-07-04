# 📘 Week 1 - Embedded Systems & Networking Foundations

## 📚 Topics Covered

### 🛰 Networking & OSI Model
- Detailed explanation of all *OSI Layers*
- Real-world protocol mapping (e.g., *UDP* at Transport Layer)
- Packet transmission using *Sockets in C*

### 💻 C Programming Brush-up
- *Pointers, Arrays, Structures*
- *Function Pointers* and *Callback Functions*
- *Bitwise Operations* and *Byte Packing*
- *State Machine Implementation*
- *Event-Driven Programming*

### 📐 Data Structures
- *Queue*
- *Linked List*
- *Circular Buffer*

### ⚙ Embedded Concepts
- *RTOS, **Superloop*
- *Threading & Multithreading Concepts*

---

## 🗂 OSI Model (Open Systems Interconnection)

| Layer | Name         | Description                                 | Real-Time Protocols / Examples                             |
|-------|--------------|---------------------------------------------|-------------------------------------------------------------|
| 7     | Application  | Interface for end-user applications         | HTTP, FTP, SMTP, DNS, MQTT, Chat Apps, Browsers            |
| 6     | Presentation | Data formatting, encryption, compression    | SSL/TLS, ASCII, JPEG, MPEG, UTF-8                          |
| 5     | Session      | Session control, connection setup/teardown | NetBIOS, RPC, SIP, SMB                                     |
| 4     | Transport    | End-to-end delivery, reliability, flow ctrl | TCP (Connection-Oriented), UDP (Connectionless), SCTP      |
| 3     | Network      | Logical addressing, routing                 | IP (IPv4/IPv6), ICMP, ARP, BGP, OSPF, RIP, IPSec           |
| 2     | Data Link    | Node-to-node data transfer, error detection | Ethernet, Wi-Fi (802.11), PPP, MAC, VLAN                   |
| 1     | Physical     | Transmission of raw bits over medium        | USB, Bluetooth, RS-232, Ethernet Cables, Fiber, Wi-Fi Sig. |

---

## 🧪 Programs Implemented

### 1️⃣ Queue

A *Queue* is a linear data structure that follows the *FIFO (First In, First Out)* principle.

*Queue Operations:*
- enqueue() – Adds (inserts) an element to the rear of the queue
- dequeue() – Removes an element from the front of the queue
- peek() – Returns the element at the front without removing it
- isFull() – Checks if the queue is full (for fixed size arrays)
- isEmpty() – Checks if the queue is empty

---

### 2️⃣ Linked List

A *Linked List* is a linear data structure where each element (node) contains:
- data – the value to store
- next – a pointer to the next node

Linked lists do *not* store data in contiguous memory locations. Each node points to the next forming a chain.

This program provides:
- Node creation
- Insertion at the beginning
- Deletion from the beginning

---

### 3️⃣ Circular Buffer

A *Circular Buffer (Ring Buffer)* is a fixed-size buffer that works like a queue but wraps around when it reaches the end.

*Operations Implemented:*
- enqueue()
- dequeue()
- display()
- peek()

---

### 4️⃣ State Machine

This program implements a *Finite State Machine (FSM)* in C that simulates receiving and processing messages byte-by-byte.

*States:*
- STATE_WAIT_START – Idle state, waits for the first byte of a message
- STATE_RECEIVING – Collects the message bytes until a newline \n is received
- STATE_PROCESSING – Once a message is received → triggers processing logic
- STATE_SENDING_RESPONSE – Sends a fixed response (e.g., "Fine") and resets

*Events:*
- EVENT_BYTE_RECEIVED – Triggered when a byte is received in simulate_input()
- EVENT_NONE – Used manually to step from PROCESSING → SENDING_RESPONSE → WAIT_START

---

## 🛠 Tools & Languages Used
- *Programming Language:* C
- *Environment:* GCC / Linux Terminal
- *Concepts Practiced:* Data Structures, RTOS, Socket Programming, Event Handling, FSM

---

