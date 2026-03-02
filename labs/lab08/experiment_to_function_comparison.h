// Comparison between records_experiment & r_functions function declarations/definitions


// R_functions intialize_structures definition
void InitializeStructures(UndergradStudents us[], int &size) {
  // Initialize first student entry. The database can hold from 1 to 20 students
  // Counter for number of students in database
  int student = 1;

  // Student information variables
  string firstName, lastName, major;
  // Were going to declare studentIDnumber & GPA as strings, then convert to appropriate numerical types using stoi & stod
  // For studentIDnumber use stoi
  string studentIDnumber;
  // For GPA use stod
  string GPA;

  // Numerical variables to store the values in after using stoi & stod
  int studentID;
  double gpa;
  
  // Use for loop to get all user input (up to 20) in Undergrad students array
  for (int i = 1; i <= size; i++) {
    // Printing
    cout << "Student 0" << student << ": Enter first name (or x to quit): ";
    getline(cin, firstName);

    // Check if user wants to quit program (using 'x' or 'X' key)
    if (firstName == "x" || firstName == "X") {
      exit(1);
    }

    // Save first name to undergrad students strcuture firstNames variable (do the same for the other variables in the structure)
    //    Note: the firstNames in the next line arent the same variable, they are different (.firstname is structure variable, 2nd is local string variable)
    us[i].firstName = firstName;

    // If user enters entire student information
    // Get last name from user
    cout << "Student 0" << student << ": Enter last name: ";
    getline(cin, lastName);
    us[i].lastName = lastName;

    // Get major
    cout << "Stuent 0" << student << ": Enter major: ";
    getline(cin, major);
    us[i].major = major;

    // Get GPA (years 1 - 4)
    //  Note: the actual GPA variable stored in the .GPA structure variable is the average GPA over all 4 years
    double gpaTotal[4] = {};
    for (int i = 1; i <= 4; i++) {
      cout << "Student 0" << student << ": Enter GPA Year " << i << ": ";
      getline(cin, GPA);
      gpaTotal[i] = stod(GPA);
    }
    // Create double average variable to save actual average in the GPA structure variable
    double totalGPA = 0;
    for (int i = 0; i <= 4; i++) {
      totalGPA += gpaTotal[i];
    }
    double avGPA = totalGPA / 4;
    // Add to GPA variable in struct
    us[i].GPA = avGPA;
  }
}

// records_experiments initalize structures function definition
void InitializeStructures(UndergradStudents us[], int &size) {
  // Initialize first student entry. The database can hold from 1 to 20 students
  // Counter for number of students in database
  int student = 1;

  // Student information variables
  string firstName, lastName, major;
  // Were going to declare studentIDnumber & GPA as strings, then convert to appropriate numerical types using stoi & stod
  // For studentIDnumber use stoi
  string studentIDnumber;
  // For GPA use stod
  string GPA;

  // Numerical variables to store the values in after using stoi & stod
  int studentID;
  double gpa;
  
  // Use for loop to get all user input (up to 20) in Undergrad students array
  for (int i = 1; i <= size; i++) {
    // Printing
    cout << "Student 0" << student << ": Enter first name (or x to quit): ";
    getline(cin, firstName);

    // Check if user wants to quit program (using 'x' or 'X' key)
    if (firstName == "x" || firstName == "X") {
      exit(1);
    }

    // Save first name to undergrad students strcuture firstNames variable (do the same for the other variables in the structure)
    //    Note: the firstNames in the next line arent the same variable, they are different (.firstname is structure variable, 2nd is local string variable)
    us[i].firstName = firstName;

    // If user enters entire student information
    // Get last name from user
    cout << "Student 0" << student << ": Enter last name: ";
    getline(cin, lastName);
    us[i].lastName = lastName;

    // Get major
    cout << "Stuent 0" << student << ": Enter major: ";
    getline(cin, major);
    us[i].major = major;

    // Get GPA (years 1 - 4)
    //  Note: the actual GPA variable stored in the .GPA structure variable is the average GPA over all 4 years
    double gpaTotal[4] = {};
    for (int i = 1; i <= 4; i++) {
      cout << "Student 0" << student << ": Enter GPA Year " << i << ": ";
      getline(cin, GPA);
      gpaTotal[i] = stod(GPA);
    }
    // Create double average variable to save actual average in the GPA structure variable
    double totalGPA = 0;
    for (int i = 0; i <= 4; i++) {
      totalGPA += gpaTotal[i];
    }
    double avGPA = totalGPA / 4;
    // Add to GPA variable in struct
    us[i].GPA = avGPA;

    // Add to student counter to keep track of students within database
    student++;

    // Newline syntax
    cout << endl;
  }
}