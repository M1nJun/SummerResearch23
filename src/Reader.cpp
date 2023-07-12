#include"Reader.hpp"
#include<algorithm> // std::find, std::sort
#include"Algorithms.hpp" // algs::nCr
using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::getline;
using std::stoi;
using std::to_string;


const map<string,vector<vector<int>>> singular_fibers {
    {"I1", {
        {0}
    }},
    {"I2", {
        {1,1},
        {0,0}
    }},
    {"I3", {
        {2,1},
        {0,2},
        {1,0}
    }},
    {"I4", {
        {3,1},
        {0,2},
        {1,3},
        {2,0}
    }},
    {"I5", {
        {4,1},
        {0,2},
        {1,3},
        {2,4},
        {3,0}
    }},
    {"I6", {
        {5,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,0}
    }},
    {"I7", {
        {6,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,0}
    }},
    {"I8", {
        {7,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,0}
    }},
    {"I9", {
        {8,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,0}
    }},
    {"I10", {
        {9,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,0}
    }},
    {"I11", {
        {10,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,0}
    }},
    {"I12", {
        {11,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,0}
    }},
    {"I13", {
        {12,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,0}
    }},
    {"I14", {
        {13,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,13},
        {12,0}
    }},
    {"I15", {
        {14,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,13},
        {12,14},
        {13,0}
    }},
    {"I16", {
        {15,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,13},
        {12,14},
        {13,15},
        {14,0}
    }},
    {"I17", {
        {16,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,13},
        {12,14},
        {13,15},
        {14,16},
        {15,0}
    }},
    {"I18", {
        {17,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,13},
        {12,14},
        {13,15},
        {14,16},
        {15,17},
        {16,0}
    }},
    {"I19", {
        {18,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,13},
        {12,14},
        {13,15},
        {14,16},
        {15,17},
        {16,18},
        {17,0}
    }},
    {"I20", {
        {19,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,13},
        {12,14},
        {13,15},
        {14,16},
        {15,17},
        {16,18},
        {17,19},
        {18,0}
    }},
    {"I21", {
        {20,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,13},
        {12,14},
        {13,15},
        {14,16},
        {15,17},
        {16,18},
        {17,19},
        {18,20},
        {19,0}
    }},
    {"I22", {
        {21,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7},
        {6,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,13},
        {12,14},
        {13,15},
        {14,16},
        {15,17},
        {16,18},
        {17,19},
        {18,20},
        {19,21},
        {20,0}
    }},
    {"I0*", {
        {1,2,3,4},
        {0},
        {0},
        {0},
        {0}
    }},
    {"I1*", {
        {1,2,3},
        {0,4,5},
        {0},
        {0},
        {1},
        {1}
    }},
    {"I2*", {
        {1,3,4},
        {0,2},
        {1,5,6},
        {0},
        {0},
        {2},
        {2}
    }},
    {"I3*", {
        {1,4,5},
        {0,2},
        {1,3},
        {2,6,7},
        {0},
        {0},
        {3},
        {3}
    }},
    {"I4*", {
        {1,5,6},
        {0,2},
        {1,3},
        {2,4},
        {3,7,8},
        {0},
        {0},
        {4},
        {4}
    }},
    {"IV*", {
        {1,3,5},
        {0,2},
        {1},
        {0,4},
        {3},
        {0,6},
        {5}
    }},
    {"III*", {
        {1,2,5},
        {0},
        {0,3},
        {2,4},
        {3},
        {0,6},
        {5,7},
        {6}
    }},
    {"II*", {
        {1,2,4},
        {0},
        {0,3},
        {2},
        {0,5},
        {4,6},
        {5,7},
        {6,8},
        {7}
    }}
};

//python-like split yay
//Function split takes in String 's' and a character 'c'
vector<string> split(const string& s, char c = '\0') {
    //vector of strings containing the resulting substrings
    vector<string> result;
    //keeps track of the index of the last whitespace character
    //or the specified character encountered.
    int last_whitespace = -1;
    for (int i = 0; i < s.size(); ++i) {
        //check if 'c' is not 0 and the current character is equal to the specified character 'c'
        if ((c != 0 and s[i] == c) or
        //check if 'c' is a whitespace character, which include
        //space(' '), newline('\n'), return('\r'), and tab('\t')
        (c == 0 and (s[i] == ' ' or s[i] == '\n' or s[i] == '\r' or s[i] == '\t'))) {
            //if true, check if the distance between the current index 'i'
            //and the index of the last whitespace character is greater than 1.
            if (i - last_whitespace > 1) {
                //this ensures that only non-empty substrings are added to the result vector.
                //if true, add the substring to the result vector excluding the whitespace character.
                result.push_back(s.substr(last_whitespace+1, i - last_whitespace - 1));
            }
            //update to current index 'i'
            last_whitespace = i;
        }
    }
    //check if the last whitespace character is not at the end of the string
    if (last_whitespace != s.size() - 1) {
        //if true, add the substring from 'last_whitespace+1' to the end of the substring to the result vector.
        result.push_back(s.substr(last_whitespace+1));
    }
    //return vector that contains the split substrings
    return result;
}

//this function attempts to convert a string 's' to and integer
//using the stoi function.
//it returns a boolean value indicating whether the conversion was successful.
bool safe_stoi(const string& s, int& result) {
    try {
        size_t z;
        result = stoi(s,&z);
        //check if the index stored in'z' is different from the size of the input string 's'
        //if they are different, it means there are non-digit characters present in the string after the converted portion
        //so returns false(0)
        if (z != s.size()) {
            return 0;
        }
    }
    catch (std::exception& e) {
        return 0;
    }
    return 1;
}

