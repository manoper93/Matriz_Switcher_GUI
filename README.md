# WT32-SC01: Matriz Switcher Edition

This project is designed for the WT32-SC01 hardware and provides a matrix switcher system for managing button states using a touch-enabled display. It includes features such as EEPROM storage, touch control, and customizable button states.

---

## 🌟 **Project Objective**
The aim of this project is to create a dynamic interface using the WT32-SC01 for managing multiple buttons in a matrix layout. Key objectives include:

- Implementation of a capacitive touch system.
- Customizable button states with persistent storage.
- Integration with a TFT display for visualization and interaction.

---

## 📂 **Structure Overview**
### **Settings**
Key project settings include:
- **AUTO_SLEEP**: Enables or disables automatic sleep mode.
- **AUTO_SLEEP_TIME**: Defines the timeout for auto-sleep in milliseconds.
- **DELAY_TOUCH**: Sets the delay after each touch input in milliseconds.
- **COLOR_ON / COLOR_OFF**: Define the colors for active and inactive buttons.
- **ledBrightness**: Sets the backlight brightness level.

### **Libraries**
The following libraries are used in the project:
- **TFT_eSPI**: For managing the TFT display.
- **FT6236**: For capacitive touch control.
- **EEPROM**: For persistent storage.
- **SPI & Wire**: For communication.

### **Customizations**
- Button dimensions, spacing, and text size can be adjusted.
- Custom touch pins and backlight control pins.

---

## 🛠️ **Hardware Requirements**
- **WT32-SC01**: Primary hardware.
- **Capacitive Touchscreen**: Integrated with WT32-SC01.
- **TFT Display**: For visualizing the button matrix.

---

## 🔧 **Features Implemented**
1. **Matrix Button Layout**: A 3x4 grid of buttons with customizable states.
2. **Persistent Storage**: Saves and restores button states using EEPROM.
3. **Capacitive Touch Support**: Detects touch input and interacts with buttons.
4. **Dynamic TFT Interface**: Updates button colors and states dynamically.

---

## 📚 **Code Overview**
### **Key Functions**
#### Initialization
- `setup()`: Initializes the TFT display, touch controller, and EEPROM.
- `lcd()`: Sets up the TFT display and backlight.

#### Button Management
- `matriz()`: Draws the button matrix on the TFT display.
- `switch_color(button)`: Toggles the color and state of a button.
- `buttonpress(button)`: Handles button press events and updates states.

#### Storage Management
- `salvarNaEEPROM()`: Saves button states to EEPROM.
- `lerDaEEPROM()`: Reads button states from EEPROM.

#### Touch Interaction
- `loop()`: Main program loop for detecting touch input and managing button interactions.

---

## 🎯 **Next Steps**
- Implement additional button configurations.
- Add support for advanced touch gestures.
- Enhance power management features for longer uptime.

---

Thank you for exploring this project! 💡

---

## Photos

![1728915107769505817847876977442](https://github.com/user-attachments/assets/6583a2c2-4b0e-45c2-bec2-3bdb2cf4612f)
