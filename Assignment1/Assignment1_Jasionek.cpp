#include <iostream>
#include <vector>
#include <string>
//#include <algorithm> ...iterating is ok

// A simple device is a device with a property of being in an ON or OFF state
class SimpleDevice { 
private:
    int m_deviceID{ }; // ID of a particular device
    bool m_isDeviceOn{ }; // Is a particular device on? y or n
public:
    // We need to instantiate objects within this class with certain properties
    SimpleDevice(int id) : m_deviceID(id), m_isDeviceOn(false) { } 
    // We also want to be able to destruct objects
    ~SimpleDevice() = default; 

    // We want to be able to turn off and on the device, since this is the main functionality
    void turnOnDevice() { m_isDeviceOn = true; }
    void turnOffDevice() { m_isDeviceOn = false; }
    
    // We also want to check the status and ID of a device
    bool isDeviceOn() const { return m_isDeviceOn; } 
    int getDeviceID() const { return m_deviceID; } 
};

// We also anticipate components of a complex device, with special properties; a ComplexDevice has a DeviceComponent(s)
class DeviceComponent { 
private:
    // A component has a name, e.g. Motor and we want to know if it is functional and why it failed
    std::string m_componentName; 
    bool m_functional; 
    std::string m_failureReason; 
public:
    // If we want to create a member, with a name, status (is it functional?)
    DeviceComponent(const std::string& name, bool m_status = false) : m_componentName(name), m_functional(m_status), m_failureReason("") {}

    // Method to set the component's functionality m_status with a reason e.g. motor is overheating
    void setFunctional(bool m_status, const std::string& reason = "") {
        m_functional = m_status;
        if (!m_status && reason.empty()) {
            m_failureReason = "Device is probably off";
        }
        else {
            m_failureReason = reason;
        }
    }
    // Methods to check if the component is functional, get the component's name, get the failure reason
    bool isFunctional() const { return m_functional; }
    std::string getComponentName() const { return m_componentName; }
    std::string getFailureReason() const { return m_failureReason; }
};

// A ComplexDevice is a SimpleDevice (not really but they have same principle functionality)
class ComplexDevice : public SimpleDevice {
private:
    // m_deviceInfo just shows that a complex device might need more information than just an ID
    int m_deviceInfo{};
    // ComplexIoTDevice has DeviceComponents, we organize this in a vector
    std::vector<DeviceComponent> m_components; 

public:
    // Constructor
    ComplexDevice(int id, int info) : SimpleDevice(id), m_deviceInfo(info) {}

    // Method to get device information
    int getDeviceInfo() const { return m_deviceInfo; }

    // Method to add a component to the device
    void addComponent(const DeviceComponent& component) {
        m_components.push_back(component);
    }

    // Method to list all components of the device
    void listComponents() const {
        std::cout << "Components of device " << getDeviceID() << ":\n";
        for (const auto& comp : m_components) { // auto for modularity, other classes than DeviceComponents might be made in the future
            std::cout << "- " << comp.getComponentName() // Lists each component (in a bullet point fashion)
                << " (Functional: " << (comp.isFunctional() ? "Yes" : "No") << ")";
            if (!comp.isFunctional()) {
                std::cout << " [Reason: " << comp.getFailureReason() << "]";
            }
            std::cout << "\n";
        }
    }

    // Method to set the functionality status of a specific component
    void setComponentStatus(const std::string& name, bool m_status, const std::string& reason = "") {
        for (DeviceComponent& comp : m_components) {
            if (comp.getComponentName() == name) { // iterates through devices until a match is found
                comp.setFunctional(m_status, reason);
                break;
            }
        }
    }

    // Method to check if all components are m_functional
    bool areAllComponentsFunctional() const {
        for (const DeviceComponent& comp : m_components) {
            if (!comp.isFunctional()) return false;
        }
        return true;
    }

