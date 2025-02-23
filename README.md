# GPSreader
Project to read GPS NMEA data from a GPS chip and write it to a file

TODO:
** Replace getRawGPSData() with an actual NMEA function like:

GPSData parseNMEAGGA(const std::string& nmea) {
    // Example: $GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47
    // Parse latitude, longitude, altitude from NMEA string
    // This is a placeholder—use a real NMEA parser library
    return {48.1173, 11.5167, 545.4}; // Dummy values
}

** Integrate a library such as Boost.Asio to allow for live data instead of sample data
