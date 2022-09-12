/*
729. My Calendar I

You are implementing a program to use as your calendar. We can add a new event if adding the event 
will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is 
common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the 
half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:
MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully 
without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 

Example 1:
Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by 
another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time 
less than 20, but not including 20.
 

Constraints:
0 <= start < end <= 109
At most 1000 calls will be made to book.
*/



//Brute force
class MyCalendar {
  private:
  vector<pair<int,int>> vp; 
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:vp){
          if(it.first < end && start<it.second){
            return false;
          }
        }
      vp.push_back({start,end});
      return true;
    }
};

//Optimized Approch
class MyCalendar {
    private:
        set<pair<int, int>> s;
    public:
        MyCalendar() {
        }       
        bool book(int start, int end) {           
            auto it=s.upper_bound({start,end});
            if(it!=s.end() && it->second<end) return false;
            s.insert({end,start});
            return true;
        }
};

class MyCalendar {
    private:
       map<int,int>m;
    public:
        MyCalendar() {
        }       
        bool book(int start, int end) {           
          m[start]++;
          m[end]--;
          int sum=0;
          for(auto it=m.begin();it != m.end();it++){
            sum += it->second;
            if(sum>1){
              m[start]--;
              m[end]++;
              return false;
            }
          }
          return true;
        }
};

