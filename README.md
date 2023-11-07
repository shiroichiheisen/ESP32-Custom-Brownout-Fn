# ESP32 Custom Brownout Handler Library

This library provides a way to integrate a custom brownout handler function for ESP32 devices, enhancing system stability during voltage dips. It's compatible with both the ESP-IDF and Arduino development frameworks.

## Features
- **Customizable Brownout Handling**: Tailor the response to brownout conditions with your own function.
- **Optimized for Real-Time Execution**: Use the `IRAM_ATTR` to ensure the handler is in IRAM for quick execution.
- **Framework Compatibility**: Works with both ESP-IDF and Arduino setups.

## How to Install

For ESP-IDF, clone this repository into your `components` directory. For Arduino, include the library in your project's libraries directory.

## How to Use

Before you use the library, ensure you have included the `esp_attr.h` header to enable the use of `IRAM_ATTR`.

Here's how to set up your custom brownout handler:

### With ESP-IDF:

```c
#include "esp_attr.h"
#include "ESP32_Custom_Brownout_Handler.h"

// Define your custom brownout handler function with IRAM_ATTR
IRAM_ATTR void custom_brownout_handler() {
    // Custom logic for handling brownout conditions
}

void app_main() {
    // Initialize the custom brownout handler
    ESP32_Custom_Brownout_Fn(custom_brownout_handler);
    // Rest of your setup code
}
```

### With Arduino:

```c
#include "esp_attr.h"
#include "ESP32_Custom_Brownout_Handler.h"

// Global instance of the custom brownout handler
IRAM_ATTR void custom_brownout_handler() {
    // Custom logic for handling brownout conditions
}

// Initialize with your custom handler
ESP32_Custom_Brownout_Fn customBrownoutHandler(custom_brownout_handler);

void setup() {
    // Your setup code here
}

void loop() {
    // Main code loop
}

```

### Global Instance:

You may also declare the handler globally if you prefer:

```c
#include "esp_attr.h"
#include "ESP32_Custom_Brownout_Handler.h"

// Global instance of the custom brownout handler
IRAM_ATTR void custom_brownout_handler() {
    // Custom logic for handling brownout conditions
}

// Initialize with your custom handler
ESP32_Custom_Brownout_Fn customBrownoutHandler(custom_brownout_handler);

void setup() {
    // Your setup code here
}

void loop() {
    // Main code loop
}
```

Remember that the function you pass to `ESP32_Custom_Brownout_Fn` must be marked with `IRAM_ATTR` to ensure that it's placed in IRAM for faster execution which is critical during brownout conditions.