bool safe_stoll(const string& s, long long& result) {
    try {
        size_t z;// Variable to store the index of the first invalid character after converting the string to a long long
        result = stoll(s,&z);// Convert the string to a long long and store the result. z will be updated with the index of the first invalid character.
        if (z != s.size()) {// Check if there are any remaining characters in the string after the conversion
            return 0;// Return false (0) indicating conversion failure
        }
    }
    catch (std::exception& e) {// Catch any exception that occurs during the conversion
        return 0;// Return false (0) indicating conversion failure
    }
    return 1;// Return true (1) indicating successful conversion
}
/*The safe_stroll function basically just conversts a string to a long long .
 if the conversion is successful it returns 1 
 if the conversion is not successful it returns 0 
*/
Reader::Reader() {
    summary_style = plain_text_;
    summary_sort = sort_by_n_;
    nef_check = skip_;
    effective_check = skip_;
    obstruction_check = skip_;
    keep_first = keep_global_;
    section_input_mode = by_self_intersection_;
    export_pretests = no_;
    parse_only = false;
    search_single_chain = true;
    search_double_chain = false;
    search_single_QHD = false;
    search_double_QHD = false;
    summary_include_gcd = false;
    latex_include_subsection = false;
    line_no = 0;
    curve_no = 0;
    tests_no = 1;
    tests_start_index = 0;
    max_test_number = 1;
    subtest_start = -1;
    subtest_end = -1;
    curves_used_exactly = -1;
    K.self_int = 0;
    fixed_curves.resize(1);
    try_curves.resize(1);
    choose_curves.resize(1);
    ignored_curves.resize(1);
#ifdef MULTITHREAD
    threads = MAX_THREADS;
#endif
    output_filename = DEFAULT_OUTPUT_NAME;
    summary_filename = DEFAULT_SUMMARY_NAME;
    pretest_filename = DEFAULT_PRETEST_NAME;
    search_for.insert(1);
    search_for.insert(2);
    search_for.insert(3);
    search_for.insert(4);
    error_stream = &std::cerr;
}

