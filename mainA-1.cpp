#include <iostream>
#include <vector>
#include <limits>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

vector<int> split_to_ints(string input,string valid) {
	size_t startPos = 0;
	size_t endPos;
	size_t subStringLength;
	vector <int> result;

	do {
		endPos = input.find_first_not_of(valid, startPos);
		// if not found in string...
		if (endPos == string::npos) {	
			subStringLength = input.length();
		}
		// otherwise,
		else {
			subStringLength = endPos - startPos;
		}

		result.push_back(stoi(input.substr(startPos, subStringLength)));
		startPos = input.find_first_of(valid, endPos);
	}

	while (endPos != string::npos);
		return result;
}


int main(void) {
	// take-in inputs -- note this code assumes for a valid input format!
	string user_input;
	getline(cin, user_input);

	// cut out the numbers from user_input & place into vector of ints
	string numeric_characters = "-0123456789";
	vector<int> numeric_inputs = split_to_ints(user_input, numeric_characters);

	// copy all (but last 2) digits from vector into a c-array (to be passed into LinkedList constructor)
	int array_size = numeric_inputs.size()-2;
	int * input_array = new int[array_size];
	for(unsigned int i = 0; i < (numeric_inputs.size()-2); i++) {
		input_array[i] = numeric_inputs[i];
	}

	// then, copy the last 2 digits from user_input (ie the parameters) into a parameter array
	int param_array[2] = { 
		numeric_inputs.at(numeric_inputs.size()-2), 
		numeric_inputs.at(numeric_inputs.size()-1)
	};

	// finally, copy the letter code into a new variable
	string commandCode;
	for(unsigned int i = 0; i < user_input.length(); i++) {
		if(isalpha(user_input[i])) {
			commandCode.push_back(user_input[i]);
		}
	}

    // create list based on input data & array size
    LinkedList submissionList(input_array, array_size);

    // run function on the list depending on letter code, using the parameters
    if (commandCode=="I") {
        submissionList.insertPosition(param_array[0], param_array[1]);
    }
    else if (commandCode=="D") {
        if (!submissionList.deletePosition(param_array[0])) {
            cout << "ERROR ";
        }
    }
    else if (commandCode=="S") {
		int got = submissionList.search(param_array[0]);
        if (got == -1) {
            cout << "ERROR ";
        }
        else {
			std::cout << got << " ";
		}
    }
    else if (commandCode=="G") {
		int got = submissionList.get(param_array[0]);
        if (got == numeric_limits<int>::max()) {
            cout << "ERROR ";
        }
        else {
			std::cout << got << " ";
		}
    }
    else {
        cout << "invalid command" << endl;
        return 0;
    }

    submissionList.printList();

	return 0;
}