    // Method to update the device m_status based on m_components' functionality.
    // Assumes that if a component within a complex device is not on, we want
    // to turn off the whole device; like the extruder not working for a 3D printer.
    void updateDeviceStatus() {
        if (areAllComponentsFunctional()) {
            turnOnDevice();
        }
        else {
            turnOffDevice();
        }
    }

    // Methods to turn on and off the complex device and update component states accordingly if components are dependent
    void turnOnComplexDevice() {
        turnOnDevice();
        for (auto& comp : m_components) {
            comp.setFunctional(true);
        }
    }

    void turnOffComplexDevice() {
        turnOffDevice();
        for (auto& comp : m_components) {
            comp.setFunctional(false);
        }
    }
};

/*
* Note to instructor: 
* 
* Program is a device manager, maybe this manages IOT devices or a more complex system.
* There is a base SimpleDevice class, with the basic functionality of being off or on,
* this might be a light switch, or a fan.
* 
* There is a ComplexDevice class that inherits from SimpleDevice, the idea here is that a
* device can have more moving parts than just being on, like a 3D printer that has motors, 
* heating elements, etc.
* 
* These complex devices are made up of components, which are members of the component class.
* Again, for a 3D printer, this might be a heating element.
* 
* IDs for simple or complex devices are listed in choice (4), there are some default devices
* I made as a demo. Note, checking the components status on instantiation is ambiguous.
*/


