#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>
#include <sstream>

// Simulated GPS data structure
struct GPSData {
    double latitude;
    double longitude;
    double altitude;
};

// Function to get current timestamp as string
std::string getTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(now);
    std::tm* ptm = std::localtime(&tt);
    
    std::ostringstream oss;
    oss << std::put_time(ptm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// Function to get date for filename (e.g., "20250220")
std::string getDateForFilename() {
    auto now = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(now);
    std::tm* ptm = std::localtime(&tt);
    
    std::ostringstream oss;
    oss << std::put_time(ptm, "%Y%m%d");
    return oss.str();
}

// Simulate fetching GPS data (replace with real device input)
GPSData getRawGPSData() {
    static double lat = 37.7749; // Example starting point (San Francisco)
    static double lon = -122.4194;
    static double alt = 10.0;
    
    lat += 0.0001; // Simulate movement
    lon += 0.0001;
    alt += 0.1;
    
    return {lat, lon, alt};
}

// Write GPS data to CSV file
void writeToCSV(const GPSData& data, const std::string& timestamp) {
    std::string filename = "GPS_" + getDateForFilename() + ".csv";
    std::ofstream file(filename, std::ios::app); // Append mode
    
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    // Write header if file is new/empty
    if (file.tellp() == 0) {
        file << "Timestamp,Latitude,Longitude,Altitude\n";
    }
    
    // Write data
    file << timestamp << "," << data.latitude << "," << data.longitude << "," << data.altitude << "\n";
    
    file.close();
}

int main() {
    std::cout << "Starting GPS data logger...\n";
    
    while (true) {
        // Get raw GPS data
        GPSData data = getRawGPSData();
        
        // Get timestamp
        std::string timestamp = getTimestamp();
        
        // Write to CSV (simulates GPX-like data in CSV format)
        writeToCSV(data, timestamp);
        
        // Print to console for debugging
        std::cout << "Logged: " << timestamp << " | Lat: " << data.latitude 
                  << " | Lon: " << data.longitude << " | Alt: " << data.altitude << "\n";
        
        // Wait 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}
