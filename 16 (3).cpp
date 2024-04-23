// or Q2. Create a class Time containing members as:
// - hours
// - minutes
// - seconds
// Write a C++ program for overloading operators >> and << to accept and display a Time
// also write a member function to display time in total seconds.//not understand logic

#include <iostream>

using namespace std;

class Time {
    private:
        int hours, minutes, seconds;
    public:
        Time() { hours = minutes = seconds = 0; }
        friend istream& operator>>(istream&, Time&);
        friend ostream& operator<<(ostream&, const Time&);
        int total_seconds() const;
};

istream& operator>>(istream& in, Time& t) {
    cout << "Enter time (hh:mm:ss): ";
    in >> t.hours;
    in.ignore();
    in >> t.minutes;
    in.ignore();
    in >> t.seconds;
    return in;
}

ostream& operator<<(ostream& out, const Time& t) {
    out << t.hours << ":" << t.minutes << ":" << t.seconds;
    return out;
}

int Time::total_seconds() const {
    return (hours * 3600) + (minutes * 60) + seconds;
}

int main() {
    Time t;
    cin >> t;
    cout << "Time entered: " << t << endl;
    cout << "Total seconds: " << t.total_seconds() << endl;
    return 0;
}