int main() {
    // Vector to store devices
    std::vector<ComplexDevice> complexDevices;
    std::vector<SimpleDevice> simpleDevices;

    // DEMO:
    SimpleDevice lights(42);
    simpleDevices.push_back(lights);
    ComplexDevice ThreeDprinter(1, 333);
    ThreeDprinter.addComponent(DeviceComponent("motor"));
    ThreeDprinter.addComponent(DeviceComponent("heating element"));
    ThreeDprinter.addComponent(DeviceComponent("raspberry pi"));
    complexDevices.push_back(ThreeDprinter);


    // Fancy formatting
    while (true) {
        std::cout << "---------------------------------------\n";
        std::cout << "\n=== Device Management Terminal ===\n";
        std::cout << "1. Create Simple Device\n";
        std::cout << "2. Create Complex Device\n";
        std::cout << "3. Create Complex Device Component\n";
        std::cout << "4. List Devices\n";
        std::cout << "5. List Complex Device Components\n";
        std::cout << "6. Simulate Component Failure\n";
        std::cout << "7. Repair Component\n";
        std::cout << "8. Turn On/Off Device\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter choice: ";
        int choice{ };
        std::cin >> choice;
        std::cout << "---------------------------------------\n";

        // Clear input buffer (input like '\' causes failed state, clear and reset input buffer)
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input. Please enter a number between 1 and 8.\n";
            continue;
        }
        
        // Choices in the menu, and their respective consequences:
        switch (choice) {
        case 1: { // Create simple device
            int deviceID;
            std::cout << "Enter Simple Device ID (int): ";
            std::cin >> deviceID;
            SimpleDevice simpleDevice(deviceID);

            char action;
            std::cout << "Turn device on (o) or off (f): ";
            std::cin >> action;
            if (action == 'o') {
                simpleDevice.turnOnDevice();
            }
            else if (action == 'f') {
                simpleDevice.turnOffDevice();
            }

            simpleDevices.push_back(simpleDevice);
            std::cout << "Simple Device " << simpleDevice.getDeviceID() << " created and is " << (simpleDevice.isDeviceOn() ? "On" : "Off") << "\n";
            break;
        }
        case 2: { // Create complex device
            int deviceID, deviceInfo;
            std::cout << "Enter Complex Device ID (int): ";
            std::cin >> deviceID;
            std::cout << "Enter additional device info (int): ";
            std::cin >> deviceInfo;
            ComplexDevice complexDevice(deviceID, deviceInfo);
            complexDevices.push_back(complexDevice);
            std::cout << "Complex Device " << deviceID << " created with additional info: " << deviceInfo << "\n";
            break;
        }
        case 3: { // Create component to complex device
            int deviceID;
            std::cout << "Enter Complex Device ID (int): ";
            std::cin >> deviceID;

            bool found = false;
            for (auto& device : complexDevices) {
                if (device.getDeviceID() == deviceID) {
                    std::string componentName;
                    std::cout << "Enter Component Name (str): ";
                    std::cin >> componentName;
                    device.addComponent(DeviceComponent(componentName));
                    std::cout << "Component " << componentName << " added to Complex Device.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Complex Device with ID " << deviceID << " not found.\n";
            }
            break;
        }
        case 4: { // List devices
            for (const auto& device : simpleDevices) {
                std::cout << "Simple Device ID: " << device.getDeviceID() << " is " << (device.isDeviceOn() ? "On" : "Off") << "\n";
            }
            for (const auto& device : complexDevices) {
                std::cout << "Complex Device ID: " << device.getDeviceID() << " is " << (device.isDeviceOn() ? "On" : "Off") << "\n";
            }
            break;
        }
        case 5: { // List components of complex device
            int deviceID;
            std::cout << "Enter Complex Device ID (int): ";
            std::cin >> deviceID;

            bool found = false;
            for (const auto& device : complexDevices) {
                if (device.getDeviceID() == deviceID) {
                    device.listComponents();
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Complex Device with ID " << deviceID << " not found.\n";
            }
            break;
        }
        case 6: { // Simulate component failure
            int deviceID;
            std::cout << "Enter Complex Device ID (int): ";
            std::cin >> deviceID;

            bool found = false;
            for (auto& device : complexDevices) {
                if (device.getDeviceID() == deviceID) {
                    std::string componentName;
                    std::cout << "Enter Component Name to Fail (str): ";
                    std::cin >> componentName;
                    device.setComponentStatus(componentName, false, "Simulated failure");
                    device.updateDeviceStatus();
                    std::cout << "Component " << componentName << " marked as failed.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Complex Device with ID " << deviceID << " not found.\n";
            }
            break;
        }
        case 7: { // Simulate component repair
            int deviceID;
            std::cout << "Enter Complex Device ID (int): ";
            std::cin >> deviceID;

            bool found = false;
            for (auto& device : complexDevices) {
                if (device.getDeviceID() == deviceID) {
                    std::string componentName;
                    std::cout << "Enter Component Name to Repair (str): ";
                    std::cin >> componentName;
                    device.setComponentStatus(componentName, true);
                    device.updateDeviceStatus();
                    std::cout << "Component " << componentName << " repaired.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Complex Device with ID " << deviceID << " not found.\n";
            }
            break;
        }
        case 8: { // Turn off or on device
            int deviceID;
            std::cout << "Enter Device ID (int): ";
            std::cin >> deviceID;

            bool found = false;
            for (auto& device : simpleDevices) {
                if (device.getDeviceID() == deviceID) {
                    char action;
                    std::cout << "Turn device on (o) or off (f): ";
                    std::cin >> action;
                    if (action == 'o') {
                        device.turnOnDevice();
                    }
                    else if (action == 'f') {
                        device.turnOffDevice();
                    }
                    std::cout << "Simple Device " << device.getDeviceID() << " is now " << (device.isDeviceOn() ? "On" : "Off") << "\n";
                    found = true;
                    break;
                }
            }
            for (auto& device : complexDevices) {
                if (device.getDeviceID() == deviceID) {
                    char action;
                    std::cout << "Turn device on (o) or off (f): ";
                    std::cin >> action;
                    if (action == 'o') {
                        device.turnOnComplexDevice();
                    }
                    else if (action == 'f') {
                        device.turnOffComplexDevice();
                    }
                    std::cout << "Complex Device " << device.getDeviceID() << " is now " << (device.isDeviceOn() ? "On" : "Off") << "\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Device with ID " << deviceID << " not found.\n";
            }
            break;
        }
        case 9: { // exit program
            return 0;
        }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    }

    return 0;
}