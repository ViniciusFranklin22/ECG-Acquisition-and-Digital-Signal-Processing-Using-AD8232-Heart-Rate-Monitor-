# ECG Acquisition and Signal Processing Using AD8232 and Arduino

This repository presents the procedure and application for acquiring an electrocardiogram (ECG) signal using the AD8232 module with Arduino, followed by digital signal processing and feature extraction.

## Project Structure

### 1. Signal Acquisition with Arduino
- The `read_ecg.ino` file contains a simple Arduino sketch that reads ECG signals via ADC and sends them through the serial monitor.
- Sampling frequency is set to **500 Hz**, respecting the Nyquist criterion, since typical ECG signals do not exceed **250 Hz**.
- The sketch prints both ADC values and timestamps, allowing verification of sampling frequency and period.

### 2. Data Logging
- The `serial_monitor.ipynb` notebook reads serial data and writes it to a `data_ecg_2.csv` file.
- This step captures the raw signal for offline analysis.

### 3. Digital Signal Processing
- The raw ECG signal is noisy and distorted, requiring several DSP techniques for meaningful interpretation.
- These techniques are implemented in the Digital_Signal_Processing.ipynb notebook, where the data is both understood and processed to enhance signal quality and prepare it for feature extraction.
- Processing steps include:
  - Removal of DC component (mean).
  - Notch filter to eliminate power line interference.
  - Low-pass filter to remove high-frequency components.
  - Low-order moving average for smoothing.
- IIR filters with **zero-phase compensation** are used, which is feasible in offline processing since future samples are available.
- A comparison between standard IIR filtering and zero-phase filtering is included, highlighting the impact on peak preservation and waveform integrity (time domain).

> For real-time applications, using filter coefficients directly would require alternative strategies, such as introducing a delay to simulate access to future samples (semi real-time processing).

### 4. Feature Extraction
- The `feature_extraction.ipynb` notebook extracts key features from the filtered signal both in time and frequency domain, such as:
  - Amplitude Envelope
  - RMS
  - Zero Crossing Rate
  - Band Energy Ratio
  - Spectral Centroid
  - Bandwidth
  - Fundamental frequency


## Repository Contents

- `read_ecg.ino`: Arduino sketch for ECG signal acquisition via ADC and serial monitor.
- `serial_monitor.ipynb`: Reads serial data and saves it to `.csv`.
- The 'Digital_Signal_Processing.ipynb' notebook performs digital signal processing (DSP) directly on the acquired ECG signal.
- `feature_extraction.ipynb`: Applies DSP techniques and extracts features.
- `raw_data.csv`: Raw or filtered ECG data.
- `features.csv`: Table of extracted features.

## Notes

- You can use the `.csv` files directly for analysis without needing to acquire new data with Arduino.

## Future Work

- Implement real-time signal processing strategies, possibly using delayed buffering to simulate access to future samples.
- Explore classification techniques for detecting cardiac abnormalities (e.g., arrhythmias), using the extracted features as input for future machine learning models.
