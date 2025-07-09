#include <stdio.h>

// Enum for different states in the system
typedef enum {
    IDLE,          // System is idle, waiting for an event
    SENDING,       // Message has been sent, waiting for ACK
    WAITING_ACK,   // (Unused in this code, could be added if needed)
    RECEIVING      // Receiving a message from another node
} State;

// Enum for different events that can occur
typedef enum {
    EV_SEND_REQUEST,   // Event to initiate sending a message
    EV_MSG_ARRIVED,    // Event when a message is received
    EV_ACK_RECEIVED,   // Event when an ACK is received
    EV_TIMEOUT         // Event when timeout occurs
} Event;

// Global variable to track the current state
State current_state = IDLE;

// Action function: Simulates sending a message
void send_message() {
    printf("[Action] Sending message...\n");
}

// Action function: Simulates waiting for ACK (not explicitly used here)
void wait_for_ack() {
    printf("[Action] Waiting for ACK...\n");
}

// Action function: Simulates processing a received message
void process_incoming_message() {
    printf("[Action] Processing incoming message...\n");
}

// Action function: Called when timeout happens; resets state to IDLE
void reset_to_idle() {
    printf("[Action] Timeout occurred. Returning to IDLE...\n");
}

// Event handler: Transitions state based on current state and incoming event
void handle_event(Event ev) {
    switch (current_state) {
        case IDLE:
            if (ev == EV_SEND_REQUEST) {
                send_message();             // Trigger send action
                current_state = SENDING;   // Move to SENDING state
            } else if (ev == EV_MSG_ARRIVED) {
                process_incoming_message(); // Process the message
                current_state = RECEIVING;  // Move to RECEIVING state
            }
            break;

        case SENDING:
            if (ev == EV_ACK_RECEIVED) {
                printf("[Info] ACK received. Going to IDLE.\n");
                current_state = IDLE;       // ACK received, back to IDLE
            } else if (ev == EV_TIMEOUT) {
                reset_to_idle();            // Timeout handling
                current_state = IDLE;
            }
            break;

        case RECEIVING:
            if (ev == EV_ACK_RECEIVED) {
                printf("[Info] Message received and acknowledged.\n");
                current_state = IDLE;       // Message processed, back to IDLE
            }
            break;

        default:
            printf("[Error] Unknown state!\n");
            break;
    }
}

// Function to simulate event triggering from main()
void simulate_event(Event ev) {
    printf("\n[Event Triggered] ");
    switch (ev) {
        case EV_SEND_REQUEST:  printf("Send Request\n"); break;
        case EV_MSG_ARRIVED:   printf("Message Arrived\n"); break;
        case EV_ACK_RECEIVED:  printf("ACK Received\n"); break;
        case EV_TIMEOUT:       printf("Timeout\n"); break;
    }

    // Call the handler with the triggered event
    handle_event(ev);
}

int main() {
    // Simulating various events to test the state machine

    simulate_event(EV_SEND_REQUEST);   // Send a message → IDLE → SENDING
    simulate_event(EV_ACK_RECEIVED);   // ACK received → SENDING → IDLE
    simulate_event(EV_MSG_ARRIVED);    // Message arrived → IDLE → RECEIVING
    simulate_event(EV_ACK_RECEIVED);   // ACK after receiving → RECEIVING → IDLE
    simulate_event(EV_SEND_REQUEST);   // Send again → IDLE → SENDING
    simulate_event(EV_TIMEOUT);        // Timeout occurred → SENDING → IDLE

    return 0;
}

