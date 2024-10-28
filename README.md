# Phishing Website Classification Model on ESP32

This project involves building a machine learning classification model to detect phishing websites using the Phishing Websites dataset from the UC Irvine ML Repository. The trained model is converted to TensorFlow Lite (TFLite) format and ported to an ESP32 microcontroller for edge inference.

## Steps to Build and Deploy (Summary)

1. **Dataset Selection**: 
   - Selected the Phishing Website dataset.
   - Logged the dataset in the provided Excel sheet per course guidelines.

2. **Preprocessing & Model Training**:
   - Loaded and cleaned data with Pandas.
   - Split data into training, testing, and validation sets.
   - Built and trained a neural network model using TensorFlow/Keras.

3. **Model Conversion to TFLite**:
   - Converted the trained model to TFLite format.
   - Applied quantization to reduce model size for ESP32.
   - Generated a C header file (`model.h`) using the `xxd` tool:
     ```bash
     xxd -i phishing_model.tflite > model.h
     ```

4. **Deployment on ESP32**:
   - Developed ESP32 code using the TensorFlow Lite Micro library to load and run the model.
   - Included sample input data for inference testing.
   - Verified inference outputs on ESP32 for accuracy in phishing classification.

## Tools and Libraries
- **Python**: TensorFlow, Keras, Pandas, NumPy
- **Microcontroller Libraries**: TensorFlow Lite Micro for ESP32
- **Dataset**: [Phishing Website dataset from UC Irvine ML Repository](https://archive.ics.uci.edu/dataset/327/phishing+websites)
