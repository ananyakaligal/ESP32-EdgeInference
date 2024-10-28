// Course: IoT and Edge Computing: Oct 2024
// This is an IoT project by Ananya S Kaligal, USN: 1RVU22CSE023

#include <EloquentTinyML.h>
#include "PhishingWebsites_esp32.h"

#define NUMBER_OF_INPUTS 36  // Update this if you have a different number of inputs
#define NUMBER_OF_OUTPUTS 2   // Adjust based on your model's output
#define TENSOR_ARENA_SIZE 2*1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
    Serial.begin(115200);

    if (!ml.begin(PhishingWebsites_esp32)) {
        Serial.println("Failed to initialize the model.");
        while (1); // Halt execution
    }
}

float fResult[NUMBER_OF_OUTPUTS] = {0};
float fRes = NULL;

void loop() {
    // Example Input 1
    float input1[] = {0.0f, 0.1f, 0.2f, 0.3f, 0.0f, 1.0f, 0.0f, 0.5f, 0.7f, 0.9f,
                      0.4f, 0.8f, 0.1f, 0.6f, 0.2f, 0.3f, 0.0f, 1.0f, 
                      0.0f, 0.5f, 0.7f, 0.9f, 0.4f, 0.8f, 0.1f, 0.6f, 
                      0.2f, 0.3f, 0.0f, 1.0f, 0.0f, 0.5f, 0.7f, 0.9f, 
                      0.4f, 0.5f};  // 36 features

    // Example Input 2
    float input2[] = {1.0f, 0.1f, 0.2f, 0.4f, 0.3f, 0.0f, 0.2f, 0.5f, 0.8f, 0.6f,
                      0.1f, 0.3f, 0.9f, 0.0f, 0.5f, 0.8f, 0.1f, 0.0f, 
                      0.3f, 0.9f, 0.6f, 0.4f, 0.7f, 0.1f, 0.3f, 0.2f, 
                      0.0f, 1.0f, 0.3f, 0.4f, 0.5f, 0.6f, 0.2f, 0.1f, 
                      0.0f, 1.0f};  // Ensure this also has 36 features

    // Initialize result array
    initfResult(fResult);
    
    // Make predictions
    fRes = ml.predict(input1, fResult);
    Serial.print("\nThe output value returned for input1 is:\n");
    Serial.print("Output Class 1: ");
    Serial.print(fResult[0]);
    Serial.print(" Output Class 2: ");
    Serial.println(fResult[1]);
    displayOutput(fResult);  

    initfResult(fResult);
    fRes = ml.predict(input2, fResult);
    Serial.print("\nThe output value returned for input2 is:\n");
    Serial.print("Output Class 1: ");
    Serial.print(fResult[0]);
    Serial.print(" Output Class 2: ");
    Serial.println(fResult[1]);
    displayOutput(fResult);      

    delay(5000); // 5 seconds delay between predictions
}

void initfResult(float *fResult) {
    for (int i = 0; i < NUMBER_OF_OUTPUTS; i++) {
        fResult[i] = 0.0f;
    }
}

void displayOutput(float *fResult) {
    Serial.print("Output Values: ");
    for (int i = 0; i < NUMBER_OF_OUTPUTS; i++) {
        Serial.print(fResult[i]);
        Serial.print(" ");
    }
    Serial.println();
}

