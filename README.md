# C++ Date
The purpose of this library is to provide a reliable date implementation for C++. It started because of the outstanding complexity to generate epochs from raw dates.

It provides header-only implementation so nothing to compile, you just need to include `date/date.hpp` in your code.

# Usage
These declarations are simplified for documentation purpose, they may vary in the actual implementation.

## Date
### Constructors
Creates a date.
```cpp
Date(size_t day, size_t month, size_t year)
```

Creates a date from standard's `time_point`.
```cpp
Date(std::chrono::system_clock::time_point time)
```

### Static methods
Creates a new date with of current time.
```cpp
Date::now()
```

### Methods
Convert the date to epoch.
```cpp
std::chrono::seconds epoch()
```

### Operators
```cpp
Date > Date
```

```cpp
Date < Date
```
