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

//Change: We changed the map to contain vector that contains a pair of a vector, int
const map<string,vector<std::pair<vector<int>, int>>> singular_fibers {
    {"I1", {
        {{0}, 0}
    }},
    {"I2", {
        {{1,1}, -2},
        {{0,0}, -2}
    }},
    {"I3", {
        {{2,1}, -2},
        {{0,2}, -2},
        {{1,0}, -2}
    }},
    {"I4", {
        {{3,1}, -2},
        {{0,2}, -2},
        {{1,3}, -2},
        {{2,0}, -2}
    }},
    {"I5", {
        {{4,1}, -2},
        {{0,2}, -2},
        {{1,3}, -2},
        {{2,4}, -2},
        {{3,0}, -2}
    }},
    {"I6", {
        {{5,1}, -2},
        {{0,2}, -2},
        {{1,3}, -2},
        {{2,4}, -2},
        {{3,5}, -2},
        {{4,0}, -2}
    }},
    // {"I7", {
    //     {6,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,0}
    // }},
    // {"I8", {
    //     {7,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,0}
    // }},
    // {"I9", {
    //     {8,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,0}
    // }},
    // {"I10", {
    //     {9,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,0}
    // }},
    // {"I11", {
    //     {10,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,0}
    // }},
    // {"I12", {
    //     {11,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,0}
    // }},
    // {"I13", {
    //     {12,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,12},
    //     {11,0}
    // }},
    // {"I14", {
    //     {13,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,12},
    //     {11,13},
    //     {12,0}
    // }},
    // {"I15", {
    //     {14,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,12},
    //     {11,13},
    //     {12,14},
    //     {13,0}
    // }},
    // {"I16", {
    //     {15,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,12},
    //     {11,13},
    //     {12,14},
    //     {13,15},
    //     {14,0}
    // }},
    // {"I17", {
    //     {16,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,12},
    //     {11,13},
    //     {12,14},
    //     {13,15},
    //     {14,16},
    //     {15,0}
    // }},
    // {"I18", {
    //     {17,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,12},
    //     {11,13},
    //     {12,14},
    //     {13,15},
    //     {14,16},
    //     {15,17},
    //     {16,0}
    // }},
    // {"I19", {
    //     {18,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,12},
    //     {11,13},
    //     {12,14},
    //     {13,15},
    //     {14,16},
    //     {15,17},
    //     {16,18},
    //     {17,0}
    // }},
    // {"I20", {
    //     {19,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,12},
    //     {11,13},
    //     {12,14},
    //     {13,15},
    //     {14,16},
    //     {15,17},
    //     {16,18},
    //     {17,19},
    //     {18,0}
    // }},
    // {"I21", {
    //     {20,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,12},
    //     {11,13},
    //     {12,14},
    //     {13,15},
    //     {14,16},
    //     {15,17},
    //     {16,18},
    //     {17,19},
    //     {18,20},
    //     {19,0}
    // }},
    // {"I22", {
    //     {21,1},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7,9},
    //     {8,10},
    //     {9,11},
    //     {10,12},
    //     {11,13},
    //     {12,14},
    //     {13,15},
    //     {14,16},
    //     {15,17},
    //     {16,18},
    //     {17,19},
    //     {18,20},
    //     {19,21},
    //     {20,0}
    // }},
    // {"I0*", {
    //     {1,2,3,4},
    //     {0},
    //     {0},
    //     {0},
    //     {0}
    // }},
    // {"I1*", {
    //     {1,2,3},
    //     {0,4,5},
    //     {0},
    //     {0},
    //     {1},
    //     {1}
    // }},
    // {"I2*", {
    //     {1,3,4},
    //     {0,2},
    //     {1,5,6},
    //     {0},
    //     {0},
    //     {2},
    //     {2}
    // }},
    // {"I3*", {
    //     {1,4,5},
    //     {0,2},
    //     {1,3},
    //     {2,6,7},
    //     {0},
    //     {0},
    //     {3},
    //     {3}
    // }},
    // {"I4*", {
    //     {1,5,6},
    //     {0,2},
    //     {1,3},
    //     {2,4},
    //     {3,7,8},
    //     {0},
    //     {0},
    //     {4},
    //     {4}
    // }},
    // {"IV*", {
    //     {1,3,5},
    //     {0,2},
    //     {1},
    //     {0,4},
    //     {3},
    //     {0,6},
    //     {5}
    // }},
    // {"III*", {
    //     {1,2,5},
    //     {0},
    //     {0,3},
    //     {2,4},
    //     {3},
    //     {0,6},
    //     {5,7},
    //     {6}
    // }},
    // {"II*", {
    //     {1,2,4},
    //     {0},
    //     {0,3},
    //     {2},
    //     {0,5},
    //     {4,6},
    //     {5,7},
    //     {6,8},
    //     {7}
    // }},
    
    //Elliptic Type [1]
    {"E1,I000", {
        //should be one node but how?
       {{}, -2} //SI-2
    }},
    {"E1,I*000", {
        {{1,2,3,4,5,6}, -3}, //M2
        {{0}, -2},
        {{0}, -2},
        {{0}, -2},
        {{0}, -2},
        {{0}, -2},
        {{0}, -2}
    }},
    // {"E1,II", {
    //     {1,2}, //G1,SI-1
    //     {0}, //G0,SI-2
    //     {0} //G0,SI-2
    // }},
    {"E1,III", {
        {{1,2,3,4}, -2}, //M3
        {{0}, -3},
        {{0}, -3},
        {{0,5}, -2}, //M2
        {{0,6}, -2}, //M2
        {{3}, -2},
        {{4}, -2}
    }},
    {"E1,IV", {
        {{1,2,3,4}, -2}, //M6
        {{0}, -3}, //M2
        {{0}, -2}, //M3
        {{0}, -2}, //M3
        {{0,5}, -2}, //M4
        {{4}, -2} //M2
    }},
    // {"EI,V", {
    //     {1,2,3,4},
    //     {0},
    //     {0},
    //     {0},
    //     {0}
    // }},
    {"E1,V*", {
        {{1,2,3}, -2}, //G0,M6
        {{0,4}, -2},//G0,M5
        {{0}, -3},//G0,M2
        {{0,5}, -2},//G0,M5
        {{1,6}, -2},//G0,M4
        {{3,7}, -2},//G0,M4
        {{4,8}, -2},//G0,M3
        {{5,9}, -2}, //G0,M3
        {{6,10}, -2}, //G0,M2
        {{7,11}, -2},//G0,M2
        {{8}, -2}, //G0,M1
        {{9}, -2}//G0,M1
    }},
    {"E1,VI", {
        {{1,2,3,4}, -2},//G0,M4
        {{0}, -4},//G0,M1
        {{0}, -2},//G0,M2
        {{0}, -2},//G0,M2
        {{0,5}, -2},//G0,M3
        {{4,6}, -2},//G0,M2
        {{5}, -2} //G0,M1
    }},
    // {"E1,VII", {
    //     {1,2,3},
    //     {0},
    //     {0,4},
    //     {0}
    // }},
    {"E1,VII*", {
        {{1,2,3}, -2}, //G0,M8
        {{0,5}, -2}, //G0,M5                                                                                    
        {{0}, -2}, //G0,M4
        {{0,4}, -2}, //G0,M7
        {{3,6}, -2}, //G0,M6
        {{1,7}, -3}, //G0,M2
        {{4,8}, -2}, //G0,M5
        {{5}, -2}, //G0,M1
        {{6,9}, -2}, //G0,M4
        {{8,10}, -2}, //G0,M3
        {{9,11}, -2}, //G0,M2
        {{10}, -2}//G0,M1
    }},
    // {"E1,VIII1", {
    //     {}
    // }},
    {"E1,VIII2", {
        {{1,2,3}, -2}, //M10
        {{0,4}, -2}, //M7
        {{0}, -2}, //M5
        {{0,5}, -2}, //M8
        {{1,6}, -2}, //M4
        {{3,7}, -2}, //M6
        {{4}, -4},
        {{5,8}, -2}, //M4
        {{7}, -2} //M2
    }},
    // {"E1,VIII3", {
    //     {1,2},
    //     {0,3},
    //     {0,4},
    //     {1},
    //     {2,5},
    //     {4}
    // }},
    {"E1,VIII4", {
        {{1,2,3}, -2}, //M10
        {{0,4}, -2}, //M6
        {{0}, -2}, //M5
        {{0,5}, -2}, //M9
        {{1}, -3}, //M2
        {{3,6}, -2}, //M8
        {{5,7}, -2}, //M7
        {{6,8}, -2}, //M6
        {{7,9}, -2}, //M5
        {{8,10}, -2}, //M4
        {{9,11}, -2}, //M3
        {{10,12}, -2}, //M2
        {{11}, -2}
    }},
    // {"E1,IX1", {
    //     {}
    // }},
    // {"E1,IX2", {
    //     {}
    // }},
    {"E1,IX3", {
        {{1,2,3}, -2}, //M5
        {{0,4}, -2},
        {{0,5}, -2}, //M4
        {{0,6}, -2}, //M4
        {{1}, -3}, //M2
        {{2,7}, -2}, //M3
        {{3,8}, -2}, //M3
        {{5,9}, -2}, //M2
        {{6,10}, -2}, //M2
        {{7}, -2},
        {{8}, -2}
    }},
    {"E1,IX4", {
        {{1,2,3}, -2}, // M5
        {{0,4}, -2}, //M3
        {{0,5}, -2}, //M3
        {{0,6}, -2}, //M4
        {{1}, -3}, //
        {{2}, -3}, //
        {{3,7}, -2}, //M3
        {{6,8}, -2}, //M2
        {{7}, -2} //
    }},

    // //Elliptic Type [2]
    
    // //E2,I0I0m THIS ONE HAS A IN IT 
    // {"E2,I0I0m1", {
    //     {1,2}, //G0,SI-2
    //     {0}, //G1,SI-1
    //     {0} //G1,SI-1
    // }},
    // {"E2,I0I0m2", {
    //     {1,2}, //G0,SI-2
    //     {0}, //G1,SI-1
    //     {0,3}, //G0,SI-2
    //     {2} //G1,SI-1
    // }},
    // {"E2,I0I0m3", {
    //     {1,2}, //G0,SI-2
    //     {0}, //G1,SI-1
    //     {0,3}, //G0,SI-2
    //     {2,4}, //G0,SI-2
    //     {3} //G1,SI-1
    // }},
    // {"E2,I0I0m4", {
    //     {1,2}, //G0,SI-2
    //     {0}, //G1,SI-1
    //     {0,3}, //G0,SI-2
    //     {2,4}, //G0,SI-2
    //     {3,5}, //G0,SI-2
    //     {4} //G1,SI-1
    // }},
    // {"E2,I0I0m5", {
    //     {1,2}, //G0,SI-2
    //     {0}, //G1,SI-1
    //     {0,3}, //G0,SI-2
    //     {2,4}, //G0,SI-2
    //     {3,5}, //G0,SI-2
    //     {4,6}, //G0,SI-2
    //     {5} //G1,SI-1
    // }},
    // //E2,I0*I0*m
    {"E2,I0*I0*m0", {
        {{1,2}, -4}, 
        {{0,3,5,7},-2}, //M2
        {{0,4,6,8}, -2}, //M2
        {{1}, -2}, 
        {{2}, -2}, 
        {{1}, -2}, 
        {{2}, -2}, 
        {{1}, -2}, 
        {{2}, -2} 
    }},

    //tHIS IS MISSING m1
    {"E2,I0*I0*m2", {
        {{1,2}, -2}, 
        {{0,3}, -3}, 
        {{0,4}, -3}, 
        {{1,5,7,9}, -2}, //M2
        {{2,6,8,10}, -2}, //M2
        {{3}, -2}, 
        {{4}, -2}, 
        {{3}, -2}, 
        {{4}, -2}, 
        {{3}, -2}, 
        {{4}, -2} 

    }},
        {"E2,I0*I0*m3", {
        {{1,2}, -2}, 
        {{0,3}, -2}, 
        {{0,4}, -3}, 
        {{1,5}, -3},
        {{2,6,8,10}, -2},//M2
        {{3,7,9,11}, -2},//M2
        {{4}, -2}, 
        {{5}, -2},
        {{4}, -2}, 
        {{5}, -2}, 
        {{4}, -2},
        {{5}, -2} 
    }},
    {"E2,I0*I0*m4", {
        {{1,2}, -2}, //
        {{0,3}, -2}, //
        {{0,4}, -2}, //
        {{1,5}, -3}, //
        {{2,6}, -3}, //
        {{3,7,9,11}, -2},//M2
        {{4,8,10,12}, -2}, //M2
        {{5}, -2}, //
        {{6}, -2}, //
        {{5}, -2}, //
        {{6}, -2}, //
        {{5}, -2}, //
        {{6}, -2} //

    }},
    {"E2,I0*I0*m5", {
        {{1,2}, -2}, //
        {{0,3}, -2}, //
        {{0,4}, -2}, //
        {{1,5}, -3}, //
        {{2,6}, -2}, //M2
        {{3,7,9,11}, -2}, //M2
        {{4,8}, -3}, //
        {{5}, -2}, //
        {{6,10,12,13}, -2}, //
        {{5}, -2}, //
        {{8}, -2}, //
        {{5}, -2}, //
        {{8}, -2}, //
        {{8}, -2} //
    }},
     //E2,I0I0*m 
    {"E2,I0I0*m0", {
        {{1,2,3}, -2}, //M2
        {{0}, -2},
        {{0}, -2},
        {{0}, -2}
        //there was a genus 1 curve here
    }},
    {"E2,I0I0*m1", {
        {{1,2,3,4}, -2}, //M2
        {{0}, -3},
        {{0}, -2},
        {{0}, -2},
        {{0}, -2}
        //there was a genus 1 curve here
    }},
    {"E2,I0I0*m2", {
        {{1,2,3,4}, -2}, //M2
        {{0,5}, -3},
        {{0}, -2},
        {{0}, -2},
        {{0}, -2},
        {{1}, -2}
        //there was a genus 1 curve here
    }},
    {"E2,I0I0*m3", {
        {{1,2,3,4}, -2}, //M2
        {{0,5}, -3},
        {{0}, -2},
        {{0}, -2},
        {{0}, -2},
        {{1,6}, -2},
        {{5}, -2}
        //there was a genus 1 curve here
    }},
    {"E2,I0I0*m4", {
        {{1,2,3,4}, -2}, //M2
        {{0,5}, -3},
        {{0}, -2},
        {{0}, -2},
        {{0}, -2},
        {{1,6}, -2},
        {{5,7}, -2},
        {{6}, -2}
        //there was a genus 1 curve here
    }},
    {"E2,I0I0*m5", {
        {{1,2,3,4}, -2}, //M2
        {{0,5}, -3},
        {{0}, -2},
        {{0}, -2},
        {{0}, -2},
        {{1,6}, -2},
        {{5,7}, -2},
        {{6,8}, -2},
        {{7}, -2}
        //there was a genus 1 curve here
    }},
    //need to ask what I should do when m=0 is insignificant
    {"E2,2I0m1", {
        {{1,2,3}, -2}, //M2
        {{0}, -2}, //M2
        {{0}, -2},
        {{0}, -2}
        //there was a genus 1 curve here
    }},
    {"E2,2I0m2", {
        {{1,2,3}, -2}, //M2
        {{0,4}, -2}, //M2
        {{0}, -2},
        {{0}, -2},
        {{1}, -2} //M2
        //there was a genus 1 curve here
    }},
    {"E2,2I0m3", {
        {{1,2,3}, -2}, //M2
        {{0,4}, -2},
        {{0}, -2},
        {{0}, -2},
        {{1,5}, -2}, //M2
        {{4}, -2} //M2
        //there was a genus 1 curve here
    }},
    {"E2,2I0m4", {
        {{1,2,3}, -2}, //M2
        {{0,4}, -2},
        {{0}, -2},
        {{0}, -2},
        {{1,5}, -2},
        {{4,6}, -2}, //M2
        {{5}, -2} //M2
        //there was a genus 1 curve here
    }},
    {"E2,2I0m5", {
        {{1,2,3}, -2}, //M2
        {{0,4}, -2},
        {{0}, -2},
        {{0}, -2},
        {{1,5}, -2},
        {{4,6}, -2},
        {{5,7}, -2}, //M2
        {{6}, -2} //M2
        //there was a genus 1 curve here
    }},

    //E2,2I0*m case
    {"E2,2I0*m1", {
        {{1,2,3,4}, -2}, //M4
        {{0,5}, -3}, //M2
        {{0}, -2}, //M2
        {{0}, -2}, //M2
        {{0}, -2}, //M2
        {{1,6,7}, -2}, //M2
        {{5}, -2},
        {{5}, -2}
    }},
    {"E2,2I0*m2", {
        {{1,2,3,4}, -2}, //M4
        {{0,5}, -3}, //M2
        {{0}, -2}, //M2
        {{0}, -2}, //M2
        {{0}, -2}, //M2
        {{1,6}, -2}, //M2
        {{5,7,8}, -2}, //M2
        {{6}, -2},
        {{6}, -2}
    }},
    {"E2,2I0*m3", {
        {{1,2,3,4}, -2}, //M4
        {{0,5}, -3}, //M2
        {{0}, -2}, //M2
        {{0}, -2}, //M2
        {{0}, -2}, //M2
        {{1,6}, -2}, //M2
        {{5,7}, -2},
        {{6,8,9}, -2}, //M2
        {{7}, -2},
        {{7}, -2}
    }},
    {"E2,2I0*m4", {
        {{1,2,3,4}, -2}, //M4
        {{0,5}, -3}, //M2
        {{0}, -2}, //M2
        {{0}, -2}, //M2
        {{0}, -2}, //M2
        {{1,6}, -2}, //M2
        {{5,7}, -2},
        {{6,8}, -2},
        {{7,9,10}, -2}, //M2
        {{8}, -2},
        {{8}, -2}
    }},
    {"E2,2I0*m5", {
        {{1,2,3,4}, -2}, //M4
        {{0,5}, -3}, //M2
        {{0}, -2}, //M2
        {{0}, -2}, //M2
        {{0}, -2}, //M2
        {{1,6}, -2}, //M2
        {{5,7}, -2},
        {{6,8}, -2},
        {{7,9}, -2},
        {{8,10,11}, -2}, //M2
        {{9}, -2},
        {{9}, -2}
    }},
    // {"E2,I0IIm", {
    //     {}
    // }},
    // {"E2,I0II*m", {
    //     {}
    // }},
    // {"E2,I0IVm", {
    //     {}
    // }},
    {"E2,I0IV*m2", {
       {{1},-2},
       {{0,2}, -3},
       {{1,3}, -2},//M2
       {{2,4,5}, -2},//M3
       {{3,6}, -2},//M2
       {{3,7}, -2},//M2
       {{4}, -2},
       {{5}, -2}
       //There was a -1 curve here
       }},
    {"E2,I0IV*m3", {
       {{1},-2},
       {{0,2}, -2},
       {{1,3}, -3},
       {{2,4}, -2},//M2
       {{3,5,6}, -2},//M3
       {{4,7}, -2},//M2
       {{4,8}, -2},//M2
       {{5}, -2},
       {{6}, -2}
       //There was a -1 curve here
       }},

       {"E2,I0IV*m4", {
       {{1},-2},
       {{0,2}, -2},
       {{1,3}, -2},
       {{2,4}, -3},
       {{3,5}, -2},//M2
       {{4,6,7}, -2},//M3
       {{5,8},-2},//M2
       {{5,9},-2},//M2
       {{6}, -2},
       {{7}, -2}
       //There was a -1 curve here
       }},
};