//can't explain fully, too much variables.
void Reader::parse(istream& input) {
    string line;
    string next_line;
    vector<string> tokens;
    vector<string> next_tokens;
    State previous_state = start_;
    State state = start_;
    //reads lines from the input stream
    while (getline(input,line)) {
        //keeps track of the line number being processed
        line_no++;
        //splits current line into tokens
        tokens = split(line);
        //perform several checks on tokens to determine if the line should be skipped or the program should enter a different state
        if (tokens.size() == 0) continue;
        if (tokens[0][0] == '#') continue;
        if (tokens[0].size() > 1 and tokens[0][0] == '/' and tokens[0][1] == '/') continue;
        if (tokens[0].size() > 1 and tokens[0][0] == '/' and tokens[0][1] == '*') {
            previous_state = state;
            state = comment_;
            continue;
        }
        //check if current state is comment state, it adjusts the state
        if (state == comment_) {
            if (tokens[0].size() > 1 and tokens[0][0] == '*' and tokens[0][1] == '/') {
                state = previous_state;
                continue;
            }
            continue;
        }
        //check if line ends with a colon, and meets certain conditions, it changes the state based on the content of the line.
        if (tokens.size() == 1 and tokens[0].back() == ':') {
            
            if (tokens[0] == "Fibers:") {
                state = fibers_;
                continue;
            }
            if (tokens[0] == "DoubleSections:") {
                if (section_input_mode == by_self_intersection_) {
                    current_section_argument = 0;
                }
                else {
                    current_section_argument = -2;
                }
                state = sections_;
                continue;
            }
            if (tokens[0] == "Sections:") {
                current_section_argument = -1;
                state = sections_;
                continue;
            }
            if (tokens[0] == "Name:" or tokens[0] == "Merge:") {
                state = merge_;
                continue;
            }
            if (tokens[0] == "MakeFibers:") {
                state = make_fibers_;
                continue;
            }
            if (tokens[0] == "ForgetExceptionals:") {
                state = forget_exceptionals_;
                continue;
            }
            if (tokens[0].substr(0,9) == "Sections(" and
                tokens[0].substr(tokens[0].size() - 2) == "):") {
                int value;
                string temp = tokens[0].substr(9,tokens[0].size() - 11);
                if (safe_stoi(temp,value)) {
                    current_section_argument = value;
                    state = sections_;
                    continue;
                }
                else {
                    error("Invalid self intersection for Sections: " + temp);
                }
            }
            warning("Token \'" + tokens[0] + "\' is not a command. Treated as a name.");
        }
        //if none of the above conditions are met, it calls different parsing functions depending on the state
        switch (state) {
        case start_:
            parse_option(tokens);
            break;
        case fibers_:
            if (input.eof()) {
                error("Unexpected EOF after Fiber definition.");
            }
            getline(input,next_line);
            line_no++;
            next_tokens = split(next_line);
            parse_fiber(tokens,next_tokens);
            break;
        case sections_:
            if (input.eof()) {
                error("Unexpected EOF after Section definition.");
            }
            getline(input,next_line);
            line_no++;
            next_tokens = split(next_line);
            parse_section(tokens,next_tokens);
            break;
        case merge_:
            if (input.eof()) {
                error("Unexpected EOF after Name/Merge definition.");
            }
            getline(input,next_line);
            line_no++;
            next_tokens = split(next_line);
            parse_merge(tokens,next_tokens);
            break;
        case make_fibers_:
            if (input.eof()) {
                error("Unexpected EOF after MakeFiber definition.");
            }
            getline(input,next_line);
            line_no++;
            next_tokens = split(next_line);
            parse_make_fiber(tokens,next_tokens);
            break;
        case forget_exceptionals_:
            parse_forget_exceptional(tokens);
            break;
        default:;
        }
    }

    //performs additional checks and operations on the data parsed during the loop.
    for (int i = 0; i < curve_no; ++i) {
        if (contains(adj_list[i],i)) {
            error("Curve \'" + curve_name[i] + "\' still has singularities.");
        }
    }

    // For consistency, sort all fixed / ignored / try vectors
    for (auto& v : fixed_curves) {
        std::sort(v.begin(),v.end());
    }
    for (auto& v : try_curves) {
        std::sort(v.begin(),v.end());
    }
    for (auto& v : ignored_curves) {
        std::sort(v.begin(),v.end());
    }

    for (auto comp : K.components_including_forgotten) {
        if (contains(forgotten_exceptionals,comp.right_parent)) {
            comp.right_parent = -1;
        }
        if (contains(forgotten_exceptionals,comp.left_parent)) {
            comp.left_parent = comp.right_parent;
            comp.right_parent = -1;
        }
        if (!contains(forgotten_exceptionals,comp.id)) {
            K.components.emplace_back(comp);
            K.used_components.insert(comp.id);
        }
    }

    //prints warning and messages based on condiiton
    if (tests_no > 1 and tests_start_index + tests_no > max_test_number) {
        warning("Test range exedes number of tests given by curve options. Redundant tests are ignored.");
        tests_no = std::max(1,max_test_number - tests_start_index);
    }

    if (parse_only) {
        warning("Parse only debug mode: no testing is done.");
    }
}
//The function handles different options by checking the value of the first token.
//takes a vector of strings called 'tokens' as input, which contains the parsed tokens from a line of input.
void Reader::parse_option(const vector<string>& tokens) {
    //checks the value of the first token to determine the option and performs different actions based on the option.
    if (tokens[0] == "Tests:") {
        //checks the size of 'tokens' to ensure it has the correct number of arguments.
        //it then processes the arguments to determine the number of tests to run and sets the variables.
        if (tokens.size() != 2 and !(tokens.size() == 4 and tokens[2] == "-")) {
            error("Argument for option \'Tests\' must be \'<number>\' or \'<number> - <number>\'.");
        }
        if (tokens.size() == 2) {
            int value;
            if (!safe_stoi(tokens[1],value) or value < 0) {
                error("Invalid number for option \'Tests\': " + tokens[1]);
            }
            if (value > MAX_TESTS) {
                warning("Number of tests cannot exceed " + to_string(MAX_TESTS) + ". Further test ignored.");
                value = MAX_TESTS;
            }
            if (value == 0) {
                parse_only = true;
                value = 1;
            }
            else {
                parse_only = false;
            }
            tests_no = value;
            fixed_curves.resize(tests_no);
            try_curves.resize(tests_no);
            choose_curves.resize(tests_no);
            ignored_curves.resize(tests_no);
            return;
        }
        else {
            parse_only = false;
            int start, finish;
            if (!safe_stoi(tokens[1],start) or start < 1) {
                error("Invalid number for option \'Tests\': " + tokens[1]);
            }
            if (!safe_stoi(tokens[3],finish) or finish < start) {
                error("Invalid number for option \'Tests\': " + tokens[3]);
            }
            if (finish > MAX_TESTS) {
                warning("Tests cannot exceed " + to_string(MAX_TESTS) + ". Range clamped to [1," + to_string(MAX_TESTS) + "].");
                start = std::min(start,MAX_TESTS);
                finish = MAX_TESTS;
            }
            tests_no = finish - start + 1;
            tests_start_index = start - 1;
            fixed_curves.resize(tests_no);
            try_curves.resize(tests_no);
            choose_curves.resize(tests_no);
            ignored_curves.resize(tests_no);
            return;
        }
    }
    //if the first token is 'Subtests',
    else if (tokens[0] == "SubTests:") {
        //checks the size of 'tokens' to ensure it has the correct number of arguments.
        //same when it was 'tests'
        if (!(tokens.size() == 4 and tokens[2] == "-")) {
            error("Argument for option \'SubTests\' must be \'<number> - <number>\'.");
        }
        parse_only = false;
        long long start, finish;
        if (!safe_stoll(tokens[1],start) or start < 0ll) {
            error("Invalid number for option \'Tests\': " + tokens[1]);
        }
        if (!safe_stoll(tokens[3],finish) or finish < start) {
            error("Invalid number for option \'Tests\': " + tokens[3]);
        }
        subtest_start = start;
        subtest_end = finish;
        return;
    }
    //if the first token is 'output', it checks the size of 'tokens' and sets the 'output_filename' variable to the specified value.
    else if (tokens[0] == "Output:") {
        if (tokens.size() != 2) {
            error("Option \'Output\' must take exactly one argument.");
        }
        output_filename = tokens[1];
        return;
    }
    //if first token is 'summary output', checks size of tokens, and sets 'summary_filename' to the specified value.
    else if (tokens[0] == "Summary_Output:") {
        if (tokens.size() != 2) {
            error("Option \'Summary_Output\' must take exactly one argument.");
        }
        summary_filename = tokens[1];
        return;
    }
    //if first token in 'pretest file', it checks the size of tokens, and sets 'pretest_name' to the specified value.
    else if (tokens[0] == "Pretest_File:") {
        if (tokens.size() != 2) {
            error("Option \'Pretest_File\' must take exactly one argument.");
        }
#ifndef EXPORT_PRETEST_DATA
        warning("Build does not allow pretest options. This option does nothing");
#endif
        pretest_filename = tokens[1];
        return;
    }
    else if (tokens[0] == "Summary_Style:") {
        if (tokens.size() != 2) {
            error("Option \'Summary_Style\' must take exactly one argument.");
        }
        if (tokens[1] == "LaTeX_Table") {
            summary_style = latex_table_;
        }
        else if (tokens[1] == "Plain_Text") {
            summary_style = plain_text_;
        }
        else if (tokens[1] == "skip") {
            summary_style = skip_;
        }
        else {
            error("Invalid argument for \'Summary_Style\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Summary_Include_GCD:") {
        if (tokens.size() != 2) {
            error("Option \'Summary_Include_GCD\' must take exactly one argument.");
        }
        if (tokens[1] == "Y") {
            summary_include_gcd = true;
        }
        else if (tokens[1] == "N") {
            summary_include_gcd = false;
        }
        else {
            error("Invalid argument for \'Summary_Include_GCD\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "LaTeX_Include_Subsection:") {
        if (tokens.size() != 2) {
            error("Option \'LaTeX_Include_Subsection\' must take exactly one argument.");
        }
        if (tokens[1] == "Y") {
            latex_include_subsection = true;
        }
        else if (tokens[1] == "N") {
            latex_include_subsection = false;
        }
        else {
            error("Invalid argument for \'LaTeX_Include_Subsection\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Summary_Sort:") {
        if (tokens.size() != 2) {
            error("Option \'Summary_Sort\' must take exactly one argument.");
        }
        if (tokens[1] == "By_N") {
            summary_sort = sort_by_n_;
        }
        else if (tokens[1] == "By_Length") {
            summary_sort = sort_by_length_;
        }
        else {
            error("Invalid argument for \'Summary_Sort\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Nef_Check:") {
        if (tokens.size() != 2) {
            error("Option \'Nef_Check\' must take exactly one argument.");
        }
        if (tokens[1] == "Y" or tokens[1] == "skip") {
            nef_check = skip_;
        }
        else if (tokens[1] == "N") {
            nef_check = no_;
        }
        else if (tokens[1] == "print") {
            nef_check = print_;
        }
        else {
            error("Invalid argument for \'Nef_Check\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Effective_Check:") {
        if (tokens.size() != 2) {
            error("Option \'Effective_Check\' must take exactly one argument.");
        }
        if (tokens[1] == "Y" or tokens[1] == "skip") {
            effective_check = skip_;
        }
        else if (tokens[1] == "N") {
            effective_check = no_;
        }
        else if (tokens[1] == "print") {
            effective_check = print_;
        }
        else {
            error("Invalid argument for \'Effective_Check\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Obstruction_Check:") {
        if (tokens.size() != 2) {
            error("Option \'Obstruction_Check\' must take exactly one argument.");
        }
        if (tokens[1] == "Y" or tokens[1] == "skip") {
            obstruction_check = skip_;
        }
        else if (tokens[1] == "N") {
            obstruction_check = no_;
        }
        else if (tokens[1] == "print") {
            obstruction_check = print_;
        }
        else {
            error("Invalid argument for \'Obstruction_Check\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Single_Chain:") {
        if (tokens.size() != 2) {
            error("Option \'Single_Chain\' must take exactly one argument.");
        }
        if (tokens[1] == "Y") {
            search_single_chain = true;
        }
        else if (tokens[1] == "N") {
            search_single_chain = false;
        }
        else {
            error("Invalid argument for \'Single_Chain\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Double_Chain:") {
        if (tokens.size() != 2) {
            error("Option \'Double_Chain\' must take exactly one argument.");
        }
        if (tokens[1] == "Y") {
            search_double_chain = true;
        }
        else if (tokens[1] == "N") {
            search_double_chain = false;
        }
        else {
            error("Invalid argument for \'Double_Chain\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Single_QHD:") {
        if (tokens.size() != 2) {
            error("Option \'Single_QHD\' must take exactly one argument.");
        }
        if (tokens[1] == "Y") {
            search_single_QHD = true;
        }
        else if (tokens[1] == "N") {
            search_single_QHD = false;
        }
        else {
            error("Invalid argument for \'Single_QHD\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Double_QHD:") {
        if (tokens.size() != 2) {
            error("Option \'Double_QHD\' must take exactly one argument.");
        }
        if (tokens[1] == "Y") {
            search_double_QHD = true;
        }
        else if (tokens[1] == "N") {
            search_double_QHD = false;
        }
        else {
            error("Invalid argument for \'Double_QHD\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Search_For:") {
        if (tokens.size() == 1) {
            error("Option \'Search_For\' must take at least one argument.");
        }
        search_for.clear();
        int value;
        for (int i = 1; i < tokens.size(); ++i) {
            if(!safe_stoi(tokens[i],value)) {
                error("Invalid number for option \'Search_For\': " + tokens[i]);
            }
            search_for.insert(value);
        }
        return;
    }
    else if (tokens[0] == "K2:") {
        if (tokens.size() != 2) {
            error("Option \'K2\' must take exactly one argument.");
        }
        int value;
        if(!safe_stoi(tokens[1],value)) {
            error("Invalid number for option \'K2\': " + tokens[1]);
        }
        K.self_int = value;
        return;
    }
    else if (tokens[0] == "Keep_First:") {
        if (tokens.size() != 2) {
            error("Option \'Keep_First\' must take exactly one argument.");
        }
        if (tokens[1] == "local") {
            keep_first = keep_local_;
        }
        else if (tokens[1] == "global") {
            keep_first = keep_global_;
        }
        else if (tokens[1] == "N") {
            keep_first = no_;
            warning("Configurations are usually very symmetric. Expect tons of repeated results");

#ifndef NO_REPEATED_SEARCH
            warning("Build does not check for repeated examples within the same test case. Expect even more repeated results.");
#endif
        }
        else {
            error("Invalid argument for \'Keep_First\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Threads:") {
        if (tokens.size() != 2) {
            error("Option \'Threads\' must take exactly one argument.");
        }
        int value;
        if (!safe_stoi(tokens[1],value) or value < 1) {
            error("Invalid number for option \'Threads\': " + tokens[1]);
        }
#ifdef MULTITHREAD
        if (value > MAX_THREADS) {
            warning("Build allows for " + to_string(MAX_THREADS) + ". Value capped.");
            value = MAX_THREADS;
        }
        threads = value;
#else
        warning("Build does not allow threads. This option does nothing.");
#endif
        return;
    }
    else if (tokens[0] == "Sections_Input:") {
        if (tokens.size() != 2) {
            error("Option \'Sections_Input\' must take exactly one argument.");
        }
        if (tokens[1] == "By_Self_Intersection") {
            section_input_mode = by_self_intersection_;
        }
        else if (tokens[1] == "By_Canonical_Intersection") {
            section_input_mode = by_canonical_intersection_;
        }
        else {
            error("Invalid argument for \'Sections_Input\': " + tokens[1]);
        }
        return;
    }
    else if (tokens[0] == "Export_Pretests:") {
        if (tokens.size() != 2) {
            error("Option \'Export_Pretests\' must take exactly one argument.");
        }
        if (tokens[1] == "Y") {
            export_pretests = yes_;
        }
        else if (tokens[1] == "N") {
            export_pretests = no_;
        }
        else if (tokens[1] == "Only") {
            export_pretests = only_;
        }
        else {
            error("Invalid argument for \'Export_Pretests\': " + tokens[1]);
        }
#ifndef EXPORT_PRETEST_DATA
        warning("Build does not allow pretest options. This option does nothing");
#endif
        return;
    }
    else if (tokens[0] == "Use_Exactly:") {
        if (tokens.size() != 2) {
            error("Option \'Use_Exactly\' must take exactly one argument.");
        }
        int value;
        if (!safe_stoi(tokens[1],value) or value < -1) {
            error("Invalid number for option \'Use_Exactly\': " + tokens[1]);
        }
        curves_used_exactly = value;
        return;
    }
    //if none of the above conditions are met, it generates an error
    else {
        error("Invalid option: " + tokens[0]);
    }
}

void Reader::parse_fiber(const vector<string>& def_tokens, const vector<string>& content_tokens) {
    if (!contains(singular_fibers,def_tokens[0])) {// Check if the fiber type is known or if the command is invalid
        error("Unknown fiber type or invalid command: " + def_tokens[0] + ".",line_no-1);
    }
    fiber_type.emplace_back(def_tokens[0]); // Add the fiber type to the fiber_type vector
    fibers.emplace_back();// Add an empty vector to the fibers vector to store the curves of the fiber
    int initial_index = curve_no;// Store the current curve_no value as the initial_index
    int n = content_tokens.size();// Get the number of content tokens
    for (const string& curve : content_tokens) { 
        if (contains(curve_id,curve)) {// Check if the curve is already defined
            error("Curve \'" + curve + "\' is already defined.");
        }
        curve_id[curve] = curve_no;// Assign a curve number to the curve and update relevant data structures
        fibers.back().emplace_back(curve_no);
        curves_in_fibers.insert(curve_no);
        curve_name.emplace_back(curve);
        adj_list.emplace_back();
        if (n == 1) {// Determine the self-intersection value for the curve based on the number of content tokens
            self_int.emplace_back(0);
        }
        else {
            self_int.emplace_back(-2);
        }
        curve_no++;
    }
    const vector<vector<int>> &fiber_graph = singular_fibers.at(def_tokens[0]);// Get the fiber graph for the current fiber type
    if (fiber_graph.size() != n) {// Check if the size of the fiber graph matches the number of content tokens
        error("Fiber " + def_tokens[0] + " requires " + to_string(n) + ", " + to_string(content_tokens.size()) + " found.");
    }// Update the adjacency list based on the fiber graph
    for (int i = 0; i < n; ++i) {
        for (int neighbor : fiber_graph[i]) {
            adj_list[initial_index + i].insert(initial_index + neighbor);
        }
    }

    max_test_number = std::max(max_test_number,(int)def_tokens.size() - 1);// Update the max_test_number based on the number of test options in the definition tokens
    string option = def_tokens.size() == 1 ? "T" : def_tokens.back();// Initialize the option variable based on the last token in the definition tokens
    for (int t = 0; t < tests_no; ++t) {   // Process each test option
        if (def_tokens.size() > t + 1 + tests_start_index) {// Check if the option is provided in the definition tokens
            option = def_tokens[t + 1 + tests_start_index];
        }
        if (option == "Fix" or option == "F") {// Handle different test options
            for (int curve : fibers.back()) {// Add the curves of the current fiber to the fixed_curves vector for the current test
                fixed_curves[t].emplace_back(curve);
            }
        }
        else if (option == "Try" or option == "T") {
            for (int curve : fibers.back()) {// Add the curves of the current fiber to the try_curves vector for the current test
                try_curves[t].emplace_back(curve);
            }
        }
        else if (option == "Dis" or option == "D") {// Handle the "Dis" or "D" option based on the number of content tokens
            if (n == 1){
                ignored_curves[t].emplace_back(fibers.back()[0]);
            }
            else {
                choose_curves[t].emplace_back(fibers.back());
            }
        }
        else if (option == "Ign" or option == "I") {
            for (int curve : fibers.back()) {// Add the curves of the current fiber to the ignored_curves vector for the current test
                ignored_curves[t].emplace_back(curve);
            }
        }
        else { // Handle invalid test options
            error("Invalid test option for Fiber " + def_tokens[0] + ".",line_no-1);
        }
    }
}

//Function handles the parsing of a section.
//extracts information such as curve IDs, intersections, self-intersection values, and test options
//updates the data structures accordingly.
//takes two vectors of strings as input. 'def_tokens' and 'content_tokens'
void Reader::parse_section(const vector<string>& def_tokens, const vector<string>& content_tokens) {
    //check if the curve ID of the section('def_tokens[0]) is already defined in the 'curve_id' map.
    //If so, error is generated
    if (contains(curve_id,def_tokens[0])) {
        error("Curve \'" + def_tokens[0] + "\' is already defined.",line_no-1);
    }
    //assigns a new ID to the section and updates 'curve_id' map and others.
    int this_id = curve_no;
    curve_id[def_tokens[0]] = this_id;
    sections.insert(this_id);
    curve_name.emplace_back(def_tokens[0]);
    adj_list.emplace_back();
    //increments total number of curves
    curve_no++;
    // Original Comment: Count the intersections with other curves and use it to get the new self_intersection
    //stores the new intersection counts in the 'intersections' map
    map<int,int> intersections;
    for (const string& curve : content_tokens) {
        if (!contains(curve_id,curve)) {
            error("Curve \'" + curve + "\' is undefined.");
        }
        int id = curve_id[curve];
        adj_list.back().insert(id);
        if (id != this_id) adj_list[id].insert(this_id);
        intersections[id]++;
    }

    //based on the section_input_mode', it calculates the new self-intersection value for the section and stores it in the 'self_int' vector.
    if (section_input_mode == by_self_intersection_) {
        self_int.emplace_back(current_section_argument + K.blowup_curve_self_int_delta(intersections));
    }
    else {
        self_int.emplace_back(2*intersections[this_id] - 2 - current_section_argument - K.exceptional_intersection(intersections));
    }

    //updates the 'max_test_number' by comparing it to the size of def_tokens -1.
    max_test_number = std::max(max_test_number,(int)def_tokens.size() - 1);
    string option = def_tokens.size() == 1 ? "T" : def_tokens.back();
    //processes the test options for the section.
    //for each test, checks if a specific test option is provided in the def_token
    for (int t = 0; t < tests_no; ++t) {
        if (def_tokens.size() > t + 1 + tests_start_index) {
            option = def_tokens[t + 1 + tests_start_index];
        }
        //depending on the option value, it adds the section's ID to the corresponding vector, 'fixed_curves','try_curves','ignored_curves'
        if (option == "Fix" or option == "F") {
            fixed_curves[t].emplace_back(this_id);
        }
        else if (option == "Try" or option == "T") {
            try_curves[t].emplace_back(this_id);
        }
        else if (option == "Ign" or option == "I") {
            ignored_curves[t].emplace_back(this_id);
        }
        else {
            error("Invalid test option for Section \'" + def_tokens[0] + "\'.",line_no-1);
        }
    }
}

//Function handles parsing of a merge by processing 'def_tokens' and 'content_tokens' as inputs.
void Reader::parse_merge(const vector<string>& def_tokens, const vector<string>& content_tokens) {
    //check if the curve ID of the merge('def_tokens[0]') is already defined in the 'curve_id' map.
    //if it is, error generated.
    if (contains(curve_id,def_tokens[0])) {
        error("Curve \'" + def_tokens[0] + "\' is already defined.",line_no-1);
    }
    //assigns a new ID to the merged curve and updates the 'curve_id' map
    int this_id = curve_no;
    curve_id[def_tokens[0]] = this_id;
    curve_name.emplace_back(def_tokens[0]);
    self_int.emplace_back(-1);
    adj_list.emplace_back();
    //increments the total number of curves.
    curve_no++;
    //Counts the intersections of the merged curve with other curves and stores the intersection counts in the 'intersections' map.
    map<int,int> intersections;
    for (const string& curve : content_tokens) {
        if (!contains(curve_id,curve)) {
            error("Curve \'" + curve + "\' is undefined.");
        }
        int id = curve_id[curve];
        //checks if the merged curve intersects itself. If it does, error generated.
        if (id == this_id) {
            error("Exceptional curve \'" + def_tokens[0] + "\' must be smooth, cannot intersect itself.");
        }
        //updates adjacency list and self-intersection values of the intersecting curves
        adj_list.back().insert(id);
        adj_list[id].insert(this_id);
        intersections[id]++;
    }
    //check if intersection curve has enough singularities/arithmetic genus to merge.
    for (auto iter = intersections.begin(); iter != intersections.end(); ++iter) {
        const int& A = iter->first;
        int& singA = iter->second;
        //check if intersection curve has enough singularities/arithmetic genus to merge.
        if (adj_list[A].count(A) < singA*(singA-1)/2) {
            error("Curve \'" + curve_name[A] + "\' does not have enough singularities/arithmetic genus to merge.");
        }
        for (int i = 0; i < singA*(singA-1)/2; ++i) {
            adj_list[A].erase(adj_list[A].find(A));
        }
        self_int[A] -= singA*singA;
        for (auto iter2 = next(iter); iter2 != intersections.end(); ++iter2) {
            const int& B = iter2->first;
            int& singB = iter2->second;
            int A_int_B = adj_list[A].count(B);
            if (A_int_B < singA*singB) {
                error("Curve \'" + curve_name[A] + "\' does not intersect curve \'" + curve_name[B] + "\' enough times.");
            }
            for (int i = 0; i < singA*singB; ++i) {
                adj_list[A].erase(adj_list[A].find(B));
                adj_list[B].erase(adj_list[B].find(A));
            }
        }
    }
    //Canonical_Divisor K? perfroms blow-up on the merged curve
    K.blowup(this_id, intersections);

    //updates the 'max_test_number' variable by comparing it to the size of the 'def_tokens' -1
    max_test_number = std::max(max_test_number,(int)def_tokens.size() - 1);
    //processes the test options for the merge. For each test, it checks if a specific test option is provided in the def_tokens.
    //if not, it usese the general option from the end of def_tokens
    string option = def_tokens.size() == 1 ? "T" : def_tokens.back();
    for (int t = 0; t < tests_no; ++t) {
        if (def_tokens.size() > t + 1 + tests_start_index) {
            option = def_tokens[t + 1 + tests_start_index];
        }
        //depending on the option value, it adds the merged curve's ID to the corresponding vector
        if (option == "Fix" or option == "F") {
            fixed_curves[t].emplace_back(this_id);
        }
        else if (option == "Try" or option == "T") {
            try_curves[t].emplace_back(this_id);
        }
        else if (option == "Ign" or option == "I") {
            ignored_curves[t].emplace_back(this_id);
        }
        else {
            error("Invalid test option for Name/Merge \'" + def_tokens[0] + "\'.",line_no-1);
        }
    }
}

int Canonical_Divisor::exceptional_intersection(map<int,int>& intersections) {
    int result = 0;
    //iterates over 'components_including_forgotten' each element is assigned to comp.
    //then the id of that comp object is summed into result
    for (auto& comp : components_including_forgotten) {
        result += comp.multiplicity*intersections[comp.id];
    }
    return result; // Return the total exceptional intersection value
}
/*Over all this This function calculates the exceptional intersection value based on the provided intersections
 map and the components stored in the components_including_forgotten vector. It iterates over each component, 
 retrieves its multiplicity and corresponding intersection value from the intersections map, and accumulates the product of the multiplicity and intersection value.
  The final result is returned as the exceptional intersection value. */

int Canonical_Divisor::blowup_curve_self_int_delta(map<int,int>& intersections) {
    int ex_inters = exceptional_intersection(intersections);// Compute the exceptional intersection value by calling the exceptional_intersection function
    int delta_arithmetic_genus = 0; // Initialize the delta of the arithmetic genus
    for (auto iter = components_including_forgotten.rbegin(); iter != components_including_forgotten.rend(); ++iter) {
       // Iterate over the components_including_forgotten vector in reverse order using a reverse iterator
        auto& comp = *iter;// Retrieve the current component
        int inters = intersections[comp.id];// Retrieve the intersection value of the current component
        delta_arithmetic_genus += inters*(inters-1)/2;// Update the delta of the arithmetic genus by adding the contribution from the current component
        if (comp.left_parent != -1) {// Update the intersections of the left and right parents of the current component
        // by adding the intersection value of the current component
            intersections[comp.left_parent] += inters;
        }
        if (comp.right_parent != -1) {
            intersections[comp.right_parent] += inters;
        }
    }// Compute the final delta of the arithmetic genus by subtracting the exceptional intersections
    // and doubling the negative value of delta_arithmetic_genus
    return -2*delta_arithmetic_genus - ex_inters;
}
/*Over all this This function calculates the delta of the arithmetic genus resulting from blowing up a curve, based on the provided intersections map
 and the components stored in the components_including_forgotten vector.*/

void Canonical_Divisor::blowup(int id, const map<int,int>& intersections) {
    self_int--;// Decrease the self-intersection value by 1
    // Initialize variables for multiplicity, left parent, and right parent
    int mult = 1;
    int left_p = -1;
    int right_p = -1;
     // Iterate over the components_including_forgotten vector
    for (auto& comp : components_including_forgotten) {
        // Check if the current component id exists in the intersections map and its intersection value is greater than 0
        if (contains(intersections,comp.id) and intersections.at(comp.id) > 0) {
            // Assign the component id as the left parent if left_p is not assigned yet, otherwise assign it as the right parent
            if (left_p == -1) {
                left_p = comp.id;
            }
            else {
                right_p = comp.id;
            }
            // Increase the multiplicity by the component's multiplicity value
            mult += comp.multiplicity;
        }
    }
    // Add the current id to the used_components_including_forgotten set
    used_components_including_forgotten.insert(id);
    // Create a new component with the provided id, multiplicity, left parent, and right parent,
    // and add it to the components_including_forgotten vector
    components_including_forgotten.emplace_back(id,mult,left_p,right_p);
}
/* Over all This function performs the blow-up operation on a canonical divisor,
 based on the provided id and intersections map*/

void Reader::parse_make_fiber(const vector<string>& def_tokens, const vector<string>& content_tokens) {
    fiber_type.emplace_back(def_tokens[0]); // Add the fiber type to the fiber_type vector
    fibers.emplace_back(); // Add an empty vector for the fiber
    int n = content_tokens.size();// Get the size of the content_tokens vector
    if (n == 0) {// Check if the content_tokens vector is empty
        error("Fiber declaration empty.");
    }
    for (const string& curve : content_tokens) { // Iterate over the content_tokens vector
        if (!contains(curve_id,curve)) {// Check if the curve is defined in the curve_id map
            error("Curve \'" + curve + "\' is undefined.");
        }
        int id = curve_id[curve];// Get the id of the curve from the curve_id map
        if (contains(curves_in_fibers,id)) { // Check if the curve is already part of a fiber
            error("Curve \'" + curve + "\' is already part of a fiber.");
        }
        fibers.back().emplace_back(id);// Add the curve id to the current fiber
        curves_in_fibers.insert(id);// Add the curve id to the curves_in_fibers set
        if (contains(K.used_components_including_forgotten,id)) {// Check if the curve is in the used_components_including_forgotten set
            forgotten_exceptionals.insert(id);
        }
        sections.erase(id);// Remove the curve id from the sections map
        for (int t = 0; t < tests_no; ++t) {// Update the fixed_curves, try_curves, and ignored_curves vectors for each test
            auto it = std::find(fixed_curves[t].begin(),fixed_curves[t].end(),id);// Find the position of 'id' in 'fixed_curves[t]' vector
            if (it != fixed_curves[t].end()) {// Check if 'id' is found in 'fixed_curves[t]'
                std::iter_swap(it,fixed_curves[t].end()-1);// Swap 'id' with the last element in 'fixed_curves[t]'
                fixed_curves[t].erase(fixed_curves[t].end()-1);// Erase the last element in 'fixed_curves[t]'
            }
            it = std::find(try_curves[t].begin(),try_curves[t].end(),id);// Find the position of 'id' in 'try_curves[t]' vector
            if (it != try_curves[t].end()) {// Check if 'id' is found in 'try_curves[t]'
                std::iter_swap(it,try_curves[t].end()-1);// Swap 'id' with the last element in 'try_curves[t]'
                try_curves[t].erase(try_curves[t].end()-1);// Erase the last element in 'try_curves[t]'
            }
            it = std::find(ignored_curves[t].begin(),ignored_curves[t].end(),id);// Find the position of 'id' in 'ignored_curves[t]' vector
            if (it != ignored_curves[t].end()) {  // Check if 'id' is found in 'ignored_curves[t]'
                std::iter_swap(it,ignored_curves[t].end()-1);// Swap 'id' with the last element in 'ignored_curves[t]'
                ignored_curves[t].erase(ignored_curves[t].end()-1);// Erase the last element in 'ignored_curves[t]'
            }
        }/*Over all this loop The loop iterates over the range of tests, and for each test, it searches for the position of id in the corresponding vector (fixed_curves[t], 
        try_curves[t], or ignored_curves[t]). If id is found, it swaps it with the last element in the vector and then removes the last element. Essentially,
         it moves id to the end of the vector and removes it from the vector.*/
    }
    max_test_number = std::max(max_test_number,(int)def_tokens.size() - 1);
    // Update the max_test_number based on the number of tokens in def_tokens
    string option = def_tokens.size() == 1 ? "T" : def_tokens.back();
    // Determine the option based on the number of tokens in def_tokens
    for (int t = 0; t < tests_no; ++t) {// Iterate over the tests
        if (def_tokens.size() > t + 1 + tests_start_index) {// Check if there are more tokens in def_tokens for the current test
            option = def_tokens[t + 1 + tests_start_index];
        }
        if (option == "Fix" or option == "F") {// Update the corresponding vectors based on the option
            for (int curve : fibers.back()) {// Update 'fixed_curves[t]' vector by adding curves from the current fiber
                fixed_curves[t].emplace_back(curve);
            }
        }
        else if (option == "Try" or option == "T") {
            for (int curve : fibers.back()) {// Update 'try_curves[t]' vector by adding curves from the current fiber
                try_curves[t].emplace_back(curve);
            }
        }
        else if (option == "Dis" or option == "D") {
            if (n == 1){// Update 'choose_curves[t]' or 'ignored_curves[t]' vector based on the number of curves in the current fiber
                ignored_curves[t].emplace_back(fibers.back()[0]);
            }
            else {
                choose_curves[t].emplace_back(fibers.back());
            }
        }
        else if (option == "Ign" or option == "I") {
            for (int curve : fibers.back()) {// Update 'ignored_curves[t]' vector by adding curves from the current fiber
                ignored_curves[t].emplace_back(curve);
            }
        }
        else {// Handle the case where the option is invalid
            error("Invalid test option for MakeFiber " + def_tokens[0] + ".",line_no-1);
        }
    }
}

//Parses each curve in 'tokens' vector and performs checks
void Reader::parse_forget_exceptional(const vector<string>& tokens) {
    //iterates over each element in tokens
    for (const string& curve : tokens) {
        //check if curve in 'tokens' exists in curve_id
        if (!contains(curve_id,curve)) {
            //if not then error
            error("Curve \'" + curve + "\' is undefined.");
        }
        //if it does exist, it saves the associated id from the "curve_id" map
        int id = curve_id[curve];
        //check if the id is present in K.used_components_including_forgotten
        if (!contains(K.used_components_including_forgotten,id)) {
            //if not, then error
            error("Curve \'" + curve + "\' is not an exceptional.");
        }
        //check if the id is present in forgotten_exceptionals
        if (contains(forgotten_exceptionals,id)) {
            //if so, warning message
            warning("Curve \'" + curve + "\' is already forgotten.");
        }
        else {
            //if not the case above, it adds the 'id' to sections and forgotten_exceptionals
            sections.insert(id);
            forgotten_exceptionals.insert(id);
        }
    }
}

long long Reader::get_test_numbers(vector<long long>& number_of_tests) const {
    if (curves_used_exactly != -1) {// Check if there is a specific number of curves used exactly
        return get_test_numbers_exact_curves(number_of_tests);// Call another function to handle that case
    }
    long long total_tests = 0;// Variable to store the total number of test cases
    number_of_tests.resize(tests_no);// Resize the vector to store the number of tests for each individual test
  // Iterate over each test
    for (int t = 0; t < tests_no; ++t) {
        int curves_to_test = try_curves[t].size();// Initialize the number of curves to test with the size of the "try_curves" vector

        for (auto& choose_set : choose_curves[t]) {// Calculate the total number of curves to test by adding the sizes of the "choose_curves" sets
            curves_to_test += choose_set.size();
        }
        if (curves_to_test >= 61) {// Check if the number of curves to test exceeds the limit
            error("Too many test cases.");
        }
        long long current_test_number = 1ll<<try_curves[t].size();// Calculate the current test number based on the size of the "try_curves" vector
        for (auto& choose_set : choose_curves[t]) {// Multiply the current test number by the number of options in each "choose_curves" set
            current_test_number *= (1ll<<choose_set.size()) - 1ll;
        }
        total_tests += current_test_number;// Update the total number of test cases by adding the current test number
        if (total_tests >= (1ll<<62)) {
            error("Too many test cases.");
        }
        number_of_tests[t] = current_test_number; // Store the current test number in the vector of number of tests
    }
    return total_tests;// Return the total number of test cases
}

//calculates the number of test cases for each test and stores result in the 'number_of_tests' vector.
long long Reader::get_test_numbers_exact_curves(vector<long long>& number_of_tests) const {
    //keep track of the total number of tests
    long long total_tests = 0;
    //resize so that number_of_tests has the same size as tests_no
    number_of_tests.resize(tests_no);
    for (int t = 0; t < tests_no; ++t) {
        //retrieves the number of curves to test for the current test case
        int curves_to_test = try_curves[t].size();
        //iterates over each element of choose_curves and adds the size of each 'choose_set' to 'curves_to_test'
        for (auto& choose_set : choose_curves[t]) {
            curves_to_test += choose_set.size();
        }
        //check if total number of curves to test is greater than or equal to 61
        if (curves_to_test >= 61) {
            //if so, error
            error("Too many test cases.");
        }
        //retrieves the number of fixed curves for the currnet test case
        int fixed = fixed_curves[t].size();
        //check if the number of fixed curves is less than or equal to the used curves
        //and the sum of curves to test + fixed vurves is greater than or equal to curves used exactly.
        if (fixed <= curves_used_exactly and curves_to_test + fixed >= curves_used_exactly) {
            //if so, calculates the current test number
            long long current_test_number = algs::nCr(curves_to_test, curves_used_exactly - fixed);
            //adds the current test number to the total tests
            total_tests += current_test_number;
            //check if total test is greater than or equal to 2^62
            if (total_tests >= (1ll<<62)) {
                //if so, error
                error("Too many test cases.");
            }
            //assigns the current test numbert to the corresponding index in the 'number_of_tests' vector
            number_of_tests[t] = current_test_number;
        }
        else {
            //if not, assigns 0 to the number_of_tests vector
            number_of_tests[t] = 0;
        }
    }
    return total_tests;
}
