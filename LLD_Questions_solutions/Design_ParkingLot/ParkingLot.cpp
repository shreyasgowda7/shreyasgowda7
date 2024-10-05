/* Enumerations and custom data type */

// Enumeration
enum PaymentStatus {
  COMPLETED, 
  FAILED, 
  PENDING, 
  UNPAID, 
  REFUNDED
};

enum AccountStatus {
  ACTIVE, 
  CLOSED, 
  CANCELED, 
  BLACKLISTED, 
  NONE
};

// Custom Person data type class
class Person {
  private:
    string name;
    string address;
    string phone;
    string email;
};

// Custom Address data type class
class Address {
  private:
    int zipCode;
    string address;
    string city;
    string state;
    string country;
};


// Parking spots

// ParkingSpot is an abstract class
class ParkingSpot {
  private:
    int id;
    bool isFree;
    Vehicle vehicle; 

  public:
    bool isFree(); 
    virtual bool assignVehicle(Vehicle vehicle) = 0; 
    bool removeVehicle(){
      // definition
    } 
};

class Handicapped : public ParkingSpot {
  public:
    bool assignVehicle(Vehicle vehicle) {
        // definition
    }
};

class Compact : public ParkingSpot {
  public:
    bool assignVehicle(Vehicle vehicle) {
        // definition
    }
};

class Large : public ParkingSpot {
  public: 
    bool assignVehicle(Vehicle vehicle) {
        // definition
    }
};

class Motorcycle : public ParkingSpot {
  public: 
    bool assignVehicle(Vehicle vehicle) {
        // definition
    }
};


// Vehicle

// Vehicle is an abstract class
class Vehicle {
  private:
    string licenseNo;

  public:
    void virtual assignTicket(ParkingTicket ticket) = 0; 
};

class Car : public Vehicle {
  public:
    void assignTicket(ParkingTicket ticket) {
        // definition
    } 
};

class Van : public Vehicle {
  public:
    void assignTicket(ParkingTicket ticket) {
        // definition
    } 
};

class Truck : public Vehicle {
  public:
    void assignTicket(ParkingTicket ticket) {
        // definition
    } 
};

class MotorCycle : public Vehicle {
  public:
    void assignTicket(ParkingTicket ticket) {
        // definition
    } 
};

// Account

class Account {
  // Data members
  private: 
    string userName;
    string password;
    Person person; // Refers to an instance of the Person class
    AccountStatus status; // Refers to the AccountStatus enum

  public:
    virtual bool resetPassword() = 0;
}

class Admin : public Account {
  public: 
    // spot here refers to an instance of the ParkingSpot class
    bool addParkingSpot(ParkingSpot spot);
    // displayBoard here refers to an instance of the DisplayBoard class
    bool addDisplayBoard(DisplayBoard displayBoard);
    // entrance here refers to an instance of the Entrance class
    bool addEntrance(Entrance entrance);
    // exit here refers to an instance of the Exit class
    bool addExit(Exit exit;
  
    // Will implement the functionality in this class
    bool resetPassword() {
      // definition
    }
}

class ParkingAttendant : public Account {
  public: 
    bool processTicket(string ticketNumber);

    // Will implement the functionality in this class
    bool resetPassword() {
      // definition
    }
}


// Display board and parking rate

class DisplayBoard {
// Data members
  private:
    int id;
    std::vector<ParkingSpot*> parkingSpots;

  // Member functions
  public:
    DisplayBoard(int id) : id(id) {}
    void addParkingSpot(ParkingSpot* spot);
    void showFreeSlot();
};

class ParkingRate {
  // Data members
  private:
    double hours;
    double rate;

// Member function
  public: 
    void calculate();
};


class Entrance {
  // Data members 
  private:
    int id;

  // Member function
  public:
    ParkingTicket getTicket(); 
};

class Exit {
  // Data members 
  private:
    int id; 

  // Member function
  public:
    void validateTicket(ParkingTicket ticket);{
      // Perform validation logic for the parking ticket
      // Calculate parking charges, if necessary
      // Handle the exit process
    }
};


class ParkingTicket {
  private: 
    int ticketNo;
    time_t timestamp;
    time_t exit;
    double amount;
    bool status;
  
    // Following are the instances of their respective classes
    Vehicle vehicle;
    Payment payment;
    Entrance entrance;
    Exit exitIns;    
};

class Payment {
    private:
        double amount;
        PaymentStatus status;
        time_t timestamp;

    public virtual bool initiateTransaction() = 0;
};

class Cash : public Payment {
    public bool initiateTransaction() {
        // definition
    }
};

class CreditCard : public Payment {
    public bool initiateTransaction() {
        // definition
    }
};

class ParkingLot {
    private:
        int id;
        string name;
        string address;
        ParkingRate parkingRate;

        map<string, Entrance> entrance;
        map<string, Exit> exit;

        // Create a hashmap that identifies all currently generated tickets using their ticket number
        map<string, ParkingTicket> tickets;

        // The ParkingLot is a singleton class that ensures it will have only one active instance at a time
        // Both the Entrance and Exit classes use this class to create and close parking tickets
        static ParkingLot parkingLot = NULL;

        // Created a private constructor to add a restriction (due to Singleton)
        ParkingLot() {
            // Call the name, address and parking_rate 
            // Create initial entrance and exit hashmaps respectively
        }

    // Created a static method to access the singleton instance of ParkingLot
    public:
        static ParkingLot getInstance() {
            if (parkingLot == NULL) {
                parkingLot = new ParkingLot();
            }
            return parkingLot;
        }

        bool addEntrance(Entrance entrance) {}
        bool addExit(Exit exit) {}

        // This function allows parking tickets to be available at multiple entrances
        ParkingTicket getParkingTicket(Vehicle vehicle) {}

        bool isFull(ParkingSpot type) {}
};