//python-like split yay
vector<string> split(const string& s, char c = '\0') {
    vector<string> result;
    int last_whitespace = -1;
    for (int i = 0; i < s.size(); ++i) {
        if ((c != 0 and s[i] == c) or
        (c == 0 and (s[i] == ' ' or s[i] == '\n' or s[i] == '\r' or s[i] == '\t'))) {
            if (i - last_whitespace > 1) {
                result.push_back(s.substr(last_whitespace+1, i - last_whitespace - 1));
            }
            last_whitespace = i;
        }
    }
    if (last_whitespace != s.size() - 1) {
        result.push_back(s.substr(last_whitespace+1));
    }
    return result;
}

bool safe_stoi(const string& s, int& result) {
    try {
        size_t z;
        result = stoi(s,&z);
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
        size_t z;
        result = stoll(s,&z);
        if (z != s.size()) {
            return 0;
        }
    }
    catch (std::exception& e) {
        return 0;
    }
    return 1;
}

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

void Reader::parse(istream& input) {
    string line;
    string next_line;
    vector<string> tokens;
    vector<string> next_tokens;
    State previous_state = start_;
    State state = start_;
    while (getline(input,line)) {
        line_no++;
        tokens = split(line);
        if (tokens.size() == 0) continue;
        if (tokens[0][0] == '#') continue;
        if (tokens[0].size() > 1 and tokens[0][0] == '/' and tokens[0][1] == '/') continue;
        if (tokens[0].size() > 1 and tokens[0][0] == '/' and tokens[0][1] == '*') {
            previous_state = state;
            state = comment_;
            continue;
        }
        if (state == comment_) {
            if (tokens[0].size() > 1 and tokens[0][0] == '*' and tokens[0][1] == '/') {
                state = previous_state;
                continue;
            }
            continue;
        }
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

    if (tests_no > 1 and tests_start_index + tests_no > max_test_number) {
        warning("Test range exedes number of tests given by curve options. Redundant tests are ignored.");
        tests_no = std::max(1,max_test_number - tests_start_index);
    }

    if (parse_only) {
        warning("Parse only debug mode: no testing is done.");
    }
}

void Reader::parse_option(const vector<string>& tokens) {
    if (tokens[0] == "Tests:") {
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
    else if (tokens[0] == "SubTests:") {
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
    else if (tokens[0] == "Output:") {
        if (tokens.size() != 2) {
            error("Option \'Output\' must take exactly one argument.");
        }
        output_filename = tokens[1];
        return;
    }
    else if (tokens[0] == "Summary_Output:") {
        if (tokens.size() != 2) {
            error("Option \'Summary_Output\' must take exactly one argument.");
        }
        summary_filename = tokens[1];
        return;
    }
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
    else {
        error("Invalid option: " + tokens[0]);
    }
}


void Reader::parse_fiber(const vector<string>& def_tokens, const vector<string>& content_tokens) {
    if (!contains(singular_fibers,def_tokens[0])) {
        error("Unknown fiber type or invalid command: " + def_tokens[0] + ".",line_no-1);
    }
    fiber_type.emplace_back(def_tokens[0]);
    fibers.emplace_back();
    int initial_index = curve_no;
    int n = content_tokens.size();
    for (const string& curve : content_tokens) {
        if (contains(curve_id,curve)) {
            error("Curve \'" + curve + "\' is already defined.");
        }
        curve_id[curve] = curve_no;
        fibers.back().emplace_back(curve_no);
        curves_in_fibers.insert(curve_no);
        curve_name.emplace_back(curve);
        adj_list.emplace_back();
        //Change: we took out the if else statement that sets the self intersections to either 0 or -2.

        curve_no++;
    }

    //change: updated &fiber_graph so that it reflects the changes in the sigular_fibers map.
    const vector<std::pair<vector<int>, int>> &fiber_graph = singular_fibers.at(def_tokens[0]);
    if (fiber_graph.size() != n) {
        error("Fiber " + def_tokens[0] + " requires " + to_string(n) + ", " + to_string(content_tokens.size()) + " found.");
    }

    //change: this is a replacement for the if/else statement. reads the self intersection part of the pair.
    for (const auto& pair : singular_fibers.at(def_tokens[0])){
        self_int.emplace_back(pair.second);
    }

    //reading the hardcoded fibers

    //change: this for loop was iterating over every element of fiber_graph, which we changed into a pair not a single integer anymore.
    //So, we did .first so that it reads the first part of the pair.
    for (int i = 0; i < n; ++i) {
        for (int neighbor : fiber_graph[i].first) {
            adj_list[initial_index + i].insert(initial_index + neighbor);
        }
    }

    max_test_number = std::max(max_test_number,(int)def_tokens.size() - 1);
    string option = def_tokens.size() == 1 ? "T" : def_tokens.back();
    for (int t = 0; t < tests_no; ++t) {
        if (def_tokens.size() > t + 1 + tests_start_index) {
            option = def_tokens[t + 1 + tests_start_index];
        }
        if (option == "Fix" or option == "F") {
            for (int curve : fibers.back()) {
                fixed_curves[t].emplace_back(curve);
            }
        }
        else if (option == "Try" or option == "T") {
            for (int curve : fibers.back()) {
                try_curves[t].emplace_back(curve);
            }
        }
        else if (option == "Dis" or option == "D") {
            if (n == 1){
                ignored_curves[t].emplace_back(fibers.back()[0]);
            }
            else {
                choose_curves[t].emplace_back(fibers.back());
            }
        }
        else if (option == "Ign" or option == "I") {
            for (int curve : fibers.back()) {
                ignored_curves[t].emplace_back(curve);
            }
        }
        else {
            error("Invalid test option for Fiber " + def_tokens[0] + ".",line_no-1);
        }
    }
}

void Reader::parse_section(const vector<string>& def_tokens, const vector<string>& content_tokens) {
    if (contains(curve_id,def_tokens[0])) {
        error("Curve \'" + def_tokens[0] + "\' is already defined.",line_no-1);
    }
    int this_id = curve_no;
    curve_id[def_tokens[0]] = this_id;
    sections.insert(this_id);
    curve_name.emplace_back(def_tokens[0]);
    adj_list.emplace_back();
    curve_no++;
    // Count the intersections with other curves and use it to get the new self_intersection
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
    if (section_input_mode == by_self_intersection_) {
        self_int.emplace_back(current_section_argument + K.blowup_curve_self_int_delta(intersections));
    }
    else {
        self_int.emplace_back(2*intersections[this_id] - 2 - current_section_argument - K.exceptional_intersection(intersections));
    }

    max_test_number = std::max(max_test_number,(int)def_tokens.size() - 1);
    string option = def_tokens.size() == 1 ? "T" : def_tokens.back();
    for (int t = 0; t < tests_no; ++t) {
        if (def_tokens.size() > t + 1 + tests_start_index) {
            option = def_tokens[t + 1 + tests_start_index];
        }
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

void Reader::parse_merge(const vector<string>& def_tokens, const vector<string>& content_tokens) {
    if (contains(curve_id,def_tokens[0])) {
        error("Curve \'" + def_tokens[0] + "\' is already defined.",line_no-1);
    }
    int this_id = curve_no;
    curve_id[def_tokens[0]] = this_id;
    curve_name.emplace_back(def_tokens[0]);
    self_int.emplace_back(-1);
    adj_list.emplace_back();
    curve_no++;
    map<int,int> intersections;
    for (const string& curve : content_tokens) {
        if (!contains(curve_id,curve)) {
            error("Curve \'" + curve + "\' is undefined.");
        }
        int id = curve_id[curve];
        if (id == this_id) {
            error("Exceptional curve \'" + def_tokens[0] + "\' must be smooth, cannot intersect itself.");
        }
        adj_list.back().insert(id);
        adj_list[id].insert(this_id);
        intersections[id]++;
    }
    for (auto iter = intersections.begin(); iter != intersections.end(); ++iter) {
        const int& A = iter->first;
        int& singA = iter->second;
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
    K.blowup(this_id, intersections);

    max_test_number = std::max(max_test_number,(int)def_tokens.size() - 1);
    string option = def_tokens.size() == 1 ? "T" : def_tokens.back();
    for (int t = 0; t < tests_no; ++t) {
        if (def_tokens.size() > t + 1 + tests_start_index) {
            option = def_tokens[t + 1 + tests_start_index];
        }
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
    for (auto& comp : components_including_forgotten) {
        result += comp.multiplicity*intersections[comp.id];
    }
    return result;
}

int Canonical_Divisor::blowup_curve_self_int_delta(map<int,int>& intersections) {
    int ex_inters = exceptional_intersection(intersections);
    int delta_arithmetic_genus = 0;
    for (auto iter = components_including_forgotten.rbegin(); iter != components_including_forgotten.rend(); ++iter) {
        auto& comp = *iter;
        int inters = intersections[comp.id];
        delta_arithmetic_genus += inters*(inters-1)/2;
        if (comp.left_parent != -1) {
            intersections[comp.left_parent] += inters;
        }
        if (comp.right_parent != -1) {
            intersections[comp.right_parent] += inters;
        }
    }
    return -2*delta_arithmetic_genus - ex_inters;
}

void Canonical_Divisor::blowup(int id, const map<int,int>& intersections) {
    self_int--;
    int mult = 1;
    int left_p = -1;
    int right_p = -1;
    for (auto& comp : components_including_forgotten) {
        if (contains(intersections,comp.id) and intersections.at(comp.id) > 0) {
            if (left_p == -1) {
                left_p = comp.id;
            }
            else {
                right_p = comp.id;
            }
            mult += comp.multiplicity;
        }
    }
    used_components_including_forgotten.insert(id);
    components_including_forgotten.emplace_back(id,mult,left_p,right_p);
}

void Reader::parse_make_fiber(const vector<string>& def_tokens, const vector<string>& content_tokens) {
    fiber_type.emplace_back(def_tokens[0]);
    fibers.emplace_back();
    int n = content_tokens.size();
    if (n == 0) {
        error("Fiber declaration empty.");
    }
    for (const string& curve : content_tokens) {
        if (!contains(curve_id,curve)) {
            error("Curve \'" + curve + "\' is undefined.");
        }
        int id = curve_id[curve];
        if (contains(curves_in_fibers,id)) {
            error("Curve \'" + curve + "\' is already part of a fiber.");
        }
        fibers.back().emplace_back(id);
        curves_in_fibers.insert(id);
        if (contains(K.used_components_including_forgotten,id)) {
            forgotten_exceptionals.insert(id);
        }
        sections.erase(id);
        for (int t = 0; t < tests_no; ++t) {
            auto it = std::find(fixed_curves[t].begin(),fixed_curves[t].end(),id);
            if (it != fixed_curves[t].end()) {
                std::iter_swap(it,fixed_curves[t].end()-1);
                fixed_curves[t].erase(fixed_curves[t].end()-1);
            }
            it = std::find(try_curves[t].begin(),try_curves[t].end(),id);
            if (it != try_curves[t].end()) {
                std::iter_swap(it,try_curves[t].end()-1);
                try_curves[t].erase(try_curves[t].end()-1);
            }
            it = std::find(ignored_curves[t].begin(),ignored_curves[t].end(),id);
            if (it != ignored_curves[t].end()) {
                std::iter_swap(it,ignored_curves[t].end()-1);
                ignored_curves[t].erase(ignored_curves[t].end()-1);
            }
        }
    }
    max_test_number = std::max(max_test_number,(int)def_tokens.size() - 1);
    string option = def_tokens.size() == 1 ? "T" : def_tokens.back();
    for (int t = 0; t < tests_no; ++t) {
        if (def_tokens.size() > t + 1 + tests_start_index) {
            option = def_tokens[t + 1 + tests_start_index];
        }
        if (option == "Fix" or option == "F") {
            for (int curve : fibers.back()) {
                fixed_curves[t].emplace_back(curve);
            }
        }
        else if (option == "Try" or option == "T") {
            for (int curve : fibers.back()) {
                try_curves[t].emplace_back(curve);
            }
        }
        else if (option == "Dis" or option == "D") {
            if (n == 1){
                ignored_curves[t].emplace_back(fibers.back()[0]);
            }
            else {
                choose_curves[t].emplace_back(fibers.back());
            }
        }
        else if (option == "Ign" or option == "I") {
            for (int curve : fibers.back()) {
                ignored_curves[t].emplace_back(curve);
            }
        }
        else {
            error("Invalid test option for MakeFiber " + def_tokens[0] + ".",line_no-1);
        }
    }
}

void Reader::parse_forget_exceptional(const vector<string>& tokens) {
    for (const string& curve : tokens) {
        if (!contains(curve_id,curve)) {
            error("Curve \'" + curve + "\' is undefined.");
        }
        int id = curve_id[curve];
        if (!contains(K.used_components_including_forgotten,id)) {
            error("Curve \'" + curve + "\' is not an exceptional.");
        }
        if (contains(forgotten_exceptionals,id)) {
            warning("Curve \'" + curve + "\' is already forgotten.");
        }
        else {
            sections.insert(id);
            forgotten_exceptionals.insert(id);
        }
    }
}

long long Reader::get_test_numbers(vector<long long>& number_of_tests) const {
    if (curves_used_exactly != -1) {
        return get_test_numbers_exact_curves(number_of_tests);
    }
    long long total_tests = 0;
    number_of_tests.resize(tests_no);
    for (int t = 0; t < tests_no; ++t) {
        int curves_to_test = try_curves[t].size();
        for (auto& choose_set : choose_curves[t]) {
            curves_to_test += choose_set.size();
        }
        if (curves_to_test >= 61) {
            error("Too many test cases.");
        }
        long long current_test_number = 1ll<<try_curves[t].size();
        for (auto& choose_set : choose_curves[t]) {
            current_test_number *= (1ll<<choose_set.size()) - 1ll;
        }
        total_tests += current_test_number;
        if (total_tests >= (1ll<<62)) {
            error("Too many test cases.");
        }
        number_of_tests[t] = current_test_number;
    }
    return total_tests;
}

long long Reader::get_test_numbers_exact_curves(vector<long long>& number_of_tests) const {
    long long total_tests = 0;
    number_of_tests.resize(tests_no);
    for (int t = 0; t < tests_no; ++t) {
        int curves_to_test = try_curves[t].size();
        for (auto& choose_set : choose_curves[t]) {
            curves_to_test += choose_set.size();
        }
        if (curves_to_test >= 61) {
            error("Too many test cases.");
        }
        int fixed = fixed_curves[t].size();
        if (fixed <= curves_used_exactly and curves_to_test + fixed >= curves_used_exactly) {
            long long current_test_number = algs::nCr(curves_to_test, curves_used_exactly - fixed);
            total_tests += current_test_number;
            if (total_tests >= (1ll<<62)) {
                error("Too many test cases.");
            }
            number_of_tests[t] = current_test_number;
        }
        else {
            number_of_tests[t] = 0;
        }
    }
    return total_tests;
}
