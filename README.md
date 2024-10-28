This project involves building a machine learning classification model to detect phishing websites using the Phishing Website dataset from the UC Irvine Machine Learning Repository. The trained model is converted to TensorFlow Lite (TFLite) format and ported to an ESP32 microcontroller for edge inference. This deployment is part of the IoT and Edge Computing course project.

Project Overview
Dataset: Phishing Website dataset from UC Irvine ML Library.
Objective: Classify websites as "phishing" or "legitimate" based on the dataset's features.
Output: A converted TFLite model deployed on ESP32 for real-time phishing detection.

Steps to Build and Deploy the Model
1. Dataset Selection and Preparation
Dataset Choice: Phishing Website dataset as per project guidelines.
Features and Classes: The dataset consists of features identifying website attributes, such as URL length, HTTPS usage, etc., with target labels for classification (phishing or legitimate).
Entry: Updated project’s dataset entry in the provided Excel sheet to confirm no clashes.
2. Data Preprocessing and Model Training
Load Data: Used Pandas to load and preprocess the CSV file.
Data Splitting: Split into training, testing, and validation sets.
Model Architecture: Built a neural network model in Python using TensorFlow/Keras.
Training: Trained the model to classify phishing websites, measuring accuracy and fine-tuning the model.
3. Model Conversion to TFLite
Convert to TFLite: After training, converted the model to TensorFlow Lite format using the TensorFlow Lite converter.
Optimization: Applied model quantization to reduce size, optimizing for ESP32's memory constraints.
Convert to C Header File: Generated a C header file (model.h) from the .tflite file using the xxd tool:
bash
Copy code
xxd -i phishing_model.tflite > model.h
Header Update: Added comments in the header file to document model information and input/output tensor details.
4. Deploying Model to ESP32
Code Development: Wrote ESP32-compatible code, including the TensorFlow Lite Micro library, to initialize the TFLite interpreter and load the model.
Input Data: Included sample inputs for testing, with known output classifications to verify inference accuracy.
Testing on ESP32: Loaded the header file and ran inference on the ESP32, checking the output to confirm accurate phishing classification.
5. Verification and Evaluation
Output Verification: Compared ESP32 inference outputs against expected results to validate model accuracy.
Evaluation Criteria: Model accuracy and inference speed were checked to ensure efficient performance on ESP32.

Tools and Libraries
Python Libraries: TensorFlow, Keras, Pandas, NumPy
Microcontroller Libraries: TensorFlow Lite Micro for ESP32
Dataset: Phishing Website dataset from UC Irvine ML Repository
